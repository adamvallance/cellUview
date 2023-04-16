// This file performs standard contrast enhancement using opencv, at a set threshold. This contrast enhancement is then overlayed on the video stream.

// Author Mark Main


#include "contrastEnhancement.h"

#include <opencv2/imgproc.hpp>


//Receives in new frames through a callback.
/**
* Recieves new frames for processing via callback.
**/
void contrastEnhancement::receiveFrame(frame newFrame) {
    if (!enabled){
        newFrame.setParameter(paramLabel, "OFF");
        frameCb->receiveFrame(newFrame);
        return;
    }
    // do stuff here

    // passing frame into the contrast enhancement function
    contrastEnhance(newFrame); 
}


void contrastEnhancement::contrastEnhance(frame f) {
    // Convert input frame to cv::Mat
    cv::Mat input_mat(f.image.rows, f.image.cols, CV_8UC3, f.image.data);

    // Create output cv::Mat
    cv::Mat output_mat(input_mat.size(), CV_8UC3);

    // Apply contrast enhancement to the input image
    cv::Mat lab_img;
    cv::cvtColor(input_mat, lab_img, cv::COLOR_BGR2Lab); //LAB colour space is used in colourimetry

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

/**
* Updates contrast enhancements value for contrast enhancement method.
* Applies non-linearity to slider value.
**/
void contrastEnhancement::updateThreshold(int value){
    sliderThreshold = value;
    threshold = exp(0.022 * value) / 2.2; //Applying non-linearity to slider
    //std::cout<<"Theshold value"<< threshold<<std::endl;
}

/**
* Implemented from ImageProcessor. Updates contrast settings based on metadata.
* @param metadata metadata standard map of strings containing metadata
**/
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
