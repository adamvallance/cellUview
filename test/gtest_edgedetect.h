#include <gtest/gtest.h>
#include "gtest_endtest.h"
#include "edgeDetection.h"
#include "frame.h"
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <iostream>


// TEST(edgeDetectTest, checkThresholdMetadata){
    
//     EndTester endtest;
//     edgeDetection edge;

//     frame expected; //expected output frame
//     expected.setParameter("edgeThreshold", std::to_string(90)); //default value
    
//     frame f;
//     cv::Mat capture;  
//     capture.create(5, 5, 1);    //random matrix to process, output not used in test
//     f.image = capture;
//     edge.toggleEnable();
//     edge.registerCallback(&endtest);
//     edge.updateThreshold(90);
//     edge.receiveFrame(f);

//     EXPECT_EQ(expected.getParam("edgeThreshold"), endtest.currentFrame.getParam("edgeThreshold"));
// }
