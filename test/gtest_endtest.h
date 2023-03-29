#ifndef GTEST_ENDTEST
#define GTEST_ENDTEST


#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>

#include <iostream>
#include <stdlib.h>
#include <thread>

#include "imageProcessor.h"

class EndTester : public imageProcessor{
    public:
        void receiveFrame(frame newFrame){
            currentFrame = newFrame;
        }
        frame currentFrame;
};


#endif //GTEST_ENDTEST
