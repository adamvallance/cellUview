#include "gui.h"
#include "edgeDetection.h"
#include "contrastEnhancement.h"
#include "grayScale.h"

/**
* Constructor to initialise the GUI and set connections
* @param win points to QMainWindow 
* @param ui_win points to Ui_GUI 
* @param galleryIn points to Gallery instance
* @param motorsIn points to MotorDriver instance
* @param blocksIn is a std::vector of the image processing blocks
**/
Gui::Gui(QMainWindow *win, Ui_GUI *ui_win, Gallery *galleryIn, MotorDriver *motorsIn, std::vector<imageProcessor *> &blocksIn)
{
    widget = win;
    ui = ui_win;
    ui->setupUi(widget);

    this->gallery = galleryIn;
    this->motors = motorsIn;
    blocks = blocksIn;
    this->cam = static_cast<Camera*>(blocks[0]);
    enabled = true;

    // initialise motor positions at zero
    ui->xPos->setText(QString::number(0));
    ui->yPos->setText(QString::number(0));
    ui->zPos->setText(QString::number(0));


    // ui->logoImage->setPixmap(QPixmap(QString::fromUtf8("images/logo.png"))); add back in for future logo?

         //-----------block 1 flat field---------------------
    QObject::connect(ui->flatFieldBox, &QCheckBox::stateChanged, this, [&](bool checkboxValue){
        bool enabled = blocks[1]->getEnabled();
        if (enabled != checkboxValue){
            blocks[1]->toggleEnable();
        }
         
    });

    //-----------block 2 erosion---------------------
    QObject::connect(ui->erosionCheckBox, &QCheckBox::stateChanged, this, [&](bool checkboxValue){
        bool enabled = blocks[2]->getEnabled();
        if (enabled != checkboxValue){
            blocks[2]->toggleEnable();
        }
         
    });

    // //-----------block 3 dilation ---------------------
    QObject::connect(ui->dilationCheckBox, &QCheckBox::stateChanged, this, [&](bool checkboxValue){
        bool enabled = blocks[3]->getEnabled();
        if (enabled != checkboxValue){
            blocks[3]->toggleEnable();
        }
         
    });
    // //-----------block 4 gray ---------------------
    QObject::connect(ui->grayScaleBox, &QCheckBox::stateChanged, this, [&](bool checkboxValue){
        bool enabled = blocks[4]->getEnabled();
        if (enabled != checkboxValue){
            blocks[4]->toggleEnable();
        }
         
    });


    //-------------block -1 edge enhancement-----------------------
    QObject::connect(ui->edgeEnhancementSlider, &QSlider::valueChanged, ui->edgeEnhancementValueInput, [&](int sliderValue) {
        ui->edgeEnhancementValueInput->setText(QString::number(sliderValue));
        bool enabled = blocks[blocks.size()-1]->getEnabled();
        if (sliderValue == 0){ //disable if 0 on slider is selected
            if (enabled){
                blocks[blocks.size()-1]->toggleEnable();
            }
        }
        else{
            if (!enabled){
                blocks[blocks.size()-1]->toggleEnable();
            }
        }
        //access derived method of edgeDetector from vector of base class (image processor) pointers
        static_cast<edgeDetection*>(blocks[blocks.size()-1])->updateThreshold(sliderValue);

    });

    QObject::connect(ui->edgeEnhancementValueInput, &QLineEdit::textChanged, ui->edgeEnhancementSlider, [&](const QString &text) {
        bool ok;
        int value = text.toInt(&ok);
        if (ok) {
            ui->edgeEnhancementSlider->setValue(value);
        }
    });
    
    // //-----------block 5 contrast ---------------------
    QObject::connect(ui->contrastEnhancementSlider, &QSlider::valueChanged, ui->contrastEnhancementValueInput, [&](int sliderValue1) {
        ui->contrastEnhancementValueInput->setText(QString::number(sliderValue1));
        bool enabled = blocks[5]->getEnabled();
        if (sliderValue1 == 0){ //disable if 0 on slider is selected
            if (enabled){
                blocks[5]->toggleEnable();
            }
        }
        else{
            if (!enabled){
                blocks[5]->toggleEnable();
            }
        }
        //access derived method of contrastEnhancer from vector of base class (image processor) pointers
        static_cast<contrastEnhancement*>(blocks[5])->updateThreshold(sliderValue1);

    });

    QObject::connect(ui->contrastEnhancementValueInput, &QLineEdit::textChanged, ui->contrastEnhancementSlider, [&](const QString &text) {
        bool ok;
        int value = text.toInt(&ok);
        if (ok) {
            ui->contrastEnhancementSlider->setValue(value);
        }
    });

    QObject::connect(ui->exposureSlider, &QSlider::valueChanged, ui->exposureValueInput, [&](int sliderValue2) {
        this->cam->setExposure(sliderValue2);
        ui->exposureValueInput->setText(QString::number(sliderValue2*5));
        // bool enabled = blocks[3]->getEnabled();
        // if (sliderValue2 == 0){ //disable if 0 on slider is selected
        //     if (enabled){
        //         blocks[3]->toggleEnable();
        //     }
        // }
        // else{
        //     if (!enabled){
        //         blocks[3]->toggleEnable();
        //     }
        // }
        // //access derived method of contrastEnhancer from vector of base class (image processor) pointers
        // static_cast<contrastEnhancement*>(blocks[3])->updateThreshold(sliderValue2);

    });
    QObject::connect(ui->exposureValueInput, &QLineEdit::textChanged, ui->exposureSlider, [&](const QString &text) {
        bool ok;
        
        int value = text.toInt(&ok);
        if (ok) {
            ui->exposureSlider->setValue(value/5);
        }
    });
    




    //------------make connections-------------
    // push button (to be renamed @Jake) connects to gallery capture

    ////do a capture
    QObject::connect(ui->captureButton, &QPushButton::released, this, &Gui::captureNextFrame);

    QObject::connect(ui->FlatFieldButton, &QPushButton::released, this, &Gui::setUpdateFlatField);

    //// How to connect a button to an instance of another class
    // QObject::connect(ui->captureButton, &QPushButton::released, this, [&](){gallery->getMetadata();});

    // toggle edge
    // QObject::connect(ui->captureButton, &QPushButton::released, this, [&](){blocks[2]->toggleEnable();});

    // testing restore settings
    QObject::connect(ui->restoreSettingsButton, &QPushButton::released, this, [&](){ restoreSettings(""); });


    ui->motorDisabledText->setVisible(false);       // motor disabled message default to invisible
    // check if motors connected, if not, disable controls
    if (!motors->getConnected()){ 
        ui->motorDisabledText->setVisible(true);    // show no motors message
        ui->xUpButton->setDisabled(true);
        ui->xDownButton->setDisabled(true);
        ui->xPos->setEnabled(false);
        ui->yUpButton->setDisabled(true);
        ui->yDownButton->setDisabled(true);
        ui->yPos->setEnabled(false);
        ui->zUpButton->setDisabled(true);
        ui->zDownButton->setDisabled(true);
        ui->zPos->setEnabled(false);
    }

    // motor ui element connections
    QObject::connect(ui->xUpButton, &QPushButton::released, this, [&](){ motorMove('x', 10); });
    QObject::connect(ui->xDownButton, &QPushButton::released, this, [&](){ motorMove('x', -10); });
    QObject::connect(ui->xPos, &QLineEdit::returnPressed, this, [&]() {     // only move motors after enter pressed
        bool ok;
        QString text = ui->xPos->text();                // get text from ui element
        int finalPosition = text.toInt(&ok);
        if (ok) {
            bool motorsRunning = motors->getRunning();  // check if motors active
            if (!motorsRunning){  
                int currentPosition = motors->getPosition()[0];
                int toMove = finalPosition - currentPosition;   // move difference between current and desired positions 
                motorMove('x', toMove);
            }
        }
    });

    QObject::connect(ui->yUpButton, &QPushButton::released, this, [&](){ motorMove('y', 10); });
    QObject::connect(ui->yDownButton, &QPushButton::released, this, [&](){ motorMove('y', -10); });
    QObject::connect(ui->yPos, &QLineEdit::returnPressed, this, [&]() {
        bool ok;
        QString text = ui->yPos->text();
        int finalPosition = text.toInt(&ok);
        if (ok) {
            bool motorsRunning = motors->getRunning();  // check if motors active
            if (!motorsRunning){  
                int currentPosition = motors->getPosition()[1];
                int toMove = finalPosition - currentPosition;
                motorMove('y', toMove);
            }
        }
    });

    QObject::connect(ui->zUpButton, &QPushButton::released, this, [&](){ motorMove('z', 10); });
    QObject::connect(ui->zDownButton, &QPushButton::released, this, [&](){ motorMove('z', -10); });
    QObject::connect(ui->zPos, &QLineEdit::returnPressed, this, [&]() {
        bool ok;
        QString text = ui->zPos->text();
        int finalPosition = text.toInt(&ok);
        if (ok) {
            bool motorsRunning = motors->getRunning();  // check if motors active
            if (!motorsRunning){  
                int currentPosition = motors->getPosition()[2];
                int toMove = finalPosition - currentPosition;
                motorMove('z', toMove);
            }
        }
    });



}

