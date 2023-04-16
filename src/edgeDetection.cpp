// This file performs standard edge detection using opencv, at a set threshold. This edge detection is then overlayed on the video stream in the form of white lines.

// Author Mark Main

#include "edgeDetection.h"

#include <opencv2/imgproc.hpp>


//Receives in new frames through a callback.
/**
* Recieves new frames for processing via callback.
* If enabled, copies recieved frame for processing via separate method.
**/
void edgeDetection::receiveFrame(frame newFrame) {
    if (!enabled){
        newFrame.setParameter(paramLabel, "OFF");
        frameCb->receiveFrame(newFrame);
        return;
    }
    // do stuff here

    // passing frame into the edge detection function
    //enhanceEdge(newFrame); 
    procFrame.copyFrom(&newFrame);      // copy new frame into the frame for processing
    std::lock_guard<std::mutex> lock(mut);
    update = true;                      // set flag
    cond_var.notify_all();              // wake thread
}

void edgeDetection::start(){
    running = true;
    edgeThread = std::thread(&edgeDetection::enhanceEdge, this);    //start worker thread
}

void edgeDetection::stop(){
    running = false;
    edgeThread.join();
}


void edgeDetection::enhanceEdge() {

    while(running){

        std::unique_lock<std::mutex> lock(mut);
        cond_var.wait_for(lock, 1s); //thread sleep/block for a second but wake up if new data flagged

        if (update){
            frame f; 
            f.copyFrom(&procFrame);

            // Convert input frame to cv::Mat
            cv::Mat input_mat(f.image.rows, f.image.cols, CV_8UC3, f.image.data);

            // Create output cv::Mat
            cv::Mat output_mat(input_mat.size(), CV_8UC3);

            // Perform edge detection with set threshold
            cv::Mat gray_img;
            cv::cvtColor(input_mat, gray_img, cv::COLOR_BGR2GRAY);
            cv::GaussianBlur(gray_img, gray_img, cv::Size(3, 3), 0);
            cv::Canny(gray_img, gray_img, threshold, threshold);

            // Superimpose edges on to the original frame
            cv::Mat overlay_mat;
            cv::cvtColor(gray_img, overlay_mat, cv::COLOR_GRAY2BGR);
            cv::addWeighted(input_mat, 0.9, overlay_mat, 0.3, 0, output_mat);

            // Add output matrix to frame
            f.image = output_mat;

            f.setParameter(paramLabel, std::to_string(sliderThreshold));
            //TODO: when sliding threshold added this should match threshold variable

            // Output the frame through the callback onto the next instance in the dataflow
            frameCb->receiveFrame(f);
            update = false;
        }
        lock.unlock();          // manually unlock mutex
        cond_var.notify_all();  // notify done
    }
}

/**
* Updates edge detection threshold value for enhancement method.
* Correctly scales GUI slider value.
**/
void edgeDetection::updateThreshold(int value){
    sliderThreshold = value;
    //std::cout<<std::to_string(value)<<std::endl;
    threshold=255-2.55*value;
}

/**
* Implemented from ImageProcessor. Updates settings based on metadata.
* @param metadata standard map of strings containing metadata
**/
void edgeDetection::updateSettings(std::map<std::string, std::string> metadata){
    std::string rec = metadata[paramLabel];
    int metaThreshold;
    if (rec == "OFF"){
        if (enabled == true){
            toggleEnable();
        }
    }else{
        if (enabled==false){
            toggleEnable();
        }
        try{
            metaThreshold = std::stoi(metadata[paramLabel]);
        }catch(...){
            std::cout<<"Error invalid metadata"<<std::endl;
            return;
        }
    }
    
    updateThreshold(metaThreshold);   
}
