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
using namespace cv;
using namespace std;
#define USE_TEMPLATE //uncomment this to add the example manipulation in the chain


int main(int argc, char* argv[]){
    OpenFlexureWelcome::welcomeMessage();
    
    QApplication app(argc, argv);
    QMainWindow window;
    Ui_GUI ui;
    
    //creating camera and gui instances
    Camera camera;

    
#ifdef USE_TEMPLATE
    //Template example;
    edgeDetection edge;
    //register callbacks
    Gui gui(&window, &ui, &edge);
    
    camera.registerCallback(&edge);
    //edge.registerCallback(&example);
    edge.registerCallback(&gui);
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

