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
Camera::Camera(){
    //define variables, objects
    raspicam::RaspiCam camera_;

}


void Camera::start_stream(){
    //Open camera
    if (!camera_.open()){
        cerr << "Error opening camera" << endl;
        return; 
    }
    camera_.startCapture()
    
}

void Camera::stop_stream(){
    camera_.stopCapture();

}

void Camera::display_frame_callback(){

    Camera* camera = static_cast<Camera*>(user_data);
    Mat frame(Size(640, 480), CV_8UC3, data);
    imshow("Camera Stream", frame);
}



camera::~camera() {
	// TODO destructor stub
}

} /* namespace std */