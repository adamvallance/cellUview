#include "gui.h"
#include "edgeDetection.h"
#include "greyScale.h"




Gui::Gui(QMainWindow* win, Ui_GUI* ui_win, Gallery* galleryIn, edgeDetection* edgeDetectorPtr) {  /* greyScale* greyDetectorPtr */
    widget = win;
    ui = ui_win;
    edgeDetector = edgeDetectorPtr;
    /* greyDetector= greyDetectorPtr; */
    ui->setupUi(widget);

    

    QObject::connect(ui->horizontalSlider_2, &QSlider::valueChanged, ui->lineEdit, [&](int value) {
        ui->lineEdit->setText(QString::number(value));
        edgeDetector->updateThreshold(value);
    });

    QObject::connect(ui->lineEdit, &QLineEdit::textChanged, ui->horizontalSlider_2, [&](const QString &text) {
        bool ok;
        int value = text.toInt(&ok);
        if (ok) {
            ui->horizontalSlider_2->setValue(value);
        }
    });
        
    this->gallery = galleryIn;

    //------------make connections-------------
    //push button (to be renamed @Jake) connects to gallery capture
    QObject::connect(ui->pushButton, &QPushButton::released, this, &Gui::captureNextFrame);
    //ui->logoImage->setPixmap(QPixmap(QString::fromUtf8("images/logo.png")));edgeDetection add back in for future logo?
    //QObject::connect(ui->horizontalSlider_2, &QSlider::valueChanged, this, edgeDetector->updateThreshold);
}

void Gui::newFrame(frame newFrame) {

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