/**
* Function to recieve callbacks frames from image processor blocks
* @param newFrame frame structure from processing block via callback interface
**/
void Gui::receiveFrame(frame newFrame)
{

    // if capturing, capture before conversion to rgb
    if (doCapture && newFrame.doMeta && updateFlatField == false){
        gallery->captureFrame(newFrame);
        doCapture = false; // reset flag
    }
    else if (doCapture && newFrame.doMeta && updateFlatField == true){
        if (flatFieldCounter <20){
            gallery->captureFrame(newFrame, updateFlatField, flatFieldCounter);
            //std::cout<<"capture"+ flatFieldCounter<<std::endl;
            flatFieldCounter ++;
            doCapture=true;
            cam->captureMetadata();

        }else{
            updateFlatField = false;
            doCapture = false;
        }


    }

    img = newFrame.image;

    // maybe try replacing img with newFrame.img to avoid unnecessary copying.
    // convert from default opencv bgr to QT rgb
    cv::cvtColor(img, img, cv::COLOR_BGR2RGB);

    QImage imgOut = QImage((uchar *)img.data, img.cols, img.rows, img.step,
                           QImage::Format_RGB888);
    ui->scopeVideoFeed->setPixmap(QPixmap::fromImage(imgOut));
    ui->scopeVideoFeed->resize(ui->scopeVideoFeed->pixmap()->size());

}

