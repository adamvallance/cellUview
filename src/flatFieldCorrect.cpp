// This file performs flat field correction on the input image, to compensate for uneven illumination on the image plane

// Author Mark Main

#include "flatFieldCorrect.h"


#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>




void flatFieldCorrect::receiveFrame(frame newFrame) {
    if (!enabled){ 
        newFrame.setParameter(paramLabel, "OFF");
        frameCb->receiveFrame(newFrame);
        return;
    }
    // do stuff here

    // passing frame into the edge detection function
    flatField(newFrame); 


}


void flatFieldCorrect::updateSettings(std::map<std::string, std::string> metadata){
    
    std::string rec = metadata[paramLabel];

    bool desired = (rec == "ON");
    // std::cout<<rec<<std::endl;

    // std::cout<<desired<<std::endl;

    if (enabled != desired){
        toggleEnable();
    }

    
}
void flatFieldCorrect::updateAverage(frame f) {
    // Load reference images
    std::string pathname = getenv("HOME");
    pathname += + "/OpenFlexureGallery/.FlatFieldGallery/";
    std::vector<cv::Mat> reference_images;
    for (int i = 1; i <= 20; i++) {
        std::string flatFieldPath = pathname + "flatField" + std::to_string(i) + ".jpg";
        cv::Mat reference_image = cv::imread(flatFieldPath);
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
    cv::Mat normalised_correction_factor;
    cv::normalize(correction_factor, normalised_correction_factor, 0, 1, cv::NORM_MINMAX);


    current_correction_factor = normalised_correction_factor;

}




void flatFieldCorrect::flatField(frame f) {
    cv::Mat corrected_image;

    if (calculateAverageEnabled) {
        updateAverage(f);
        cv::multiply(f.image, current_correction_factor, corrected_image);
        std::string pathname = getenv("HOME");
        pathname += + "/OpenFlexureGallery/"; 
        std::string filename = pathname + "bob" + ".jpg";
        cv::imwrite(filename, current_correction_factor);
        calculateAverageEnabled = false;
    } else {
        cv::multiply(f.image, current_correction_factor, corrected_image);
    }
    f.image = corrected_image;
    f.setParameter(paramLabel, "ON");
    frameCb->receiveFrame(f);
}

void flatFieldCorrect::setUpdateFlag(){
    calculateAverageEnabled = true;
}