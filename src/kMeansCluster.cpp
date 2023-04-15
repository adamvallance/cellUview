// This file performs standard kMeansCluster at a set threshold to remove blurry pixels

// Author Mark Main

#include "kMeansCluster.h"
#include <opencv2/imgproc.hpp>

// Receives new frames through a callback.
void kMeansCluster::receiveFrame(frame newFrame) {
    if (!enabled){
        newFrame.setParameter(paramLabel, "OFF");
        frameCb->receiveFrame(newFrame);
        return;
    }

    // Pass frame into the kMeansCluster function
    kMeans(newFrame); 
}

void kMeansCluster::updateSettings(std::map<std::string, std::string> metadata){
    
    std::string rec = metadata[paramLabel];

    bool desired = (rec == "ON");
    // std::cout<<rec<<std::endl;

    // std::cout<<desired<<std::endl;

    if (enabled != desired){
        toggleEnable();
    }

    
}

void kMeansCluster::kMeans(frame f) {
    cv::Mat frame = f.image;
    frame.convertTo(frame, CV_32FC3);
    
    // Reshape image to a 2D array of pixels
    cv::Mat reshaped = frame.reshape(1, frame.rows * frame.cols);

    // Define the number of clusters
    int num_clusters = 10;

    // Check if the number of clusters is positive
    if (num_clusters <= 0) {
        std::cerr << "Error: number of clusters must be positive" << std::endl;
        return;
    }

    // Define termination criteria for the k-means algorithm
    cv::TermCriteria criteria(cv::TermCriteria::EPS + cv::TermCriteria::COUNT, 10, 1.0);

    // Perform k-means clustering on the reshaped image
    cv::Mat labels;
    cv::Mat centers;
    try {
        cv::kmeans(reshaped, num_clusters, labels, criteria, 3, cv::KMEANS_PP_CENTERS, centers);
    } catch (cv::Exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return;
    }

    // Replace each pixel with the centroid of its cluster
    for (int i = 0; i < reshaped.rows; i++) {
        int cluster_id = labels.at<int>(i);
        reshaped.at<float>(i, 0) = centers.at<float>(cluster_id, 0);
    }

    // Reshape the image back to its original size
    cv::Mat output_mat = reshaped.reshape(1, frame.rows).reshape(3, frame.rows);


    // Convert output cv::Mat to frame
    frame = output_mat;
    cv::Mat heatmap = cv::Mat::zeros(frame.rows, frame.cols, CV_8UC3);
    // Convert centers to CV_8UC3
    cv::Mat centers_8u;
    centers.convertTo(centers_8u, CV_8UC3);

    for (int i = 0; i < reshaped.rows; i++) {
        int cluster_id = labels.at<int>(i);
        cv::Vec3b centroid_color = centers_8u.at<cv::Vec3b>(cluster_id);
        heatmap.at<cv::Vec3b>(i) = centroid_color;
    }
    
  
    cv::Mat heatmap_resized;
    cv::resize(heatmap, heatmap_resized, frame.size(), 0, 0, cv::INTER_LINEAR);
    heatmap_resized.convertTo(frame, frame.type());
    frame.convertTo(frame, CV_8UC3);
    f.image = frame;

    // Output the frame through the callback onto the next instance in the dataflow
    frameCb->receiveFrame(f);
}