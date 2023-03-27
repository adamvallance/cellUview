// This file performs flat field correction on the input image, to compensate for uneven illumination on the image plane

// Author Mark Main

#include "flatFieldCorrect.h"

#include "flatFieldCorrect.h"

#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>


//Receives in new frames through a callback.
void flatFieldCorrect::newFrame(frame newFrame) {
    // do stuff here

    // passing frame into the flat field correction function
    flatField(newFrame); 
    
    // show the corrected image
}


void flatFieldCorrect::flatField(frame inputFrame) {
    // Load reference and actual images, where reference image is collected by user
    cv::Mat reference_image = cv::imread("/home/mark/RealTime/LENSopenflexure-microscopy-enhancement/src/capture8.jpg", cv::IMREAD_GRAYSCALE);
    cv::Mat actual_image = inputFrame.image;

    // Calculate the correction factor
    cv::Mat correction_factor;
    cv::GaussianBlur(reference_image, reference_image, cv::Size(31, 31), 0); //31x31 is large, but adjustment may be needed to produce an ideal outcome
    cv::resize(reference_image, correction_factor, actual_image.size());
    cv::divide(correction_factor, reference_image, correction_factor);

    // std::cout << "correction_factor size: " << actual_image.size() << std::endl;
    // std::cout << "reference_image size: " << actual_image.size() << std::endl;
    // std::cout << "correction_factor type: " << actual_image.type() << std::endl;
    // std::cout << "reference_image type: " << actual_image.type() << std::endl;
    // std::cout << "actual image type: " << actual_image.type() << std::endl;

    cv::Mat correction_factor3C(correction_factor.rows, correction_factor.cols, CV_8UC3); // create new 3-channel image

    // replicate single channel to all three channels
    std::vector<cv::Mat> channels(3);
    channels[0] = correction_factor;
    channels[1] = correction_factor;
    channels[2] = correction_factor;

    // merge three channels into single 3-channel image
    cv::merge(channels, correction_factor3C);


// Debugging code to identify matrix type

// int type = correction_factor3C.type();  // Get the data type of the matrix
// std::cout << "type: " << type << std::endl;
// switch (type) {
//     case CV_8UC3:
//         std::cout << "Matrix type is CV_8UC3" << std::endl;
//         break;
//     case CV_8S:
//         std::cout << "Matrix type is CV_8S" << std::endl;
//         break;
//     case CV_16U:
//         std::cout << "Matrix type is CV_16U" << std::endl;
//         break;
//     case CV_16S:
//         std::cout << "Matrix type is CV_16S" << std::endl;
//         break;
//     case CV_32S:
//         std::cout << "Matrix type is CV_32S" << std::endl;
//         break;
//     case CV_32F:
//         std::cout << "Matrix type is CV_32F" << std::endl;
//         break;
//     case CV_64F:
//         std::cout << "Matrix type is CV_64F" << std::endl;
//         break;
//     default:
//         std::cout << "Unknown matrix type" << std::endl;
//         break;
// }


    // Apply produced correction factor to the input image

    cv::Mat corrected_image;

    // Multiply the two matrices 
    cv::multiply(actual_image, correction_factor3C, corrected_image);


    // cv::cvtColor(correction_factor, correction_factor, cv::COLOR_GRAY2RGB);
    // cv::Mat corrected_image = actual_image* correction_factor ;
    //cv::multiply(actual_image, correction_factor, corrected_image);
    //std::cout << "correction_factor size: " << actual_image.size() << std::endl;
    //std::cout << "reference_image size: " << correction_factor.size() << std::endl;

    // // Check if the dimensions of the input frame and corrected image match
    // if (inputFrame.image.size() == corrected_image.size()) {
    //     // Copy the corrected image back to the input frame
    //     corrected_image.copyTo(inputFrame.image);
    // } else {
    //     std::cerr << "Error: image dimensions do not match!" << std::endl;
    // }
    frameCb->newFrame(inputFrame);
}
