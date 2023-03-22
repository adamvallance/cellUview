// This file performs flat field correction on the input image, to compensate for uneven illumination on the image plane

// Author Mark Main

#include "flatField.h"

#include <opencv2/imgproc.hpp>


//Receives in new frames through a callback.
void flatField::newFrame(frame newFrame) {
    // do stuff here

    // passing frame into the edge detection function
    flatFieldCorrect(newFrame); 
}


void flatField::flatFieldCorrect(frame inputFrame) {
    // Load reference and actual images, where reference image is collected by user
    cv::Mat reference_image = cv::imread("reference.jpg", cv::IMREAD_GRAYSCALE);
    cv::Mat actual_image = inputFrame.image;

    // Calculate the correction factor
    cv::Mat correction_factor;
    cv::GaussianBlur(reference_image, reference_image, cv::Size(31, 31), 0); //31x31 is large, but adjustment may be needed to produce an ideal outcome
    cv::divide(reference_image, correction_factor, correction_factor);

    // Apply produced correction factor to the input image
    cv::Mat corrected_image;
    cv::multiply(actual_image, correction_factor, corrected_image);

    // Copy the corrected image back to the input frame
    corrected_image.copyTo(inputFrame.image);
}


