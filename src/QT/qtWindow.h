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
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GUI
{
public:
    QWidget *centralwidget;
    QWidget *ImageCaptureColumn;
    QWidget *widget;
    QPushButton *pushButton;
    QWidget *ImageHolder;
    QWidget *StreamControlPanel;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QWidget *StreamView;
    QLabel *scopeVideoFeed;
    QTabWidget *ControlPanel;
    QWidget *tab;
    QSlider *horizontalSlider;
    QWidget *tab_2;
    QSlider *horizontalSlider_2;
    QLineEdit *lineEdit;
    QMenuBar *menubar;
    QMenu *menuOpenflexure;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *GUI)
    {
        if (GUI->objectName().isEmpty())
            GUI->setObjectName(QString::fromUtf8("GUI"));
        GUI->resize(1269, 889);
        centralwidget = new QWidget(GUI);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8("#centralWidget {\n"
"background-color:#FF121212}"));
        ImageCaptureColumn = new QWidget(centralwidget);
        ImageCaptureColumn->setObjectName(QString::fromUtf8("ImageCaptureColumn"));
        ImageCaptureColumn->setGeometry(QRect(30, -10, 331, 781));
        ImageCaptureColumn->setStyleSheet(QString::fromUtf8("#ImageCaptureColumn{\n"
"background-color:#FF212121}"));
        widget = new QWidget(ImageCaptureColumn);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 489, 191, 21));
        pushButton = new QPushButton(ImageCaptureColumn);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 700, 291, 51));
        ImageHolder = new QWidget(ImageCaptureColumn);
        ImageHolder->setObjectName(QString::fromUtf8("ImageHolder"));
        ImageHolder->setGeometry(QRect(40, 70, 251, 221));
        StreamControlPanel = new QWidget(centralwidget);
        StreamControlPanel->setObjectName(QString::fromUtf8("StreamControlPanel"));
        StreamControlPanel->setGeometry(QRect(380, 490, 741, 31));
        pushButton_2 = new QPushButton(StreamControlPanel);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(0, 0, 31, 18));
        pushButton_3 = new QPushButton(StreamControlPanel);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(40, 0, 31, 18));
        pushButton_4 = new QPushButton(StreamControlPanel);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(80, 0, 31, 18));
        pushButton_5 = new QPushButton(StreamControlPanel);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(120, 0, 31, 18));
        pushButton_6 = new QPushButton(StreamControlPanel);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(710, 0, 31, 18));
        StreamView = new QWidget(centralwidget);
        StreamView->setObjectName(QString::fromUtf8("StreamView"));
        StreamView->setGeometry(QRect(380, -10, 741, 491));
        StreamView->setStyleSheet(QString::fromUtf8("#StreamView {\n"
"background-color: #FF212121}"));
        scopeVideoFeed = new QLabel(StreamView);
        scopeVideoFeed->setObjectName(QString::fromUtf8("scopeVideoFeed"));
        scopeVideoFeed->setGeometry(QRect(6, 11, 731, 481));
        ControlPanel = new QTabWidget(centralwidget);
        ControlPanel->setObjectName(QString::fromUtf8("ControlPanel"));
        ControlPanel->setGeometry(QRect(380, 540, 741, 231));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        horizontalSlider = new QSlider(tab);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(10, 90, 711, 21));
        horizontalSlider->setOrientation(Qt::Horizontal);
        ControlPanel->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        horizontalSlider_2 = new QSlider(tab_2);
        horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
        horizontalSlider_2->setGeometry(QRect(20, 90, 611, 21));
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        lineEdit = new QLineEdit(tab_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(650, 90, 71, 25));
        ControlPanel->addTab(tab_2, QString());
        GUI->setCentralWidget(centralwidget);
        menubar = new QMenuBar(GUI);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1269, 22));
        menuOpenflexure = new QMenu(menubar);
        menuOpenflexure->setObjectName(QString::fromUtf8("menuOpenflexure"));
        GUI->setMenuBar(menubar);
        statusbar = new QStatusBar(GUI);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        GUI->setStatusBar(statusbar);

        menubar->addAction(menuOpenflexure->menuAction());

        retranslateUi(GUI);

        ControlPanel->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(GUI);
    } // setupUi

    void retranslateUi(QMainWindow *GUI)
    {
        GUI->setWindowTitle(QCoreApplication::translate("GUI", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("GUI", "PushButton", nullptr));
        pushButton_2->setText(QCoreApplication::translate("GUI", "PushButton", nullptr));
        pushButton_3->setText(QCoreApplication::translate("GUI", "PushButton", nullptr));
        pushButton_4->setText(QCoreApplication::translate("GUI", "PushButton", nullptr));
        pushButton_5->setText(QCoreApplication::translate("GUI", "PushButton", nullptr));
        pushButton_6->setText(QCoreApplication::translate("GUI", "PushButton", nullptr));
        scopeVideoFeed->setText(QCoreApplication::translate("GUI", "TextLabel", nullptr));
        ControlPanel->setTabText(ControlPanel->indexOf(tab), QCoreApplication::translate("GUI", "Tab 1", nullptr));
        lineEdit->setText(QString());
        ControlPanel->setTabText(ControlPanel->indexOf(tab_2), QCoreApplication::translate("GUI", "Tab 2", nullptr));
        menuOpenflexure->setTitle(QCoreApplication::translate("GUI", "Openflexure+", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GUI: public Ui_GUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
