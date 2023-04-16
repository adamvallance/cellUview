#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/imgproc.hpp>

#include <iostream>
#include <stdio.h>
#include <queue>

#include "camera.h"
#include "stdlib.h"
#include "gui.h"
#include "cellUviewWelcome.h"
#include "edgeDetection.h"
#include "gallery.h"
#include "flatFieldCorrect.h"
#include "erosion.h"
#include "dilation.h"
#include "grayScale.h"
#include "contrastEnhancement.h"

int main(int argc, char* argv[]){
    cellUviewWelcome::welcomeMessage();
    
    QApplication app(argc, argv);
    QMainWindow window;
    Ui_GUI ui;
    
 

    //creating camera and gallery and gui instances
    Camera camera;
    Gallery gallery;
    
    edgeDetection edge;
    contrastEnhancement cont;
    flatFieldCorrect flat;
    //edge.toggleEnable(); //changes default enable to disabled
    erosion erode;
    dilation dilate;
    grayScale gray;
    std::vector <imageProcessor *> blocks={&camera, &flat, &erode, &dilate, &gray, &cont, &edge};

    Gui gui(&window, &ui, &gallery, blocks);

    //Keep image enhancement classes in the callback chain
    //but call instance.toggleEnable to bypass
    //eg to default turn 

    //register callbacks. To change order, change the order in the blocks vector above
    camera.registerCallback(blocks[1]);
    for (int i = 1; i < blocks.size()-1; i++){
            blocks[i]->registerCallback(blocks[i+1]);
    }

    blocks.back()->registerCallback(&gui);

    erode.start();
    dilate.start();
    gray.start();
    cont.start();
    edge.start();

    //start camera
    camera.start();
    
    //start gui
    gui.SetVisible(true);

    try{
        app.exec(); //loops main thread
    }catch(...){
        app.exit();
    }
    
    //stop camera
    camera.stop();

    erode.stop();
    dilate.stop();
    gray.stop();
    cont.stop();
    edge.stop();

    
    //exit
    return 0;
}

