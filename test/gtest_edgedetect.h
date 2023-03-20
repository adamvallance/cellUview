#include <gtest/gtest.h>
#include "gtest_endtest.h"
#include "edgeDetection.h"

#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <iostream>


TEST(edgeDetectTest, checkOutputNote){
    
    EndTester endtest;
    edgeDetection edge;

    imageProcessor::frame expected; //expected output frame
    // cv::Mat cap;      
    // expected.image = cap;
    expected.note = "Frame processed through edge detection"; //note from running through edge detection, must match edgeDetection.cpp
    // expected.note = "This is a dummy note"; //debug, using this note will cause a fail
    
    imageProcessor::frame f;
    cv::Mat capture;  
    capture.create(5, 5, 1);    //random matrix to process, output not used in test
    f.image = capture;
    f.note = "";
    // POSSIBLE IMPROVEMENT: expand frame struct to include dedicated testnote aside from note?

    edge.registerCallback(&endtest);
    edge.newFrame(f);

    EXPECT_EQ(endtest.currentFrame.note, expected.note);
}
