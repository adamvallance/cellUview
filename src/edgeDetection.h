
#ifndef CELLUVIEW_EDGE_DETECTION_H
#define CELLUVIEW_EDGE_DETECTION_H


#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <iostream>
#include <stdlib.h>
#include <thread>
#include "imageProcessor.h"

/**
* Class to implement edge enhancement on image stream.
**/
class edgeDetection:   public imageProcessor{
   

public:
    edgeDetection() = default;
    int threshold= 0;
    int sliderThreshold = 100; //slider threshold used for metadata purposes
    void receiveFrame(frame newFrame);
    void updateThreshold(int value);
    void updateSettings(std::map<std::string, std::string>);
    std::string getParamLabel(){return paramLabel;};
    
    void start();
    void stop();
private:
    //add any other methods here
    void enhanceEdge(); //edge detection
    std::string paramLabel = "edgeThreshold";

    std::thread edgeThread;

    frame procFrame;
    bool update = false;
    bool running = false;

    std::mutex mut;
    std::condition_variable cond_var;


};
#endif // CELLUVIEW_EDGE_DETECTION_H
