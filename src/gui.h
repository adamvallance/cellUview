#ifndef CELLUVIEW_GUI_H
#define CELLUVIEW_GUI_H
#include <QMainWindow> 

#include "QT/qtWindow.h" //compiled header file from qtcreator
#include "stdlib.h"
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include "imageProcessor.h"
#include "edgeDetection.h"
#include "gallery.h"
#include "grayScale.h"
#include "frame.h"
#include "dilation.h"
#include "erosion.h"
#include "camera.h"
#include "contrastEnhancement.h"
#include "flatFieldCorrect.h"



class Gui : public QWidget, public imageProcessor{ 
    Q_OBJECT

public:
    void receiveFrame(frame newFrame);
    Gui(QMainWindow*, Ui_GUI*, Gallery*, std::vector <imageProcessor *>&);
    void SetVisible(bool visible);

private:
    QMainWindow *widget;
    Ui_GUI *ui;
    bool doCapture =false;
    void captureNextFrame();
    void restoreSettings(std::string = "");
    void updateSettings(std::map<std::string, std::string>);
    std::string getParamLabel(){return "";};
    bool updateFlatField = false;
    bool flatFieldEnable = false;
    void setUpdateFlatField();


    cv::Mat img;
    Gallery* gallery;
    Camera* cam;
    std::vector<imageProcessor*> blocks;

    std::map<std::string, std::string> metadata;



    edgeDetection *edgeDetector;
    grayScale *grayDetector;
};
#endif // CELLUVIEW_GUI_H
