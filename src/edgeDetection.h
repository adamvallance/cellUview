
#ifndef OPENFLEXURE_EDGE_DETECTION_H
#define OPENFLEXURE_EDGE_DETECTION_H


#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <iostream>
#include <stdlib.h>
#include <thread>
#include "imageProcessor.h"


class edgeDetection:  public imageProcessor{
    
public:
    edgeDetection() = default;
    int threshold= 0;
    void newFrame(frame newFrame);
    void updateThreshold(int value);

private:
    //add any other methods here
    void enhanceEdge(frame, int threshold); //edge detection
};
#endif // OPENFLEXURE_EDGE_DETECTION_H