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

void kMeansCluster::updateKMeans(frame f) {

    f.image.convertTo(f.image, CV_32FC3);
    
    // Reshape image to a 2D array of pixels
    cv::Mat reshaped = f.image.reshape(1, f.image.rows * f.image.cols);

    // Define the number of clusters
    int num_clusters = 3;

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



    //Reordering centroids to avoid looking like a disco, with changing colours!
 // Extract the rows from the input matrix
    std::vector<cv::Vec3f> rows;
    for (int i = 0; i < centers.rows; i++) {
        cv::Vec3f row = centers.at<cv::Vec3f>(i);
        rows.push_back(row);
    }

    auto compare_transformations = [&rows](cv::Vec3f& i, cv::Vec3f& j){
        return (i[0] < j[0]);
    };
    std::vector<int>transformations = {0,1,2};

    // Sort the rows based on the first element of each row
    // std::sort(rows.begin(), rows.end(),
    //           [](const cv::Vec3f& a, const cv::Vec3f& b) {
    //               return a[0] < b[0];
    //           });
    std::sort(transformations.begin(), transformations.end(),
              [rows](int a, int b) {
                  return rows[a][0] < rows[b][0];
              });
    // Build the output matrix from the sorted rows

    cv::Mat output = cv::Mat::zeros(centers.size(), centers.type());
    for (int i = 0; i < rows.size(); i++) {
        cv::Vec3f row = rows[transformations[i]];
        output.at<cv::Vec3f>(i) = row;
    }
    centers = output;
    //std::cout<<centers<<std::endl;
    std::cout<<transformations[0]<<transformations[1]<<transformations[2]<< "   ";//<<std::endl<<std::endl;
    

    // //reassign label values based on reordered centroids 
    std::cout<<labels.at<int>(0,0);
    for (int i = 0; i < labels.rows; i++){
        labels.at<int>(i, 0) = transformations[labels.at<int>(i, 0)];
        ;
    }
    //std::cerr << centers << std::endl;

    centers = output;
    //std::cerr << labels.size << std::endl;
    std::cout<<labels.at<int>(0,0)<<std::endl;
    

    // Replace each pixel with the centroid of its cluster
    for (int i = 0; i < reshaped.rows; i++) {
        int cluster_id = labels.at<int>(i);
        reshaped.at<float>(i, 0) = centers.at<float>(cluster_id, 0);
    }

    // Reshape the image back to its original size
    cv::Mat output_mat = reshaped.reshape(1, f.image.rows).reshape(3, f.image.rows);


    // Convert output cv::Mat to f.image
    f.image = output_mat;
    cv::Mat heatmap = cv::Mat::zeros(f.image.rows, f.image.cols, CV_8UC3);
    // Convert centers to CV_8UC3
    cv::Mat centers_8u;
    centers.convertTo(centers_8u, CV_8UC3);


    // Iterate through the pixels and assign colors based on the cluster IDs
    for (int i = 0; i < reshaped.rows; i++) {
        int cluster_id = labels.at<int>(i);
        cv::Vec3b centroid_color = colors[cluster_id];
        heatmap.at<cv::Vec3b>(i) = centroid_color;
    }

    current_k_means = heatmap;
}


void kMeansCluster::kMeans(frame f) {
    
    
    updateKMeans(f);
    f.image = current_k_means;

    f.setParameter(paramLabel, "ON");
    frameCb->receiveFrame(f);
}

