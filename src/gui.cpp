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
#ifndef LINUX_DEV_NO_MOTORS
Gui::Gui(QMainWindow *win, Ui_GUI *ui_win, Gallery *galleryIn, MotorDriver *motorsIn, std::vector<imageProcessor *> &blocksIn){
    this->motors = motorsIn;
#else
Gui::Gui(QMainWindow *win, Ui_GUI *ui_win, Gallery *galleryIn, std::vector<imageProcessor *> &blocksIn){
#endif //LINUX_DEV_NO_MOTORS

    widget = win;
    ui = ui_win;
    ui->setupUi(widget);

    //----- save class instances passed in by reference ------
    this->gallery = galleryIn;
    blocks = blocksIn; 
    this->cam = static_cast<Camera*>(blocks[0]);
    enabled = true;
    
    //-------------Set styles of selected widgets--------------------------

    ui->dilationCheckBox->setStyleSheet("QCheckBox { color: white; } QCheckBox::indicator {background-color: rgb(179, 179, 179);  } QCheckBox::indicator:checked { background-color: rgb(29, 185, 84); }");
    ui->erosionCheckBox->setStyleSheet("QCheckBox { color: white; } QCheckBox::indicator {background-color: rgb(179, 179, 179);  } QCheckBox::indicator:checked { background-color: rgb(29, 185, 84); }");
    ui->flatFieldBox->setStyleSheet("QCheckBox { color: white; } QCheckBox::indicator {background-color: rgb(179, 179, 179);  } QCheckBox::indicator:checked { background-color: rgb(29, 185, 84); }");
    ui->flatFieldBox->setEnabled(false);
    ui->grayScaleBox->setStyleSheet("QCheckBox { color: white; } QCheckBox::indicator {background-color: rgb(179, 179, 179);  } QCheckBox::indicator:checked { background-color: rgb(29, 185, 84); }");


    //----------------------------------------------MAKE IMAGE PROCESSOR CONTROLS CONNECTIONS_--------------------------

     //-----------camera (block 0)---------------------
    QObject::connect(ui->exposureSlider, &QSlider::valueChanged, ui->exposureValueInput, [&](int sliderValue2) {
        this->cam->setExposure(sliderValue2);
        ui->exposureValueInput->setText(QString::number(sliderValue2*5));


    });
    QObject::connect(ui->exposureValueInput, &QLineEdit::textChanged, ui->exposureSlider, [&](const QString &text) {
        bool ok;
        
        int value = text.toInt(&ok);
        if (ok) {
            ui->exposureSlider->setValue(value/5);
        }
    });

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

 // //-----------block 6 kMeans ---------------------
    QObject::connect(ui->kMeansSlider, &QSlider::valueChanged, ui->kMeansValueInput, [&](int sliderValue3) {
        ui->kMeansValueInput->setText(QString::number(sliderValue3));
        bool enabled = blocks[6]->getEnabled();
        if (sliderValue3 == 0){ //disable if 0 on slider is selected
            if (enabled){
                blocks[6]->toggleEnable();
            }
        }
        else{
            if (!enabled){
                blocks[6]->toggleEnable();
            }
        }
        //access derived method of contrastEnhancer from vector of base class (image processor) pointers
        static_cast<kMeansCluster*>(blocks[6])->updateClusterCount(sliderValue3);
        static_cast<kMeansCluster*>(blocks[6])->centroidPercentage();
        
    });

    QObject::connect(ui->kMeansValueInput, &QLineEdit::textChanged, ui->kMeansSlider, [&](const QString &text) {
        bool ok;
        int value = text.toInt(&ok);
        if (ok) {
            ui->kMeansSlider->setValue(value);
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
    

    ////do a capture
    QObject::connect(ui->captureButton, &QPushButton::released, this, &Gui::captureNextFrame); 
    //flat field capture
    QObject::connect(ui->FlatFieldButton, &QPushButton::released, this, &Gui::setUpdateFlatField);


    //-----------Kmeans image analysis------------------
    QObject::connect(ui->kMeansPercentage, &QPushButton::released, this, &Gui::displayKmeans);

    ui->cluster0Checkbox->setChecked(true);
    ui->cluster1Checkbox->setChecked(true);
    ui->cluster2Checkbox->setChecked(true);
    ui->cluster3Checkbox->setChecked(true);
    ui->cluster4Checkbox->setChecked(true);
    ui->cluster0Checkbox->setEnabled(false);
    ui->cluster1Checkbox->setEnabled(false);
    ui->cluster2Checkbox->setEnabled(false);
    ui->cluster3Checkbox->setEnabled(false);
    ui->cluster4Checkbox->setEnabled(false);
    ui->cluster0Checkbox->setVisible(false);
    ui->cluster1Checkbox->setVisible(false);
    ui->cluster2Checkbox->setVisible(false);
    ui->cluster3Checkbox->setVisible(false);
    ui->cluster4Checkbox->setVisible(false);

    //Label text box, ensures that the text is never empty
    ui->updateNameBox->setText(" ");

    QObject::connect(ui->updateNameBox, &QTextEdit::textChanged, this, [&](){
        QString enteredText = ui->updateNameBox->toPlainText();
        std::string enteredTextStr = enteredText.toStdString();
        if (enteredTextStr == ""){
            //std::cout<<"switching"<<std::endl;
            enteredTextStr = " ";
        }
        this->cam->setNote(enteredTextStr);
    });

    //gallery button connections
    QObject::connect(ui->nextButton, &QPushButton::released, this, [&](){ updateGalleryView(true);});
    QObject::connect(ui->backButton, &QPushButton::released, this, [&](){ updateGalleryView(false);});
    //Enlarge image from gallery previews
    QObject::connect(ui->buttonPos1, &QPushButton::released, this, [&](){showDialog(galleryPos1Index);});
    QObject::connect(ui->buttonPos2, &QPushButton::released, this, [&](){showDialog(galleryPos2Index);});
    QObject::connect(ui->buttonPos3, &QPushButton::released, this, [&](){showDialog(galleryPos3Index);});
    QObject::connect(ui->buttonPos4, &QPushButton::released, this, [&](){showDialog(galleryPos4Index);});

    //loads in existing images in gallery if they exist
    updateGalleryView(true);


    // Motor Initialisation

    ui->motorDisableText->setVisible(false);       // motor disabled message default to invisible
#ifndef LINUX_DEV_NO_MOTORS    
    // check if motors connected
    if (!motors->getConnected()){           // if not connected, disable controls
        ui->motorDisableText->setVisible(true);    // show no motors message
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
    else{
        // initialise motor positions
        ui->xPos->setText(QString::number(motors->getPosition()[0]));
        ui->yPos->setText(QString::number(motors->getPosition()[1]));
        ui->zPos->setText(QString::number(motors->getPosition()[2]));
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

#endif //LINUX_DEV_NO_MOTORS

}

/**
* Function to recieve callbacks frames from image processor blocks and display in GUI and optionally pass to gallery to do captures
* @param newFrame frame structure from processing block via callback interface
**/
void Gui::receiveFrame(frame newFrame)
{

    // if capturing, capture before conversion to rgb
    if (doCapture && newFrame.doMeta && updateFlatField == false){
        gallery->captureFrame(newFrame);
        doCapture = false; // reset flag
        if (this->gallery->galleryAtEnd()== true){
            updateGalleryView(true); //if at end frame, move right
        }
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

    // convert from default opencv bgr to QT rgb
    cv::cvtColor(img, img, cv::COLOR_BGR2RGB);

    QImage imgOut = QImage((uchar *)img.data, img.cols, img.rows, img.step,
                           QImage::Format_RGB888);
    ui->scopeVideoFeed->setPixmap(QPixmap::fromImage(imgOut));
    ui->scopeVideoFeed->resize(ui->scopeVideoFeed->pixmap()->size());

}

/**
* Triggers capturing of 20 frames for flatfield/chromatic aberration correction.
**/
void Gui::setUpdateFlatField(){
    //std::cout<<"setUpdateField"<<std::endl;

    updateFlatField=true;
    flatFieldCounter = 0;
    std::cout<<"New flatfield correction captured."<<std::endl;

    
    static_cast<flatFieldCorrect*>(blocks[1])->setUpdateFlag();
    if (blocks[1]->getEnabled()==true){
        blocks[1]->toggleEnable();
        ui->flatFieldBox->setChecked(false);
    }
    cam->captureMetadata();
    doCapture = true;
    //To allow checkbox to be enabled
    ui->flatFieldBox->setEnabled(true);
}


/**
* Sets checkboxes to show percentages taken up by different clusters
**/
void Gui::displayKmeans(){
        //make all initially invisible
    resetCheckbox(ui->cluster0Checkbox);
    resetCheckbox(ui->cluster1Checkbox);
    resetCheckbox(ui->cluster2Checkbox);
    resetCheckbox(ui->cluster3Checkbox);
    resetCheckbox(ui->cluster4Checkbox);

    if (blocks[6]->getEnabled() == false){
        std::cout<<"K-means clustering not turned on. Adjust the slider to set number of clusters."<<std::endl;
        return;
    }

    //static_cast<kMeansCluster*>(blocks[6])->centroidPercentage();
    std::list<std::pair<cv::Vec3b, std::string>> kmeansValues = static_cast<kMeansCluster*>(blocks[6])->getClusterAnalysis();


    //replace this to iterate over

    std::list<std::pair<cv::Vec3b, std::string>>::const_iterator it;
    std::vector<cv::Vec3b> centroidColors;
    std::vector<std::string> percentages;
    centroidColors.clear();
    percentages.clear();
    for (it = kmeansValues.begin(); it != kmeansValues.end(); ++it){
        centroidColors.push_back(it->first);
        percentages.push_back(it->second);
    } 
    


    
    std::string styleSheet;
    cv::Vec3b centroidColor;
    std::string percentageLabel;
    QString styleSheetQ;
    QString percentageQStr;

    if (kmeansValues.size() >0){
        setClusterCheckbox(ui->cluster0Checkbox, centroidColors[0], percentages[0]);
    }
    if (kmeansValues.size() >1){
        setClusterCheckbox(ui->cluster1Checkbox, centroidColors[1], percentages[1]);
    }
    if (kmeansValues.size() >2){
        setClusterCheckbox(ui->cluster2Checkbox, centroidColors[2], percentages[2]);
    }
    if (kmeansValues.size() >3){
        setClusterCheckbox(ui->cluster3Checkbox, centroidColors[3], percentages[3]);
    }
    if (kmeansValues.size() >4){
        setClusterCheckbox(ui->cluster4Checkbox, centroidColors[4], percentages[4]);
    }

}

void Gui::setClusterCheckbox(QCheckBox* box, cv::Vec3b centroidColor, std::string percentageLabel){
    box->setVisible(true);
    QString styleSheetQ;
    QString percentageQStr;
    std::string stylesheet;
    stylesheet = setKmeansStyleSheet(centroidColor);
    styleSheetQ = QString::fromStdString(stylesheet);
    box->setStyleSheet(styleSheetQ);
    percentageQStr = QString::fromStdString(percentageLabel);
    box->setText(percentageQStr);
}
/**
* Resets a Kmeans cluster checkbox to be invisible 
**/
void Gui::resetCheckbox(QCheckBox* box){
    box->setText("");
    box->setVisible(false);

}

/**
* Generates a Kmeans stylesheet 
**/
std::string Gui::setKmeansStyleSheet(cv::Vec3b In){
    std::string color = std::to_string(In[2]) + ", " + std::to_string(In[1]) + ", " + std::to_string(In[0]);
    std::string styleSheet = "QCheckBox::indicator:checked { background-color: rgb(" + color + "); }";
    return styleSheet;

}


/**
* Sets UI visibility 
* @param visible true to make visible
**/
void Gui::SetVisible(bool visible)
{
    widget->setVisible(visible);
}

// set flags to trigger a capture for the next frame which is initialised once it arrives here at GUI.
/**
* Sets camera object to capture next frame
**/
void Gui::captureNextFrame()
{
    cam->captureMetadata();
    doCapture = true;
}


/**
* Restores image processing settings from existing capture metadata by passing to every image processor block through callback
* @param fname filename for image to restore metadata from
**/
void Gui::restoreSettings(std::string fname)
{
    std::cout<<"restoring settings" <<std::endl;
    // std::cout<<fname <<std::endl;
    metadata = this->gallery->getMetadata(fname);


    //pass retrieved metadata through callbacks to each image proc block
    for (auto block : blocks){
        block->updateSettings(metadata);
    }
    this->updateSettings(metadata);//updates gui sliders
}

/**
* Restores GUI sliders and checkboxes to match the restored image processor settings.
* @param metadata restored from saved capture in gallery directory.
**/
void Gui::updateSettings(std::map<std::string, std::string> metadata){
    //std::cout<<"in gui update settings"<<std::endl;
    std::string value;
    std::string label;

    //iterate over image processor blocks to update settings
    for (auto block: blocks){
        //fetch label of block
        label = block->getParamLabel();
        try{
            value = metadata[label];
        }catch(...){
            std::cerr<<"label not in metadata";
            return;
        };


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
        //------------------------------- iterate through metadata to restore GUI state-------------------
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
            ////broken fix this
            // try{
            //     ui->exposureSlider->setValue(std::stoi(value));
            // }catch(...){
            //     if (value == "OFF"){
            //         ui->exposureSlider->setValue(0);
            //     }else{
            //     std::cerr<<"Invalid metadata for contrast enhancement"<<std::endl;
            //     }
            // } 
            ;
        }
               //janky but not sure how else to make these connections
        else if(label == "kMean"){
            try{
                ui->kMeansSlider->setValue(std::stoi(value));
            }catch(...){
                if (value == "OFF"){
                    ui->kMeansSlider->setValue(0);
                }else{
                std::cerr<<"Invalid metadata for kMeans clustering"<<std::endl;
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
* Updates gallery previews with a new four images with labels
* @param directionIsNext if true, moves the gallery view forward to more recent captures, otherwise back to an earlier 4 captures
**/
void Gui::updateGalleryView(bool directionIsNext){
    std::list<std::pair<std::string, cv::Mat>> loaded = this->gallery->getCaptures(directionIsNext);
    //std::vector<std::string> keys;
    std::list<std::pair<std::string, cv::Mat>>::const_iterator it;
    mats.clear();
    keys.clear();
    for (it = loaded.begin(); it != loaded.end(); ++it){
        keys.push_back(it->first);
        mats.push_back(it->second);
    }


    cv::Mat img;
    QSize labelSize = ui->galleryPos1->size();

    //-----------Load in cv mats and labels from gallery and populate the preview window-----------

    //reload first of four gallery view
    img = mats[0];
    if (img.empty() == false){
        img = mats[0];
        cv::cvtColor(img, img, cv::COLOR_BGR2RGB);
        gallery1 = QImage((uchar *)img.data, img.cols, img.rows, img.step,
                            QImage::Format_RGB888);
        ui->galleryPos1->setPixmap(QPixmap::fromImage(gallery1).scaled(labelSize, Qt::KeepAspectRatio, Qt::SmoothTransformation));

        str1 = QString::fromStdString(keys[0]);
        ui->namePos1->setText(str1);
    } else{
        ui->galleryPos1->clear();
        ui->namePos1->clear();
    }


    //second of four
    img = mats[1];
    if (img.empty() == false){
        cv::cvtColor(img, img, cv::COLOR_BGR2RGB);
        gallery2 = QImage((uchar *)img.data, img.cols, img.rows, img.step,
                            QImage::Format_RGB888);
        ui->galleryPos2->setPixmap(QPixmap::fromImage(gallery2).scaled(labelSize, Qt::KeepAspectRatio, Qt::SmoothTransformation));

    str2 = QString::fromStdString(keys[1]);
    ui->namePos2->setText(str2);
    }else{
        ui->galleryPos2->clear();
        ui->namePos2->clear();
    }
    //third of four
    img = mats[2];
    if (img.empty() == false){
        cv::cvtColor(img, img, cv::COLOR_BGR2RGB);
        gallery3 = QImage((uchar *)img.data, img.cols, img.rows, img.step,
                            QImage::Format_RGB888);
        ui->galleryPos3->setPixmap(QPixmap::fromImage(gallery3).scaled(labelSize, Qt::KeepAspectRatio, Qt::SmoothTransformation));

        str3 = QString::fromStdString(keys[2]);
        ui->namePos3->setText(str3);
    }else{
        ui->galleryPos3->clear();
        ui->namePos3->clear();
    }

    //fourth of four
    img = mats[3];
    if (img.empty() == false){
        cv::cvtColor(img, img, cv::COLOR_BGR2RGB);
        gallery4 = QImage((uchar *)img.data, img.cols, img.rows, img.step,
                            QImage::Format_RGB888);
        ui->galleryPos4->setPixmap(QPixmap::fromImage(gallery4).scaled(labelSize, Qt::KeepAspectRatio, Qt::SmoothTransformation));

        str4 = QString::fromStdString(keys[3]);
        ui->namePos4->setText(str4);
    } else{
        ui->galleryPos4->clear();
        ui->namePos4->clear();
    }

    //required for restoring settings from selected capture
    galleryStrs.clear();
    galleryStrs = {str1, str2, str3, str4};
    galleryQImages.clear();
    galleryQImages={gallery1, gallery2, gallery3, gallery4}; 

}


/**
* Displays a popup window showing a full-sized capture with a button option to restore settings from that capture.
* @param position position within the four spaced as 0, 1 on top row and 2, 3 on the bottom.
**/
void Gui::showDialog(int position) {
    dialog.accept();
    if (position!=-1){
        //dialog.setWindowTitle("Restore Settings");
        std::string title = keys[position];
        QString titleQ = QString::fromStdString(title);
        dialog.setWindowTitle(titleQ);
        QString caption = galleryStrs[position];
        cv::Mat img = mats[position];
        QImage dialogImg = QImage((uchar *)img.data, img.cols, img.rows, img.step,
                            QImage::Format_RGB888);
        QLabel label;
        label.setPixmap(QPixmap::fromImage(dialogImg));


        // Create a QPushButton and set its text
        QPushButton button("Restore Image Properties");
        QObject::connect(&button, &QPushButton::released, this, [=](){ 
            std::string pathStr = this->gallery->getPathname();
            std::string fileToRestore = this->gallery->getGalleryDisplayFname(position);
            restoreSettings(fileToRestore); 
            dialog.accept();
        });

        // Create a QHBoxLayout and add the label to it
        QVBoxLayout layout;
        layout.addWidget(&label);
        layout.addWidget(&button);

        // Add the QHBoxLayout to the dialog's layout
        dialog.setLayout(&layout);

        dialog.exec();
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


