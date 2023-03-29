// This file performs standard erosion at a set threshold to remove blurry pixels

// Author Mark Main

#include "erosion.h"
#include <opencv2/imgproc.hpp>

// Receives new frames through a callback.
void erosion::receiveFrame(frame newFrame) {
    if (!enabled){
        newFrame.setParameter("erosion", "OFF");
        frameCb->receiveFrame(newFrame);
        return;
    }

    // Pass frame into the erosion function
    erode(newFrame); 
}

void erosion::erode(frame f) {
    // Convert input frame to cv::Mat
    cv::Mat input_mat(f.image.rows, f.image.cols, CV_8UC3, f.image.data);

    // Create output cv::Mat
    cv::Mat output_mat(input_mat.size(), CV_8UC3);

    // Perform erosion on the input image
    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3)); // Set erosion kernel
    cv::erode(input_mat, output_mat, kernel); // Perform erosion operation

    // Overwrite frame image
    f.image = output_mat;

    f.setParameter("erosion", "ON");
    // Output the frame through the callback onto the next instance in the dataflow
    frameCb->receiveFrame(f);
}
