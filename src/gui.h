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
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

class Gui : public QWidget, public imageProcessor{ 
    Q_OBJECT
public:
    void newFrame(frame newFrame);
    Gui(QMainWindow* win, Ui_GUI* ui_win);
    void SetVisible(bool visible);


private:
    QMainWindow *widget;
    Ui_GUI *ui;
    bool doCapture;
    void captureNextFrame();
    void captureFrame(frame);
    void initialiseGallery();
    cv::Mat img;


    //Gallery attributes
    DIR *dir;
    struct dirent *ent;
    std::string pathname = "";
    std::string imgName = "capture";
    int captureImgCounter = 0;
    std::string captureFname;
    int index;
    int lastHighestIndex;
    std::string existingCaptureFname; 
};
#endif // OPENFLEXURE_GUI_H
