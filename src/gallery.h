#ifndef OPENFLEXURE_GALLERY_H
#define OPENFLEXURE_GALLERY_H

#include "stdlib.h"
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include "imageProcessor.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

class Gallery{

    public:
        Gallery();
        void captureFrame(imageProcessor::frame);
        void updateImgName(std::string);
        void updateIndex();

    private:
        DIR *dir;
        struct dirent *ent;
        std::string pathname = "";
        std::string imgName = "capture";
        int captureImgCounter = 0;
        std::string captureFname;
        int index;
        int lastHighestIndex = -1;
        int indexLen = 1;
        std::string existingCaptureFname; 

        cv::Mat img;

};
#endif //OPENFLEXURE_GALLERY_H