
#ifndef OPENFLEXURE_FLAT_FIELD_CORRECT_H
#define OPENFLEXURE_FLAT_FIELD_CORRECT_H


#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <iostream>
#include <stdlib.h>
#include <thread>
#include "imageProcessor.h"
#include "gallery.h"


class flatFieldCorrect: public imageProcessor{
public:
    flatFieldCorrect() = default;

    void receiveFrame(frame newFrame);
    std::string getParamLabel(){return paramLabel;};
    void setUpdateFlag();
    

    void updateSettings(std::map<std::string, std::string>);
private:
    //add any other methods here
    void updateAverage(frame);
    void flatField(frame); //Flat Field Correction
    std::string paramLabel = "flatField";
    cv::Mat current_correction_factor;
    bool calculateAverageEnabled;
    bool averageCalculated = false;
};
#endif // OPENFLEXURE_FLAT_FIELD_CORRECT_H