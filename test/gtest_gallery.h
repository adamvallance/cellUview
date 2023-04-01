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

TEST(gallery, galleryInit){
    
    Gallery gallery;

    EXPECT_NE("", gallery.getPathname());
}

