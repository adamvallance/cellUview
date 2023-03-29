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

int main(int argc, char* argv[]){
    OpenFlexureWelcome::welcomeMessage();
    
    QApplication app(argc, argv);
    QMainWindow window;
    Ui_GUI ui;
    
    //creating camera and gallery and gui instances
    Camera camera;
    Gallery gallery;
    Gui gui(&window, &ui, &gallery);
    
    // edgeDetection edge;
    // edge.toggleEnable(); //changes default enable to disabled
    // erosion erode;
    // dilation dilate;

    //Keep image enhancement classes in the callback chain
    //but call instance.toggleEnable to bypass

    //register callbacks
    camera.registerCallback(&gui);
    // erode.registerCallback(&dilate);
    // dilate.registerCallback(&edge);
    // edge.registerCallback(&gui);


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

