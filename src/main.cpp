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
#include "edgeDetection.h"
#include "gallery.h"
#include "erosion.h"
#include "dilation.h"
#include "greyScale.h"
#include "motorDriver.h"






int main(int argc, char* argv[]){
    OpenFlexureWelcome::welcomeMessage();
    
    QApplication app(argc, argv);
    QMainWindow window;
    Ui_GUI ui;
    
 

    //creating camera and gallery and gui instances
    Camera camera;
    Gallery gallery;
    
    edgeDetection edge;
    //edge.toggleEnable(); //changes default enable to disabled
    erosion erode;
    dilation dilate;
    greyScale grey;
    std::vector <imageProcessor *> blocks={&erode, &dilate, &grey, &edge};

    MotorDriver motor;
    MotorPrintCallback motorReturn;

    Gui gui(&window, &ui, &gallery, &camera, &motor, blocks);
    //Gui gui(&window, &ui, &gallery, &camera, blocks);

    motor.registerCallback(&motorReturn);


    //Keep image enhancement classes in the callback chain
    //but call instance.toggleEnable to bypass
    //eg to default turn 

    //register callbacks. To change order, change the order in the blocks vector above
    camera.registerCallback(blocks[0]);
    for (int i = 0; i < blocks.size()-1; i++){
            blocks[i]->registerCallback(blocks[i+1]);
    }

    blocks.back()->registerCallback(&gui);


    //start camera
    camera.start();

    //open motor communication
    motor.start();
    
    //start gui
    gui.SetVisible(true);

    try{
        app.exec(); //loops main thread
    }catch(...){
        motor.stop();
        app.exit();
    }
    

    //stop camera and motor
    motor.stop();
    camera.stop();
    
    //exit
    return 0;
}

