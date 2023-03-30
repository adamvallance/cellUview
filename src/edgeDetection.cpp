// This file performs standard edge detection using opencv, at a set threshold. This edge detection is then overlayed on the video stream in the form of white lines.

// Author Mark Main

#include "edgeDetection.h"

#include <opencv2/imgproc.hpp>


//Receives in new frames through a callback.
void edgeDetection::receiveFrame(frame newFrame) {
    if (!enabled){
        newFrame.setParameter("edgeThreshold", "OFF");
        frameCb->receiveFrame(newFrame);
        return;
    }
    // do stuff here

    // passing frame into the edge detection function
    enhanceEdge(newFrame); 
}

// void edgeDetection::updateSettings(){
//     parameter = "edgeThreshold"{
        
//     }

// }


void edgeDetection::enhanceEdge(frame f) {
    // Convert input frame to cv::Mat
    cv::Mat input_mat(f.image.rows, f.image.cols, CV_8UC3, f.image.data);

    // Create output cv::Mat
    cv::Mat output_mat(input_mat.size(), CV_8UC3);

    // Perform edge detection with set threshold
    cv::Mat gray_img;
    cv::cvtColor(input_mat, gray_img, cv::COLOR_BGR2GRAY);
    cv::GaussianBlur(gray_img, gray_img, cv::Size(3, 3), 0);
    cv::Canny(gray_img, gray_img, 100, 100);

    // Superimpose edges on to the original frame
    cv::Mat overlay_mat;
    cv::cvtColor(gray_img, overlay_mat, cv::COLOR_GRAY2BGR);
    cv::addWeighted(input_mat, 0.9, overlay_mat, 0.3, 0, output_mat);

    // Add output matrix to frame
    f.image = output_mat;

    f.setParameter("edgeThreshold", std::to_string(0.9));
    //TODO: when sliding threshold added this should match threshold variable

    // Output the frame through the callback onto the next instance in the dataflow
    frameCb->receiveFrame(f);

}

