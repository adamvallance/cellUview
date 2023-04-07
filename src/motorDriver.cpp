#include "motorDriver.h"


// void MotorDriver::registerCallback(MotorCallback* cb){
//     motorCb = cb;
// }

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

        resetToZero();      // starting position should be 0, 0, 0

        connected = true;

        //motorThread = std::thread(&MotorDriver::run, this);
    }   
}

void MotorDriver::stop(){
    if (fd>-1){  // only need to end if motor connection opened
        enabled=false;
        connected=false;
        //std::cout<<"Running: "<<running<<std::endl;   //debug
        if (running){           //if any motor functions are active
            motorThread.join();
        }
        serialClose(fd);        // close serial comms

    }
}


void MotorDriver::updatePosition(){
    
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

    // Callback interface not used in current code structure
    // motorCb -> returnPosition(positionArray[0], positionArray[1], positionArray[2]);

    return;

}


int MotorDriver::getPositionX(){
    return positionArray[0];
}

int MotorDriver::getPositionY(){
    return positionArray[1];
}

int MotorDriver::getPositionZ(){
    return positionArray[2];
}

// int* MotorDriver::getPosition(){
//     return positionArray;
// }


bool MotorDriver::getRunning(){
    return running;
}


bool MotorDriver::getConnected(){
    return connected;
}


void MotorDriver::mov(char axis, int inc){
    commandAxis = axis;
    commandInc = inc;
    motorThread = std::thread(&MotorDriver::movThread, this);
}


void MotorDriver::movThread(){

    running = true;     //flag to indicate thread is active

    std::string commandStr = "mr";
    commandStr = commandStr + commandAxis + ' ' + std::__cxx11::to_string(commandInc);    // construct command string with axis and increment value
    const char* command = commandStr.c_str();
    // std::cout << "Command string: " << command << std::endl;    //debug

    serialPuts(fd, command);  // perform movement

    do {
        bytesToRead = serialDataAvail(fd);
        //std::cout << "Bytes to read: " << bytesToRead << std::endl; //debug
    }
    while ( bytesToRead < 1  &&  enabled);
    read(fd, dataRead, bytesToRead);        // wait for and read done message
    //std::cout << dataRead << std::endl; //debug

    updatePosition();
    
    running = false;
    
    motorThread.detach();
    //return;

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

