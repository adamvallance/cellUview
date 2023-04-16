/********************************************************************************
** Form generated from reading UI file 'gui.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_H
#define UI_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GUI
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QLabel *cellUview;
    QWidget *background;
    QLabel *scopeVideoFeed;
    QWidget *ImageCaptureColumn;
    QPushButton *captureButton;
    QWidget *ImageHolder;
    QLabel *galleryPos1;
    QLabel *galleryPos2;
    QPushButton *nextButton;
    QPushButton *backButton;
    QLabel *galleryPos4;
    QLabel *galleryPos3;
    QLabel *GalleryUnderline;
    QLabel *namePos3;
    QLabel *namePos4;
    QLabel *namePos2;
    QLabel *namePos1;
    QPushButton *buttonPos1;
    QPushButton *buttonPos2;
    QPushButton *buttonPos3;
    QPushButton *buttonPos4;
    QLabel *GalleryHeader;
    QLabel *ImageSettings;
    QPushButton *restoreSettingsButton;
    QLabel *Divider1;
    QTextEdit *updateNameBox;
    QPushButton *FlatFieldButton;
    QWidget *widget_6;
    QSlider *edgeEnhancementSlider;
    QLineEdit *edgeEnhancementValueInput;
    QLabel *ControlPanelHeader;
    QCheckBox *grayScaleBox;
    QCheckBox *dilationCheckBox;
    QCheckBox *erosionCheckBox;
    QLineEdit *contrastEnhancementValueInput;
    QSlider *contrastEnhancementSlider;
    QLabel *ContrastEhnancement;
    QLabel *edgeDetectionLabel;
    QSlider *exposureSlider;
    QLineEdit *exposureValueInput;
    QLabel *edgeDetectionLabel_2;
    QCheckBox *flatFieldBox;
    QWidget *motorControlColumn;
    QLabel *MotorControls;
    QLabel *MotorControlUnderline;
    QLabel *xAxisControlHeader;
    QLabel *yAxisControlHeader;
    QLabel *zAxisControlHeader;
    QLabel *MotorControlUnderline_2;
    QPushButton *xDownButton;
    QPushButton *xUpButton;
    QLineEdit *xPos;
    QPushButton *yDownButton;
    QPushButton *yUpButton;
    QLineEdit *yPos;
    QLineEdit *zPos;
    QPushButton *zUpButton;
    QPushButton *zDownButton;
    QLabel *motorDisableText;
    QMenuBar *menubar;
    QMenu *menuOpenflexure;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *GUI)
    {
        if (GUI->objectName().isEmpty())
            GUI->setObjectName(QString::fromUtf8("GUI"));
        GUI->resize(1493, 943);
        centralwidget = new QWidget(GUI);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8("#centralWidget {\n"
"background-color:#FF121212}"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 1651, 80));
        widget->setStyleSheet(QString::fromUtf8("\n"
"	background-color: rgb(179, 179, 179);\n"
""));
        cellUview = new QLabel(widget);
        cellUview->setObjectName(QString::fromUtf8("cellUview"));
        cellUview->setGeometry(QRect(0, 19, 1651, 41));
        cellUview->setStyleSheet(QString::fromUtf8("font: 700 11pt \"Ubuntu\";"));
        cellUview->setAlignment(Qt::AlignCenter);
        background = new QWidget(centralwidget);
        background->setObjectName(QString::fromUtf8("background"));
        background->setGeometry(QRect(0, 80, 1651, 831));
        background->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(18, 18, 18);"));
        scopeVideoFeed = new QLabel(background);
        scopeVideoFeed->setObjectName(QString::fromUtf8("scopeVideoFeed"));
        scopeVideoFeed->setGeometry(QRect(500, 20, 641, 461));
        ImageCaptureColumn = new QWidget(background);
        ImageCaptureColumn->setObjectName(QString::fromUtf8("ImageCaptureColumn"));
        ImageCaptureColumn->setGeometry(QRect(10, 20, 471, 781));
        ImageCaptureColumn->setStyleSheet(QString::fromUtf8("background-color: rgb(33, 33, 33);"));
        captureButton = new QPushButton(ImageCaptureColumn);
        captureButton->setObjectName(QString::fromUtf8("captureButton"));
        captureButton->setGeometry(QRect(30, 720, 410, 40));
        captureButton->setStyleSheet(QString::fromUtf8("background-color: rgb(179, 179, 179);"));
        ImageHolder = new QWidget(ImageCaptureColumn);
        ImageHolder->setObjectName(QString::fromUtf8("ImageHolder"));
        ImageHolder->setGeometry(QRect(30, 60, 410, 471));
        ImageHolder->setStyleSheet(QString::fromUtf8("background-color: rgb(33, 33, 33);"));
        galleryPos1 = new QLabel(ImageHolder);
        galleryPos1->setObjectName(QString::fromUtf8("galleryPos1"));
        galleryPos1->setGeometry(QRect(0, 20, 191, 191));
        galleryPos2 = new QLabel(ImageHolder);
        galleryPos2->setObjectName(QString::fromUtf8("galleryPos2"));
        galleryPos2->setGeometry(QRect(220, 20, 191, 191));
        nextButton = new QPushButton(ImageHolder);
        nextButton->setObjectName(QString::fromUtf8("nextButton"));
        nextButton->setGeometry(QRect(210, 440, 51, 25));
        nextButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        backButton = new QPushButton(ImageHolder);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        backButton->setGeometry(QRect(150, 440, 51, 25));
        backButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        galleryPos4 = new QLabel(ImageHolder);
        galleryPos4->setObjectName(QString::fromUtf8("galleryPos4"));
        galleryPos4->setGeometry(QRect(220, 240, 191, 181));
        galleryPos3 = new QLabel(ImageHolder);
        galleryPos3->setObjectName(QString::fromUtf8("galleryPos3"));
        galleryPos3->setGeometry(QRect(0, 240, 191, 181));
        GalleryUnderline = new QLabel(ImageHolder);
        GalleryUnderline->setObjectName(QString::fromUtf8("GalleryUnderline"));
        GalleryUnderline->setGeometry(QRect(-1, 5, 410, 5));
        GalleryUnderline->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(83, 83, 83);"));
        GalleryUnderline->setAlignment(Qt::AlignCenter);
        namePos3 = new QLabel(ImageHolder);
        namePos3->setObjectName(QString::fromUtf8("namePos3"));
        namePos3->setGeometry(QRect(0, 400, 191, 20));
        namePos3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        namePos4 = new QLabel(ImageHolder);
        namePos4->setObjectName(QString::fromUtf8("namePos4"));
        namePos4->setGeometry(QRect(216, 400, 201, 20));
        namePos4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        namePos2 = new QLabel(ImageHolder);
        namePos2->setObjectName(QString::fromUtf8("namePos2"));
        namePos2->setGeometry(QRect(216, 190, 191, 21));
        namePos2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        namePos1 = new QLabel(ImageHolder);
        namePos1->setObjectName(QString::fromUtf8("namePos1"));
        namePos1->setGeometry(QRect(0, 190, 191, 21));
        namePos1->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        buttonPos1 = new QPushButton(ImageHolder);
        buttonPos1->setObjectName(QString::fromUtf8("buttonPos1"));
        buttonPos1->setGeometry(QRect(0, 50, 191, 121));
        buttonPos1->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border: none;"));
        buttonPos2 = new QPushButton(ImageHolder);
        buttonPos2->setObjectName(QString::fromUtf8("buttonPos2"));
        buttonPos2->setGeometry(QRect(220, 50, 191, 121));
        buttonPos2->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border: none;"));
        buttonPos3 = new QPushButton(ImageHolder);
        buttonPos3->setObjectName(QString::fromUtf8("buttonPos3"));
        buttonPos3->setGeometry(QRect(0, 270, 191, 121));
        buttonPos3->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border: none;"));
        buttonPos4 = new QPushButton(ImageHolder);
        buttonPos4->setObjectName(QString::fromUtf8("buttonPos4"));
        buttonPos4->setGeometry(QRect(220, 270, 191, 121));
        buttonPos4->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border: none;"));
        GalleryHeader = new QLabel(ImageCaptureColumn);
        GalleryHeader->setObjectName(QString::fromUtf8("GalleryHeader"));
        GalleryHeader->setGeometry(QRect(30, 20, 410, 41));
        GalleryHeader->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(83, 83, 83);"));
        GalleryHeader->setAlignment(Qt::AlignCenter);
        ImageSettings = new QLabel(ImageCaptureColumn);
        ImageSettings->setObjectName(QString::fromUtf8("ImageSettings"));
        ImageSettings->setGeometry(QRect(30, 540, 410, 25));
        ImageSettings->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(83, 83, 83);"));
        ImageSettings->setAlignment(Qt::AlignCenter);
        restoreSettingsButton = new QPushButton(ImageCaptureColumn);
        restoreSettingsButton->setObjectName(QString::fromUtf8("restoreSettingsButton"));
        restoreSettingsButton->setGeometry(QRect(30, 660, 411, 31));
        restoreSettingsButton->setStyleSheet(QString::fromUtf8("background-color: rgb(179, 179, 179);"));
        Divider1 = new QLabel(ImageCaptureColumn);
        Divider1->setObjectName(QString::fromUtf8("Divider1"));
        Divider1->setGeometry(QRect(30, 703, 410, 5));
        Divider1->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(83, 83, 83);"));
        Divider1->setAlignment(Qt::AlignCenter);
        updateNameBox = new QTextEdit(ImageCaptureColumn);
        updateNameBox->setObjectName(QString::fromUtf8("updateNameBox"));
        updateNameBox->setGeometry(QRect(30, 570, 411, 31));
        updateNameBox->setStyleSheet(QString::fromUtf8("background-color: rgb(179, 179, 179);"));
        FlatFieldButton = new QPushButton(ImageCaptureColumn);
        FlatFieldButton->setObjectName(QString::fromUtf8("FlatFieldButton"));
        FlatFieldButton->setGeometry(QRect(30, 610, 411, 41));
        FlatFieldButton->setStyleSheet(QString::fromUtf8("background-color: rgb(179, 179, 179);"));
        widget_6 = new QWidget(background);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        widget_6->setGeometry(QRect(500, 520, 641, 281));
        widget_6->setStyleSheet(QString::fromUtf8("background-color: rgb(33, 33, 33);"));
        edgeEnhancementSlider = new QSlider(widget_6);
        edgeEnhancementSlider->setObjectName(QString::fromUtf8("edgeEnhancementSlider"));
        edgeEnhancementSlider->setGeometry(QRect(10, 190, 341, 31));
        edgeEnhancementSlider->setStyleSheet(QString::fromUtf8("QSlider::handle:horizontal {\n"
"    background-color: rgb(29, 185, 84);\n"
"}\n"
""));
        edgeEnhancementSlider->setOrientation(Qt::Horizontal);
        edgeEnhancementValueInput = new QLineEdit(widget_6);
        edgeEnhancementValueInput->setObjectName(QString::fromUtf8("edgeEnhancementValueInput"));
        edgeEnhancementValueInput->setGeometry(QRect(370, 190, 71, 31));
        edgeEnhancementValueInput->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(179, 179, 179);"));
        ControlPanelHeader = new QLabel(widget_6);
        ControlPanelHeader->setObjectName(QString::fromUtf8("ControlPanelHeader"));
        ControlPanelHeader->setGeometry(QRect(-4, -4, 651, 40));
        ControlPanelHeader->setStyleSheet(QString::fromUtf8("background-color: rgb(83, 83, 83);\n"
"color: rgb(255, 255, 255);"));
        ControlPanelHeader->setAlignment(Qt::AlignCenter);
        grayScaleBox = new QCheckBox(widget_6);
        grayScaleBox->setObjectName(QString::fromUtf8("grayScaleBox"));
        grayScaleBox->setGeometry(QRect(30, 60, 92, 23));
        grayScaleBox->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"\n"
"QCheckBox::indicator {\n"
"    background-color: red;\n"
"    border: 2px solid black;\n"
"}\n"
"\n"
""));
        dilationCheckBox = new QCheckBox(widget_6);
        dilationCheckBox->setObjectName(QString::fromUtf8("dilationCheckBox"));
        dilationCheckBox->setGeometry(QRect(30, 90, 92, 23));
        dilationCheckBox->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        erosionCheckBox = new QCheckBox(widget_6);
        erosionCheckBox->setObjectName(QString::fromUtf8("erosionCheckBox"));
        erosionCheckBox->setGeometry(QRect(130, 60, 92, 23));
        erosionCheckBox->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        contrastEnhancementValueInput = new QLineEdit(widget_6);
        contrastEnhancementValueInput->setObjectName(QString::fromUtf8("contrastEnhancementValueInput"));
        contrastEnhancementValueInput->setGeometry(QRect(370, 230, 71, 31));
        contrastEnhancementValueInput->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(179, 179, 179);"));
        contrastEnhancementSlider = new QSlider(widget_6);
        contrastEnhancementSlider->setObjectName(QString::fromUtf8("contrastEnhancementSlider"));
        contrastEnhancementSlider->setGeometry(QRect(10, 230, 341, 31));
        contrastEnhancementSlider->setStyleSheet(QString::fromUtf8("QSlider::handle:horizontal {\n"
"    background-color: rgb(29, 185, 84);\n"
"}\n"
""));
        contrastEnhancementSlider->setMaximum(99);
        contrastEnhancementSlider->setOrientation(Qt::Horizontal);
        ContrastEhnancement = new QLabel(widget_6);
        ContrastEhnancement->setObjectName(QString::fromUtf8("ContrastEhnancement"));
        ContrastEhnancement->setGeometry(QRect(460, 230, 161, 21));
        ContrastEhnancement->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        edgeDetectionLabel = new QLabel(widget_6);
        edgeDetectionLabel->setObjectName(QString::fromUtf8("edgeDetectionLabel"));
        edgeDetectionLabel->setGeometry(QRect(460, 190, 111, 21));
        edgeDetectionLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        exposureSlider = new QSlider(widget_6);
        exposureSlider->setObjectName(QString::fromUtf8("exposureSlider"));
        exposureSlider->setGeometry(QRect(10, 150, 341, 31));
        exposureSlider->setStyleSheet(QString::fromUtf8("QSlider::handle:horizontal {\n"
"    background-color: rgb(29, 185, 84);\n"
"}\n"
""));
        exposureSlider->setOrientation(Qt::Horizontal);
        exposureValueInput = new QLineEdit(widget_6);
        exposureValueInput->setObjectName(QString::fromUtf8("exposureValueInput"));
        exposureValueInput->setGeometry(QRect(370, 150, 71, 31));
        exposureValueInput->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(179, 179, 179);"));
        edgeDetectionLabel_2 = new QLabel(widget_6);
        edgeDetectionLabel_2->setObjectName(QString::fromUtf8("edgeDetectionLabel_2"));
        edgeDetectionLabel_2->setGeometry(QRect(460, 150, 111, 21));
        edgeDetectionLabel_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        flatFieldBox = new QCheckBox(widget_6);
        flatFieldBox->setObjectName(QString::fromUtf8("flatFieldBox"));
        flatFieldBox->setGeometry(QRect(451, 60, 171, 23));
        motorControlColumn = new QWidget(background);
        motorControlColumn->setObjectName(QString::fromUtf8("motorControlColumn"));
        motorControlColumn->setGeometry(QRect(1160, 20, 311, 781));
        motorControlColumn->setStyleSheet(QString::fromUtf8("background-color: rgb(33, 33, 33);"));
        MotorControls = new QLabel(motorControlColumn);
        MotorControls->setObjectName(QString::fromUtf8("MotorControls"));
        MotorControls->setGeometry(QRect(15, 20, 280, 41));
        MotorControls->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(83, 83, 83);"));
        MotorControls->setAlignment(Qt::AlignCenter);
        MotorControlUnderline = new QLabel(motorControlColumn);
        MotorControlUnderline->setObjectName(QString::fromUtf8("MotorControlUnderline"));
        MotorControlUnderline->setGeometry(QRect(15, 65, 280, 5));
        MotorControlUnderline->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(83, 83, 83);"));
        MotorControlUnderline->setAlignment(Qt::AlignCenter);
        xAxisControlHeader = new QLabel(motorControlColumn);
        xAxisControlHeader->setObjectName(QString::fromUtf8("xAxisControlHeader"));
        xAxisControlHeader->setGeometry(QRect(15, 80, 280, 25));
        xAxisControlHeader->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(83, 83, 83);"));
        xAxisControlHeader->setAlignment(Qt::AlignCenter);
        yAxisControlHeader = new QLabel(motorControlColumn);
        yAxisControlHeader->setObjectName(QString::fromUtf8("yAxisControlHeader"));
        yAxisControlHeader->setGeometry(QRect(15, 170, 280, 25));
        yAxisControlHeader->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(83, 83, 83);"));
        yAxisControlHeader->setAlignment(Qt::AlignCenter);
        zAxisControlHeader = new QLabel(motorControlColumn);
        zAxisControlHeader->setObjectName(QString::fromUtf8("zAxisControlHeader"));
        zAxisControlHeader->setGeometry(QRect(15, 260, 280, 25));
        zAxisControlHeader->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(83, 83, 83);"));
        zAxisControlHeader->setAlignment(Qt::AlignCenter);
        MotorControlUnderline_2 = new QLabel(motorControlColumn);
        MotorControlUnderline_2->setObjectName(QString::fromUtf8("MotorControlUnderline_2"));
        MotorControlUnderline_2->setGeometry(QRect(15, 350, 280, 5));
        MotorControlUnderline_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(83, 83, 83);"));
        MotorControlUnderline_2->setAlignment(Qt::AlignCenter);
        xDownButton = new QPushButton(motorControlColumn);
        xDownButton->setObjectName(QString::fromUtf8("xDownButton"));
        xDownButton->setGeometry(QRect(60, 120, 41, 31));
        xDownButton->setStyleSheet(QString::fromUtf8("background-color: rgb(179, 179, 179);\n"
"\n"
"disabled {\n"
"    background-color: gray;\n"
"}"));
        xUpButton = new QPushButton(motorControlColumn);
        xUpButton->setObjectName(QString::fromUtf8("xUpButton"));
        xUpButton->setGeometry(QRect(210, 120, 41, 31));
        xUpButton->setStyleSheet(QString::fromUtf8("background-color: rgb(179, 179, 179);"));
        xPos = new QLineEdit(motorControlColumn);
        xPos->setObjectName(QString::fromUtf8("xPos"));
        xPos->setGeometry(QRect(115, 120, 81, 31));
        xPos->setStyleSheet(QString::fromUtf8("background-color: rgb(179, 179, 179);"));
        yDownButton = new QPushButton(motorControlColumn);
        yDownButton->setObjectName(QString::fromUtf8("yDownButton"));
        yDownButton->setGeometry(QRect(60, 210, 41, 31));
        yDownButton->setStyleSheet(QString::fromUtf8("background-color: rgb(179, 179, 179);"));
        yUpButton = new QPushButton(motorControlColumn);
        yUpButton->setObjectName(QString::fromUtf8("yUpButton"));
        yUpButton->setGeometry(QRect(210, 210, 41, 31));
        yUpButton->setStyleSheet(QString::fromUtf8("background-color: rgb(179, 179, 179);"));
        yPos = new QLineEdit(motorControlColumn);
        yPos->setObjectName(QString::fromUtf8("yPos"));
        yPos->setGeometry(QRect(115, 210, 81, 31));
        yPos->setStyleSheet(QString::fromUtf8("background-color: rgb(179, 179, 179);"));
        zPos = new QLineEdit(motorControlColumn);
        zPos->setObjectName(QString::fromUtf8("zPos"));
        zPos->setGeometry(QRect(115, 300, 81, 31));
        zPos->setStyleSheet(QString::fromUtf8("background-color: rgb(179, 179, 179);"));
        zUpButton = new QPushButton(motorControlColumn);
        zUpButton->setObjectName(QString::fromUtf8("zUpButton"));
        zUpButton->setGeometry(QRect(210, 300, 41, 31));
        zUpButton->setStyleSheet(QString::fromUtf8("background-color: rgb(179, 179, 179);"));
        zDownButton = new QPushButton(motorControlColumn);
        zDownButton->setObjectName(QString::fromUtf8("zDownButton"));
        zDownButton->setGeometry(QRect(60, 300, 41, 31));
        zDownButton->setStyleSheet(QString::fromUtf8("background-color: rgb(179, 179, 179);"));
        motorDisableText = new QLabel(motorControlColumn);
        motorDisableText->setObjectName(QString::fromUtf8("motorDisableText"));
        motorDisableText->setGeometry(QRect(6, 76, 301, 261));
        motorDisableText->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        GUI->setCentralWidget(centralwidget);
        menubar = new QMenuBar(GUI);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1493, 22));
        menuOpenflexure = new QMenu(menubar);
        menuOpenflexure->setObjectName(QString::fromUtf8("menuOpenflexure"));
        GUI->setMenuBar(menubar);
        statusbar = new QStatusBar(GUI);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        GUI->setStatusBar(statusbar);

        menubar->addAction(menuOpenflexure->menuAction());

        retranslateUi(GUI);

        QMetaObject::connectSlotsByName(GUI);
    } // setupUi

    void retranslateUi(QMainWindow *GUI)
    {
        GUI->setWindowTitle(QCoreApplication::translate("GUI", "cellUview", nullptr));
        cellUview->setText(QCoreApplication::translate("GUI", "<html><head/><body><p><span style=\" font-size:20pt; font-weight:700;\">cellUview</span></p></body></html>", nullptr));
        scopeVideoFeed->setText(QString());
        captureButton->setText(QCoreApplication::translate("GUI", "Capture Image", nullptr));
        galleryPos1->setText(QString());
        galleryPos2->setText(QString());
        nextButton->setText(QCoreApplication::translate("GUI", "Next", nullptr));
        backButton->setText(QCoreApplication::translate("GUI", "Back", nullptr));
        galleryPos4->setText(QString());
        galleryPos3->setText(QString());
        GalleryUnderline->setText(QCoreApplication::translate("GUI", "<html><head/><body><p><br/></p></body></html>", nullptr));
        namePos3->setText(QString());
        namePos4->setText(QString());
        namePos2->setText(QString());
        namePos1->setText(QString());
        buttonPos1->setText(QString());
        buttonPos2->setText(QString());
        buttonPos3->setText(QString());
        buttonPos4->setText(QString());
        GalleryHeader->setText(QCoreApplication::translate("GUI", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700;\">Gallery</span></p></body></html>", nullptr));
        ImageSettings->setText(QCoreApplication::translate("GUI", "<html><head/><body><p><span style=\" font-weight:700;\">Capture Name</span></p></body></html>", nullptr));
        restoreSettingsButton->setText(QCoreApplication::translate("GUI", "Restore Settings", nullptr));
        Divider1->setText(QCoreApplication::translate("GUI", "<html><head/><body><p><br/></p></body></html>", nullptr));
        FlatFieldButton->setText(QCoreApplication::translate("GUI", "Flat Field Capture (Capture with empty slide)", nullptr));
        edgeEnhancementValueInput->setText(QString());
        ControlPanelHeader->setText(QCoreApplication::translate("GUI", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700;\">Control Panel</span></p></body></html>", nullptr));
        grayScaleBox->setText(QCoreApplication::translate("GUI", "Grey Scale", nullptr));
        dilationCheckBox->setText(QCoreApplication::translate("GUI", "Dilation", nullptr));
        erosionCheckBox->setText(QCoreApplication::translate("GUI", "Erosion", nullptr));
        contrastEnhancementValueInput->setText(QString());
        ContrastEhnancement->setText(QCoreApplication::translate("GUI", "Contrast Enhancement", nullptr));
        edgeDetectionLabel->setText(QCoreApplication::translate("GUI", "Edge Detection", nullptr));
        exposureValueInput->setText(QString());
        edgeDetectionLabel_2->setText(QCoreApplication::translate("GUI", "Exposure(EV)", nullptr));
        flatFieldBox->setText(QCoreApplication::translate("GUI", "Flat Field Correction", nullptr));
        MotorControls->setText(QCoreApplication::translate("GUI", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700;\">Motor Controls</span></p></body></html>", nullptr));
        MotorControlUnderline->setText(QCoreApplication::translate("GUI", "<html><head/><body><p><br/></p></body></html>", nullptr));
        xAxisControlHeader->setText(QCoreApplication::translate("GUI", "<html><head/><body><p>X-axis Controls</p></body></html>", nullptr));
        yAxisControlHeader->setText(QCoreApplication::translate("GUI", "<html><head/><body><p>Y-axis Controls</p></body></html>", nullptr));
        zAxisControlHeader->setText(QCoreApplication::translate("GUI", "<html><head/><body><p>Z-axis Controls</p></body></html>", nullptr));
        MotorControlUnderline_2->setText(QCoreApplication::translate("GUI", "<html><head/><body><p><br/></p></body></html>", nullptr));
        xDownButton->setText(QCoreApplication::translate("GUI", "-", nullptr));
        xUpButton->setText(QCoreApplication::translate("GUI", "+", nullptr));
        yDownButton->setText(QCoreApplication::translate("GUI", "-", nullptr));
        yUpButton->setText(QCoreApplication::translate("GUI", "+", nullptr));
        zUpButton->setText(QCoreApplication::translate("GUI", "+", nullptr));
        zDownButton->setText(QCoreApplication::translate("GUI", "-", nullptr));
        motorDisableText->setText(QCoreApplication::translate("GUI", "<html><head/><body><p align=\"center\">Motors are not connected</p><p align=\"center\">Manual operation only</p></body></html>", nullptr));
        menuOpenflexure->setTitle(QCoreApplication::translate("GUI", "cellUview", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GUI: public Ui_GUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
