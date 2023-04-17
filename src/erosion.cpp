// This file performs standard erosion at a set threshold to remove blurry pixels

// Author Mark Main

#include "erosion.h"
#include <opencv2/imgproc.hpp>

// Receives new frames through a callback.
void erosion::receiveFrame(frame newFrame) {
    if (!enabled){
        newFrame.setParameter(paramLabel, "OFF");
        frameCb->receiveFrame(newFrame);
        return;
    }

    // Pass frame into the erosion function
    //erode(newFrame); 
    procFrame.copyFrom(&newFrame);      // copy new frame into the frame for processing
    std::lock_guard<std::mutex> lock(mut_ero);
    update = true;                      // set flag
    cond_var_ero.notify_all();              // wake thread
}

void erosion::start(){
    running = true;
    erodeThread = std::thread(&erosion::erode, this);
}

void erosion::stop(){
    running = false;
    erodeThread.join();
}

/**
* Implemented from ImageProcessor. Updates settings based on metadata.
* @param metadata standard map of strings containing metadata
**/
void erosion::updateSettings(std::map<std::string, std::string> metadata){
    
    std::string rec = metadata[paramLabel];

    bool desired = (rec == "ON");
    // std::cout<<rec<<std::endl;

    // std::cout<<desired<<std::endl;

    if (enabled != desired){
        toggleEnable();
    }

    
}

void erosion::erode() {


    while(running){

        std::unique_lock<std::mutex> lock(mut_ero);
        cond_var_ero.wait_for(lock, 1s); //thread sleep/block for a second but wake up if new data flagged
        //std::cout<<"waited"<<std::endl;

        if (update){
            frame f; 
            f.copyFrom(&procFrame);

            // Convert input frame to cv::Mat
            cv::Mat input_mat(f.image.rows, f.image.cols, CV_8UC3, f.image.data);

            // Create output cv::Mat
            cv::Mat output_mat(input_mat.size(), CV_8UC3);

            // Perform erosion on the input image
            cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3)); // Set erosion kernel
            cv::erode(input_mat, output_mat, kernel); // Perform erosion operation

            // Overwrite frame image
            f.image = output_mat;

            f.setParameter(paramLabel, "ON");
            // Output the frame through the callback onto the next instance in the dataflow
            frameCb->receiveFrame(f);
            update = false;
        }
        lock.unlock();          // manually unlock mutex
        cond_var_ero.notify_all();  // notify done
    }
}
