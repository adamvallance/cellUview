//Author Adam Vallance
//This is a template file to be replaced with various image processing. Must be added into the chain in main.cpp and have its callback registered.

//REMEBER to add the cpp to src/CMakeLists.txt

#ifndef OPENFLEXURE_TEMPLATE_H
#define OPENFLEXURE_TEMPLATE_H


#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <iostream>
#include <stdlib.h>
#include <thread>
#include "imageProcessor.h"


class Template: public imageProcessor{
public:
    Template() = default;
    void newFrame(frame newFrame);

private:
    //add any other methods here
    void exampleManipulation(frame); //example manipulation
};
#endif // OPENFLEXURE_TEMPLATE_H