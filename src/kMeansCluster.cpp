// This file performs k-means clustering to split an image into centroids for image classification.

// Author Mark Main

#include "kMeansCluster.h"
#include <opencv2/imgproc.hpp>

/**
* Recieves new frames for processing via callback.
**/
void kMeansCluster::receiveFrame(frame newFrame) {
    if (!enabled){
        newFrame.setParameter(paramLabel, "OFF");
        frameCb->receiveFrame(newFrame);
        return;
    }

    // Pass frame into the kMeansCluster function
    kMeans(newFrame); 
}


void kMeansCluster::kMeans(frame f) {
      
    if (calculatePercentageEnabled == true) {
        calculatePercentageEnabled = false;
        percentageCalculated=false;
        updateKMeans(f, true);
        
    }
    else{
        updateKMeans(f, false);
    }  
    
    f.image = current_k_means;


    
    f.setParameter(paramLabel, std::to_string(clusterSlider));
    frameCb->receiveFrame(f);
}




void kMeansCluster::updateKMeans(frame f, bool calculateClusterPercentages) {

    f.image.convertTo(f.image, CV_32FC3);
    
    // Reshape image to a 2D array of pixels
    cv::Mat reshaped = f.image.reshape(1, f.image.rows * f.image.cols);


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
    std::vector<int>transformations;
    for (int i = 0; i < centers.rows; i++) {
        cv::Vec3f row = centers.at<cv::Vec3f>(i);
        rows.push_back(row);
        transformations.push_back(i);
    }

    auto compare_transformations = [&rows](cv::Vec3f& i, cv::Vec3f& j){
        return (i[0] < j[0]);
    };


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
    //std::cout<<transformations[0]<<transformations[1]<<transformations[2]<< "   ";//<<std::endl<<std::endl;
    
    std::vector<int>::iterator it;
    std::vector<int>newTransform;
    for (int i = 0; i < transformations.size(); i++){
        it = std::find(transformations.begin(), transformations.end(), i);
        newTransform.push_back(it - transformations.begin());
    }
    transformations = newTransform;

    // //reassign label values based on reordered centroids 
    //std::cout<<labels.at<int>(0,0);
    for (int i = 0; i < labels.rows; i++){
        labels.at<int>(i, 0) = transformations[labels.at<int>(i, 0)];
        //labels.at<int>(i,0) = transformations.
        ;
    }
    //std::cerr << labels << std::endl;

    centers = output;
    //std::cerr << labels.size << std::endl;
    //std::cout<<labels.at<int>(0,0)<<std::endl;
    

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

    if(calculateClusterPercentages ==true){


        // initialize a vector to store the pixel counts for each cluster
        std::vector<int> pixel_counts(centers.rows, 0);

        // loop over all pixels and increment the corresponding pixel count
        for (int i = 0; i < reshaped.rows; i++) {
            int cluster_id = labels.at<int>(i);
            cv::Vec3b centroid_color = colors[cluster_id];
            heatmap.at<cv::Vec3b>(i) = centroid_color;

            pixel_counts[cluster_id]++;
        }

        // compute the total number of pixels
        int total_pixels = reshaped.rows;
        percentageDisplay.clear();
        // loop over the clusters and print out the percentage of pixels for each cluster
        for (int i = 0; i < pixel_counts.size(); i++) {
            double percentage = (double)pixel_counts[i] / total_pixels * 100;
            std::string percentageStr = std::to_string(percentage);

            //truncate the string
            if (pixel_counts.size()==1){
                percentageStr=percentageStr.substr(0, 6);
            }else{
                percentageStr=percentageStr.substr(0,5);
            }
            percentageStr = percentageStr + " %";

            //std::cout << "Cluster " << i+1 << " has " << pixel_counts[i] << " pixels (" << percentage << "%)." << std::endl;
            cv::Vec3b keyColor = colors[i];
            percentageDisplay.push_back({keyColor, percentageStr});
        }
    }

}


/**
* Updates k-means cluster count value for processing method.
* @param value GUI slider value which is passed to give mapping to clusterSlider.
**/
void kMeansCluster::updateClusterCount(int value){
    num_clusters = value;
    clusterSlider = value;
}


/**
* Enables percentage calculation for cluster size.
**/
void kMeansCluster::centroidPercentage(){
    calculatePercentageEnabled = true;
    percentageCalculated=false;

}

/**
* Getter for k-means cluster percentages to be displayed on the GUI.
**/
std::list<std::pair<cv::Vec3b, std::string>> kMeansCluster::getClusterAnalysis(){
    return percentageDisplay;
}


/**
* Implemented from ImageProcessor. Updates settings based on metadata.
* @param metadata standard map of strings containing metadata
**/
void kMeansCluster::updateSettings(std::map<std::string, std::string> metadata){
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
    
    updateClusterCount(metaThreshold);   
}



