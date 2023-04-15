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
#include <QDir>
#include <QDialog>
#include <QVBoxLayout>

/**
* A class which handles GUI connections and functionality.
**/
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
    int flatFieldCounter = 0; 
    void updateGalleryIndex(bool);
    
    void displayImages();
    void intialGallerySetting();
    void onCaptureButtonPress();
    void textEditController(std::string enteredTextStr, bool pressed);
    void showDialog(int position);
    //std::string textEditController(std::string enteredTextStr){return myString;};    
    
    int galleryPos1Index = 0;
    int galleryPos2Index = 1;
    int galleryPos3Index = 2;
    int galleryPos4Index = 3;
    std::string myString; 
    QStringList images;
    int batchIndex = 1; 
    QDir imageDir;
    QStringList imageFilters;

    cv::Mat img;
    Gallery* gallery;
    Camera* cam;
    std::vector<imageProcessor*> blocks;

    std::map<std::string, std::string> metadata;



    edgeDetection *edgeDetector;
    grayScale *grayDetector;
};
#endif // CELLUVIEW_GUI_H
