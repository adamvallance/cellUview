#ifndef MOTOR_DRIVER_H
#define MOTOR_DRIVER_H

#ifndef LINUX_DEV_NO_MOTORS

#include <iostream>
#include <stdlib.h>
#include <thread>

#include <wiringSerial.h>
#include <unistd.h>

#include <condition_variable>
#include <mutex>
#include <chrono>
using namespace std::chrono_literals;


// class MotorCallback {
// public:
//     virtual void returnPosition(int x, int y, int z) = 0;
// };


/**
* Class to interface with motor control board.
**/
class MotorDriver {

public:
    MotorDriver() = default;     // constructor

    // void registerCallback(MotorCallback* cb);

    //void start(std::string device = "/dev/ttyUSB0", int baud = 115200);
    void start(const char* device = "/dev/ttyUSB0", int baud = 115200);
    void stop();

    int* getPosition();
    bool getRunning();
    bool getConnected();

    void mov(char axis, int inc);


private:

    //void movThread();

    void run();

    void resetToZero();
    void updatePosition();

    // MotorCallback* motorCb = nullptr;
    bool enabled = false;       // motor thread enable
    bool connected = false;     // motor board connection established

    int fd = 0;
    int positionArray[3] = {0, 0, 0}; 
    int bytesToRead;

    char commandAxis;
    int commandInc;

    bool running = false;       // indicates motors currently moving
    bool update = false;        // indicates new move to make
    
    std::thread motorThread;

    std::mutex mut;
    std::condition_variable cond_var;

    char firmwareVer[26];
    char dataRead[30];


};


// class MotorPrintCallback : public MotorCallback {
//     virtual void returnPosition(int x, int y, int z){
//         std::cout << "Motor current position:  " << "x: " << x << "  y: " << y << "  z: " << z << std::endl;
//     }
// };

#endif //LINUX_DEV_NO_MOTORS
#endif //MOTOR_DRIVER_H

