#ifndef MOTOR_DRIVER_H
#define MOTOR_DRIVER_H

#include <iostream>
#include <stdlib.h>
#include <thread>

#include <wiringSerial.h>


class MotorCallback {
public:
    virtual void returnPosition(std::string message) = 0;
};


class MotorDriver {

public:
    MotorDriver() = default;     // constructor

    void registerCallback(MotorCallback* cb);

    //void start(std::string device = "/dev/ttyUSB0", int baud = 115200);
    void start(const char* device = "/dev/ttyUSB0", int baud = 115200);
    void stop();


private:

    void run();

    MotorCallback* motorCb = nullptr;
    bool enabled = false;

    int fd = 0;
    std::string currentPosition = "0 0 0";

    std::thread motorThread;



};






#endif //MOTOR_DRIVER_H
