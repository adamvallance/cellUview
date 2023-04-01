#ifndef OPENFLEXURE_GREY_SCALE_H
#define OPENFLEXURE_GREY_SCALE_H

#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <iostream>
#include <stdlib.h>
#include <thread>
#include "imageProcessor.h"

class greyScale: public imageProcessor{

public:
greyScale() = default;

void newFrame(frame newFrame);

private:
//add any other methods here
void greyEnhance(frame); // grayscale conversion
};
#endif // OPENFLEXURE_GREY_SCALE_H