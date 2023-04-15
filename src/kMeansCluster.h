
#ifndef CELLUVIEW_K_MEANS_CLUSTER_H
#define CELLUVIEW_K_MEANS_CLUSTER_H


#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <iostream>
#include <stdlib.h>
#include <thread>
#include "imageProcessor.h"


class kMeansCluster: public imageProcessor{
public:
    kMeansCluster() = default;
    void receiveFrame(frame newFrame);
    std::string getParamLabel(){return paramLabel;};

    void updateSettings(std::map<std::string, std::string>);

private:
    //add any other methods here
    void updateKMeans(frame);
    void kMeans(frame);
    std::string paramLabel = "kMean";
    // Define a vector of colors
    std::vector<cv::Vec3b> colors = {cv::Vec3b(255, 0, 0), cv::Vec3b(0, 255, 0), cv::Vec3b(0, 0, 255)};
    cv::Mat current_k_means;
    cv::Mat current_centers;
};
#endif // CELLUVIEW_K_MEANS_CLUSTER_H