#include "gui.h"


Gui::Gui(QMainWindow* win, Ui_GUI* ui_win, Gallery* galleryIn, std::vector<imageProcessor *>& blocksIn) {
    widget = win;
    ui = ui_win;
    ui->setupUi(widget);
    //ui->logoImage->setPixmap(QPixmap(QString::fromUtf8("images/logo.png"))); add back in for future logo?
    //const std::vector<imageProcessor*> *blocks = blocksIn;
    this->gallery = galleryIn;
    blocks=blocksIn;

    //------------make connections-------------
    //push button (to be renamed @Jake) connects to gallery capture
    
    ////do a capture
    //QObject::connect(ui->pushButton, &QPushButton::released, this, &Gui::captureNextFrame);
    
    //// How to connect a button to an instance of another class
    //QObject::connect(ui->pushButton, &QPushButton::released, this, [&](){gallery->getMetadata();});

    //toggle edge
    QObject::connect(ui->pushButton, &QPushButton::released, this, [&](){blocks[2]->toggleEnable();});
}



void Gui::receiveFrame(frame newFrame) {

    //if capturing, capture before conversion to rgb
    if (doCapture){
        gallery->captureFrame(newFrame);
        doCapture = false; //reset flag
    }

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
