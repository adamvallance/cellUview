#include "grayScale.h"
#include <opencv2/imgproc.hpp>

void grayScale::receiveFrame(frame newFrame) {
    if (!enabled){
        newFrame.setParameter(paramLabel, "OFF");
        frameCb->receiveFrame(newFrame);
        return;
    }

    // Pass frame into the erosion function
    //grayEnhance(newFrame); 

    procFrame.copyFrom(&newFrame);
    std::lock_guard lock(mut);
    update = true;
    cond_var.notify_all();

    //std::cout<<"Gonna start the new thread for gray scale"<<std::endl;

    // grayScaleThread = std::thread(&grayScale::grayEnhance, this);
    // grayScaleThread = std::thread( [&, this](){ grayEnhance(std::ref(newFrame)); } );
}

void grayScale::start(){
    running = true;
    grayScaleThread = std::thread(&grayScale::grayEnhance, this);
}

void grayScale::stop(){
    running = false;
    grayScaleThread.join();
}

void grayScale::grayEnhance() {
        
    while (running){    

        std::unique_lock lock(mut);
        cond_var.wait_for(lock, 1s); //block for a second but wake up if new data
        std::cout<<"waited 1s for gs"<<std::endl;
        if (update){
            //std::cout<<"Called it"<<std::endl;
        
            // Copy frame for processing
            frame f; 
            f.copyFrom(&procFrame);

            // Convert input frame to cv::Mat
            cv::Mat input_mat(f.image.rows, f.image.cols, CV_8UC3, f.image.data);

            // Create output cv::Mat
            cv::Mat output_mat(input_mat.size(), CV_8UC3);

            // Convert input frame to grayscale
            cv::Mat gray_frame;
            cv::cvtColor(input_mat, gray_frame, cv::COLOR_BGR2GRAY);

            // Copy grayscale frame to output
            cv::cvtColor(gray_frame, output_mat, cv::COLOR_GRAY2BGR);

            //Add output to frame
            f.image = output_mat;

            // Output the frame through the callback onto the next instance in the dataflow
            f.setParameter(paramLabel, "ON");
            frameCb->receiveFrame(f);
            update = false;
        }
        lock.unlock();
        cond_var.notify_all();

    }

}

void grayScale::updateSettings(std::map<std::string, std::string> metadata){
    
    std::string rec = metadata[paramLabel];

    bool desired = (rec == "ON");
    // std::cout<<rec<<std::endl;

    // std::cout<<desired<<std::endl;

    if (enabled != desired){
        toggleEnable();
    }

    
}