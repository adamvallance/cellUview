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
    QPushButton *FlatFieldButton;
    QWidget *widget_6;
    QSlider *edgeEnhancementSlider;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QCheckBox *greyScaleBox;
    QCheckBox *dilationCheckBox;
    QCheckBox *erosionCheckBox;
    QCheckBox *flatFieldBox;
    QMenuBar *menubar;
    QMenu *menuOpenflexure;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *GUI)
    {
        if (GUI->objectName().isEmpty())
            GUI->setObjectName(QStringLiteral("GUI"));
        GUI->resize(1162, 936);
        centralwidget = new QWidget(GUI);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        centralwidget->setStyleSheet(QLatin1String("#centralWidget {\n"
"background-color:#FF121212}"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 1321, 80));
        widget->setStyleSheet(QLatin1String("\n"
"	background-color: rgb(179, 179, 179);\n"
""));
        OpenFlexurePlus = new QLabel(widget);
        OpenFlexurePlus->setObjectName(QStringLiteral("OpenFlexurePlus"));
        OpenFlexurePlus->setGeometry(QRect(0, 19, 1321, 41));
        OpenFlexurePlus->setAlignment(Qt::AlignCenter);
        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(0, 80, 1351, 841));
        widget_2->setStyleSheet(QLatin1String("\n"
"background-color: rgb(18, 18, 18);"));
        scopeVideoFeed = new QLabel(widget_2);
        scopeVideoFeed->setObjectName(QStringLiteral("scopeVideoFeed"));
        scopeVideoFeed->setGeometry(QRect(500, 20, 621, 461));
        ImageCaptureColumn = new QWidget(widget_2);
        ImageCaptureColumn->setObjectName(QStringLiteral("ImageCaptureColumn"));
        ImageCaptureColumn->setGeometry(QRect(10, 20, 471, 781));
        ImageCaptureColumn->setStyleSheet(QStringLiteral("background-color: rgb(33, 33, 33);"));
        captureButton = new QPushButton(ImageCaptureColumn);
        captureButton->setObjectName(QStringLiteral("captureButton"));
        captureButton->setGeometry(QRect(30, 720, 410, 40));
        captureButton->setStyleSheet(QStringLiteral("background-color: rgb(179, 179, 179);"));
        ImageHolder = new QWidget(ImageCaptureColumn);
        ImageHolder->setObjectName(QStringLiteral("ImageHolder"));
        ImageHolder->setGeometry(QRect(30, 60, 410, 401));
        ImageHolder->setStyleSheet(QStringLiteral(""));
        label = new QLabel(ImageCaptureColumn);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 20, 410, 25));
        label->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(83, 83, 83);"));
        label->setAlignment(Qt::AlignCenter);
        restoreSettingsButton = new QPushButton(ImageCaptureColumn);
        restoreSettingsButton->setObjectName(QStringLiteral("restoreSettingsButton"));
        restoreSettingsButton->setGeometry(QRect(30, 664, 411, 41));
        restoreSettingsButton->setStyleSheet(QStringLiteral("background-color: rgb(179, 179, 179);"));
        label_2 = new QLabel(ImageCaptureColumn);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 470, 410, 25));
        label_2->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(83, 83, 83);"));
        label_2->setAlignment(Qt::AlignCenter);
        FlatFieldButton = new QPushButton(ImageCaptureColumn);
        FlatFieldButton->setObjectName(QStringLiteral("FlatFieldButton"));
        FlatFieldButton->setEnabled(true);
        FlatFieldButton->setGeometry(QRect(30, 610, 411, 41));
        FlatFieldButton->setAutoFillBackground(false);
        FlatFieldButton->setStyleSheet(QStringLiteral("background-color: rgb(179, 179, 179);"));
        FlatFieldButton->setCheckable(false);
        widget_6 = new QWidget(widget_2);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        widget_6->setGeometry(QRect(500, 520, 641, 281));
        widget_6->setStyleSheet(QStringLiteral("background-color: rgb(33, 33, 33);"));
        edgeEnhancementSlider = new QSlider(widget_6);
        edgeEnhancementSlider->setObjectName(QStringLiteral("edgeEnhancementSlider"));
        edgeEnhancementSlider->setGeometry(QRect(10, 190, 341, 31));
        edgeEnhancementSlider->setStyleSheet(QLatin1String("QSlider::handle:horizontal {\n"
"    background-color: rgb(29, 185, 84);\n"
"}\n"
""));
        edgeEnhancementSlider->setOrientation(Qt::Horizontal);
        lineEdit = new QLineEdit(widget_6);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(370, 190, 71, 31));
        lineEdit->setStyleSheet(QLatin1String("\n"
"background-color: rgb(179, 179, 179);"));
        label_3 = new QLabel(widget_6);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(-4, -4, 711, 40));
        label_3->setStyleSheet(QLatin1String("background-color: rgb(83, 83, 83);\n"
"color: rgb(255, 255, 255);"));
        label_3->setAlignment(Qt::AlignCenter);
        greyScaleBox = new QCheckBox(widget_6);
        greyScaleBox->setObjectName(QStringLiteral("greyScaleBox"));
        greyScaleBox->setGeometry(QRect(30, 60, 92, 23));
        greyScaleBox->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        dilationCheckBox = new QCheckBox(widget_6);
        dilationCheckBox->setObjectName(QStringLiteral("dilationCheckBox"));
        dilationCheckBox->setGeometry(QRect(30, 90, 92, 23));
        dilationCheckBox->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        erosionCheckBox = new QCheckBox(widget_6);
        erosionCheckBox->setObjectName(QStringLiteral("erosionCheckBox"));
        erosionCheckBox->setGeometry(QRect(30, 120, 92, 23));
        erosionCheckBox->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        flatFieldBox = new QCheckBox(widget_6);
        flatFieldBox->setObjectName(QStringLiteral("flatFieldBox"));
        flatFieldBox->setEnabled(true);
        flatFieldBox->setGeometry(QRect(461, 60, 161, 23));
        flatFieldBox->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        GUI->setCentralWidget(centralwidget);
        menubar = new QMenuBar(GUI);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1162, 25));
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
        GUI->setWindowTitle(QApplication::translate("GUI", "MainWindow", Q_NULLPTR));
        OpenFlexurePlus->setText(QApplication::translate("GUI", "OpenFlexure +", Q_NULLPTR));
        scopeVideoFeed->setText(QApplication::translate("GUI", "TextLabel", Q_NULLPTR));
        captureButton->setText(QApplication::translate("GUI", "Capture Image", Q_NULLPTR));
        label->setText(QApplication::translate("GUI", "Gallery", Q_NULLPTR));
        restoreSettingsButton->setText(QApplication::translate("GUI", "Restore Settings", Q_NULLPTR));
        label_2->setText(QApplication::translate("GUI", "Image Settings", Q_NULLPTR));
        FlatFieldButton->setText(QApplication::translate("GUI", "Flat Field Capture (Perform with empty objective)", Q_NULLPTR));
        lineEdit->setText(QString());
        label_3->setText(QApplication::translate("GUI", "Control Panel", Q_NULLPTR));
        greyScaleBox->setText(QApplication::translate("GUI", "Grey Scale", Q_NULLPTR));
        dilationCheckBox->setText(QApplication::translate("GUI", "Dilation", Q_NULLPTR));
        erosionCheckBox->setText(QApplication::translate("GUI", "Erosion", Q_NULLPTR));
        flatFieldBox->setText(QApplication::translate("GUI", "Flat Field Correction", Q_NULLPTR));
        menuOpenflexure->setTitle(QApplication::translate("GUI", "Openflexure+", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GUI: public Ui_GUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
