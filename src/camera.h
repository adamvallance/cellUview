#ifndef CELLUVIEW_CAMERA_H
#define CELLUVIEW_CAMERA_H


#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <iostream>
#include <stdlib.h>
#include <thread>
#include "imageProcessor.h"

#include "frame.h"


class Camera{
public:
    Camera() = default;
    void start(int deviceID = 0, int apiID=0);
    void stop();
    //void receiveFrame(frame newFrame);
    bool getIsOn();
    void registerCallback(imageProcessor*);
    void captureMetadata();
    void setExposure(int);
    std::string getParamLable(){return paramLabel;};
    void updateSettings(std::map<std::string, std::string>);

    
private:
    frame f;
    void postFrame();
    void threadLoop();
    cv::VideoCapture videoCapture;
    std::thread cameraThread;
    std::string exposureState = "OFF";
    bool isOn = false;
    std::string paramLabel = "exposure";
    imageProcessor* frameCb = nullptr;
    bool doMeta = false;

};

#endif // CELLUVIEW_CAMERA_H