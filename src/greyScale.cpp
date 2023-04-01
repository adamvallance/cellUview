#include "greyScale.h"
#include <opencv2/imgproc.hpp>


void greyScale::greyEnhance(frame inputFrame) {
    // Convert input frame to cv::Mat
    cv::Mat input_mat(inputFrame.image.rows, inputFrame.image.cols, CV_8UC3, inputFrame.image.data);

    // Create output cv::Mat
    cv::Mat output_mat(input_mat.size(), CV_8UC3);

    // Convert input frame to grayscale
    cv::Mat gray_frame;
    cv::cvtColor(input_mat, gray_frame, cv::COLOR_BGR2GRAY);

    // Copy grayscale frame to output
    cv::cvtColor(gray_frame, output_mat, cv::COLOR_GRAY2BGR);

    // Convert output cv::Mat to frame
    frame outputFrame;
    outputFrame.image = output_mat.clone();

    // Output the frame through the callback onto the next instance in the dataflow
    frameCb->newFrame(outputFrame);
}