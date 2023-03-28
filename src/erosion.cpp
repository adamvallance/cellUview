// This file performs standard erosion at a set threshold to remove blurry pixels

// Author Mark Main

#include "erosion.h"
#include <opencv2/imgproc.hpp>

// Receives new frames through a callback.
void erosion::newFrame(frame newFrame) {
    // Do stuff here

    // Pass frame into the erosion function
    erode(newFrame); 
}

void erosion::erode(frame inputFrame) {
    // Convert input frame to cv::Mat
    cv::Mat input_mat(inputFrame.image.rows, inputFrame.image.cols, CV_8UC3, inputFrame.image.data);

    // Create output cv::Mat
    cv::Mat output_mat(input_mat.size(), CV_8UC3);

    // Perform erosion on the input image
    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3)); // Set erosion kernel
    cv::erode(input_mat, output_mat, kernel); // Perform erosion operation

    // Convert output cv::Mat to frame
    frame outputFrame;
    outputFrame.image = output_mat.clone();
    outputFrame.edgeThreshold = 0.9;    //set threshold for test
    //TODO: when sliding threshold added this should match threshold variable

    // Output the frame through the callback onto the next instance in the dataflow
    frameCb->newFrame(outputFrame);
}
