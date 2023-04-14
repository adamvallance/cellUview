/********************************************************************************
** Form generated from reading UI file 'gui.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
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
    QLineEdit *exposureValueInput;
    QLabel *label_6;
    QSlider *exposureSlider;
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
        cellUviewPlus = new QLabel(widget);
        cellUviewPlus->setObjectName(QStringLiteral("cellUviewPlus"));
        cellUviewPlus->setGeometry(QRect(0, 19, 1321, 41));
        cellUviewPlus->setAlignment(Qt::AlignCenter);
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
        edgeEnhancementSlider->setMaximum(100);
        edgeEnhancementSlider->setOrientation(Qt::Horizontal);
        edgeEnhancementValueInput = new QLineEdit(widget_6);
        edgeEnhancementValueInput->setObjectName(QStringLiteral("edgeEnhancementValueInput"));
        edgeEnhancementValueInput->setGeometry(QRect(370, 190, 71, 31));
        edgeEnhancementValueInput->setStyleSheet(QLatin1String("\n"
"background-color: rgb(179, 179, 179);"));
        label_3 = new QLabel(widget_6);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(-4, -4, 711, 40));
        label_3->setStyleSheet(QLatin1String("background-color: rgb(83, 83, 83);\n"
"color: rgb(255, 255, 255);"));
        label_3->setAlignment(Qt::AlignCenter);
        grayScaleBox = new QCheckBox(widget_6);
        grayScaleBox->setObjectName(QStringLiteral("grayScaleBox"));
        grayScaleBox->setGeometry(QRect(30, 60, 111, 23));
        grayScaleBox->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        dilationCheckBox = new QCheckBox(widget_6);
        dilationCheckBox->setObjectName(QStringLiteral("dilationCheckBox"));
        dilationCheckBox->setGeometry(QRect(30, 90, 92, 23));
        dilationCheckBox->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        erosionCheckBox = new QCheckBox(widget_6);
        erosionCheckBox->setObjectName(QStringLiteral("erosionCheckBox"));
        erosionCheckBox->setGeometry(QRect(30, 120, 92, 23));
        erosionCheckBox->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        contrastEnhancementSlider = new QSlider(widget_6);
        contrastEnhancementSlider->setObjectName(QStringLiteral("contrastEnhancementSlider"));
        contrastEnhancementSlider->setGeometry(QRect(10, 230, 341, 31));
        contrastEnhancementSlider->setStyleSheet(QLatin1String("QSlider::handle:horizontal {\n"
"    background-color: rgb(29, 185, 84);\n"
"}\n"
""));
        contrastEnhancementSlider->setMaximum(100);
        contrastEnhancementSlider->setOrientation(Qt::Horizontal);
        contrastEnhancementValueInput = new QLineEdit(widget_6);
        contrastEnhancementValueInput->setObjectName(QStringLiteral("contrastEnhancementValueInput"));
        contrastEnhancementValueInput->setGeometry(QRect(370, 230, 71, 31));
        contrastEnhancementValueInput->setStyleSheet(QLatin1String("\n"
"background-color: rgb(179, 179, 179);"));
        label_4 = new QLabel(widget_6);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(460, 190, 111, 21));
        label_4->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_5 = new QLabel(widget_6);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(460, 230, 161, 21));
        label_5->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        exposureValueInput = new QLineEdit(widget_6);
        exposureValueInput->setObjectName(QStringLiteral("exposureValueInput"));
        exposureValueInput->setGeometry(QRect(370, 150, 71, 31));
        exposureValueInput->setStyleSheet(QLatin1String("\n"
"background-color: rgb(179, 179, 179);"));
        label_6 = new QLabel(widget_6);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(460, 150, 111, 21));
        label_6->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        exposureSlider = new QSlider(widget_6);
        exposureSlider->setObjectName(QStringLiteral("exposureSlider"));
        exposureSlider->setGeometry(QRect(10, 150, 341, 31));
        exposureSlider->setStyleSheet(QLatin1String("QSlider::handle:horizontal {\n"
"    background-color: rgb(29, 185, 84);\n"
"}\n"
""));
        exposureSlider->setMaximum(100);
        exposureSlider->setOrientation(Qt::Horizontal);
        GUI->setCentralWidget(centralwidget);
        menubar = new QMenuBar(GUI);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1162, 20));
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
        GUI->setWindowTitle(QApplication::translate("GUI", "MainWindow", 0));
        cellUviewPlus->setText(QApplication::translate("GUI", "cellUview", 0));
        scopeVideoFeed->setText(QApplication::translate("GUI", "TextLabel", 0));
        captureButton->setText(QApplication::translate("GUI", "Capture Image", 0));
        label->setText(QApplication::translate("GUI", "Gallery", 0));
        restoreSettingsButton->setText(QApplication::translate("GUI", "Restore Settings", 0));
        label_2->setText(QApplication::translate("GUI", "Image Settings", 0));
        edgeEnhancementValueInput->setText(QString());
        label_3->setText(QApplication::translate("GUI", "Control Panel", 0));
        grayScaleBox->setText(QApplication::translate("GUI", "Gray Scale", 0));
        dilationCheckBox->setText(QApplication::translate("GUI", "Dilation", 0));
        erosionCheckBox->setText(QApplication::translate("GUI", "Erosion", 0));
        contrastEnhancementValueInput->setText(QString());
        label_4->setText(QApplication::translate("GUI", "Edge Detection", 0));
        label_5->setText(QApplication::translate("GUI", "Contrast Enhancement", 0));
        exposureValueInput->setText(QString());
        label_6->setText(QApplication::translate("GUI", "Exposure (EV)", 0));
        menuOpenflexure->setTitle(QApplication::translate("GUI", "cellUview", 0));
    } // retranslateUi

};

namespace Ui {
    class GUI: public Ui_GUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
