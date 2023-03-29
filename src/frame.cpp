#include "frame.h"


void frame::setParameter(std::string param, std::string val){
    if (!doMeta){
        return;
    }

    //if param is valid
    if (std::count(validParams.begin(), validParams.end(), param)){
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
    //c++17
    // for (const auto& [key, value] : &params){
    //     encodedString += key + "*" + value + "*";
    // }
    for (const auto& kv: params){
        encodedString += kv.first + "*" + kv.second + "*";
    }
    return encodedString;
}
std::string frame::getParam(std::string param){
    return params[param];
}