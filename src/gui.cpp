#include "gui.h"
#include "edgeDetection.h"
#include "contrastEnhancement.h"
#include "grayScale.h"

/**
* Constructor to initialise the GUI and set connections
* @param win points to QMainWindow 
* @param ui_win points to Ui_GUI 
* @param galleryIn points to Gallery instance
* @param blocksIn is a std::vector of the image processing blocks
**/
Gui::Gui(QMainWindow *win, Ui_GUI *ui_win, Gallery *galleryIn, std::vector<imageProcessor *> &blocksIn)
{
    widget = win;
    ui = ui_win;
    ui->setupUi(widget);

    this->gallery = galleryIn;
    blocks = blocksIn; 
    this->cam = static_cast<Camera*>(blocks[0]);
    enabled = true;
    

    ui->dilationCheckBox->setStyleSheet("QCheckBox { color: white; } QCheckBox::indicator {background-color: rgb(179, 179, 179);  } QCheckBox::indicator:checked { background-color: rgb(29, 185, 84); }");
    ui->erosionCheckBox->setStyleSheet("QCheckBox { color: white; } QCheckBox::indicator {background-color: rgb(179, 179, 179);  } QCheckBox::indicator:checked { background-color: rgb(29, 185, 84); }");
    ui->flatFieldBox->setStyleSheet("QCheckBox { color: white; } QCheckBox::indicator {background-color: rgb(179, 179, 179);  } QCheckBox::indicator:checked { background-color: rgb(29, 185, 84); }");
    ui->flatFieldBox->setEnabled(false);
    ui->grayScaleBox->setStyleSheet("QCheckBox { color: white; } QCheckBox::indicator {background-color: rgb(179, 179, 179);  } QCheckBox::indicator:checked { background-color: rgb(29, 185, 84); }");


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
    


    
    


    //------------make connections-------------
    // push button (to be renamed @Jake) connects to gallery capture

    ////do a capture
    QObject::connect(ui->captureButton, &QPushButton::released, this, &Gui::captureNextFrame); //&Gui::captureNextFrame
    //QObject::connect(ui->captureButton, &QPushButton::released, this, [&](){textEditController(myString, true);});

    QObject::connect(ui->FlatFieldButton, &QPushButton::released, this, &Gui::setUpdateFlatField);

    //// How to connect a button to an instance of another class
    // QObject::connect(ui->captureButton, &QPushButton::released, this, [&](){gallery->getMetadata();});

    // toggle edge
    // QObject::connect(ui->captureButton, &QPushButton::released, this, [&](){blocks[2]->toggleEnable();});
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
    // testing restore settings
    QObject::connect(ui->restoreSettingsButton, &QPushButton::released, this, [&](){ restoreSettings(""); });
    //gallery button connections
    QObject::connect(ui->nextButton, &QPushButton::released, this, [&](){ updateGalleryView(true);});
    QObject::connect(ui->backButton, &QPushButton::released, this, [&](){ updateGalleryView(false);});

    QObject::connect(ui->buttonPos1, &QPushButton::released, this, [&](){showDialog(galleryPos1Index);});
    QObject::connect(ui->buttonPos2, &QPushButton::released, this, [&](){showDialog(galleryPos2Index);});
    QObject::connect(ui->buttonPos3, &QPushButton::released, this, [&](){showDialog(galleryPos3Index);});
    QObject::connect(ui->buttonPos4, &QPushButton::released, this, [&](){showDialog(galleryPos4Index);});


    updateGalleryView(true);
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
    for (auto block: blocks){
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
* Updates gallery previews with a new four images with labels
* @param directionIsNext if true, moves the gallery view forward to more recent captures, otherwise back to an earlier 4 captures
**/
void Gui::updateGalleryView(bool directionIsNext){
    std::list<std::pair<std::string, cv::Mat>> loaded = this->gallery->getCaptures(directionIsNext);
    std::vector<std::string> keys;
    std::list<std::pair<std::string, cv::Mat>>::const_iterator it;
    mats.clear();
    for (it = loaded.begin(); it != loaded.end(); ++it){
        keys.push_back(it->first);
        mats.push_back(it->second);
    }


    cv::Mat img;
    QSize labelSize = ui->galleryPos1->size();

    //reload first of four gallery view
    img = mats[0];
    if (img.empty() == false){
        img = mats[0];
        std::cout<<img.size()<<std::endl;
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
        std::cout<<img.size()<<std::endl;
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

        std::cout<<img.size()<<std::endl;
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

        std::cout<<img.size()<<std::endl;
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
//function that see's that the button is pressed, return true, make batch index go to the end and show now image, 
void Gui::showDialog(int position) {
    dialog.accept();
    if (position!=-1){
    dialog.setWindowTitle("Restore Settings");

    // // Load the image and create a pixmap
    // std::string directoryStr = this->gallery->getPathname();
    // QString directory = QString::fromStdString(directoryStr);
    // QDir imageDir(directory);
   
    // imageFilters << "*.jpg";
    // QStringList images = imageDir.entryList(imageFilters, QDir::Files | QDir::Readable);
    // QSize labelSize = ui->galleryPos1->size();

    // QImage image(directory + "/" + images[position]);
    // QString imagName = images.at(position);
    QString caption = galleryStrs[position];
    //QImage image = galleryQImages[position];
    ////vpassing wasn't working so trying
    cv::Mat img = mats[position];
    std::cout<<img.size()<<std::endl;
    //cv::cvtColor(img, img, cv::COLOR_BGR2RGB);
    QImage dialogImg = QImage((uchar *)img.data, img.cols, img.rows, img.step,
                        QImage::Format_RGB888);
    QLabel label;
    label.setPixmap(QPixmap::fromImage(dialogImg));//.scaled(labelSize, Qt::KeepAspectRatio, Qt::SmoothTransformation));


    // Create a QPushButton and set its text
    QPushButton button("Restore Image Properties");
    QObject::connect(&button, &QPushButton::released, this, [=](){ 
        std::string pathStr = this->gallery->getPathname();
        //std::string fileToRestore = pathStr + caption.toStdString();
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

