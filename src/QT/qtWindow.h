/********************************************************************************
** Form generated from reading UI file 'gui.ui'
**
** Created by: Qt User Interface Compiler version 5.15.6
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
    QLabel *OpenFlexurePlus;
    QWidget *widget_2;
    QLabel *scopeVideoFeed;
    QWidget *ImageCaptureColumn;
    QPushButton *captureButton;
    QWidget *ImageHolder;
    QLabel *label;
    QPushButton *restoreSettingsButton;
    QLabel *label_2;
    QWidget *widget_6;
    QSlider *horizontalSlider_2;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QCheckBox *greyScaleBox;
    QCheckBox *dilationCheckBox;
    QCheckBox *erosionCheckBox;
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
        OpenFlexurePlus = new QLabel(widget);
        OpenFlexurePlus->setObjectName(QString::fromUtf8("OpenFlexurePlus"));
        OpenFlexurePlus->setGeometry(QRect(0, 19, 1321, 41));
        OpenFlexurePlus->setAlignment(Qt::AlignCenter);
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
        widget_6 = new QWidget(widget_2);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        widget_6->setGeometry(QRect(500, 520, 641, 281));
        widget_6->setStyleSheet(QString::fromUtf8("background-color: rgb(33, 33, 33);"));
        horizontalSlider_2 = new QSlider(widget_6);
        horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
        horizontalSlider_2->setGeometry(QRect(10, 190, 341, 31));
        horizontalSlider_2->setStyleSheet(QString::fromUtf8("QSlider::handle:horizontal {\n"
"    background-color: rgb(29, 185, 84);\n"
"}\n"
""));
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        lineEdit = new QLineEdit(widget_6);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(370, 190, 71, 31));
        lineEdit->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(179, 179, 179);"));
        label_3 = new QLabel(widget_6);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(-4, -4, 711, 40));
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(83, 83, 83);\n"
"color: rgb(255, 255, 255);"));
        label_3->setAlignment(Qt::AlignCenter);
        greyScaleBox = new QCheckBox(widget_6);
        greyScaleBox->setObjectName(QString::fromUtf8("greyScaleBox"));
        greyScaleBox->setGeometry(QRect(30, 60, 92, 23));
        greyScaleBox->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        dilationCheckBox = new QCheckBox(widget_6);
        dilationCheckBox->setObjectName(QString::fromUtf8("dilationCheckBox"));
        dilationCheckBox->setGeometry(QRect(30, 90, 92, 23));
        dilationCheckBox->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        erosionCheckBox = new QCheckBox(widget_6);
        erosionCheckBox->setObjectName(QString::fromUtf8("erosionCheckBox"));
        erosionCheckBox->setGeometry(QRect(30, 120, 92, 23));
        erosionCheckBox->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
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
        OpenFlexurePlus->setText(QCoreApplication::translate("GUI", "OpenFlexure +", nullptr));
        scopeVideoFeed->setText(QCoreApplication::translate("GUI", "TextLabel", nullptr));
        captureButton->setText(QCoreApplication::translate("GUI", "Capture Image", nullptr));
        label->setText(QCoreApplication::translate("GUI", "Gallery", nullptr));
        restoreSettingsButton->setText(QCoreApplication::translate("GUI", "Restore Settings", nullptr));
        label_2->setText(QCoreApplication::translate("GUI", "Image Settings", nullptr));
        lineEdit->setText(QString());
        label_3->setText(QCoreApplication::translate("GUI", "Control Panel", nullptr));
        greyScaleBox->setText(QCoreApplication::translate("GUI", "Grey Scale", nullptr));
        dilationCheckBox->setText(QCoreApplication::translate("GUI", "Dilation", nullptr));
        erosionCheckBox->setText(QCoreApplication::translate("GUI", "Erosion", nullptr));
        menuOpenflexure->setTitle(QCoreApplication::translate("GUI", "Openflexure+", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GUI: public Ui_GUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
