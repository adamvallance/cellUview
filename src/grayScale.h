#ifndef CELLUVIEW_GREY_SCALE_H
#define CELLUVIEW_GREY_SCALE_H

#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <iostream>
#include <stdlib.h>
#include <thread>
#include "imageProcessor.h"

/**
* Image processing class to set to grayscale.
**/
class grayScale: public imageProcessor{

public:
    grayScale() = default;
    void receiveFrame(frame);
    /**
    * @returns paramLabel, std::string containing metadata parameter
    **/
    std::string getParamLabel(){return paramLabel;};
    void updateSettings(std::map<std::string, std::string>);

private:

    void grayEnhance(frame); // grayscale conversion
    std::string paramLabel = "grayScale";
};
#endif // CELLUVIEW_GREY_SCALE_H