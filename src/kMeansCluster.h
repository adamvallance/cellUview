
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
    void kMeans(frame); //edge detection
    std::string paramLabel = "kMean";
};
#endif // CELLUVIEW_K_MEANS_CLUSTER_H