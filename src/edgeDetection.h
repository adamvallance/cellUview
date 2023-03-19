
#ifndef OPENFLEXURE_EDGE_DETECTION_H
#define OPENFLEXURE_EDGE_DETECTION_H


#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <iostream>
#include <stdlib.h>
#include <thread>
#include "imageProcessor.h"


class edgeDetection: public imageProcessor{
public:
    edgeDetection() = default;
    void newFrame(frame newFrame);

private:
    //add any other methods here
    void enhanceEdge(frame); //edge detection
};
#endif // OPENFLEXURE_EDGE_DETECTION_H