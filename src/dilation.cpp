
// This file performs standard dilation to grow boundaries in the image. Usually to compensate for erosion

// Author Mark Main

#include "dilation.h"
#include <opencv2/imgproc.hpp>

// Receives new frames through a callback.
/**
* Recieves new frames for processing via callback.
* If enabled, copies recieved frame into a frame for processing.
**/
void dilation::receiveFrame(frame newFrame) {
    if (!enabled){
        newFrame.setParameter(paramLabel, "OFF");
        frameCb->receiveFrame(newFrame);
        return;
    }

    // Pass frame into the dilation function
    //dilate(newFrame); 
    procFrame.copyFrom(&newFrame);      // copy new frame into the frame for processing
    std::lock_guard lock(mut);
    update = true;                      // set flag
    cond_var.notify_all();              // wake thread
}

void dilation::start(){
    running = true;
    dilationThread = std::thread(&dilation::dilate, this);
}

void dilation::stop(){
    running = false;
    dilationThread.join();
}

void dilation::dilate() {

    while(running){

        std::unique_lock lock(mut);
        cond_var.wait_for(lock, 1s); //thread sleep/block for a second but wake up if new data flagged

        if (update){
            frame f; 
            f.copyFrom(&procFrame);

            // Convert input frame to cv::Mat
            cv::Mat input_mat(f.image.rows, f.image.cols, CV_8UC3, f.image.data);

            // Create output cv::Mat
            cv::Mat output_mat(input_mat.size(), CV_8UC3);

            // Perform dilation on the input image
            cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3)); // Set dilation kernel
            cv::dilate(input_mat, output_mat, kernel); // Perform dilation operation

            // Convert output cv::Mat to frame
            f.image = output_mat;

            // Output the frame through the callback onto the next instance in the dataflow
            f.setParameter(paramLabel, "ON");
            frameCb->receiveFrame(f);
            update = false;
        }
        lock.unlock();          // manually unlock mutex
        cond_var.notify_all();  // notify done
    }
}

/**
* Implemented from ImageProcessor. Updates settings based on metadata.
* @param metadata standard map of strings containing metadata
**/
void dilation::updateSettings(std::map<std::string, std::string> metadata){
    
    std::string rec = metadata[paramLabel];

    bool desired = (rec == "ON");
    // std::cout<<rec<<std::endl;

    // std::cout<<desired<<std::endl;

    if (enabled != desired){
        toggleEnable();
    }

    
}