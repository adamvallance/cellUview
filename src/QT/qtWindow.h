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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
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
    QMenuBar *menubar;
    QMenu *menuOpenflexure;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *GUI)
    {
        if (GUI->objectName().isEmpty())
            GUI->setObjectName(QStringLiteral("GUI"));
        GUI->resize(1153, 824);
        centralwidget = new QWidget(GUI);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        centralwidget->setStyleSheet(QLatin1String("#centralWidget {\n"
"background-color:#FF121212}"));
        ImageCaptureColumn = new QWidget(centralwidget);
        ImageCaptureColumn->setObjectName(QStringLiteral("ImageCaptureColumn"));
        ImageCaptureColumn->setGeometry(QRect(30, -10, 331, 781));
        ImageCaptureColumn->setStyleSheet(QLatin1String("#ImageCaptureColumn{\n"
"background-color:#FF212121}"));
        widget = new QWidget(ImageCaptureColumn);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 489, 191, 21));
        pushButton = new QPushButton(ImageCaptureColumn);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 700, 291, 51));
        ImageHolder = new QWidget(ImageCaptureColumn);
        ImageHolder->setObjectName(QStringLiteral("ImageHolder"));
        ImageHolder->setGeometry(QRect(40, 70, 251, 221));
        StreamControlPanel = new QWidget(centralwidget);
        StreamControlPanel->setObjectName(QStringLiteral("StreamControlPanel"));
        StreamControlPanel->setGeometry(QRect(380, 490, 741, 31));
        pushButton_2 = new QPushButton(StreamControlPanel);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(0, 0, 31, 18));
        pushButton_3 = new QPushButton(StreamControlPanel);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(40, 0, 31, 18));
        pushButton_4 = new QPushButton(StreamControlPanel);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(80, 0, 31, 18));
        pushButton_5 = new QPushButton(StreamControlPanel);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(120, 0, 31, 18));
        pushButton_6 = new QPushButton(StreamControlPanel);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(710, 0, 31, 18));
        StreamView = new QWidget(centralwidget);
        StreamView->setObjectName(QStringLiteral("StreamView"));
        StreamView->setGeometry(QRect(380, -10, 741, 491));
        StreamView->setStyleSheet(QLatin1String("#StreamView {\n"
"background-color: #FF212121}"));
        scopeVideoFeed = new QLabel(StreamView);
        scopeVideoFeed->setObjectName(QStringLiteral("scopeVideoFeed"));
        scopeVideoFeed->setGeometry(QRect(6, 11, 731, 481));
        ControlPanel = new QTabWidget(centralwidget);
        ControlPanel->setObjectName(QStringLiteral("ControlPanel"));
        ControlPanel->setGeometry(QRect(380, 540, 741, 231));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        horizontalSlider = new QSlider(tab);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(10, 90, 711, 21));
        horizontalSlider->setOrientation(Qt::Horizontal);
        ControlPanel->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        horizontalSlider_2 = new QSlider(tab_2);
        horizontalSlider_2->setObjectName(QStringLiteral("horizontalSlider_2"));
        horizontalSlider_2->setGeometry(QRect(10, 90, 711, 21));
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        ControlPanel->addTab(tab_2, QString());
        GUI->setCentralWidget(centralwidget);
        menubar = new QMenuBar(GUI);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1153, 17));
        menuOpenflexure = new QMenu(menubar);
        menuOpenflexure->setObjectName(QStringLiteral("menuOpenflexure"));
        GUI->setMenuBar(menubar);
        statusbar = new QStatusBar(GUI);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        GUI->setStatusBar(statusbar);

        menubar->addAction(menuOpenflexure->menuAction());

        retranslateUi(GUI);

        ControlPanel->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(GUI);
    } // setupUi

    void retranslateUi(QMainWindow *GUI)
    {
        GUI->setWindowTitle(QApplication::translate("GUI", "MainWindow", 0));
        pushButton->setText(QApplication::translate("GUI", "PushButton", 0));
        pushButton_2->setText(QApplication::translate("GUI", "PushButton", 0));
        pushButton_3->setText(QApplication::translate("GUI", "PushButton", 0));
        pushButton_4->setText(QApplication::translate("GUI", "PushButton", 0));
        pushButton_5->setText(QApplication::translate("GUI", "PushButton", 0));
        pushButton_6->setText(QApplication::translate("GUI", "PushButton", 0));
        scopeVideoFeed->setText(QApplication::translate("GUI", "TextLabel", 0));
        ControlPanel->setTabText(ControlPanel->indexOf(tab), QApplication::translate("GUI", "Tab 1", 0));
        ControlPanel->setTabText(ControlPanel->indexOf(tab_2), QApplication::translate("GUI", "Tab 2", 0));
        menuOpenflexure->setTitle(QApplication::translate("GUI", "Openflexure+", 0));
    } // retranslateUi

};

namespace Ui {
    class GUI: public Ui_GUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
