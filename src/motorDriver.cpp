#include "motorDriver.h"


void MotorDriver::registerCallback(MotorCallback* cb){
    motorCb = cb;
}

//void MotorDriver::start(std::string device, int baud){
void MotorDriver::start(const char* device, int baud){
    if (enabled){
        return;
    }
    enabled = true;
    fd = serialOpen(device, baud);
    //if (fd<0) {
    //    std::cerr << "Error: could not connect to motor driver" << std::endl;
    //   throw 1;
    //} 
    motorThread = std::thread(&MotorDriver::run, this);
}

void MotorDriver::stop(){
    serialClose(fd);
    enabled=false;
    motorThread.join();
}

void MotorDriver::run(){

    while(enabled){
        serialPuts(fd, "mr 5000 5000 5000");
        serialGetchar(fd);
        currentPosition = "done";
        motorCb -> returnPosition(currentPosition);
    }

}