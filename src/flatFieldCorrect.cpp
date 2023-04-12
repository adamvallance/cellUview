// This file performs flat field correction on the input image, to compensate for uneven illumination on the image plane

// Author Mark Main

#include "flatFieldCorrect.h"


#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>


//Receives in new frames through a callback.



void flatFieldCorrect::receiveFrame(frame newFrame) {
    if (!enabled){ 
        frameCb->receiveFrame(newFrame);
        return;
    }
    // do stuff here

    // passing frame into the edge detection function
    flatField(newFrame); 
}

void flatFieldCorrect::flatField(frame f) {
    // Load reference and actual images, where reference image is collected by user
    std::string pathname = getenv("HOME");
    pathname += + "/OpenFlexureGallery/"; 
    std::string flatFieldPath = pathname + ".FlatFieldGallery/flatField.jpg";
    std::cout << "Recieved Flat field" << std::endl;
    cv::Mat reference_image = cv::imread(flatFieldPath, cv::IMREAD_GRAYSCALE);
    cv::Mat actual_image = f.image;

    // Calculate the correction factor
    cv::Mat correction_factor;
    cv::GaussianBlur(reference_image, reference_image, cv::Size(31, 31), 0); //31x31 is large, but adjustment may be needed to produce an ideal outcome
    cv::resize(reference_image, correction_factor, actual_image.size());
    cv::divide(correction_factor, reference_image, correction_factor);

    cv::Mat correction_factor3C(correction_factor.rows, correction_factor.cols, CV_8UC3); // create new 3-channel image

    // replicate single channel to all three channels
    std::vector<cv::Mat> channels(3);
    channels[0] = correction_factor;
    channels[1] = correction_factor;
    channels[2] = correction_factor;

    // merge three channels into single 3-channel image
    cv::merge(channels, correction_factor3C);



    // Apply produced correction factor to the input image

    cv::Mat corrected_image;

    // Multiply the two matrices 
    cv::multiply(actual_image, correction_factor3C, corrected_image);

    frameCb->receiveFrame(f);
}
