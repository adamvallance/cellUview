// This file performs standard edge detection using opencv, at a set threshold. This edge detection is then overlayed on the video stream in the form of white lines.

// Author Mark Main

#include "edgeDetection.h"

#include <opencv2/imgproc.hpp>


//Receives in new frames through a callback.
/**
* Recieves new frames for processing via callback.
**/
void edgeDetection::receiveFrame(frame newFrame) {
    if (!enabled){
        newFrame.setParameter(paramLabel, "OFF");
        frameCb->receiveFrame(newFrame);
        return;
    }
    // do stuff here

    // passing frame into the edge detection function
    enhanceEdge(newFrame); 
}


void edgeDetection::enhanceEdge(frame f) {
    // Convert input frame to cv::Mat
    cv::Mat input_mat(f.image.rows, f.image.cols, CV_8UC3, f.image.data);

    // Create output cv::Mat
    cv::Mat output_mat(input_mat.size(), CV_8UC3);

    // Perform edge detection with set threshold
    cv::Mat gray_img;
    cv::cvtColor(input_mat, gray_img, cv::COLOR_BGR2GRAY);
    cv::GaussianBlur(gray_img, gray_img, cv::Size(3, 3), 0);
    cv::Canny(gray_img, gray_img, threshold, threshold);

    // Superimpose edges on to the original frame
    cv::Mat overlay_mat;
    cv::cvtColor(gray_img, overlay_mat, cv::COLOR_GRAY2BGR);
    double alpha = 0.9;     // variables for weighted sum of arrays calculation
    double beta = 0.3;      // array sum calculation:
    double gamma = 0.0;     // output_mat = array1*alpha + array2*beta + gamma
    cv::addWeighted(input_mat, alpha, overlay_mat, beta, gamma, output_mat);

    // Add output matrix to frame
    f.image = output_mat;

    f.setParameter(paramLabel, std::to_string(sliderThreshold));
    //TODO: when sliding threshold added this should match threshold variable

    // Output the frame through the callback onto the next instance in the dataflow
    frameCb->receiveFrame(f);

}

/**
* Updates edge detection threshold value for processing method.
* @param value GUI slider value which is scaled to give correct mapping to threshold.
**/
void edgeDetection::updateThreshold(int value){
    sliderThreshold = value;
    //std::cout<<std::to_string(value)<<std::endl;
    double max_value = 255;                     // maximum threshold value
    double scale_factor = 2.55;                 // allows scaling of slider value from percentage to proportion of maximum value
    threshold=max_value-scale_factor*value;     // creates inversely proportional relationship between GUI slider and edge threshold, linear from max to min
}

/**
* Implemented from ImageProcessor. Updates settings based on metadata.
* @param metadata standard map of strings containing metadata
**/
void edgeDetection::updateSettings(std::map<std::string, std::string> metadata){
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
