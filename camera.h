/*camera.h
    created: 15/02/23
    last updated: 15/02/23
    author: adamvallance
    description: contains class declaration for camera class
     which creates a stream from the pi camera 
    optionally creates a websocket connection for the app
*/

#ifndef CAMERA_H_
#define CAMERA_H_
#include <raspicam/raspicam.h> //potentially update this to use libcamera 2 and later version of raspbian
#include <opencv2/opencv.hpp> //for displaying stream?



namespace std {

class Camera {
public:
	Camera();
	virtual ~Camera();

    void start_stream();
    void stop_stream();

private:
	raspicam::RaspiCam camera_;
    void display_frame_callback(); //needs worked out

};

} /* namespace std */



#endif
/* CAMERA_H_ */