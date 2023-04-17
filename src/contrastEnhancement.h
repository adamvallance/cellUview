
#ifndef CELLUVIEW_CONTRAST_ENHANCEMENT_H
#define CELLUVIEW_CONTRAST_ENHANCEMENT_H


#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <iostream>
#include <stdlib.h>
#include <thread>
#include "imageProcessor.h"


class contrastEnhancement:   public imageProcessor{
   

public:
    contrastEnhancement() = default;
    float threshold= 0;
    float sliderThreshold = 10; //slider threshold used for metadata purposes
    void receiveFrame(frame newFrame);
    void updateThreshold(int value);
    void updateSettings(std::map<std::string, std::string>);
    std::string getParamLabel(){return paramLabel;};

    void start();
    void stop();

private:
    //add any other methods here
    // void contrastEnhance(frame); //contrast enhancement
    void contrastEnhance(); //contrast enhancement
    std::string paramLabel = "contrastThreshold";

    std::thread contrastThread;

    frame procFrame;
    bool update = false;
    bool running = false;

    std::mutex mut_contrast;
    std::condition_variable cond_var_contrast;

};
#endif // CELLUVIEW_CONTRAST_ENHANCEMENT_H

