
#ifndef OPENFLEXURE_CONTRAST_ENHANCEMENT_H
#define OPENFLEXURE_CONTRAST_ENHANCEMENT_H


#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <iostream>
#include <stdlib.h>
#include <thread>
#include "imageProcessor.h"


class contrastEnhancement:   public imageProcessor{
   

public:
    contrastEnhancement() = default;
    int threshold= 0;
    int sliderThreshold = 10; //slider threshold used for metadata purposes
    void receiveFrame(frame newFrame);
    void updateThreshold(int value);
    void updateSettings(std::map<std::string, std::string>);
    std::string getParamLabel(){return paramLabel;};
private:
    //add any other methods here
    void contrastEnhance(frame); //edge detection
    std::string paramLabel = "contrastThreshold";
};
#endif // OPENFLEXURE_CONTRAST_ENHANCEMENT_H

