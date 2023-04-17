#ifndef CELLUVIEW_CAMERA_H
#define CELLUVIEW_CAMERA_H


#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <iostream>
#include <stdlib.h>
#include <thread>
#include "imageProcessor.h"

#include "frame.h"

/**
* Class to capture frames at framerate of camera using OpenCV and send to image processing blocks through callbacks.
**/
class Camera: public imageProcessor{
public:
    Camera() = default;
    void start(int deviceID = 0, int apiID=0);
    void stop();
    bool getIsOn();
    void captureMetadata();
    void setExposure(int);
    void updateSettings(std::map<std::string, std::string>);
    void setNote(std::string);
    
    /**
    * Not required for camera.
    **/
    std::string getParamLabel(){return paramLabel;};

    /**
    * Not required for camera.
    **/
    void receiveFrame(frame newFrame){return;};


    
private:
    frame f;
    void postFrame();
    void threadLoop();
    cv::VideoCapture videoCapture;
    std::thread cameraThread;
    std::string exposureState = "OFF";
    bool isOn = false;
    std::string paramLabel = "exposure";
    std::string paramLabel2 = "note";
    bool doMeta = false;
    std::string note = " ";

};

#endif // CELLUVIEW_CAMERA_H