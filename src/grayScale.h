#ifndef OPENFLEXURE_GREY_SCALE_H
#define OPENFLEXURE_GREY_SCALE_H

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

private:

    void grayEnhance(frame); // grayscale conversion
    std::string paramLabel = "grayScale";
};
#endif // OPENFLEXURE_GREY_SCALE_H