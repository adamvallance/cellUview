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

class Gui : public QWidget, public imageProcessor{ 
    Q_OBJECT
public:
    void newFrame(frame newFrame);
    Gui(QMainWindow* win, Ui_GUI* ui_win,edgeDetection *edgeDetectorPtr);
    void SetVisible(bool visible);


private:
    QMainWindow *widget;
    Ui_GUI *ui;
    edgeDetection *edgeDetector;
};

#endif // OPENFLEXURE_GUI_H
