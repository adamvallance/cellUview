#ifndef OPENFLEXURE_FRAME_H
#define OPENFLEXURE_FRAME_H
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>

#include <iostream>
#include <stdlib.h>
#include <thread>
#include <typeinfo>


class frame{
    public: 
        frame(cv::Mat);
        cv::Mat image;
        void setParameter(std::string, std::string);
        std::string encodeMetadata();
        bool doMeta = true;

    
    private:
        params = std::map<std::string, std::string>;


        const validParams = std::vector<std::string> = {
            "note",
            "edgeThreshold"
            //ADD MORE PARAMETERS HERE
        };


        std::string encodedString;

};



#endif //OPENFLEXURE_FRAME_H