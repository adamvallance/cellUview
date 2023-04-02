#ifndef OPENFLEXURE_GUI_H
#define OPENFLEXURE_GUI_H
#include <QMainWindow> 

#include "QT/qtWindow.h" //compiled header file from qtcreator
#include "stdlib.h"
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include "imageProcessor.h"
#include "edgeDetection.h"
#include "gallery.h"
#include "greyScale.h"


class Gui : public QWidget, public imageProcessor{ 
    Q_OBJECT

public:
    void newFrame(frame newFrame);
    Gui(QMainWindow* win, Ui_GUI* ui_win, Gallery* galleryIn, edgeDetection *edgeDetectorPtr, greyScale* greyDetectorPtr); //greyScale *greyDetectorPtr
    void SetVisible(bool visible);

private:
    QMainWindow *widget;
    Ui_GUI *ui;
    bool doCapture =false;
    void captureNextFrame();

    cv::Mat img;
    Gallery* gallery;


    edgeDetection *edgeDetector;
    greyScale* greyDetector;
};
#endif // OPENFLEXURE_GUI_H
