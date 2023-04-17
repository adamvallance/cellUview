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
    //void receiveFrame(frame newFrame);
    bool getIsOn();
    //void registerCallback(imageProcessor*);
    void captureMetadata();
    void setExposure(int);
    std::string getParamLabel(){return paramLabel;};
    void updateSettings(std::map<std::string, std::string>);
    void receiveFrame(frame newFrame){return;};
    void setNote(std::string);

    
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
    //imageProcessor* frameCb = nullptr;
    bool doMeta = false;
    std::string note = "";

};

#endif // CELLUVIEW_CAMERA_H