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
    QWidget *widget_3;
    QPushButton *pushButton;
    QWidget *widget_4;
    QLabel *label_2;
    QWidget *widget_5;
    QLabel *label;
    QWidget *widget_6;
    QSlider *horizontalSlider_2;
    QLineEdit *lineEdit;
    QLabel *label_3;
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
        scopeVideoFeed->setGeometry(QRect(500, 20, 581, 441));
        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(10, 20, 471, 781));
        widget_3->setStyleSheet(QString::fromUtf8("background-color: rgb(33, 33, 33);"));
        pushButton = new QPushButton(widget_3);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(30, 720, 410, 40));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(179, 179, 179);"));
        widget_4 = new QWidget(widget_3);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setGeometry(QRect(30, 530, 410, 141));
        widget_4->setStyleSheet(QString::fromUtf8(""));
        label_2 = new QLabel(widget_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 30, 410, 25));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(83, 83, 83);\n"
"color: rgb(255, 255, 255);"));
        label_2->setAlignment(Qt::AlignCenter);
        widget_5 = new QWidget(widget_3);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setGeometry(QRect(30, 60, 410, 401));
        widget_5->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(widget_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 20, 410, 25));
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(83, 83, 83);"));
        label->setAlignment(Qt::AlignCenter);
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
"\n"
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
        pushButton->setText(QCoreApplication::translate("GUI", "Capture Image", nullptr));
        label_2->setText(QCoreApplication::translate("GUI", "Image Settings", nullptr));
        label->setText(QCoreApplication::translate("GUI", "Gallery", nullptr));
        lineEdit->setText(QString());
        label_3->setText(QCoreApplication::translate("GUI", "Control Panel", nullptr));
        menuOpenflexure->setTitle(QCoreApplication::translate("GUI", "Openflexure+", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GUI: public Ui_GUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
