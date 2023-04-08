// This file performs standard edge detection using opencv, at a set threshold. This edge detection is then overlayed on the video stream in the form of white lines.

// Author Mark Main


#include "contrastEnhancement.h"

#include <opencv2/imgproc.hpp>


//Receives in new frames through a callback.
void contrastEnhancement::receiveFrame(frame newFrame) {
    if (!enabled){
        newFrame.setParameter(paramLabel, "OFF");
        frameCb->receiveFrame(newFrame);
        return;
    }
    // do stuff here

    // passing frame into the edge detection function
    contrastEnhance(newFrame); 
}


void contrastEnhancement::contrastEnhance(frame f) {
    // Convert input frame to cv::Mat
    cv::Mat input_mat(f.image.rows, f.image.cols, CV_8UC3, f.image.data);

    // Create output cv::Mat
    cv::Mat output_mat(input_mat.size(), CV_8UC3);

    // Apply contrast enhancement to the input image
    cv::Mat lab_img;
    cv::cvtColor(input_mat, lab_img, cv::COLOR_BGR2Lab);

    std::vector<cv::Mat> lab_planes(3);
    cv::split(lab_img, lab_planes);

    // Apply CLAHE (Contrast Limited Adaptive Histogram Equalization) to the L channel
    cv::Ptr<cv::CLAHE> clahe = cv::createCLAHE();
    clahe->setClipLimit(threshold);
    clahe->apply(lab_planes[0], lab_planes[0]);

    cv::merge(lab_planes, lab_img);
    cv::cvtColor(lab_img, output_mat, cv::COLOR_Lab2BGR);

    // Add output matrix to frame
    f.image = output_mat;

    f.setParameter(paramLabel, std::to_string(sliderThreshold));

    // Output the frame through the callback onto the next instance in the dataflow
    frameCb->receiveFrame(f);


}

void contrastEnhancement::updateThreshold(int value){
    sliderThreshold = value;
    threshold = value;
}
void contrastEnhancement::updateSettings(std::map<std::string, std::string> metadata){
    std::string rec = metadata[paramLabel];
    int metaThreshold;
    if (rec == "OFF"){
        if (enabled == true){
            toggleEnable();
        }
    }else{
        if (enabled==false){
            toggleEnable();
        }
        try{
            metaThreshold = std::stoi(metadata[paramLabel]);
        }catch(...){
            std::cout<<"Error invalid metadata"<<std::endl;
            return;
        }
    }
    
    updateThreshold(metaThreshold);   
}
