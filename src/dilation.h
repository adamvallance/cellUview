
#ifndef OPENFLEXURE_DILATION_H
#define OPENFLEXURE_DILATION_H


#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <iostream>
#include <stdlib.h>
#include <thread>
#include "imageProcessor.h"
#include "frame.h"


class dilation: public imageProcessor{
public:
    dilation() = default;
    void receiveFrame(frame newFrame);
    std::string getParamLabel(){return paramLabel;};
    void updateSettings(std::map<std::string, std::string>);

private:
    //add any other methods here
    void dilate(frame); //image dilation
    std::string paramLabel = "dilation";
};
#endif // OPENFLEXURE_DILATION_H