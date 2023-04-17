
#ifndef CELLUVIEW_EROSION_H
#define CELLUVIEW_EROSION_H


#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <iostream>
#include <stdlib.h>
#include <thread>
#include "imageProcessor.h"


class erosion: public imageProcessor{
public:
    erosion() = default;
    void receiveFrame(frame newFrame);
    std::string getParamLabel(){return paramLabel;};

    void updateSettings(std::map<std::string, std::string>);

    void start();
    void stop();

private:
    //add any other methods here
    void erode(); //erosion
    std::string paramLabel = "erosion";

    std::thread erodeThread;

    frame procFrame;
    bool update = false;
    bool running = false;

    std::mutex mut_ero;
    std::condition_variable cond_var_ero;
};
#endif // CELLUVIEW_EROSION_H