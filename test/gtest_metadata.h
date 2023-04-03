#include <gtest/gtest.h>
#include "gtest_endtest.h"
#include "edgeDetection.h"
#include "frame.h"
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <iostream>
#include <cstdio>
#include "erosion.h"
#include "dilation.h"
#include "imageProcessor.h"
#include "greyScale.h"

TEST(metadata, saveMetadata){
    
    EndTester endtest;
    edgeDetection edge;
    erosion erode;
    dilation dilate;
    greyScale grey;

    std::vector<imageProcessor *> blocks = {&erode, &dilate, &grey, &edge};
    
    frame f;
    cv::Mat capture;  
    capture.create(5, 5, 1);    //random matrix to process, output not used in test
    f.image = capture;
    f.doMeta = true;


    erode.registerCallback(&dilate);
    dilate.registerCallback(&grey);
    grey.registerCallback(&edge);
    edge.registerCallback(&endtest);
    edge.updateThreshold(90);

    //turn all blocks on
    for (auto block : blocks){
        if (!(block->getEnabled())){
            block->toggleEnable();
        }
    }



    erode.receiveFrame(f);

    frame expected; //expected output frame
    expected.doMeta=true;

    expected.setParameter("erosion", "ON");
    expected.setParameter("dilation", "ON");
    expected.setParameter("edgeThreshold", std::to_string(90)); //default value
    expected.setParameter("greyScale", "ON");


    // std::cout<<f.doMeta<<std::endl;
    // std::cout<<expected.doMeta<<std::endl;

    EXPECT_EQ(expected.getParam("edgeThreshold"), endtest.currentFrame.getParam("edgeThreshold"));
    EXPECT_EQ(expected.getParam("greyScale"), endtest.currentFrame.getParam("greyScale"));
    EXPECT_EQ(expected.getParam("erosion"), endtest.currentFrame.getParam("erosion"));
    EXPECT_EQ(expected.getParam("dilation"), endtest.currentFrame.getParam("dilation"));

    //test 
    edge.updateThreshold(0);
    //turn all blocks off
    for (auto block : blocks){
        if (block->getEnabled()){
            block->toggleEnable();
        }
    }


    expected.setParameter("erosion", "OFF");
    expected.setParameter("dilation", "OFF");
    expected.setParameter("edgeThreshold", "OFF"); 
    expected.setParameter("greyScale", "OFF");
    erode.receiveFrame(f);

    EXPECT_EQ(expected.getParam("edgeThreshold"), endtest.currentFrame.getParam("edgeThreshold"));
    EXPECT_EQ(expected.getParam("erosion"), endtest.currentFrame.getParam("erosion"));
    EXPECT_EQ(expected.getParam("dilation"), endtest.currentFrame.getParam("dilation"));
    EXPECT_EQ(expected.getParam("greyScale"), endtest.currentFrame.getParam("greyScale"));


}


//checks no metadata is saved when it is disabled
TEST(metadata, disableMetadata){
    
    EndTester endtest;
    edgeDetection edge;
    erosion erode;
    dilation dilate;
    greyScale grey;

    std::vector<imageProcessor *> blocks = {&erode, &dilate, &grey, &edge};

    frame f;
    cv::Mat capture;  
    capture.create(5, 5, 1);    //random matrix to process, output not used in test
    f.image = capture;
    f.doMeta = false;


    edge.registerCallback(&erode);
    erode.registerCallback(&dilate);
    dilate.registerCallback(&grey);
    grey.registerCallback(&edge);
    edge.registerCallback(&endtest);
    edge.updateThreshold(90);

    //turn all blocks on
    for (auto block : blocks){
        if (!(block->getEnabled())){
            block->toggleEnable();
        }
    }

    edge.receiveFrame(f);

    EXPECT_EQ("NULL", endtest.currentFrame.getParam("edgeThreshold"));
    EXPECT_EQ("NULL", endtest.currentFrame.getParam("erosion"));
    EXPECT_EQ("NULL", endtest.currentFrame.getParam("dilation"));
    EXPECT_EQ("NULL", endtest.currentFrame.getParam("greyScale"));
    EXPECT_EQ(0, endtest.currentFrame.getParamSize());


}
