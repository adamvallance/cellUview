
#ifndef OPENFLEXURE_DILATION_H
#define OPENFLEXURE_DILATION_H


#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <iostream>
#include <stdlib.h>
#include <thread>
#include "imageProcessor.h"


class dilation: public imageProcessor{
public:
    dilation() = default;
    void receiveFrame(frame newFrame);

private:
    //add any other methods here
    void dilate(frame); //image dilation
};
#endif // OPENFLEXURE_DILATION_H