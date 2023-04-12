#ifndef MOTOR_DRIVER_H
#define MOTOR_DRIVER_H

#include <iostream>
#include <stdlib.h>
#include <thread>

#include <wiringSerial.h>
#include <unistd.h>


// class MotorCallback {
// public:
//     virtual void returnPosition(int x, int y, int z) = 0;
// };


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

    void movThread();

    void resetToZero();
    void updatePosition();

    // MotorCallback* motorCb = nullptr;
    bool enabled = false;

    bool connected = false;

    int fd = 0;
    int positionArray[3] = {0, 0, 0}; 
    int bytesToRead;

    char commandAxis;
    int commandInc;

    bool running = false;
    
    std::thread motorThread;

    char firmwareVer[26];
    char dataRead[30];


};


// class MotorPrintCallback : public MotorCallback {
//     virtual void returnPosition(int x, int y, int z){
//         std::cout << "Motor current position:  " << "x: " << x << "  y: " << y << "  z: " << z << std::endl;
//     }
// };


#endif //MOTOR_DRIVER_H
