#ifndef OPENFLEXURE_IMAGEPROCESSOR_H
#define OPENFLEXURE_IMAGEPROCESSOR_H
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>

#include <iostream>
#include <stdlib.h>
#include <thread>

//abstract class 
class imageProcessor{
public:
    imageProcessor() = default;

    //  //frame structure passed between processing classes
    struct frame{ 
        cv::Mat image;
        //add metadata in here eg contrast = 0.4 so that settings are saved in the image itself. 
        std::string note;
        //edge detection threshold metadata
        float edgeThreshold;

        //ideas:
        //low res version for gallery view?
        //original un-enhanced version. 
    };

    virtual void newFrame(frame newFrame) = 0; 

    void registerCallback(imageProcessor* cb){
        frameCb = cb;
    }

protected:
    imageProcessor* frameCb = nullptr;
};

#endif