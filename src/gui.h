#ifndef OPENFLEXURE_GUI_H
#define OPENFLEXURE_GUI_H
#include <QMainWindow> 
#include <QCoreApplication>
#include "QT/qtWindow.h" //compiled header file from qtcreator
#include "stdlib.h"
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include "imageProcessor.h"
#include "gallery.h"


class Gui : public QWidget, public imageProcessor{ 
    Q_OBJECT

public:
    void receiveFrame(frame newFrame);
    Gui(QMainWindow* win, Ui_GUI* ui_win, Gallery* galleryIn);
    void SetVisible(bool visible);

private:
    QMainWindow *widget;
    Ui_GUI *ui;
    bool doCapture =false;
    void captureNextFrame();

    cv::Mat img;
    Gallery* gallery;


};
#endif // OPENFLEXURE_GUI_H
