#ifndef OPENFLEXURE_GREY_SCALE_H
#define OPENFLEXURE_GREY_SCALE_H

#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <iostream>
#include <stdlib.h>
#include <thread>
#include "imageProcessor.h"

class greyScale: public imageProcessor{

public:
    greyScale() = default;
    void receiveFrame(frame);
    std::string getParamLabel(){return paramLabel;};
    void updateSettings(std::map<std::string, std::string>);

private:

    void greyEnhance(frame); // grayscale conversion
    std::string paramLabel = "greyScale";
};
#endif // OPENFLEXURE_GREY_SCALE_H