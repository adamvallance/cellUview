/*camera.h
    created: 15/02/23
    last updated: 15/02/23
    author: adamvallance
    description: contains class definition for camera class
     which creates a stream from the pi camera 
    optionally creates a websocket connection for the app
*/


#include "camera.h"
#include <stdlib.h>
#include <iostream>


namespace std {

//camera class constructor
//input: none; output: none
camera::camera(){
    //define variables, objects
    raspicam::RaspiCam camera_;

}


void camera::start_stream(){
    //Open camera
    if (!camera_.open()){
        cerr << "Error opening camera" << endl;
        return; 
    }
    camera_.startCapture()
    
}

void camera::stop_stream(){
    camera_.stopCapture();

}

void camera::callbackTBD(){
    //dostuff
}


camera::~camera() {
	// TODO destructor stub
}

} /* namespace std */