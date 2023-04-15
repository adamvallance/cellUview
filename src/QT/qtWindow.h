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
    QPushButton *captureButton;
    QWidget *ImageHolder;
    QPushButton *xUpButton;
    QPushButton *xDownButton;
    QLineEdit *xPos;
    QPushButton *yDownButton;
    QLineEdit *yPos;
    QPushButton *yUpButton;
    QPushButton *zDownButton;
    QPushButton *zUpButton;
    QLineEdit *zPos;
    QLabel *label;
    QPushButton *restoreSettingsButton;
    QLabel *label_2;
    QPushButton *FlatFieldButton;
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
    QLineEdit *exposureValueInput;
    QLabel *label_6;
    QSlider *exposureSlider;
    QCheckBox *flatFieldBox;
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
        captureButton = new QPushButton(ImageCaptureColumn);
        captureButton->setObjectName(QString::fromUtf8("captureButton"));
        captureButton->setGeometry(QRect(30, 720, 410, 40));
        captureButton->setStyleSheet(QString::fromUtf8("background-color: rgb(179, 179, 179);"));
        ImageHolder = new QWidget(ImageCaptureColumn);
        ImageHolder->setObjectName(QString::fromUtf8("ImageHolder"));
        ImageHolder->setGeometry(QRect(30, 60, 410, 401));
        ImageHolder->setStyleSheet(QString::fromUtf8(""));
        xUpButton = new QPushButton(ImageHolder);
        xUpButton->setObjectName(QString::fromUtf8("xUpButton"));
        xUpButton->setGeometry(QRect(10, 130, 51, 40));
        xUpButton->setStyleSheet(QString::fromUtf8("background-color: rgb(179, 179, 179);"));
        xDownButton = new QPushButton(ImageHolder);
        xDownButton->setObjectName(QString::fromUtf8("xDownButton"));
        xDownButton->setGeometry(QRect(10, 220, 51, 40));
        xDownButton->setStyleSheet(QString::fromUtf8("background-color: rgb(179, 179, 179);"));
        xPos = new QLineEdit(ImageHolder);
        xPos->setObjectName(QString::fromUtf8("xPos"));
        xPos->setGeometry(QRect(10, 180, 51, 31));
        xPos->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(179, 179, 179);"));
        yDownButton = new QPushButton(ImageHolder);
        yDownButton->setObjectName(QString::fromUtf8("yDownButton"));
        yDownButton->setGeometry(QRect(100, 220, 51, 40));
        yDownButton->setStyleSheet(QString::fromUtf8("background-color: rgb(179, 179, 179);"));
        yPos = new QLineEdit(ImageHolder);
        yPos->setObjectName(QString::fromUtf8("yPos"));
        yPos->setGeometry(QRect(100, 180, 51, 31));
        yPos->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(179, 179, 179);"));
        yUpButton = new QPushButton(ImageHolder);
        yUpButton->setObjectName(QString::fromUtf8("yUpButton"));
        yUpButton->setGeometry(QRect(100, 130, 51, 40));
        yUpButton->setStyleSheet(QString::fromUtf8("background-color: rgb(179, 179, 179);"));
        zDownButton = new QPushButton(ImageHolder);
        zDownButton->setObjectName(QString::fromUtf8("zDownButton"));
        zDownButton->setGeometry(QRect(190, 220, 51, 40));
        zDownButton->setStyleSheet(QString::fromUtf8("background-color: rgb(179, 179, 179);"));
        zUpButton = new QPushButton(ImageHolder);
        zUpButton->setObjectName(QString::fromUtf8("zUpButton"));
        zUpButton->setGeometry(QRect(190, 130, 51, 40));
        zUpButton->setStyleSheet(QString::fromUtf8("background-color: rgb(179, 179, 179);"));
        zPos = new QLineEdit(ImageHolder);
        zPos->setObjectName(QString::fromUtf8("zPos"));
        zPos->setGeometry(QRect(190, 180, 51, 31));
        zPos->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(179, 179, 179);"));
        label = new QLabel(ImageCaptureColumn);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 20, 410, 25));
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(83, 83, 83);"));
        label->setAlignment(Qt::AlignCenter);
        restoreSettingsButton = new QPushButton(ImageCaptureColumn);
        restoreSettingsButton->setObjectName(QString::fromUtf8("restoreSettingsButton"));
        restoreSettingsButton->setGeometry(QRect(30, 664, 411, 41));
        restoreSettingsButton->setStyleSheet(QString::fromUtf8("background-color: rgb(179, 179, 179);"));
        label_2 = new QLabel(ImageCaptureColumn);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 470, 410, 25));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(83, 83, 83);"));
        label_2->setAlignment(Qt::AlignCenter);
        FlatFieldButton = new QPushButton(ImageCaptureColumn);
        FlatFieldButton->setObjectName(QStringLiteral("FlatFieldButton"));
        FlatFieldButton->setGeometry(QRect(30, 610, 411, 41));
        FlatFieldButton->setStyleSheet(QStringLiteral("background-color: rgb(179, 179, 179);"));
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
        edgeEnhancementSlider->setMaximum(100);
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
        dilationCheckBox->setGeometry(QRect(30, 90, 92, 23));
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
        contrastEnhancementSlider->setMaximum(100);
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
        exposureValueInput = new QLineEdit(widget_6);
        exposureValueInput->setObjectName(QString::fromUtf8("exposureValueInput"));
        exposureValueInput->setGeometry(QRect(370, 150, 71, 31));
        exposureValueInput->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(179, 179, 179);"));
        label_6 = new QLabel(widget_6);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(460, 150, 111, 21));
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        exposureSlider = new QSlider(widget_6);
        exposureSlider->setObjectName(QString::fromUtf8("exposureSlider"));
        exposureSlider->setGeometry(QRect(10, 150, 341, 31));
        exposureSlider->setStyleSheet(QString::fromUtf8("QSlider::handle:horizontal {\n"
"    background-color: rgb(29, 185, 84);\n"
"}\n"
""));
        exposureSlider->setMaximum(100);
        exposureSlider->setOrientation(Qt::Horizontal);
        flatFieldBox = new QCheckBox(widget_6);
        flatFieldBox->setObjectName(QStringLiteral("flatFieldBox"));
        flatFieldBox->setEnabled(false);
        flatFieldBox->setGeometry(QRect(480, 60, 111, 23));
        flatFieldBox->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        GUI->setCentralWidget(centralwidget);
        menubar = new QMenuBar(GUI);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1162, 25));
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
        GUI->setWindowTitle(QApplication::translate("GUI", "MainWindow", Q_NULLPTR));
        cellUviewPlus->setText(QApplication::translate("GUI", "cellUview", Q_NULLPTR));
        scopeVideoFeed->setText(QApplication::translate("GUI", "TextLabel", Q_NULLPTR));
        captureButton->setText(QApplication::translate("GUI", "Capture Image", Q_NULLPTR));
        label->setText(QApplication::translate("GUI", "Gallery", Q_NULLPTR));
        restoreSettingsButton->setText(QApplication::translate("GUI", "Restore Settings", Q_NULLPTR));
        label_2->setText(QApplication::translate("GUI", "Image Settings", Q_NULLPTR));
        FlatFieldButton->setText(QApplication::translate("GUI", "Flat", Q_NULLPTR));
        edgeEnhancementValueInput->setText(QString());
        label_3->setText(QApplication::translate("GUI", "Control Panel", Q_NULLPTR));
        grayScaleBox->setText(QApplication::translate("GUI", "Gray Scale", Q_NULLPTR));
        dilationCheckBox->setText(QApplication::translate("GUI", "Dilation", Q_NULLPTR));
        erosionCheckBox->setText(QApplication::translate("GUI", "Erosion", Q_NULLPTR));
        contrastEnhancementValueInput->setText(QString());
        label_4->setText(QApplication::translate("GUI", "Edge Detection", Q_NULLPTR));
        label_5->setText(QApplication::translate("GUI", "Contrast Enhancement", Q_NULLPTR));
        exposureValueInput->setText(QString());
        label_6->setText(QApplication::translate("GUI", "Exposure (EV)", Q_NULLPTR));
        flatFieldBox->setText(QApplication::translate("GUI", "Flat", Q_NULLPTR));
        menuOpenflexure->setTitle(QApplication::translate("GUI", "cellUview", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GUI: public Ui_GUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
