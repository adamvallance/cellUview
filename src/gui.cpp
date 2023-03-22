#include "gui.h"



Gui::Gui(QMainWindow* win, Ui_GUI* ui_win) {
    widget = win;
    ui = ui_win;
    ui->setupUi(widget);
    //ui->logoImage->setPixmap(QPixmap(QString::fromUtf8("images/logo.png"))); add back in for future logo?

    //make connections 
    //push button (to be renamed @Jake) connects to gallery capture
    QObject::connect(ui->pushButton, &QPushButton::released, this, &Gui::captureNextFrame);


    pathname = getenv("HOME");
    pathname += + "/OpenFlexureGallery/"; 
    if (mkdir(pathname.c_str(), S_IRWXU) == -1){
    //if (mkdir("testMKDIR", S_IRWXU) == -1){
        std::cerr << "Error :  " << std::strerror(errno) << std::endl;
        std::cout << "Gallery directory not found/created";
        //disable button if failed
    }
    else{
        std::cout << "Gallery directory found at " + pathname;
    }
    //std::string home_dir = getenv("HOME");
    //std::cout << home_dir <<std::endl;
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
        captureFname = pathname + "testCapture_";
        captureFname += std::to_string(captureImgCounter);
        captureFname += ".jpg";


        //save image
        img = capFrame.image;
        cv::imwrite(captureFname, img); //watch out for bgr vs rgb CHECK THIS
        doCapture = false;
        captureImgCounter++;
}