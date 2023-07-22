#ifndef CELLUVIEW_IMAGEPROCESSOR_H
#define CELLUVIEW_IMAGEPROCESSOR_H
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include "frame.h"

#include <iostream>
#include <stdlib.h>
#include <thread>

#define LINUX_DEV_NO_MOTORS //comment this to leave out motors


//abstract class 
/**
* Abstract class for image processing blocks.
**/
class imageProcessor{
public:
    imageProcessor() = default;

    virtual void receiveFrame(frame newFrame) = 0; 

    virtual void updateSettings(std::map<std::string, std::string>) = 0;

    virtual std::string getParamLabel() = 0;

    void registerCallback(imageProcessor* cb){
        frameCb = cb;
    }

    bool toggleEnable(){
        enabled = !enabled;
        return enabled;
    }

    bool getEnabled(){
        return enabled;
    }


protected:
    imageProcessor* frameCb = nullptr;
    bool enabled = false;


};

#endif