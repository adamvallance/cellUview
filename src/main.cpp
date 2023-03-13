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

using namespace cv;
using namespace std;

int main(int argc, char* argv[]){
    OpenFlexureWelcome::welcomeMessage();
    
    QApplication app(argc, argv);
    QMainWindow window;
    Ui_GUI ui;
    
    //creating camera and gui instances
    Camera camera;
    Gui gui(&window, &ui);
    Template example;
    
    //register callback
    camera.registerCallback(&example);
    example.registerCallback(&gui);

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

