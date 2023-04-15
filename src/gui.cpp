#include "gui.h"
#include "edgeDetection.h"
#include "contrastEnhancement.h"
#include "grayScale.h"

Gui::Gui(QMainWindow *win, Ui_GUI *ui_win, Gallery *galleryIn, std::vector<imageProcessor *> &blocksIn)
{
    widget = win;
    ui = ui_win;
    ui->setupUi(widget);

    this->gallery = galleryIn;
    blocks = blocksIn;
    this->cam = static_cast<Camera*>(blocks[0]);
    enabled = true;
    this->displayImages();

    ui->dilationCheckBox->setStyleSheet("QCheckBox { color: white; } QCheckBox::indicator {background-color: rgb(179, 179, 179);  } QCheckBox::indicator:checked { background-color: rgb(29, 185, 84); }");
    ui->erosionCheckBox->setStyleSheet("QCheckBox { color: white; } QCheckBox::indicator {background-color: rgb(179, 179, 179);  } QCheckBox::indicator:checked { background-color: rgb(29, 185, 84); }");
    ui->flatFieldBox->setStyleSheet("QCheckBox { color: white; } QCheckBox::indicator {background-color: rgb(179, 179, 179);  } QCheckBox::indicator:checked { background-color: rgb(29, 185, 84); }");
    ui->flatFieldBox->setEnabled(false);


    ui->grayScaleBox->setStyleSheet("QCheckBox { color: white; } QCheckBox::indicator {background-color: rgb(179, 179, 179);  } QCheckBox::indicator:checked { background-color: rgb(29, 185, 84); }");

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
    QObject::connect(ui->captureButton, &QPushButton::released, this, &Gui::captureNextFrame); //&Gui::captureNextFrame
    QObject::connect(ui->captureButton, &QPushButton::released, this, [&](){textEditController(myString, true);});

    QObject::connect(ui->FlatFieldButton, &QPushButton::released, this, &Gui::setUpdateFlatField);

    //// How to connect a button to an instance of another class
    // QObject::connect(ui->captureButton, &QPushButton::released, this, [&](){gallery->getMetadata();});

    // toggle edge
    // QObject::connect(ui->captureButton, &QPushButton::released, this, [&](){blocks[2]->toggleEnable();});
    QObject::connect(ui->updateNameBox, &QTextEdit::textChanged, this, [&](){
        QString enteredText = ui->updateNameBox->toPlainText();
        std::string enteredTextStr = enteredText.toStdString();
        textEditController(enteredTextStr, false);
    });
    // testing restore settings
    QObject::connect(ui->restoreSettingsButton, &QPushButton::released, this, [&](){ restoreSettings(""); });
    //gallery button connections
    QObject::connect(ui->nextButton, &QPushButton::released, this, [&](){ updateGalleryIndex(true);});
    QObject::connect(ui->backButton, &QPushButton::released, this, [&](){ updateGalleryIndex(false);});

    QObject::connect(ui->buttonPos1, &QPushButton::released, this, [&](){showDialog(galleryPos1Index);});
    QObject::connect(ui->buttonPos2, &QPushButton::released, this, [&](){showDialog(galleryPos2Index);});
    QObject::connect(ui->buttonPos3, &QPushButton::released, this, [&](){showDialog(galleryPos3Index);});
    QObject::connect(ui->buttonPos4, &QPushButton::released, this, [&](){showDialog(galleryPos4Index);});
}

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


void Gui::SetVisible(bool visible)
{
    widget->setVisible(visible);
}

// set to capture on next frame
void Gui::captureNextFrame()
{
    cam->captureMetadata();
    doCapture = true;
}


