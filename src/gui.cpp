#include "gui.h"

Gui::Gui(QMainWindow* win, Ui_GUI* ui_win) {
    widget = win;
    ui = ui_win;
    ui->setupUi(widget);
    ui->logoImage->setPixmap(QPixmap(QString::fromUtf8("images/logo.png")));

}
void Gui::newFrame(frame newFrame) {
    //maybe add some sort of protection here
    cv::Mat img;
    img = newFrame.image; 
    QImage imgOut = QImage((uchar *) img.data, img.cols, img.rows, img.step,
                            QImage::Format_RGB888);
    ui->scopeVideoFeed->setPixmap(QPixmap::fromImage(imgOut));
    ui->scopeVideoFeed->resize(ui->scopeVideoFeed->pixmap()->size());
    
}

void Gui::SetVisible(bool visible) {
    widget->setVisible(visible);
}
