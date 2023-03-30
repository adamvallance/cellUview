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

#define USE_TEMPLATE //uncomment this to add the example manipulation in the chain


int main(int argc, char* argv[]){
    OpenFlexureWelcome::welcomeMessage();
    
    QApplication app(argc, argv);
    QMainWindow window;
    Ui_GUI ui;
    
    //creating camera and gallery and gui instances
    Camera camera;
    Gallery gallery;
    Gui gui(&window, &ui, &gallery);
    
#ifdef USE_TEMPLATE
    //Template example;
    edgeDetection edge;
    erosion erode;
    dilation dilate;
    //register callbacks
    Gui gui(&window, &ui, &edge);
    
    camera.registerCallback(&dilate);
    //erode.registerCallback(&dilate);
    dilate.registerCallback(&gui);
    //example.registerCallback(&gui);
    //edge.registerCallback(&gui);
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

