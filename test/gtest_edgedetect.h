#include <gtest/gtest.h>
#include "gtest_endtest.h"
#include "edgeDetection.h"
#include "frame.h"
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <iostream>


TEST(edgeDetectTest, checkThresholdMetadata){
    
    EndTester endtest;
    edgeDetection edge;

    frame expected; //expected output frame
    expected.setParameter("edgeThreshold", std::to_string(0.9)); //default value
    // expected.edgeThreshold = 0;     //debug, using this will cause a fail
    
    frame f;
    cv::Mat capture;  
    capture.create(5, 5, 1);    //random matrix to process, output not used in test
    f.image = capture;

    edge.registerCallback(&endtest);
    edge.receiveFrame(f);
    std::cout<<endtest.currentFrame.getParam("edgeThreshold")<<std::endl;
    std::cout<<expected.getParam("edgeThreshold")<<std::endl;

    EXPECT_EQ(expected.getParam("edgeThreshold"), endtest.currentFrame.getParam("edgeThreshold"));
}
