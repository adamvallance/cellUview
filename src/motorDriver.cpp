#include "motorDriver.h"


void MotorDriver::registerCallback(MotorCallback* cb){
    motorCb = cb;
}

//void MotorDriver::start(std::string device, int baud){
void MotorDriver::start(const char* device, int baud){
    if (enabled){
        std::cout<<"Motor already started"<<std::endl;
        return;
    }
    enabled = true;
    fd = serialOpen(device, baud);
    if (fd<0) {
        std::cerr << "Error: could not connect to motor driver" << std::endl;
        //throw 1;
    } 
    else {//connection succesful
        serialFlush(fd);

        do {                                        // wait for intro message
            bytesToRead = serialDataAvail(fd);
            //std::cout << "Bytes to read: " << bytesToRead << std::endl; //debug
        }
        while ( bytesToRead < 1  &&  enabled);
        read(fd, firmwareVer, bytesToRead);         // reads intro message with firmware version
        std::cout << "Motor driver connection opened: " << firmwareVer << std::endl;

        //motorThread = std::thread(&MotorDriver::run, this);
    }   // is this bad practice??
}

void MotorDriver::stop(){
    if (fd>-1){  // only need to end if motor connection opened
        enabled=false;
        motorThread.join();
        serialClose(fd);

    }
}

void MotorDriver::run(){

    while (enabled){
    
        serialFlush(fd);

        mov('x', 512);

        getPosition();
        //std::cout << positionArray[0] << " " << positionArray[1] << " " << positionArray[2] << std::endl; //debug
        motorCb -> returnPosition(positionArray[0], positionArray[1], positionArray[2]);

        mov('y', 1024);

        getPosition();
        //std::cout << positionArray[0] << " " << positionArray[1] << " " << positionArray[2] << std::endl; //debug
        motorCb -> returnPosition(positionArray[0], positionArray[1], positionArray[2]);

        mov('z', -512);

        getPosition();
        //std::cout << positionArray[0] << " " << positionArray[1] << " " << positionArray[2] << std::endl; //debug
        motorCb -> returnPosition(positionArray[0], positionArray[1], positionArray[2]);

        resetToZero();

        getPosition();
        //std::cout << dataRead << std::endl; //debug
        //std::cout << positionArray[0] << " " << positionArray[1] << " " << positionArray[2] << std::endl; //debug

        //currentPosition = dataRead;
        motorCb -> returnPosition(positionArray[0], positionArray[1], positionArray[2]);

    }


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
    //std::cout << "dataString: " << dataString << std::endl;    //debug
    int i = 0;
    for (char & x : dataString){
        if (x == ' ' || x == '\n'){
            try {
                //std::cout << "Str to convert to int: " << temp << std::endl;    //debug
                positionArray[i] = stoi(temp);  // updates positionArray with int value
            }
            catch(...){
               if (temp == "done"){
                    return;
               }
               positionArray[i] = -1;
            }
            temp = "";
            i = i+1;
            if (i>2){
                break;
            }
        }
        else {
            temp = temp + x;
        }
    }
    i = 0;

    return;

}

void MotorDriver::mov(char axis, int inc){

    std::string commandStr = "mr";
    commandStr = commandStr + axis + ' ' + std::__cxx11::to_string(inc);    // construct command string with axis and increment value
    const char* command = commandStr.c_str();
    std::cout << "Command string: " << command << std::endl;    //debug

    serialPuts(fd, command);  // perform movement

    do {
        bytesToRead = serialDataAvail(fd);
        //std::cout << "Bytes to read: " << bytesToRead << std::endl; //debug
    }
    while ( bytesToRead < 1  &&  enabled);
    read(fd, dataRead, bytesToRead);        // wait for and read done message
    //std::cout << dataRead << std::endl; //debug

    return;

}

void MotorDriver::resetToZero(){
    serialPuts(fd, "zero");
    do {
        bytesToRead = serialDataAvail(fd);
        //std::cout << "Bytes to read: " << bytesToRead << std::endl; //debug
    }
    while ( bytesToRead < 1  &&  enabled);
    //read(fd, dataRead, bytesToRead);        // wait for and read done message
    //std::cout << dataRead << std::endl;
    serialFlush(fd);        // wait for and discard returned message
    //std::cout << serialDataAvail(fd) << std::endl;
    return;
}

