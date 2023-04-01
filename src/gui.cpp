#include "gui.h"
#include "edgeDetection.h"

Gui::Gui(QMainWindow *win, Ui_GUI *ui_win, Gallery *galleryIn, std::vector<imageProcessor *> &blocksIn)
{
    widget = win;
    ui = ui_win;
    ui->setupUi(widget);

    this->gallery = galleryIn;
    blocks = blocksIn;

    // ui->logoImage->setPixmap(QPixmap(QString::fromUtf8("images/logo.png"))); add back in for future logo?
    // const std::vector<imageProcessor*> *blocks = blocksIn;

    //-----------block 0 erosion---------------------
    QObject::connect(ui->erosionCheckBox, &QCheckBox::stateChanged, this, [&](bool checkboxValue){
        bool enabled = blocks[0]->getEnabled();
        if (enabled != checkboxValue){
            blocks[0]->toggleEnable();
        }
         
    });

    // //-----------block 1 dilation ---------------------
    QObject::connect(ui->dilationCheckBox, &QCheckBox::stateChanged, this, [&](bool checkboxValue){
        bool enabled = blocks[1]->getEnabled();
        if (enabled != checkboxValue){
            blocks[1]->toggleEnable();
        }
         
    });
   
    //-------------block -1 edge enhancement-----------------------
    QObject::connect(ui->edgeEnhancementSlider, &QSlider::valueChanged, ui->lineEdit, [&](int sliderValue) {
        ui->lineEdit->setText(QString::number(sliderValue));
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

    QObject::connect(ui->lineEdit, &QLineEdit::textChanged, ui->edgeEnhancementSlider, [&](const QString &text) {
        bool ok;
        int value = text.toInt(&ok);
        if (ok) {
            ui->edgeEnhancementSlider->setValue(value);
        }
    });
    





    //------------make connections-------------
    // push button (to be renamed @Jake) connects to gallery capture

    ////do a capture
    //QObject::connect(ui->captureButton, &QPushButton::released, this, &Gui::captureNextFrame);

    //// How to connect a button to an instance of another class
    // QObject::connect(ui->captureButton, &QPushButton::released, this, [&](){gallery->getMetadata();});

    // toggle edge
    // QObject::connect(ui->captureButton, &QPushButton::released, this, [&](){blocks[2]->toggleEnable();});

    // testing restore settings
    QObject::connect(ui->captureButton, &QPushButton::released, this, [&](){ restoreSettings(""); });
}

void Gui::receiveFrame(frame newFrame)
{

    // if capturing, capture before conversion to rgb
    if (doCapture)
    {
        gallery->captureFrame(newFrame);
        doCapture = false; // reset flag
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

void Gui::SetVisible(bool visible)
{
    widget->setVisible(visible);
}

// set to capture on next frame
void Gui::captureNextFrame()
{
    doCapture = true;
}

void Gui::restoreSettings(std::string fname)
{
    // debug only
    captureNextFrame();
    // debug only


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
        //std::cout<<label<<std::endl;
        try{
            value = metadata[label];
        }catch(...){
            std::cerr<<"label not in metadata";
            return;
        };
        //std::cout<<value<<std::endl;

        if (value == ""){
            std::cerr<<"check paramLabel is defined in derived image procesor class"<<std::endl;
        }

        //janky but not sure how else to make these connections
        else if(label == "edgeThreshold"){
            ui->edgeEnhancementSlider->setValue(std::stoi(value));
        }

    }
    
}