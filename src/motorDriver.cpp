
#ifndef LINUX_DEV_NO_MOTORS
#include "motorDriver.h"


// void MotorDriver::registerCallback(MotorCallback* cb){
//     motorCb = cb;
// } 

/**
* Opens serial link with motor driver board and starts motor thread.
* @param device device id, defaults to "/dev/ttyUSB0"
* @param baud baud rate of serial connection, defaults to 115200
**/
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
        //std::cout << "Motor driver connection opened: " << firmwareVer << std::endl;
        char firmwareParsed[26];
        int i = 0;
        for (char & c : firmwareVer){       //parses relevant part of message
            if (c != '\n'){
                firmwareParsed[i] = c;
                i=i+1;
            }
            else{
                break;
            }
        }
        std::cout << "Motor driver connection opened: " << firmwareParsed << std::endl;

        resetToZero();      // starting position should be 0, 0, 0
        // motorThread = std::thread(&MotorDriver::resetToZero, this);

        motorThread = std::thread(&MotorDriver::run, this);

        connected = true;
    }   
}

/**
* Stops motor thread and closes serial connection.
**/
void MotorDriver::stop(){
    if (fd>-1){  // only need to end if motor connection opened
        enabled=false;
        connected=false;
        //std::cout<<"Running: "<<running<<std::endl;   //debug
        // if (running){           //if any motor functions are active
        motorThread.join();
        // }
        serialClose(fd);        // close serial comms
        std::cout << "Motor driver connection closed" << std::endl;

    }
}


/**
* Private member function running in dedicated thread after motor connection opened. 
* Runs while motors are enabled. 
* Thread sleeps until a motor movement action is input.
**/
void MotorDriver::run(){

    while (enabled){

        // thread goes to sleep because of blocking system flag when no new movement to make
        // blocks but thread wakes up when flag changed because of new data
        // timeout of 1 second on wait for exit condition
        std::unique_lock<std::mutex> lock(mut);
        cond_var.wait_for(lock, 1s); 
        // std::cout<<"cond var just passed"<<std::endl;    //debug
        if (update){            // if there is a new movement to make
    
            running = true;     //flag to indicate motors are moving

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
            update = false;
        
        }

        lock.unlock();          // manually unlocks mutex
        cond_var.notify_all();

    }

}

/**
* Requests position from motor driver board and updates array.
**/
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


/**
* Sends command to motor driver board to zero current position.
**/
void MotorDriver::resetToZero(){

    running = true;

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

    running = false;

    // motorThread.detach();
    // return;
}

/**
* @returns array of 3 integer values for current x, y, and z motor positions
**/
int* MotorDriver::getPosition(){
    return positionArray;
}


/**
* @returns true if motors currently moving
**/
bool MotorDriver::getRunning(){
    return running;
}


/**
* @returns true if motor connection could be established
**/
bool MotorDriver::getConnected(){
    return connected;
}


/**
* Public member function called by GUI class to initiate a motor movement.
* Updates axis and increment for movement and sets flag to wake motor thread.
**/
void MotorDriver::mov(char axis, int inc){
    commandAxis = axis;
    commandInc = inc;
    //motorThread = std::thread(&MotorDriver::movThread, this);
    std::lock_guard<std::mutex> lock(mut);
    update = true;
    cond_var.notify_all();  // wakes motor thread to move motors
}

    

#endif //#LINUX_DEV_NO_MOTORS