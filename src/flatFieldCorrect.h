
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
    void newFrame(frame newFrame);

private:
    //add any other methods here
    void flatField(frame); //Flat Field Correction
};
#endif // OPENFLEXURE_FLAT_FIELD_CORRECT_H