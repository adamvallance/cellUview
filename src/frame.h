#ifndef CELLUVIEW_FRAME_H
#define CELLUVIEW_FRAME_H
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>

#include <iostream>
#include <stdlib.h>
#include <thread>
#include <typeinfo>
#include <map>

#define metaDataPairDelim "|"
#define metaDataItemDelim "*"


/**
* Frame structure used for images passing through processing blocks.
* Supports inserting metadata into frames on processing steps applied and threshold values, which can be later read.
**/
class frame{
    public: 
        frame() = default;
        frame(cv::Mat matIn): image(matIn){}

        //custom copy constructor replacement to allow test to pass,
        // provide a pointer to existing frame
        //and copy from there into a constructed second frame
        /**
        * Custom copy constructor.
        * Provide a pointer to an existing frame and copy from there into a constructed second frame.
        **/
        void copyFrom(frame* copyFrom){
            this->image = copyFrom->image;
            this->doMeta = copyFrom ->doMeta;
            this->params = copyFrom->params;

        }

        
        cv::Mat image;
        void setParameter(std::string, std::string);
        std::string encodeMetadata();
        bool doMeta = false;

        std::string getParam(std::string);

        frame(frame const & ) = default; //default copy constructor
        
        int getParamSize();

    
    private:
        std::map<std::string, std::string> params;

        const std::vector<std::string> validParams= {
            "edgeThreshold",
            "erosion",
            "dilation",
            "grayScale",
            "contrastThreshold",
            "flatField",
            "exposure",
            "note"
            //ADD MORE PARAMETERS HERE
        };


        std::string encodedString;

};



#endif //CELLUVIEW_FRAME_H