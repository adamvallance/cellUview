
#ifndef OPENFLEXURE_EDGE_DETECTION_H
#define OPENFLEXURE_EDGE_DETECTION_H


#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <iostream>
#include <stdlib.h>
#include <thread>
#include "imageProcessor.h"


class edgeDetection:   public imageProcessor{
   

public:
    edgeDetection() = default;
    int threshold= 0;
    int sliderThreshold = 100; //slider threshold used for metadata purposes
    void receiveFrame(frame newFrame);
    void updateThreshold(int value);
    void updateSettings(std::map<std::string, std::string>);
    std::string getParamLabel(){return paramLabel;};
private:
    //add any other methods here
    void enhanceEdge(frame); //edge detection
    std::string paramLabel = "edgeThreshold";
};
#endif // OPENFLEXURE_EDGE_DETECTION_H
