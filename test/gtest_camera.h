#include <gtest/gtest.h>
#include "camera.h"

TEST(cameraTest, checkOnOff){
    Camera cam;
    EXPECT_EQ(cam.getIsOn(), false);         //non-fatal failure, isOn starts false
    cam.start();
    EXPECT_EQ(cam.getIsOn(), true);          //check camera started
    cam.stop();
    EXPECT_EQ(cam.getIsOn(), false);         //check camera stopped
}
