#include "gallery.h"

//TODO 
//error checking if no pathname 

//FUTURE todo:
//configureable dir name and filename 
//metadata saved? inside jpg or alongside comp7anion file to be viewed in cellUview gallery?

Gallery::Gallery(){

//---- find or create gallery directory----
    pathname = getenv("HOME");
    pathname += + "/cellUviewGallery/"; 
    flatFieldPath = pathname + ".FlatFieldGallery";
    //updates index to find highest existing file with matching name to avoid overwriting
    initialiseDirectory(pathname, "cellUview Gallery");
    initialiseDirectory(flatFieldPath, "Flat field capture gallery");
    updateIndex();
    
}

int Gallery::initialiseDirectory(std::string path, std::string description){
        //if it doesn't exist
    if ((dir = opendir(path.c_str())) == NULL){
        //try to make the directory
        if (mkdir(path.c_str(), S_IRWXU) == -1){
            //if failed:
            std::cerr << "Error :  " << std::strerror(errno) << std::endl;
            std::cout << description << " directory not found/created";
            //ADD. disable button if failed
            pathname = ""; 
            return 1;
        }
        else{//if gallery succesfully made
            std::cout << description << " directory created at " + path << std::endl;
        }
    }else{//if gallery already exists
        std::cout << description << " directory found at " + path << std::endl;
        closedir(dir);
    }

    return 0;

    //updates index to find highest existing file with matching name to avoid overwriting
}


//add some error handling
void Gallery::captureFrame(frame capFrame, bool updateFlatField, int flatFieldCounter){
    if (pathname == ""){
        return;
    }
    //add ability to set custom string before number
    if (updateFlatField == true){


            captureFname = pathname + "/.FlatFieldGallery/flatField" + std::to_string(flatFieldCounter) + ".jpg";
            std::string flatFieldPath = captureFname;

            //save image
            img = capFrame.image;
            cv::imwrite(captureFname, img); 
            
    }
    else{
        //build output name string
        captureFname = pathname + imgName + std::to_string(captureImgCounter) +".jpg";

        //save image
        img = capFrame.image;
        cv::imwrite(captureFname, img); 

        captureImgCounter++;
        

        writeMetadata(capFrame, captureFname);
        
        std::cout<<"Capturing"<<std::endl;
        //debug
        //std::cout << getMetadata() << std::endl;    

    }   
    
} 

void Gallery::writeMetadata(frame f, std::string captureFname){
    MetadataToWrite = f.encodeMetadata();
    et->SetNewValue("XMP:Description", MetadataToWrite.c_str());
    et->WriteInfo(captureFname.c_str());
    int result = et->Complete();
    if (result<=0) std::cerr << "Error writing metadata" << std::endl;

    //remove original image left over from exiftool
    std::string origCap = captureFname + "_original";
    std::remove(origCap.c_str());
}

std::map<std::string, std::string> Gallery::getMetadata(std::string fname){
    //Come back to here to pass in fname 
    //for now just read back image capture from this run

    if (fname == ""){
        fname = captureFname;
    }

    //debug
    // std::cout<<fname<<std::endl;

    receivedMetadata="";
    TagInfo *info = et->ImageInfo(fname.c_str());
    if (info){
        for (TagInfo *i=info; i; i=i->next){
            tagName = i->name;
            if (tagName == "Description"){
                receivedMetadata = i->value;

                //build back into param map matching frame
                std::string pair;
                std::string item;
                std::istringstream iss(receivedMetadata);
                while (std::getline(iss, pair, *metaDataPairDelim)){


                    std::vector<std::string> rec ={};
                    std::istringstream iss2(pair);
                    while (std::getline(iss2, item, *metaDataItemDelim)){
                        rec.push_back(item);
                    }
                    restoredParams[rec[0]] = rec[1];
                    //std::cout<< rec[0] + "::" + restoredParams[rec[0]]<< std::endl;

                    rec.clear();
                    
                }
                break;
            }
        }

        delete info;

    }else if (et->LastComplete()<=0){
        std::cerr << "Metadata read error" << std::endl;
    }else{
        std::cout << "No metadata to read" << std::endl;
    }
    //debug
    //THIS DOESN'T BREAK
    //std::cout<<restoredParams["edgeThreshold"]<<std::endl;
    return restoredParams;
}


void Gallery::updateImgName(std::string newName){
    if (newName.find("/") != std::string::npos) {
        std::cout << "Error. Contains illegal / char" << std::endl;
        //UPDATE TEXTBOX HERE TODO
        //add check to see if names are the same, if they are then break. 
    }else{//update name
        imgName=newName;
        updateIndex();
    }
    // if (newName.empty()){
    //     imgName="Capture";
    //     updateIndex();
    // }
}
 
void Gallery::updateIndex(){
//(re)open already existing/newly created directory 
    //to find if files with current name already exis.=t
    //to avoid overwriting the files
    if ((dir = opendir(pathname.c_str())) != NULL) {
        
        //iterate over all entries in the gallery directory
        while ((ent = readdir(dir)) != NULL) {

            //get name of file
            existingCaptureFname = ent->d_name;

            //if file matches the set filename template
            if (existingCaptureFname.substr(0, imgName.length()) == imgName){
   
                //get number of digits of file index in filename
                indexLen = existingCaptureFname.length() - imgName.length() - 4; //4 for .jpg chars

                //get file index
                index = std::stoi(existingCaptureFname.substr(imgName.length(), indexLen));
                 
                //if index is higher than last highest found
                if (index > lastHighestIndex){
                    captureImgCounter = index + 1;
                    lastHighestIndex = index;
                }
            } 
        }
    closedir(dir);
    
    //debug
    //std::cout << std::to_string(captureImgCounter) + " ALREADY FOUND" << std::endl;
    }  

}


//get rid of back slashes in names

