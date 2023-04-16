
#ifndef CELLUVIEW_DILATION_H
#define CELLUVIEW_DILATION_H


#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <iostream>
#include <stdlib.h>
#include <thread>
#include "imageProcessor.h"
#include "frame.h"

/**
* Image processing class to implement dilation.
**/
class dilation: public imageProcessor{
public:
    dilation() = default;
    void receiveFrame(frame newFrame);
    std::string getParamLabel(){return paramLabel;};
    void updateSettings(std::map<std::string, std::string>);

    void start();
    void stop();

private:
    //add any other methods here
    void dilate(); //image dilation
    std::string paramLabel = "dilation";

    std::thread dilationThread;

    frame procFrame;
    bool update = false;
    bool running = false;

    std::mutex mut;
    std::condition_variable cond_var;

};
#endif // CELLUVIEW_DILATION_H