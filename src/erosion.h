
#ifndef CELLUVIEW_EROSION_H
#define CELLUVIEW_EROSION_H


#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <iostream>
#include <stdlib.h>
#include <thread>
#include "imageProcessor.h"

/**
* Image processing class to carry out standard erosion at a set threshold to remove blurry pixels.
**/
class erosion: public imageProcessor{
public:
    erosion() = default;
    void receiveFrame(frame newFrame);
    /**
    * @returns paramLabel, std::string containing metadata parameter
    **/
    std::string getParamLabel(){return paramLabel;};

    void updateSettings(std::map<std::string, std::string>);

private:
    //add any other methods here
    void erode(frame); //edge detection
    std::string paramLabel = "erosion";
};
#endif // CELLUVIEW_EROSION_H