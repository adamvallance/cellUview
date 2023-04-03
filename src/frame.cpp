#include "frame.h"


void frame::setParameter(std::string param, std::string val){
    if (doMeta == false){
        return;
    }

    //if param is valid
    if (std::count(validParams.begin(), validParams.end(), param)){
        //save parameter
        params[param] = val;
    }else{
        std::cerr<< "invalid metadata paremter :" + param <<std::endl;
    }
    
//maybe add type assertion


}

std::string frame::encodeMetadata(){
    if (doMeta == false){
        return "";
    }
    //c++17
    // for (const auto& [key, value] : &params){
    //     encodedString += key + "*" + value + "*";
    // }
    for (const auto& kv: params){
        encodedString += kv.first + metaDataItemDelim + kv.second + metaDataPairDelim;
    }
    return encodedString;
}
std::string frame::getParam(std::string param){
    if (doMeta == false){
        return "NULL";
    }
    return params[param];
}

int frame::getParamSize(){
    return params.size();
}