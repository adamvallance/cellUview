// This file performs flat field correction on the input image, to compensate for uneven illumination on the image plane

// Author Mark Main

#include "flatFieldCorrect.h"


#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>




void flatFieldCorrect::receiveFrame(frame newFrame) {
    if (!enabled){ 
        frameCb->receiveFrame(newFrame);
        return;
    }
    // do stuff here

    // passing frame into the edge detection function
    flatField(newFrame); 
}

void flatFieldCorrect::updateAverage(frame f) {
    // Load reference images
    std::string pathname = getenv("HOME");
    pathname += + "/OpenFlexureGallery/.FlatFieldGallery/";
    std::vector<cv::Mat> reference_images;
    for (int i = 1; i <= 20; i++) {
        std::string flatFieldPath = pathname + "flatField" + std::to_string(i) + ".jpg";
        cv::Mat reference_image = cv::imread(flatFieldPath, cv::IMREAD_GRAYSCALE);
        reference_images.push_back(reference_image);
    }

    // Calculate the average of the reference images
    cv::Mat average_reference_image;
    cv::addWeighted(reference_images[0], 1.0/20, reference_images[1], 1.0/20, 0, average_reference_image);
    for (int i = 2; i < 20; i++) {
        cv::addWeighted(average_reference_image, 1.0, reference_images[i], 1.0/20, 0, average_reference_image);
    }

    // Calculate the correction factor using the average reference image
    cv::Mat correction_factor;
    cv::GaussianBlur(average_reference_image, average_reference_image, cv::Size(31, 31), 0);
    cv::resize(average_reference_image, correction_factor, f.image.size());
    cv::divide(correction_factor, average_reference_image, correction_factor);

    cv::Mat correction_factor3C(correction_factor.rows, correction_factor.cols, CV_8UC3);
    std::vector<cv::Mat> channels(3);
    channels[0] = correction_factor;
    channels[1] = correction_factor;
    channels[2] = correction_factor;
    cv::merge(channels, correction_factor3C);
    current_correction_factor3C = correction_factor3C;

}


void flatFieldCorrect::flatField(frame f) {
    cv::Mat corrected_image;

    if (calculateAverageEnabled) {
        updateAverage(f);
        cv::multiply(f.image, current_correction_factor3C, corrected_image);
        calculateAverageEnabled = false;
    } else {
        cv::multiply(f.image, current_correction_factor3C, corrected_image);
    }
    
    frameCb->receiveFrame(f);
}

void flatFieldCorrect::setUpdateFlag(){
    calculateAverageEnabled = true;
}
