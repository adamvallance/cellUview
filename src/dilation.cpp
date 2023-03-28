// This file performs standard dilation to grow boundaries in the image. Usually to compensate for erosion

// Author Mark Main

#include "dilation.h"
#include <opencv2/imgproc.hpp>

// Receives new frames through a callback.
void dilation::newFrame(frame newFrame) {
    // Do stuff here

    // Pass frame into the dilation function
    dilate(newFrame); 
}

void dilation::dilate(frame inputFrame) {
    // Convert input frame to cv::Mat
    cv::Mat input_mat(inputFrame.image.rows, inputFrame.image.cols, CV_8UC3, inputFrame.image.data);

    // Create output cv::Mat
    cv::Mat output_mat(input_mat.size(), CV_8UC3);

    // Perform dilation on the input image
    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3)); // Set dilation kernel
    cv::dilate(input_mat, output_mat, kernel); // Perform dilation operation

    // Convert output cv::Mat to frame
    frame outputFrame;
    outputFrame.image = output_mat.clone();
    outputFrame.edgeThreshold = 0.9;    //example threshold for test
    //TODO: when sliding threshold added this should match threshold variable

    // Output the frame through the callback onto the next instance in the dataflow
    frameCb->newFrame(outputFrame);
}