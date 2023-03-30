
#ifndef OPENFLEXURE_EROSION_H
#define OPENFLEXURE_EROSION_H


#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <iostream>
#include <stdlib.h>
#include <thread>
#include "imageProcessor.h"


class erosion: public imageProcessor{
public:
    erosion() = default;
    void newFrame(frame newFrame);

private:
    //add any other methods here
    void erode(frame); //edge detection
};
#endif // OPENFLEXURE_EROSION_H