/**
* Takes capture and initialises flatfield correction
**/
void Gui::setUpdateFlatField(){
    //std::cout<<"setUpdateField"<<std::endl;

    updateFlatField=true;
    flatFieldCounter = 0;
    static_cast<flatFieldCorrect*>(blocks[0])->setUpdateFlag();
    cam->captureMetadata();
    doCapture = true;
    //To allow checkbox to be enabled
    ui->flatFieldBox->setEnabled(true);
}


/**
* Sets UI visibility 
* @param visible true to make visible
**/
void Gui::SetVisible(bool visible)
{
    widget->setVisible(visible);
}

// set to capture on next frame
/**
* Sets camera object to capture next frame
**/
void Gui::captureNextFrame()
{
    cam->captureMetadata();
    doCapture = true;
}


/**
* Restores image processing settings from existing capture metadata
* @param fname filename for image to restore metadata from
**/
void Gui::restoreSettings(std::string fname)
{
    std::cout<<"restoring settings" <<std::endl;
    metadata = this->gallery->getMetadata(fname);


    ////debug
    //std::string erosion = metadata["erosion"];
    //std::cout<<"erosion::" + erosion<<std::endl;
    

    //pass retrieved metadata through callbacks to each image proc block
    for (auto block : blocks){
        block->updateSettings(metadata);
    }
    this->updateSettings(metadata);//updates gui sliders
}

//resets gui sliders and checkboxes to match new settings
/**
* Restores GUI sliders and checkboxes to match the restored image processor settings.
**/
void Gui::updateSettings(std::map<std::string, std::string> metadata){
    //std::cout<<"in gui update settings"<<std::endl;
    std::string value;
    std::string label;
    for (auto block: blocks){
        label = block->getParamLabel();
        try{
            value = metadata[label];
        }catch(...){
            std::cerr<<"label not in metadata";
            return;
        };


        //std::cout<<value<<std::endl;

        if (value == ""){
            std::cerr<<"check paramLabel is defined in derived image procesor class"<<std::endl;
            return;
        }

        bool valueBool = false;
        if (value == "ON"){
            valueBool = true;
        }else if (value == "OFF"){
            valueBool = false;
        }

        //janky but not sure how else to make these connections
        if(label == "edgeThreshold"){
            try{
                ui->edgeEnhancementSlider->setValue(std::stoi(value));
            }catch(...){
                if (value == "OFF"){
                    ui->edgeEnhancementSlider->setValue(0);
                }else{
                std::cerr<<"Invalid metadata for edge enhancement"<<std::endl;
                }
            }
        }
                //janky but not sure how else to make these connections
        else if(label == "contrastThreshold"){
            try{
                ui->contrastEnhancementSlider->setValue(std::stoi(value));
            }catch(...){
                if (value == "OFF"){
                    ui->contrastEnhancementSlider->setValue(0);
                }else{
                std::cerr<<"Invalid metadata for contrast enhancement"<<std::endl;
                }
            }
        }

        else if(label == "exposure"){
            try{
                ui->exposureSlider->setValue(std::stoi(value));
            }catch(...){
                if (value == "OFF"){
                    ui->exposureSlider->setValue(0);
                }else{
                std::cerr<<"Invalid metadata for contrast enhancement"<<std::endl;
                }
            }
        }

        else if(label == "erosion"){
            ui->erosionCheckBox->setChecked(valueBool);
        }
        else if(label == "grayScale"){
            ui->grayScaleBox->setChecked(valueBool);
        }

        else if(label == "dilation"){
            ui->dilationCheckBox->setChecked(valueBool);
        }
        else if(label == "flatField"){
            ui->flatFieldBox->setChecked(valueBool);
        }
    }
    
}

/**
* Calls MotorDriver move function if motors have been connected and initialised at startup.
* Updates UI with new position.
* @param ax axis of travel (x, y, or z)
* @param increment step to move motors by
**/
void Gui::motorMove(char ax, int increment){
    
    bool motorsConnected = motors->getConnected();
    bool motorsRunning = motors->getRunning();
    if (!motorsRunning && motorsConnected){            // only move if motors connected and not currently active
        
        motors->mov(ax, increment);

        if (ax=='x'){
            int positionForUpdate = motors->getPosition()[0];
            ui->xPos->setText(QString::number(positionForUpdate+increment));    // update position to starting pos + increment
        }

        else if (ax=='y'){
            int positionForUpdate = motors->getPosition()[1];
            ui->yPos->setText(QString::number(positionForUpdate+increment));   
        }

        else if (ax=='z'){
            int positionForUpdate = motors->getPosition()[2];
            ui->zPos->setText(QString::number(positionForUpdate+increment));  
        }

    }

}


