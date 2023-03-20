// This file performs standard edge detection using opencv, at a set threshold. This edge detection is then overlayed on the video stream in the form of white lines.

// Author Mark Main

#include "edgeDetection.h"

#include <opencv2/imgproc.hpp>


//Receives in new frames through a callback.
void edgeDetection::newFrame(frame newFrame) {
    // do stuff here

    // passing frame into the edge detection function
    enhanceEdge(newFrame); 
}


void edgeDetection::enhanceEdge(frame inputFrame) {
    // Convert input frame to cv::Mat
    cv::Mat input_mat(inputFrame.image.rows, inputFrame.image.cols, CV_8UC3, inputFrame.image.data);

    // Create output cv::Mat
    cv::Mat output_mat(input_mat.size(), CV_8UC3);

    // Perform edge detection with set threshold
    cv::Mat gray_frame;
    cv::cvtColor(input_mat, gray_frame, cv::COLOR_BGR2GRAY);
    cv::GaussianBlur(gray_frame, gray_frame, cv::Size(3, 3), 0);
    cv::Canny(gray_frame, gray_frame, 100, 100);

    // Superimpose edges on to the origional frame
    cv::Mat overlay_mat;
    cv::cvtColor(gray_frame, overlay_mat, cv::COLOR_GRAY2BGR);
    cv::addWeighted(input_mat, 0.9, overlay_mat, 0.3, 0, output_mat);

    // Convert output cv::Mat to frame
    frame outputFrame;
    outputFrame.image = output_mat.clone();
    outputFrame.note = "Frame processed through edge detection";  //processing note, if updated must update test

    // Output the frame through the callback onto the next instance in the dataflow
    frameCb->newFrame(outputFrame);
}

