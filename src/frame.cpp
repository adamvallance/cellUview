#include "frame.h"

frame::frame(cv::Mat img){
    image=img;

}

void frame::setParameter(std::string param, std::string val){
    if (!doMeta){
        return;
    }
    
    //if param in valid params
    //assert type is right
    //set parameter


}

std::string frame::encodeMetadata(){
    if (!doMeta){
        return;
    }
}