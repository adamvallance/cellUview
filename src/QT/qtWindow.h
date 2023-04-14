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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GUI
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QLabel *cellUviewPlus;
    QWidget *widget_2;
    QLabel *scopeVideoFeed;
    QWidget *ImageCaptureColumn;
    QWidget *ImageHolder;
    QPushButton *xUpButton;
    QPushButton *xDownButton;
    QLineEdit *xPos;
    QLineEdit *yPos;
    QPushButton *yUpButton;
    QPushButton *yDownButton;
    QLineEdit *zPos;
    QPushButton *zUpButton;
    QPushButton *zDownButton;
    QPushButton *restoreSettingsButton;
    QPushButton *captureButton;
    QLabel *label;
    QLabel *label_2;
    QWidget *widget_6;
    QSlider *edgeEnhancementSlider;
    QLineEdit *edgeEnhancementValueInput;
    QLabel *label_3;
    QCheckBox *grayScaleBox;
    QCheckBox *dilationCheckBox;
    QCheckBox *erosionCheckBox;
    QSlider *contrastEnhancementSlider;
    QLineEdit *contrastEnhancementValueInput;
    QLabel *label_4;
    QLabel *label_5;
    QMenuBar *menubar;
    QMenu *menuOpenflexure;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *GUI)
    {
        if (GUI->objectName().isEmpty())
            GUI->setObjectName(QString::fromUtf8("GUI"));
        GUI->resize(1162, 936);
        centralwidget = new QWidget(GUI);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8("#centralWidget {\n"
"background-color:#FF121212}"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 1321, 80));
        widget->setStyleSheet(QString::fromUtf8("\n"
"	background-color: rgb(179, 179, 179);\n"
""));
        cellUviewPlus = new QLabel(widget);
        cellUviewPlus->setObjectName(QString::fromUtf8("cellUviewPlus"));
        cellUviewPlus->setGeometry(QRect(0, 19, 1321, 41));
        cellUviewPlus->setAlignment(Qt::AlignCenter);
        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(0, 80, 1351, 841));
        widget_2->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(18, 18, 18);"));
        scopeVideoFeed = new QLabel(widget_2);
        scopeVideoFeed->setObjectName(QString::fromUtf8("scopeVideoFeed"));
        scopeVideoFeed->setGeometry(QRect(500, 20, 621, 461));
        ImageCaptureColumn = new QWidget(widget_2);
        ImageCaptureColumn->setObjectName(QString::fromUtf8("ImageCaptureColumn"));
        ImageCaptureColumn->setGeometry(QRect(10, 20, 471, 781));
        ImageCaptureColumn->setStyleSheet(QString::fromUtf8("background-color: rgb(33, 33, 33);"));
        ImageHolder = new QWidget(ImageCaptureColumn);
        ImageHolder->setObjectName(QString::fromUtf8("ImageHolder"));
        ImageHolder->setGeometry(QRect(30, 60, 410, 401));
        ImageHolder->setStyleSheet(QString::fromUtf8(""));
        xUpButton = new QPushButton(ImageHolder);
        xUpButton->setObjectName(QString::fromUtf8("xUpButton"));
        xUpButton->setGeometry(QRect(100, 80, 61, 41));
        xUpButton->setStyleSheet(QString::fromUtf8("background-color: rgb(179, 179, 179);"));
        xDownButton = new QPushButton(ImageHolder);
        xDownButton->setObjectName(QString::fromUtf8("xDownButton"));
        xDownButton->setGeometry(QRect(170, 80, 61, 41));
        xDownButton->setStyleSheet(QString::fromUtf8("background-color: rgb(179, 179, 179);"));
        xPos = new QLineEdit(ImageHolder);
        xPos->setObjectName(QString::fromUtf8("xPos"));
        xPos->setGeometry(QRect(130, 30, 71, 41));
        xPos->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(179, 179, 179);"));
        yPos = new QLineEdit(ImageHolder);
        yPos->setObjectName(QString::fromUtf8("yPos"));
        yPos->setGeometry(QRect(130, 160, 71, 41));
        yPos->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(179, 179, 179);"));
        yUpButton = new QPushButton(ImageHolder);
        yUpButton->setObjectName(QString::fromUtf8("yUpButton"));
        yUpButton->setGeometry(QRect(100, 210, 61, 41));
        yUpButton->setStyleSheet(QString::fromUtf8("background-color: rgb(179, 179, 179);"));
        yDownButton = new QPushButton(ImageHolder);
        yDownButton->setObjectName(QString::fromUtf8("yDownButton"));
        yDownButton->setGeometry(QRect(170, 210, 61, 41));
        yDownButton->setStyleSheet(QString::fromUtf8("background-color: rgb(179, 179, 179);"));
        zPos = new QLineEdit(ImageHolder);
        zPos->setObjectName(QString::fromUtf8("zPos"));
        zPos->setGeometry(QRect(130, 290, 71, 41));
        zPos->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(179, 179, 179);"));
        zUpButton = new QPushButton(ImageHolder);
        zUpButton->setObjectName(QString::fromUtf8("zUpButton"));
        zUpButton->setGeometry(QRect(100, 340, 61, 41));
        zUpButton->setStyleSheet(QString::fromUtf8("background-color: rgb(179, 179, 179);"));
        zDownButton = new QPushButton(ImageHolder);
        zDownButton->setObjectName(QString::fromUtf8("zDownButton"));
        zDownButton->setGeometry(QRect(170, 340, 61, 41));
        zDownButton->setStyleSheet(QString::fromUtf8("background-color: rgb(179, 179, 179);"));
        restoreSettingsButton = new QPushButton(ImageHolder);
        restoreSettingsButton->setObjectName(QString::fromUtf8("restoreSettingsButton"));
        restoreSettingsButton->setGeometry(QRect(320, 194, 81, 41));
        restoreSettingsButton->setStyleSheet(QString::fromUtf8("background-color: rgb(179, 179, 179);"));
        captureButton = new QPushButton(ImageHolder);
        captureButton->setObjectName(QString::fromUtf8("captureButton"));
        captureButton->setGeometry(QRect(320, 250, 81, 40));
        captureButton->setStyleSheet(QString::fromUtf8("background-color: rgb(179, 179, 179);"));
        label = new QLabel(ImageCaptureColumn);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 20, 410, 25));
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(83, 83, 83);"));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(ImageCaptureColumn);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 470, 410, 25));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(83, 83, 83);"));
        label_2->setAlignment(Qt::AlignCenter);
        widget_6 = new QWidget(widget_2);
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
        label_3 = new QLabel(widget_6);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(-4, -4, 711, 40));
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(83, 83, 83);\n"
"color: rgb(255, 255, 255);"));
        label_3->setAlignment(Qt::AlignCenter);
        grayScaleBox = new QCheckBox(widget_6);
        grayScaleBox->setObjectName(QString::fromUtf8("grayScaleBox"));
        grayScaleBox->setGeometry(QRect(30, 60, 111, 23));
        grayScaleBox->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        dilationCheckBox = new QCheckBox(widget_6);
        dilationCheckBox->setObjectName(QString::fromUtf8("dilationCheckBox"));
        dilationCheckBox->setGeometry(QRect(140, 10, 92, 23));
        dilationCheckBox->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        erosionCheckBox = new QCheckBox(widget_6);
        erosionCheckBox->setObjectName(QString::fromUtf8("erosionCheckBox"));
        erosionCheckBox->setGeometry(QRect(30, 120, 92, 23));
        erosionCheckBox->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        contrastEnhancementSlider = new QSlider(widget_6);
        contrastEnhancementSlider->setObjectName(QString::fromUtf8("contrastEnhancementSlider"));
        contrastEnhancementSlider->setGeometry(QRect(10, 230, 341, 31));
        contrastEnhancementSlider->setStyleSheet(QString::fromUtf8("QSlider::handle:horizontal {\n"
"    background-color: rgb(29, 185, 84);\n"
"}\n"
""));
        contrastEnhancementSlider->setMaximum(99);
        contrastEnhancementSlider->setOrientation(Qt::Horizontal);
        contrastEnhancementValueInput = new QLineEdit(widget_6);
        contrastEnhancementValueInput->setObjectName(QString::fromUtf8("contrastEnhancementValueInput"));
        contrastEnhancementValueInput->setGeometry(QRect(370, 230, 71, 31));
        contrastEnhancementValueInput->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(179, 179, 179);"));
        label_4 = new QLabel(widget_6);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(460, 190, 111, 21));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_5 = new QLabel(widget_6);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(460, 230, 161, 21));
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        GUI->setCentralWidget(centralwidget);
        menubar = new QMenuBar(GUI);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1162, 22));
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
        GUI->setWindowTitle(QCoreApplication::translate("GUI", "MainWindow", nullptr));
        cellUviewPlus->setText(QCoreApplication::translate("GUI", "cellUview", nullptr));
        scopeVideoFeed->setText(QCoreApplication::translate("GUI", "TextLabel", nullptr));
        xUpButton->setText(QCoreApplication::translate("GUI", "x up", nullptr));
        xDownButton->setText(QCoreApplication::translate("GUI", "x down", nullptr));
        xPos->setText(QString());
        yPos->setText(QString());
        yUpButton->setText(QCoreApplication::translate("GUI", "y up", nullptr));
        yDownButton->setText(QCoreApplication::translate("GUI", "y down", nullptr));
        zPos->setText(QString());
        zUpButton->setText(QCoreApplication::translate("GUI", "z up", nullptr));
        zDownButton->setText(QCoreApplication::translate("GUI", "z down", nullptr));
        restoreSettingsButton->setText(QCoreApplication::translate("GUI", "Restore Settings", nullptr));
        captureButton->setText(QCoreApplication::translate("GUI", "Capture Image", nullptr));
        label->setText(QCoreApplication::translate("GUI", "Gallery", nullptr));
        label_2->setText(QCoreApplication::translate("GUI", "Image Settings", nullptr));
        edgeEnhancementValueInput->setText(QString());
        label_3->setText(QCoreApplication::translate("GUI", "Control Panel", nullptr));
        grayScaleBox->setText(QCoreApplication::translate("GUI", "Gray Scale", nullptr));
        dilationCheckBox->setText(QCoreApplication::translate("GUI", "Dilation", nullptr));
        erosionCheckBox->setText(QCoreApplication::translate("GUI", "Erosion", nullptr));
        contrastEnhancementValueInput->setText(QString());
        label_4->setText(QCoreApplication::translate("GUI", "Edge Detection", nullptr));
        label_5->setText(QCoreApplication::translate("GUI", "Contrast Enhancement", nullptr));
        menuOpenflexure->setTitle(QCoreApplication::translate("GUI", "cellUview", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GUI: public Ui_GUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
