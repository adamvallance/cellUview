#include "frame.h"


/**
* Sets metadata parameter value. 
* First checks that parameter is a valid image setting. If so, sets corresponding parameter to given value in frame structure metadata.
* If metadata is disabled, will do nothing and return.
* @param param metadata parameter to set
* @param val value to set
**/
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

/**
* If metadata capture is enabled, encodes metadata into frame structure.
* @returns standard string containing image processing settings encoded such that it can be later be parsed to recover image settings.
**/
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

/**
* Getter for metadata parameter value.
* @param param metadata parameter for which to return value
* @returns std string containing requests metadata value
**/
std::string frame::getParam(std::string param){
    if (doMeta == false){
        return "NULL";
    }
    return params[param];
}

/**
* @returns size of metadata parameters map
**/
int frame::getParamSize(){
    return params.size();
}