#include "gui.h"

//TODO 
//error checking if no pathname 

//FUTURE todo:
//configureable dir name and filename 
//metadata saved? inside jpg or alongside companion file to be viewed in OpenFlexure gallery?

Gui::Gui(QMainWindow* win, Ui_GUI* ui_win, Gallery* galleryIn) {
    widget = win;
    ui = ui_win;
    ui->setupUi(widget);
    //ui->logoImage->setPixmap(QPixmap(QString::fromUtf8("images/logo.png"))); add back in for future logo?
    
    this->gallery = galleryIn;

    //------------make connections-------------
    //push button (to be renamed @Jake) connects to gallery capture
    QObject::connect(ui->pushButton, &QPushButton::released, this, &Gui::captureNextFrame);
}



void Gui::newFrame(frame newFrame) {

    //if capturing, capture before conversion to rgb
    if (doCapture){
        gallery->captureFrame(newFrame);
        doCapture = false; //reset flag
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
