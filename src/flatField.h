
#ifndef OPENFLEXURE_FLAT_FIELD_CORRECTION_H
#define OPENFLEXURE_FLAT_FIELD_CORRECTION_H


#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <iostream>
#include <stdlib.h>
#include <thread>
#include "imageProcessor.h"


class flatField: public imageProcessor{
public:
    flatFieldCorrect() = default;
    void newFrame(frame newFrame);

private:
    //add any other methods here
    void flatFieldCorrect(frame); //Flat Field Correction
};
#endif // OPENFLEXURE_FLAT_FIELD_CORRECTION_H