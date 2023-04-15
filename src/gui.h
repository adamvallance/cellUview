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
#include "motorDriver.h"


/**
* A class which handles GUI connections and functionality.
**/
class Gui : public QWidget, public imageProcessor{ 
    Q_OBJECT

public:
    void receiveFrame(frame newFrame);
    Gui(QMainWindow*, Ui_GUI*, Gallery*, MotorDriver*, std::vector <imageProcessor *>&);
    void SetVisible(bool visible);
    void returnPosition(int x, int y, int z);

private:
    QMainWindow *widget;
    Ui_GUI *ui;
    bool doCapture =false;
    void captureNextFrame();
    void restoreSettings(std::string = "");
    void updateSettings(std::map<std::string, std::string>);
    
    void motorMove(char ax, int increment);
    

    std::string getParamLabel(){return "";};
    bool updateFlatField = false;
    bool flatFieldEnable = false;
    void setUpdateFlatField();
    int flatFieldCounter = 0; 


    cv::Mat img;
    Gallery* gallery;
    Camera* cam;
    std::vector<imageProcessor*> blocks;

    std::map<std::string, std::string> metadata;


    MotorDriver *motors;
    //std::thread motorThread;
};
#endif // CELLUVIEW_GUI_H
