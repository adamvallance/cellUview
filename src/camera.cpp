#include "camera.h"

void Camera::threadLoop()
{
    while (isOn)
    {
        postFrame();
    }
}

void Camera::postFrame()
{
    if (frameCb == nullptr)
        return;
    cv::Mat capture;
    videoCapture.read(capture);
    if (capture.empty())
    {
        std::cerr << "cellUview Error! blank frame grabbed\nPlease check your PiCamera microscope module is connected.<n";
        frameCb == nullptr;
        this->stop(); // stop processing. To avoid endless loop
        throw 1;
        // exit(1);
    }

    // Create frame instance
    frame f;
    f.doMeta = doMeta;

    // turn back off for next frame
    if (doMeta)
    {
        f.setParameter(paramLabel, exposureState);
        f.setParameter(paramLabel2, note);
        doMeta = false;
    }

    f.image = capture;
    // outputs f to the receiveFrame method of the next object in the dataflow through a callback
    frameCb->receiveFrame(f);
}

/**
* Starts recording in separate camera thread.
**/
void Camera::start(int deviceID, int apiID){
    isOn = true;
    videoCapture.open(deviceID, apiID);
    videoCapture.set(cv::CAP_PROP_AUTO_EXPOSURE, 3); // set initial value to auto exposure
    cameraThread = std::thread(&Camera::threadLoop, this);
}

/**
* Stops camera thread. Call before program exit.
**/
void Camera::stop(){
    isOn = false;
    cameraThread.join();
}

/**
* Modifies camera exposure value
* @param exposureValue exposure in EV 
**/
void Camera::setExposure(int exposureValue){
    exposureState = std::to_string(exposureValue);
    videoCapture.set(cv::CAP_PROP_AUTO_EXPOSURE, 1); // set to manual exposure
    int mapped = exposureValue * 5;
    videoCapture.set(cv::CAP_PROP_EXPOSURE, exposureValue);
}


/**
* @returns isOn, true if camera recording started
**/
bool Camera::getIsOn(){
    return isOn; // method to check status of camera
}

/**
* Sets doMeta to true, to enable metadata in frame structure for the following frame.
**/
void Camera::captureMetadata(){
    doMeta = true;
}

/**
* @param metadata updates exposure value saved in restored metadata map
**/
void Camera::updateSettings(std::map<std::string, std::string> metadata){
    exposureState = metadata[paramLabel];

    int metaThreshold;
    if (exposureState == "OFF"){
        videoCapture.set(cv::CAP_PROP_AUTO_EXPOSURE, 3); // set initial value to auto exposure
    }else{
        try{
            metaThreshold = std::stoi(metadata[paramLabel]);
        }catch(...){
            std::cout<<"Error invalid metadata"<<std::endl;
            return;
        }
    }
    
    setExposure(metaThreshold);   
}

/**
* Sets the note value which is saved in metadata and shown under images in the gallery preview.
**/
void Camera::setNote(std::string noteIn){
    note = noteIn;
    std::cout<<note<<std::endl;
}