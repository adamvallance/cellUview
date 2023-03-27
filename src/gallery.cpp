#include "gallery.h"

//TODO 
//error checking if no pathname 

//FUTURE todo:
//configureable dir name and filename 
//metadata saved? inside jpg or alongside comp7anion file to be viewed in OpenFlexure gallery?

Gallery::Gallery(){

//---- find or create gallery directory----
    pathname = getenv("HOME");
    pathname += + "/OpenFlexureGallery/"; 
    
    //if it doesn't exist
    if ((dir = opendir(pathname.c_str())) == NULL){
        //try to make the directory
        if (mkdir(pathname.c_str(), S_IRWXU) == -1){
            //if failed:
            std::cerr << "Error :  " << std::strerror(errno) << std::endl;
            std::cout << "Gallery directory not found/created";
            //ADD. disable button if failed
            pathname = ""; 
            return;
        }
        else{//if gallery succesfully made
            std::cout << "Gallery directory created at " + pathname << std::endl;
        }
    }else{//if gallery already exists
        std::cout << "Gallery directory found at " + pathname << std::endl;
        closedir(dir);
    }

    //updates index to find highest existing file with matching name to avoid overwriting
    updateIndex();
    
}

//add some error handling
void Gallery::captureFrame(imageProcessor::frame capFrame){
        if (pathname == ""){
            return;
        }
        //add ability to set custom string before number

        //build output name string
        captureFname = pathname + imgName + std::to_string(captureImgCounter) +".jpg";

        //save image
        img = capFrame.image;
        cv::imwrite(captureFname, img); 

        captureImgCounter++;

        writeMetadata(capFrame, captureFname);

} 

void Gallery::writeMetadata(imageProcessor::frame savedFrame, std::string captureFname){
    et->SetNewValue("COM", "test1234");
    et->WriteInfo(captureFname.c_str());
    int result = et->Complete();
    if (result<=0) std::cerr << "Error writing metadata" << std::endl;
}


void Gallery::updateImgName(std::string newName){
    if (newName.find("/") != std::string::npos) {
        std::cout << "Error. Contains illegal / char" << std::endl;
        //UPDATE TEXTBOX HERE TODO
    }else{//update name
        imgName=newName;
        updateIndex();
    }
}

void Gallery::updateIndex(){
//(re)open already existing/newly created directory 
    //to find if files with current name already exist
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