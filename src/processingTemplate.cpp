#include "processingTemplate.h"

using namespace cv;

//recieves in new frames through a callback. A frame here is our own structure, currently holds a matrix (the picture) and a note (a string).
void Template::newFrame(frame newFrame) {
    // do stuff here

    //if you need/want to, pass the frame into an additional function like this:
    exampleManipulation(newFrame); 
}
void Template::exampleManipulation(frame inputFrame){
    Mat imgIn, imgOut;
    imgIn = inputFrame.image;
    imgOut = imgIn.clone();

    //example manipulation to mess with the top half of the frame but not the bottom
    //token gain and bias parameters, controls contrast and brightness respectively
    double alpha = 1.5;
    int beta = 4;
    for (int y = 0; y < imgIn.rows/2; y++){
        for (int x = 0; x < imgIn.cols; x++){
            for (int c = 0; c< imgIn.channels(); c++){
                imgOut.at<Vec3b>(y,x)[c] = saturate_cast<uchar>(alpha*imgIn.at<Vec3b>(y,x)[c] + beta);
            }
        }
    } 
    //see https://docs.opencv.org/3.4/d3/dc1/tutorial_basic_linear_transform.html 
    
    //start building output frame. You could just manipulate the input frame. 
    frame outputFrame;
    outputFrame.image = imgOut;
    outputFrame.note = "Example manipulation. Top half has contrast and brightness messed with.";

    //output the frame through the callback onto the next instance in the dataflow
    frameCb -> newFrame(outputFrame);

}