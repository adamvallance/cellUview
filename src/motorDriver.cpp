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
    if (fd<0) {
        std::cerr << "Error: could not connect to motor driver" << std::endl;
        //throw 1;
    } 
    else {
        serialFlush(fd);
        motorThread = std::thread(&MotorDriver::run, this);
    }   // is this bad practice??
}

void MotorDriver::stop(){
    serialClose(fd);
    enabled=false;
    motorThread.join();
}

void MotorDriver::run(){

    //while(enabled){
        // serialPuts(fd, "mr 5000 5000 -250");    //dummy rotation for now
        // //std::cout << commandAck << std::endl; //debug only
        // serialPuts(fd, "p?");
        // currentPosition = serialGetchar(fd);
        // motorCb -> returnPosition(currentPosition);

        do {                                        // read the intro message and discard
            bytesToRead = serialDataAvail(fd);
            //std::cout << "Bytes to read: " << bytesToRead << std::endl; //debug
        }
        while ( bytesToRead < 1  &&  enabled);

        read(fd, firmwareVer, bytesToRead);         // reads intro message with firmware version
        std::cout << "Initial message : " << firmwareVer << std::endl; //debug

        while (enabled){
        
            serialFlush(fd);

            serialPuts(fd, "mrx 100");  // half rotation for x
            do {
                bytesToRead = serialDataAvail(fd);
                //std::cout << "Bytes to read: " << bytesToRead << std::endl; //debug
            }
            while ( bytesToRead < 1  &&  enabled);
            read(fd, dataRead, bytesToRead);        // wait for and read done message
            //std::cout << dataRead << std::endl; //debug

            getPosition();

            //std::cout << dataRead << std::endl; //debug
            std::cout << positionArray[0] << " " << positionArray[1] << " " << positionArray[2] << std::endl; //debug

            currentPosition = dataRead;
            motorCb -> returnPosition(currentPosition);

        }

    //}

}

void MotorDriver::getPosition(){

    serialPuts(fd, "p?");   //request new position

    do {
        bytesToRead = serialDataAvail(fd);
        //std::cout << "Bytes to read: " << bytesToRead << std::endl; //debug
    }
    while ( bytesToRead < 1  &&  enabled);  // wait for position to be returned

    read(fd, dataRead, bytesToRead);        // read position

    //parse position char array
    std::string temp = "";
    std::string dataString = dataRead;
    int i = 0;
    for (char & x : dataString){
        if (x == ' ' || x == '\n'){
            positionArray[i] = stoi(temp);  // updates positionArray with int value
            temp = "";
            i = i+1;
        }
        else {
            temp = temp + x;
        }
    }
    i = 0;

}

