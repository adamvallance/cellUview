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
#include "gallery.h"
#include "unistd.h"

TEST(gallery, galleryInit)
{

    Gallery gallery;

    EXPECT_NE("", gallery.getPathname());
}

//captures an image, checks it is captured, messes with settings, restores settings from metadata, deletes capture and checks it is gone
TEST(gallery, galleryCaptureAndRestore)
{

    Gallery gallery;
    EndTester endtest1;
    EndTester endtest2;
    edgeDetection edge;
    erosion erode;
    dilation dilate;

    std::vector<imageProcessor *> blocks = {&erode, &dilate, &edge};

    frame f;
    cv::Mat capture;
    capture.create(5, 5, 1); // random matrix to process, output not used in test
    f.image = capture;
    f.doMeta = true;

    erode.registerCallback(&dilate);
    dilate.registerCallback(&edge);
    edge.registerCallback(&endtest1);
    edge.updateThreshold(90);

    // turn all blocks on
    for (auto block : blocks)
    {
        if (!(block->getEnabled()))
        {
            block->toggleEnable();
        }
    }

    erode.receiveFrame(f);

    EXPECT_EQ("90", endtest1.currentFrame.getParam("edgeThreshold"));
    EXPECT_EQ("ON", endtest1.currentFrame.getParam("erosion"));
    EXPECT_EQ("ON", endtest1.currentFrame.getParam("dilation"));

    gallery.captureFrame(endtest1.currentFrame);

    std::string capFname = gallery.getCaptureFname();
    // assert file exists
    int open = access(capFname.c_str(), F_OK);
    EXPECT_TRUE(open == 0);

    std::map<std::string, std::string> metadata = gallery.getMetadata(gallery.getCaptureFname());

    // mess with settings
    // turn all blocks off
    for (auto block : blocks)
    {
        if (block->getEnabled())
        {
            block->toggleEnable();
        }
    }
    edge.updateThreshold(50);

    // restore settings from metadata 
    for (auto block : blocks)
    {
        block->updateSettings(metadata);
    }

    edge.registerCallback(&endtest2);
    erode.receiveFrame(f);

    EXPECT_EQ(endtest1.currentFrame.getParam("edgeThreshold"), endtest2.currentFrame.getParam("edgeThreshold"));
    EXPECT_EQ(endtest1.currentFrame.getParam("erosion"), endtest2.currentFrame.getParam("erosion"));
    EXPECT_EQ(endtest1.currentFrame.getParam("dilation"), endtest2.currentFrame.getParam("dilation"));

    // delete capture
    std::remove(capFname.c_str());
    // assert it is deleted
    open = access(capFname.c_str(), F_OK);
    EXPECT_TRUE(open != 0);
}
