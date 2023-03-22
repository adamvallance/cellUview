#include "gui.h"

//TODO cleanup
//get highest number already there so no overwrite
//error checking if no pathname 

//FUTURE todo:
//configureable dir name and filename 
//metadata saved? inside jpg or alongside companion file to be viewed in OpenFlexure gallery?

Gui::Gui(QMainWindow* win, Ui_GUI* ui_win) {
    widget = win;
    ui = ui_win;
    ui->setupUi(widget);
    //ui->logoImage->setPixmap(QPixmap(QString::fromUtf8("images/logo.png"))); add back in for future logo?

    //------------make connections-------------
    //push button (to be renamed @Jake) connects to gallery capture
    QObject::connect(ui->pushButton, &QPushButton::released, this, &Gui::captureNextFrame);

    initialiseGallery();
}



void Gui::newFrame(frame newFrame) {

    //if capturing, capture before conversion to rgb
    if (doCapture){
        //prob add some error handling
        captureFrame(newFrame);
    }

    //maybe add some sort of protectiSon here
    img = newFrame.image; 
    
    //maybe try replacing img with newFrame.img to avoid unnecessary copying.
    //convert from default opencv bgr to QT rgb
    cv::cvtColor(img, img, cv::COLOR_BGR2RGB);

    QImage imgOut = QImage((uchar *) img.data, img.cols, img.rows, img.step,
                            QImage::Format_RGB888);
    ui->scopeVideoFeed->setPixmap(QPixmap::fromImage(imgOut));
    ui->scopeVideoFeed->resize(ui->scopeVideoFeed->pixmap()->size());   
}
    


void Gui::SetVisible(bool visible) {
    widget->setVisible(visible);
}

//set to capture on next frame
void Gui::captureNextFrame(){
    doCapture = true;
}

//add some error handling
void Gui::captureFrame(frame capFrame){
        if (pathname == ""){
            doCapture=false;
            return;
        }
        //add ability to set custom string before number

        //build output name string
        captureFname = pathname + imgName + std::to_string(captureImgCounter) +".jpg";

        //save image
        img = capFrame.image;
        cv::imwrite(captureFname, img); 

        //reset doCapture flag so that next frame is not captured
        doCapture = false;
        captureImgCounter++;
} 

void Gui::initialiseGallery(){
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