/********************************************************************************
** Form generated from reading UI file 'gui.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_H
#define UI_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
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
    QLabel *kMeansLabel;
    QSlider *kMeansSlider;
    QLineEdit *kMeansValueInput;
    QPushButton *kMeansPercentage;
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
            GUI->setObjectName(QStringLiteral("GUI"));
        GUI->resize(1493, 943);
        centralwidget = new QWidget(GUI);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        centralwidget->setStyleSheet(QLatin1String("#centralWidget {\n"
"background-color:#FF121212}"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 1651, 80));
        widget->setStyleSheet(QLatin1String("\n"
"	background-color: rgb(179, 179, 179);\n"
""));
        cellUview = new QLabel(widget);
        cellUview->setObjectName(QStringLiteral("cellUview"));
        cellUview->setGeometry(QRect(0, 19, 1651, 41));
        cellUview->setStyleSheet(QStringLiteral("font: 700 11pt \"Ubuntu\";"));
        cellUview->setAlignment(Qt::AlignCenter);
        background = new QWidget(centralwidget);
        background->setObjectName(QStringLiteral("background"));
        background->setGeometry(QRect(0, 80, 1651, 831));
        background->setStyleSheet(QLatin1String("\n"
"background-color: rgb(18, 18, 18);"));
        scopeVideoFeed = new QLabel(background);
        scopeVideoFeed->setObjectName(QStringLiteral("scopeVideoFeed"));
        scopeVideoFeed->setGeometry(QRect(500, 20, 641, 461));
        ImageCaptureColumn = new QWidget(background);
        ImageCaptureColumn->setObjectName(QStringLiteral("ImageCaptureColumn"));
        ImageCaptureColumn->setGeometry(QRect(10, 20, 471, 781));
        ImageCaptureColumn->setStyleSheet(QStringLiteral("background-color: rgb(33, 33, 33);"));
        captureButton = new QPushButton(ImageCaptureColumn);
        captureButton->setObjectName(QStringLiteral("captureButton"));
        captureButton->setGeometry(QRect(30, 720, 410, 40));
        captureButton->setStyleSheet(QStringLiteral("background-color: rgb(179, 179, 179);"));
        ImageHolder = new QWidget(ImageCaptureColumn);
        ImageHolder->setObjectName(QStringLiteral("ImageHolder"));
        ImageHolder->setGeometry(QRect(30, 60, 410, 471));
        ImageHolder->setStyleSheet(QStringLiteral("background-color: rgb(33, 33, 33);"));
        galleryPos1 = new QLabel(ImageHolder);
        galleryPos1->setObjectName(QStringLiteral("galleryPos1"));
        galleryPos1->setGeometry(QRect(0, 20, 191, 191));
        galleryPos2 = new QLabel(ImageHolder);
        galleryPos2->setObjectName(QStringLiteral("galleryPos2"));
        galleryPos2->setGeometry(QRect(220, 20, 191, 191));
        nextButton = new QPushButton(ImageHolder);
        nextButton->setObjectName(QStringLiteral("nextButton"));
        nextButton->setGeometry(QRect(210, 440, 51, 25));
        nextButton->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        backButton = new QPushButton(ImageHolder);
        backButton->setObjectName(QStringLiteral("backButton"));
        backButton->setGeometry(QRect(150, 440, 51, 25));
        backButton->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        galleryPos4 = new QLabel(ImageHolder);
        galleryPos4->setObjectName(QStringLiteral("galleryPos4"));
        galleryPos4->setGeometry(QRect(220, 240, 191, 181));
        galleryPos3 = new QLabel(ImageHolder);
        galleryPos3->setObjectName(QStringLiteral("galleryPos3"));
        galleryPos3->setGeometry(QRect(0, 240, 191, 181));
        GalleryUnderline = new QLabel(ImageHolder);
        GalleryUnderline->setObjectName(QStringLiteral("GalleryUnderline"));
        GalleryUnderline->setGeometry(QRect(-1, 5, 410, 5));
        GalleryUnderline->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(83, 83, 83);"));
        GalleryUnderline->setAlignment(Qt::AlignCenter);
        namePos3 = new QLabel(ImageHolder);
        namePos3->setObjectName(QStringLiteral("namePos3"));
        namePos3->setGeometry(QRect(0, 400, 191, 20));
        namePos3->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        namePos4 = new QLabel(ImageHolder);
        namePos4->setObjectName(QStringLiteral("namePos4"));
        namePos4->setGeometry(QRect(216, 400, 201, 20));
        namePos4->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        namePos2 = new QLabel(ImageHolder);
        namePos2->setObjectName(QStringLiteral("namePos2"));
        namePos2->setGeometry(QRect(216, 190, 191, 21));
        namePos2->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        namePos1 = new QLabel(ImageHolder);
        namePos1->setObjectName(QStringLiteral("namePos1"));
        namePos1->setGeometry(QRect(0, 190, 191, 21));
        namePos1->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        buttonPos1 = new QPushButton(ImageHolder);
        buttonPos1->setObjectName(QStringLiteral("buttonPos1"));
        buttonPos1->setGeometry(QRect(0, 50, 191, 121));
        buttonPos1->setStyleSheet(QLatin1String("background-color: transparent;\n"
"border: none;"));
        buttonPos2 = new QPushButton(ImageHolder);
        buttonPos2->setObjectName(QStringLiteral("buttonPos2"));
        buttonPos2->setGeometry(QRect(220, 50, 191, 121));
        buttonPos2->setStyleSheet(QLatin1String("background-color: transparent;\n"
"border: none;"));
        buttonPos3 = new QPushButton(ImageHolder);
        buttonPos3->setObjectName(QStringLiteral("buttonPos3"));
        buttonPos3->setGeometry(QRect(0, 270, 191, 121));
        buttonPos3->setStyleSheet(QLatin1String("background-color: transparent;\n"
"border: none;"));
        buttonPos4 = new QPushButton(ImageHolder);
        buttonPos4->setObjectName(QStringLiteral("buttonPos4"));
        buttonPos4->setGeometry(QRect(220, 270, 191, 121));
        buttonPos4->setStyleSheet(QLatin1String("background-color: transparent;\n"
"border: none;"));
        GalleryHeader = new QLabel(ImageCaptureColumn);
        GalleryHeader->setObjectName(QStringLiteral("GalleryHeader"));
        GalleryHeader->setGeometry(QRect(30, 20, 410, 41));
        GalleryHeader->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(83, 83, 83);"));
        GalleryHeader->setAlignment(Qt::AlignCenter);
        ImageSettings = new QLabel(ImageCaptureColumn);
        ImageSettings->setObjectName(QStringLiteral("ImageSettings"));
        ImageSettings->setGeometry(QRect(30, 540, 410, 25));
        ImageSettings->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(83, 83, 83);"));
        ImageSettings->setAlignment(Qt::AlignCenter);
        restoreSettingsButton = new QPushButton(ImageCaptureColumn);
        restoreSettingsButton->setObjectName(QStringLiteral("restoreSettingsButton"));
        restoreSettingsButton->setGeometry(QRect(30, 660, 411, 31));
        restoreSettingsButton->setStyleSheet(QStringLiteral("background-color: rgb(179, 179, 179);"));
        Divider1 = new QLabel(ImageCaptureColumn);
        Divider1->setObjectName(QStringLiteral("Divider1"));
        Divider1->setGeometry(QRect(30, 703, 410, 5));
        Divider1->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(83, 83, 83);"));
        Divider1->setAlignment(Qt::AlignCenter);
        updateNameBox = new QTextEdit(ImageCaptureColumn);
        updateNameBox->setObjectName(QStringLiteral("updateNameBox"));
        updateNameBox->setGeometry(QRect(30, 570, 411, 31));
        updateNameBox->setStyleSheet(QStringLiteral("background-color: rgb(179, 179, 179);"));
        FlatFieldButton = new QPushButton(ImageCaptureColumn);
        FlatFieldButton->setObjectName(QStringLiteral("FlatFieldButton"));
        FlatFieldButton->setGeometry(QRect(30, 610, 411, 41));
        FlatFieldButton->setStyleSheet(QStringLiteral("background-color: rgb(179, 179, 179);"));
        widget_6 = new QWidget(background);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        widget_6->setGeometry(QRect(500, 520, 641, 281));
        widget_6->setStyleSheet(QStringLiteral("background-color: rgb(33, 33, 33);"));
        edgeEnhancementSlider = new QSlider(widget_6);
        edgeEnhancementSlider->setObjectName(QStringLiteral("edgeEnhancementSlider"));
        edgeEnhancementSlider->setGeometry(QRect(10, 210, 341, 31));
        edgeEnhancementSlider->setStyleSheet(QLatin1String("QSlider::handle:horizontal {\n"
"    background-color: rgb(29, 185, 84);\n"
"}\n"
""));
        edgeEnhancementSlider->setOrientation(Qt::Horizontal);
        edgeEnhancementValueInput = new QLineEdit(widget_6);
        edgeEnhancementValueInput->setObjectName(QStringLiteral("edgeEnhancementValueInput"));
        edgeEnhancementValueInput->setGeometry(QRect(370, 210, 71, 31));
        edgeEnhancementValueInput->setStyleSheet(QLatin1String("\n"
"background-color: rgb(179, 179, 179);"));
        ControlPanelHeader = new QLabel(widget_6);
        ControlPanelHeader->setObjectName(QStringLiteral("ControlPanelHeader"));
        ControlPanelHeader->setGeometry(QRect(-4, -4, 651, 40));
        ControlPanelHeader->setStyleSheet(QLatin1String("background-color: rgb(83, 83, 83);\n"
"color: rgb(255, 255, 255);"));
        ControlPanelHeader->setAlignment(Qt::AlignCenter);
        grayScaleBox = new QCheckBox(widget_6);
        grayScaleBox->setObjectName(QStringLiteral("grayScaleBox"));
        grayScaleBox->setGeometry(QRect(30, 60, 101, 23));
        grayScaleBox->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"\n"
"QCheckBox::indicator {\n"
"    background-color: red;\n"
"    border: 2px solid black;\n"
"}\n"
"\n"
""));
        dilationCheckBox = new QCheckBox(widget_6);
        dilationCheckBox->setObjectName(QStringLiteral("dilationCheckBox"));
        dilationCheckBox->setGeometry(QRect(240, 60, 92, 23));
        dilationCheckBox->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        erosionCheckBox = new QCheckBox(widget_6);
        erosionCheckBox->setObjectName(QStringLiteral("erosionCheckBox"));
        erosionCheckBox->setGeometry(QRect(140, 60, 92, 23));
        erosionCheckBox->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        contrastEnhancementValueInput = new QLineEdit(widget_6);
        contrastEnhancementValueInput->setObjectName(QStringLiteral("contrastEnhancementValueInput"));
        contrastEnhancementValueInput->setGeometry(QRect(370, 250, 71, 31));
        contrastEnhancementValueInput->setStyleSheet(QLatin1String("\n"
"background-color: rgb(179, 179, 179);"));
        contrastEnhancementSlider = new QSlider(widget_6);
        contrastEnhancementSlider->setObjectName(QStringLiteral("contrastEnhancementSlider"));
        contrastEnhancementSlider->setGeometry(QRect(10, 250, 341, 31));
        contrastEnhancementSlider->setStyleSheet(QLatin1String("QSlider::handle:horizontal {\n"
"    background-color: rgb(29, 185, 84);\n"
"}\n"
""));
        contrastEnhancementSlider->setMaximum(99);
        contrastEnhancementSlider->setOrientation(Qt::Horizontal);
        ContrastEhnancement = new QLabel(widget_6);
        ContrastEhnancement->setObjectName(QStringLiteral("ContrastEhnancement"));
        ContrastEhnancement->setGeometry(QRect(460, 250, 161, 21));
        ContrastEhnancement->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        edgeDetectionLabel = new QLabel(widget_6);
        edgeDetectionLabel->setObjectName(QStringLiteral("edgeDetectionLabel"));
        edgeDetectionLabel->setGeometry(QRect(460, 210, 111, 21));
        edgeDetectionLabel->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        exposureSlider = new QSlider(widget_6);
        exposureSlider->setObjectName(QStringLiteral("exposureSlider"));
        exposureSlider->setGeometry(QRect(10, 170, 341, 31));
        exposureSlider->setStyleSheet(QLatin1String("QSlider::handle:horizontal {\n"
"    background-color: rgb(29, 185, 84);\n"
"}\n"
""));
        exposureSlider->setOrientation(Qt::Horizontal);
        exposureValueInput = new QLineEdit(widget_6);
        exposureValueInput->setObjectName(QStringLiteral("exposureValueInput"));
        exposureValueInput->setGeometry(QRect(370, 170, 71, 31));
        exposureValueInput->setStyleSheet(QLatin1String("\n"
"background-color: rgb(179, 179, 179);"));
        edgeDetectionLabel_2 = new QLabel(widget_6);
        edgeDetectionLabel_2->setObjectName(QStringLiteral("edgeDetectionLabel_2"));
        edgeDetectionLabel_2->setGeometry(QRect(460, 170, 111, 21));
        edgeDetectionLabel_2->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        flatFieldBox = new QCheckBox(widget_6);
        flatFieldBox->setObjectName(QStringLiteral("flatFieldBox"));
        flatFieldBox->setGeometry(QRect(451, 60, 171, 23));
        kMeansLabel = new QLabel(widget_6);
        kMeansLabel->setObjectName(QStringLiteral("kMeansLabel"));
        kMeansLabel->setGeometry(QRect(460, 130, 161, 21));
        kMeansLabel->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        kMeansSlider = new QSlider(widget_6);
        kMeansSlider->setObjectName(QStringLiteral("kMeansSlider"));
        kMeansSlider->setGeometry(QRect(10, 130, 341, 31));
        kMeansSlider->setStyleSheet(QLatin1String("QSlider::handle:horizontal {\n"
"    background-color: rgb(29, 185, 84);\n"
"}\n"
""));
        kMeansSlider->setMaximum(5);
        kMeansSlider->setPageStep(5);
        kMeansSlider->setOrientation(Qt::Horizontal);
        kMeansValueInput = new QLineEdit(widget_6);
        kMeansValueInput->setObjectName(QStringLiteral("kMeansValueInput"));
        kMeansValueInput->setGeometry(QRect(370, 130, 71, 31));
        kMeansValueInput->setStyleSheet(QLatin1String("\n"
"background-color: rgb(179, 179, 179);"));
        kMeansPercentage = new QPushButton(widget_6);
        kMeansPercentage->setObjectName(QStringLiteral("kMeansPercentage"));
        kMeansPercentage->setGeometry(QRect(270, 90, 361, 41));
        kMeansPercentage->setStyleSheet(QStringLiteral("background-color: rgb(179, 179, 179);"));
        motorControlColumn = new QWidget(background);
        motorControlColumn->setObjectName(QStringLiteral("motorControlColumn"));
        motorControlColumn->setGeometry(QRect(1160, 20, 311, 781));
        motorControlColumn->setStyleSheet(QStringLiteral("background-color: rgb(33, 33, 33);"));
        MotorControls = new QLabel(motorControlColumn);
        MotorControls->setObjectName(QStringLiteral("MotorControls"));
        MotorControls->setGeometry(QRect(15, 20, 280, 41));
        MotorControls->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(83, 83, 83);"));
        MotorControls->setAlignment(Qt::AlignCenter);
        MotorControlUnderline = new QLabel(motorControlColumn);
        MotorControlUnderline->setObjectName(QStringLiteral("MotorControlUnderline"));
        MotorControlUnderline->setGeometry(QRect(15, 65, 280, 5));
        MotorControlUnderline->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(83, 83, 83);"));
        MotorControlUnderline->setAlignment(Qt::AlignCenter);
        xAxisControlHeader = new QLabel(motorControlColumn);
        xAxisControlHeader->setObjectName(QStringLiteral("xAxisControlHeader"));
        xAxisControlHeader->setGeometry(QRect(15, 80, 280, 25));
        xAxisControlHeader->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(83, 83, 83);"));
        xAxisControlHeader->setAlignment(Qt::AlignCenter);
        yAxisControlHeader = new QLabel(motorControlColumn);
        yAxisControlHeader->setObjectName(QStringLiteral("yAxisControlHeader"));
        yAxisControlHeader->setGeometry(QRect(15, 170, 280, 25));
        yAxisControlHeader->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(83, 83, 83);"));
        yAxisControlHeader->setAlignment(Qt::AlignCenter);
        zAxisControlHeader = new QLabel(motorControlColumn);
        zAxisControlHeader->setObjectName(QStringLiteral("zAxisControlHeader"));
        zAxisControlHeader->setGeometry(QRect(15, 260, 280, 25));
        zAxisControlHeader->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(83, 83, 83);"));
        zAxisControlHeader->setAlignment(Qt::AlignCenter);
        MotorControlUnderline_2 = new QLabel(motorControlColumn);
        MotorControlUnderline_2->setObjectName(QStringLiteral("MotorControlUnderline_2"));
        MotorControlUnderline_2->setGeometry(QRect(15, 350, 280, 5));
        MotorControlUnderline_2->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(83, 83, 83);"));
        MotorControlUnderline_2->setAlignment(Qt::AlignCenter);
        xDownButton = new QPushButton(motorControlColumn);
        xDownButton->setObjectName(QStringLiteral("xDownButton"));
        xDownButton->setGeometry(QRect(60, 120, 41, 31));
        xDownButton->setStyleSheet(QLatin1String("background-color: rgb(179, 179, 179);\n"
"\n"
"disabled {\n"
"    background-color: gray;\n"
"}"));
        xUpButton = new QPushButton(motorControlColumn);
        xUpButton->setObjectName(QStringLiteral("xUpButton"));
        xUpButton->setGeometry(QRect(210, 120, 41, 31));
        xUpButton->setStyleSheet(QStringLiteral("background-color: rgb(179, 179, 179);"));
        xPos = new QLineEdit(motorControlColumn);
        xPos->setObjectName(QStringLiteral("xPos"));
        xPos->setGeometry(QRect(115, 120, 81, 31));
        xPos->setStyleSheet(QStringLiteral("background-color: rgb(179, 179, 179);"));
        yDownButton = new QPushButton(motorControlColumn);
        yDownButton->setObjectName(QStringLiteral("yDownButton"));
        yDownButton->setGeometry(QRect(60, 210, 41, 31));
        yDownButton->setStyleSheet(QStringLiteral("background-color: rgb(179, 179, 179);"));
        yUpButton = new QPushButton(motorControlColumn);
        yUpButton->setObjectName(QStringLiteral("yUpButton"));
        yUpButton->setGeometry(QRect(210, 210, 41, 31));
        yUpButton->setStyleSheet(QStringLiteral("background-color: rgb(179, 179, 179);"));
        yPos = new QLineEdit(motorControlColumn);
        yPos->setObjectName(QStringLiteral("yPos"));
        yPos->setGeometry(QRect(115, 210, 81, 31));
        yPos->setStyleSheet(QStringLiteral("background-color: rgb(179, 179, 179);"));
        zPos = new QLineEdit(motorControlColumn);
        zPos->setObjectName(QStringLiteral("zPos"));
        zPos->setGeometry(QRect(115, 300, 81, 31));
        zPos->setStyleSheet(QStringLiteral("background-color: rgb(179, 179, 179);"));
        zUpButton = new QPushButton(motorControlColumn);
        zUpButton->setObjectName(QStringLiteral("zUpButton"));
        zUpButton->setGeometry(QRect(210, 300, 41, 31));
        zUpButton->setStyleSheet(QStringLiteral("background-color: rgb(179, 179, 179);"));
        zDownButton = new QPushButton(motorControlColumn);
        zDownButton->setObjectName(QStringLiteral("zDownButton"));
        zDownButton->setGeometry(QRect(60, 300, 41, 31));
        zDownButton->setStyleSheet(QStringLiteral("background-color: rgb(179, 179, 179);"));
        motorDisableText = new QLabel(motorControlColumn);
        motorDisableText->setObjectName(QStringLiteral("motorDisableText"));
        motorDisableText->setGeometry(QRect(6, 76, 301, 261));
        motorDisableText->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        GUI->setCentralWidget(centralwidget);
        menubar = new QMenuBar(GUI);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1493, 25));
        menuOpenflexure = new QMenu(menubar);
        menuOpenflexure->setObjectName(QStringLiteral("menuOpenflexure"));
        GUI->setMenuBar(menubar);
        statusbar = new QStatusBar(GUI);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        GUI->setStatusBar(statusbar);

        menubar->addAction(menuOpenflexure->menuAction());

        retranslateUi(GUI);

        QMetaObject::connectSlotsByName(GUI);
    } // setupUi

    void retranslateUi(QMainWindow *GUI)
    {
        GUI->setWindowTitle(QApplication::translate("GUI", "cellUview", Q_NULLPTR));
        cellUview->setText(QApplication::translate("GUI", "<html><head/><body><p><span style=\" font-size:20pt; font-weight:700;\">cellUview</span></p></body></html>", Q_NULLPTR));
        scopeVideoFeed->setText(QString());
        captureButton->setText(QApplication::translate("GUI", "Capture Image", Q_NULLPTR));
        galleryPos1->setText(QString());
        galleryPos2->setText(QString());
        nextButton->setText(QApplication::translate("GUI", "Next", Q_NULLPTR));
        backButton->setText(QApplication::translate("GUI", "Back", Q_NULLPTR));
        galleryPos4->setText(QString());
        galleryPos3->setText(QString());
        GalleryUnderline->setText(QApplication::translate("GUI", "<html><head/><body><p><br/></p></body></html>", Q_NULLPTR));
        namePos3->setText(QString());
        namePos4->setText(QString());
        namePos2->setText(QString());
        namePos1->setText(QString());
        buttonPos1->setText(QString());
        buttonPos2->setText(QString());
        buttonPos3->setText(QString());
        buttonPos4->setText(QString());
        GalleryHeader->setText(QApplication::translate("GUI", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700;\">Gallery</span></p></body></html>", Q_NULLPTR));
        ImageSettings->setText(QApplication::translate("GUI", "<html><head/><body><p><span style=\" font-weight:700;\">Capture Name</span></p></body></html>", Q_NULLPTR));
        restoreSettingsButton->setText(QApplication::translate("GUI", "Restore Settings", Q_NULLPTR));
        Divider1->setText(QApplication::translate("GUI", "<html><head/><body><p><br/></p></body></html>", Q_NULLPTR));
        FlatFieldButton->setText(QApplication::translate("GUI", "Flat Field Capture (Capture with empty slide)", Q_NULLPTR));
        edgeEnhancementValueInput->setText(QString());
        ControlPanelHeader->setText(QApplication::translate("GUI", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700;\">Control Panel</span></p></body></html>", Q_NULLPTR));
        grayScaleBox->setText(QApplication::translate("GUI", "Gray Scale", Q_NULLPTR));
        dilationCheckBox->setText(QApplication::translate("GUI", "Dilation", Q_NULLPTR));
        erosionCheckBox->setText(QApplication::translate("GUI", "Erosion", Q_NULLPTR));
        contrastEnhancementValueInput->setText(QString());
        ContrastEhnancement->setText(QApplication::translate("GUI", "Contrast Enhancement", Q_NULLPTR));
        edgeDetectionLabel->setText(QApplication::translate("GUI", "Edge Detection", Q_NULLPTR));
        exposureValueInput->setText(QString());
        edgeDetectionLabel_2->setText(QApplication::translate("GUI", "Exposure(EV)", Q_NULLPTR));
        flatFieldBox->setText(QApplication::translate("GUI", "Flat Field Correction", Q_NULLPTR));
        kMeansLabel->setText(QApplication::translate("GUI", "k-Means Cluster Count", Q_NULLPTR));
        kMeansValueInput->setText(QString());
        kMeansPercentage->setText(QApplication::translate("GUI", "k mean percentage", Q_NULLPTR));
        MotorControls->setText(QApplication::translate("GUI", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700;\">Motor Controls</span></p></body></html>", Q_NULLPTR));
        MotorControlUnderline->setText(QApplication::translate("GUI", "<html><head/><body><p><br/></p></body></html>", Q_NULLPTR));
        xAxisControlHeader->setText(QApplication::translate("GUI", "<html><head/><body><p>X-axis Controls</p></body></html>", Q_NULLPTR));
        yAxisControlHeader->setText(QApplication::translate("GUI", "<html><head/><body><p>Y-axis Controls</p></body></html>", Q_NULLPTR));
        zAxisControlHeader->setText(QApplication::translate("GUI", "<html><head/><body><p>Z-axis Controls</p></body></html>", Q_NULLPTR));
        MotorControlUnderline_2->setText(QApplication::translate("GUI", "<html><head/><body><p><br/></p></body></html>", Q_NULLPTR));
        xDownButton->setText(QApplication::translate("GUI", "-", Q_NULLPTR));
        xUpButton->setText(QApplication::translate("GUI", "+", Q_NULLPTR));
        yDownButton->setText(QApplication::translate("GUI", "-", Q_NULLPTR));
        yUpButton->setText(QApplication::translate("GUI", "+", Q_NULLPTR));
        zUpButton->setText(QApplication::translate("GUI", "+", Q_NULLPTR));
        zDownButton->setText(QApplication::translate("GUI", "-", Q_NULLPTR));
        motorDisableText->setText(QApplication::translate("GUI", "<html><head/><body><p align=\"center\">Motors are not connected</p><p align=\"center\">Manual operation only</p></body></html>", Q_NULLPTR));
        menuOpenflexure->setTitle(QApplication::translate("GUI", "cellUview", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GUI: public Ui_GUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
