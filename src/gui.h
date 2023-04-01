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
#include "frame.h"
#include "dilation.h"
#include "erosion.h"



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


    cv::Mat img;
    Gallery* gallery;
    std::vector<imageProcessor*> blocks;

    std::map<std::string, std::string> metadata;



    edgeDetection *edgeDetector;
};
#endif // OPENFLEXURE_GUI_H
