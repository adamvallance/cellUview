#ifndef OPENFLEXURE_FRAME_H
#define OPENFLEXURE_FRAME_H
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>

#include <iostream>
#include <stdlib.h>
#include <thread>
#include <typeinfo>
#include <map>


class frame{
    public: 
        frame() = default;
        frame(cv::Mat matIn): image(matIn){}

        //custom copy constructor, provide
        //a pointer to existing frame
        //and copy from there into a constructed second frame
        void copyFrom(frame* copyFrom){
            this->image = copyFrom->image;
            this->params = copyFrom->params;
        }

        
        cv::Mat image;
        void setParameter(std::string, std::string);
        std::string encodeMetadata();
        bool doMeta = true;

        std::string getParam(std::string);

        //frame(frame const & ) = default; //default copy constructor

    
    private:
        std::map<std::string, std::string> params;

        const std::vector<std::string> validParams= {
            "note",
            "edgeThreshold",
            "erosion",
            "dilation"
            //ADD MORE PARAMETERS HERE
        };


        std::string encodedString;

};



#endif //OPENFLEXURE_FRAME_H