#include <gtest/gtest.h>
#include "gtest_endtest.h"
#include "edgeDetection.h"

#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <iostream>


TEST(edgeDetectTest, checkThresholdMetadata){
    
    EndTester endtest;
    edgeDetection edge;

    imageProcessor::frame expected; //expected output frame
    expected.edgeThreshold = 0.9;   //default value
    // expected.edgeThreshold = 0;     //debug, using this will cause a fail
    
    imageProcessor::frame f;
    cv::Mat capture;  
    capture.create(5, 5, 1);    //random matrix to process, output not used in test
    f.image = capture;

    edge.registerCallback(&endtest);
    edge.newFrame(f);

    EXPECT_EQ(endtest.currentFrame.edgeThreshold, expected.edgeThreshold);
}
