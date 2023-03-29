#include "frame.h"

frame::frame(cv::Mat img){
    image=img;
}

void frame::setParameter(std::string param, std::string val){
    if (!doMeta){
        return;
    }

    //if param is valid
    if (std::count(validParams.begin(), validParams.end(), param){
        params[param] = val;
    }else{
        std::cerr<< "invalid metadata paremter" <<std::endl;
    }
    
    //if param in valid params
    //assert type is right
    //set parameter


}

std::string frame::encodeMetadata(){
    if (!doMeta){
        return "";
    }
    for (const auto& [key, value] : params){
        encodedString += key + "*" + value + "*";
    }
    return encodedString;
}