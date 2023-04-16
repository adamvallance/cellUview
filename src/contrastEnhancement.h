
#ifndef CELLUVIEW_CONTRAST_ENHANCEMENT_H
#define CELLUVIEW_CONTRAST_ENHANCEMENT_H


#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <iostream>
#include <stdlib.h>
#include <thread>
#include "imageProcessor.h"


/**
* Image processing class to boost contrast.
**/
class contrastEnhancement:   public imageProcessor{
   

public:
    contrastEnhancement() = default;
    float threshold= 0;
    float sliderThreshold = 10; //slider threshold used for metadata purposes
    void receiveFrame(frame newFrame);
    void updateThreshold(int value);
    void updateSettings(std::map<std::string, std::string>);
    std::string getParamLabel(){return paramLabel;};
private:
    //add any other methods here
    void contrastEnhance(frame); //contrast enhancement
    std::string paramLabel = "contrastThreshold";

};
#endif // CELLUVIEW_CONTRAST_ENHANCEMENT_H

