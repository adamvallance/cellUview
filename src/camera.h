#ifndef OPENFLEXURE_CAMERA_H
#define OPENFLEXURE_CAMERA_H


#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <iostream>
#include <stdlib.h>
#include <thread>
#include "imageProcessor.h"


class Camera: public imageProcessor{
public:
    Camera() = default;
    void start(int deviceID = 0, int apiID=0);
    void stop();
    void newFrame(frame newFrame);
    
private:
    void postFrame();
    void threadLoop();
    cv::VideoCapture videoCapture;
    std::thread cameraThread;
    bool isOn = false;
};
#endif // OPENFLEXURE_CAMERA_H