
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
    void receiveFrame(frame newFrame);
    std::string getParamLabel(){return paramLabel;};

    void updateSettings(std::map<std::string, std::string>);

private:
    //add any other methods here
    void erode(frame); //edge detection
    std::string paramLabel = "erosion";
};
#endif // OPENFLEXURE_EROSION_H