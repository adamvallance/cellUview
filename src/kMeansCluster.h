
#ifndef OPENFLEXURE_K_MEANS_CLUSTER_H
#define OPENFLEXURE_K_MEANS_CLUSTER_H


#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <iostream>
#include <stdlib.h>
#include <thread>
#include "imageProcessor.h"


class kMeansCluster: public imageProcessor{
public:
    kMeansCluster() = default;
    void newFrame(frame newFrame);

private:
    //add any other methods here
    void kMeans(frame); //k means clustering
    int frame_counter = 0;
};
#endif // OPENFLEXURE_EK_MEANS_CLUSTER_H