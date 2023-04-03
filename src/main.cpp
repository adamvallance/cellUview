#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/imgproc.hpp>

#include <iostream>
#include <stdio.h>
#include <queue>

#include "camera.h"
#include "stdlib.h"
#include "gui.h"
#include "OpenFlexureWelcome.h"
#include "processingTemplate.h"
#include "edgeDetection.h"
#include "gallery.h"
#include "erosion.h"
#include "dilation.h"
#include "greyScale.h"

#define USE_TEMPLATE //uncomment this to add the example manipulation in the chain


int main(int argc, char* argv[]){
    OpenFlexureWelcome::welcomeMessage();
    
    QApplication app(argc, argv);
    QMainWindow window;
    Ui_GUI ui;
    
    //creating camera and gallery and gui instances
    Camera camera;
    Gallery gallery;

#ifdef USE_TEMPLATE
    //Template example;
    edgeDetection edge;
    erosion erode;
    dilation dilate;
    greyScale grey;    // erode.registerCallback(&dilate);
    // dilate.registerCallback(&edge);
    // edge.registerCallback(&gui);
    //register callbacks
    Gui gui(&window, &ui, &gallery, &edge, &grey) ; 
    
    camera.registerCallback(&grey);
    // erode.registerCallback(&dilate);
    // dilate.registerCallback(&edge);
    // edge.registerCallback(&gui);
    grey.registerCallback(&gui);
#else 
    camera.registerCallback(&gui);
#endif

    //start camera
    camera.start();
    
    //start gui
    gui.SetVisible(true);
    app.exec(); //loops main thread
    
    //stop camera
    camera.stop();
    
    //exit
    return 0;
}

