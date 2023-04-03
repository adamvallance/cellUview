
#ifndef OPENFLEXURE_FLAT_FIELD_CORRECT_H
#define OPENFLEXURE_FLAT_FIELD_CORRECT_H


#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <iostream>
#include <stdlib.h>
#include <thread>
#include "imageProcessor.h"


class flatFieldCorrect: public imageProcessor{
public:
    flatFieldCorrect() = default;
    void receiveFrame(frame newFrame);
    std::string getParamLabel(){return paramLabel;};

    void updateSettings(std::map<std::string, std::string>){return;};
private:
    //add any other methods here
    void flatField(frame); //Flat Field Correction
    std::string paramLabel = "flatField";
};
#endif // OPENFLEXURE_FLAT_FIELD_CORRECT_H