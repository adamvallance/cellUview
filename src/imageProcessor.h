#ifndef OPENFLEXURE_IMAGEPROCESSOR_H
#define OPENFLEXURE_IMAGEPROCESSOR_H
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include "frame.h"

#include <iostream>
#include <stdlib.h>
#include <thread>

//abstract class 
class imageProcessor{
public:
    imageProcessor() = default;

    virtual void receiveFrame(frame newFrame) = 0; 

    virtual void updateSettings(std::string) = 0;

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
    std::string parameter;
    bool enabled = true;


};

#endif