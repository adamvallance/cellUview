#ifndef CELLUVIEW_GREY_SCALE_H
#define CELLUVIEW_GREY_SCALE_H

#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <iostream>
#include <stdlib.h>
#include <thread>
#include "imageProcessor.h"



class grayScale: public imageProcessor{

public:
    grayScale() = default;
    void receiveFrame(frame);
    std::string getParamLabel(){return paramLabel;};
    void updateSettings(std::map<std::string, std::string>);

    void start();
    void stop();

private:

    //void grayEnhance(frame); // grayscale conversion
    void grayEnhance(); // grayscale conversion
    std::string paramLabel = "grayScale";
    std::thread grayScaleThread;
    frame procFrame;
    bool update = false;
    bool running = false;

    std::mutex mut;
    std::condition_variable cond_var;

};
#endif // CELLUVIEW_GREY_SCALE_H