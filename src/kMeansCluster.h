
#ifndef CELLUVIEW_K_MEANS_CLUSTER_H
#define CELLUVIEW_K_MEANS_CLUSTER_H


#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <iostream>
#include <stdlib.h>
#include <thread>
#include "imageProcessor.h"
#include <list>
#include <cmath>


/**
* Image analysis class to sort incoming frames into centroids which are used to classify regions in the frame.
**/
class kMeansCluster: public imageProcessor{
public:
    kMeansCluster() = default;
    void receiveFrame(frame newFrame);
    /**
    * @returns paramLabel, std::string containing metadata parameter
    **/
    std::string getParamLabel(){return paramLabel;};
    int num_clusters = 0; //number of clusters used in kmeans operation
    int clusterSlider = 2;
    void updateClusterCount(int value);
    void updateSettings(std::map<std::string, std::string>);
    void centroidPercentage();
    std::list<std::pair<cv::Vec3b, std::string>> getClusterAnalysis();

private:
    //add any other methods here
    void updateKMeans(frame, bool);
    void kMeans(frame);
    std::string paramLabel = "kMean";
    // Define a vector of colors
    std::vector<cv::Vec3b> colors = {cv::Vec3b(0xB4, 0x77, 0x1F), cv::Vec3b(0x0F, 0x7F, 0xFF), cv::Vec3b(0x2C, 0xA0, 0x2C),cv::Vec3b(0x28, 0x27, 0xD6), cv::Vec3b(0xBD, 0x67, 0x94), cv::Vec3b(0x4B, 0x56, 0x8C),cv::Vec3b(0xC2, 0x77, 0xE3), cv::Vec3b(0x7F, 0x7F, 0x7F), cv::Vec3b(0x22, 0xBD, 0xBC), cv::Vec3b(0xCF, 0xBE, 0x17)};
    cv::Mat current_k_means;
    cv::Mat current_centers;
    bool calculatePercentageEnabled = false;
    bool percentageCalculated = false;
    //std::list<std::pair<std::string, cv::Mat>>
    std::list<std::pair<cv::Vec3b, std::string>> percentageDisplay;
};
#endif // CELLUVIEW_K_MEANS_CLUSTER_H