void Gui::restoreSettings(std::string fname)
{
    std::cout<<"restoring settings" <<std::endl;
    std::cout<<fname <<std::endl;
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
// last thing to do is 0 images, 1 image on open etc. 
// potenial bug, crashes when you in a different batch after a bunch of images have been deleted. 
// probably need an auto position  

void Gui::displayImages() {

   
    std::string directoryStr = this->gallery->getPathname();
    QString directory = QString::fromStdString(directoryStr);
    QDir imageDir(directory);
   
    imageFilters << "*.jpg";
    QStringList images = imageDir.entryList(imageFilters, QDir::Files | QDir::Readable);
    QSize labelSize = ui->galleryPos1->size();
    QPixmap pixmap1, pixmap2, pixmap3, pixmap4;
    QString img1name, img2name, img3name, img4name;
    // list of image names here? 
 //how images are brought in - filters jpg's images is a list of images 

    if (images.isEmpty()) {
        qWarning("No images found in directory %s", qUtf8Printable(directory));
        return;
    }

//if the gallery index is negative 1, show nothing, if its anything else, display image in that index.
// so make a part with initliseation checks essentially 

if (galleryPos1Index != -1) {
    QImage image1(directory + "/" + images[galleryPos1Index]);
    pixmap1 = QPixmap::fromImage(image1).scaled(labelSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    QString image1name = images.at(galleryPos1Index);
    img1name = image1name;
    

    
} else {

    ui->galleryPos1->clear();
    ui->namePos1->clear();
}

if (galleryPos2Index != -1) {
    QImage image2(directory + "/" + images[galleryPos2Index]);
    pixmap2 = QPixmap::fromImage(image2).scaled(labelSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    QString image2name = images.at(galleryPos2Index);
    img2name = image2name;
} else {
    ui->galleryPos2->clear();
    ui->namePos2->clear();
}

if (galleryPos3Index != -1) {
    QImage image3(directory + "/" + images[galleryPos3Index]);
   pixmap3 = QPixmap::fromImage(image3).scaled(labelSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    QString image3name = images.at(galleryPos3Index);
    img3name = image3name;
} else {
    ui->galleryPos3->clear();
    ui->namePos3->clear();
    
}

if (galleryPos4Index != -1) {
    QImage image4(directory + "/" + images[galleryPos4Index]);
    pixmap4 = QPixmap::fromImage(image4).scaled(labelSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    QString image4name = images.at(galleryPos4Index);
    img4name = image4name;
}
 else {
    ui->galleryPos4->clear();
    ui->namePos4->clear();
}

ui->galleryPos1->setPixmap(pixmap1);
ui->galleryPos2->setPixmap(pixmap2);
ui->galleryPos3->setPixmap(pixmap3);
ui->galleryPos4->setPixmap(pixmap4);

ui->namePos1->setText(img1name); // however the name is called
ui->namePos2->setText(img2name);
ui->namePos3->setText(img3name);
ui->namePos4->setText(img4name);
}

void Gui::updateGalleryIndex (bool moveUp){
 

std::string directoryStr = this->gallery->getPathname();
    
    QString directory = QString::fromStdString(directoryStr);
    QDir imageDir(directory);
    imageFilters << "*.jpg";
    QStringList images = imageDir.entryList(imageFilters, QDir::Files | QDir::Readable);
    
    float galleryBatchNumber = (float)images.size()/4;
    
if (moveUp == true ){
    batchIndex=batchIndex+1;
    float r = batchIndex-galleryBatchNumber;
    
    
    if (batchIndex>= galleryBatchNumber) {
        
        //this is skipping over the second to last once the back button is pressed, stops a crash tho
        if (batchIndex-galleryBatchNumber>1){
            batchIndex=batchIndex-1;}
        
      intialGallerySetting();  
    // don't update the gallery position indexes on the "next" button press
    // dont update the batch index
    
     if (r<1) { 
        
         
        if (r == 0.75) {
            // update position 1 , make rest not show anything

             
            galleryPos1Index = batchIndex*4-4;
            galleryPos2Index = -1;
            galleryPos3Index = -1;
            galleryPos4Index = -1;
            
            
        }
        else if (r == 0.5) {
            
            
            galleryPos1Index = batchIndex*4-4;
            galleryPos2Index = batchIndex*4-3;
            galleryPos3Index = -1;
            galleryPos4Index = -1;
             
        }
        else if (r == 0.25) {

            galleryPos1Index = batchIndex*4-4;
            galleryPos2Index = batchIndex*4-3;
            galleryPos3Index = batchIndex*4-2;
            galleryPos4Index = -1;
        }
        
        }

    }
    else{

         
            galleryPos1Index = batchIndex*4-4;
            galleryPos2Index = batchIndex*4-3;
            galleryPos3Index = batchIndex*4-2;
            galleryPos4Index = batchIndex*4-1;
   
    }

     
}
    
else{
    if (batchIndex==1){ 
       return;
    }
    else{
        
        batchIndex =batchIndex-1;

        galleryPos1Index = batchIndex*4-4;
        galleryPos2Index = batchIndex*4-3;
        galleryPos3Index = batchIndex*4-2;
        galleryPos4Index = batchIndex*4-1;

    }
}
displayImages();


}

void Gui :: intialGallerySetting (){
   std::string directoryStr = this->gallery->getPathname();
    QString directory = QString::fromStdString(directoryStr);
    QDir imageDir(directory);
   
    imageFilters << "*.jpg";
    QStringList images = imageDir.entryList(imageFilters, QDir::Files | QDir::Readable);

    if (images.size() ==0){
        galleryPos1Index =-1;
        galleryPos2Index =-1;
        galleryPos3Index =-1;
        galleryPos4Index =-1;
    }
    else if (images.size() ==1){
        galleryPos1Index =0;
        galleryPos2Index =-1;
        galleryPos3Index =-1;
        galleryPos4Index =-1;
    }
    else if (images.size() ==2){
        galleryPos1Index =0;
        galleryPos2Index =1;
        galleryPos3Index =-1;
        galleryPos4Index =-1;
    }
     else if (images.size() ==3){
        galleryPos1Index =0;
        galleryPos2Index =1;
        galleryPos3Index =2;
        galleryPos4Index =-1;
    }
    else if (images.size() ==4){
        galleryPos1Index =0;
        galleryPos2Index =1;
        galleryPos3Index =2;
        galleryPos4Index =3;
    } 
    else{}



}

 void Gui::textEditController(std::string enteredTextStr, bool pressed){

    myString = enteredTextStr;
    if (!myString.empty()){
    std::cout<<"Entered String: "<<enteredTextStr<<std::endl;
    if( pressed == true){
        this->gallery->updateImgName(myString);
        bool pressed =false;
    }
    else{}
    }
    else{}
}

//function that see's that the button is pressed, return true, make batch index go to the end and show now image, 
void Gui::showDialog(int position) {
    if (position!=-1){
    QDialog dialog;
    dialog.setWindowTitle("Restore Image Properties");

    // Load the image and create a pixmap
    std::string directoryStr = this->gallery->getPathname();
    QString directory = QString::fromStdString(directoryStr);
    QDir imageDir(directory);
   
    imageFilters << "*.jpg";
    QStringList images = imageDir.entryList(imageFilters, QDir::Files | QDir::Readable);
    QSize labelSize = ui->galleryPos1->size();

    QImage image(directory + "/" + images[position]);
    QPixmap pixmap = QPixmap::fromImage(image);
    QString imagName = images.at(position);

    // Create a QLabel widget and set its pixmap
    QLabel label;
    label.setPixmap(pixmap);

    // Create a QPushButton and set its text
    QPushButton button("Restore Image Properties");
    QObject::connect(&button, &QPushButton::released, this, [=](){ 
        std::string pathStr = this->gallery->getPathname();
        std::string fileToRestore = pathStr + imagName.toStdString();
        restoreSettings(fileToRestore); 
        
    });

    // Create a QHBoxLayout and add the label to it
    QVBoxLayout layout;
    layout.addWidget(&label);
    layout.addWidget(&button);

    // Add the QHBoxLayout to the dialog's layout
    dialog.setLayout(&layout);

    dialog.exec();
    }
    else{}
}

