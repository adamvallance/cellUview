/********************************************************************************
** Form generated from reading UI file 'gui.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_H
#define UI_GUI_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GUI
{
public:
    QWidget *centralWidget;
    QLabel *scopeVideoFeed;
    QLabel *logoImage;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GUI)
    {
        if (GUI->objectName().isEmpty())
            GUI->setObjectName(QStringLiteral("GUI"));
        GUI->resize(876, 500);
        QIcon icon;
        icon.addFile(QStringLiteral("../openflexureplus/openflexure/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        GUI->setWindowIcon(icon);
        GUI->setAutoFillBackground(true);
        centralWidget = new QWidget(GUI);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        scopeVideoFeed = new QLabel(centralWidget);
        scopeVideoFeed->setObjectName(QStringLiteral("scopeVideoFeed"));
        scopeVideoFeed->setGeometry(QRect(20, 0, 731, 411));
        logoImage = new QLabel(centralWidget);
        logoImage->setObjectName(QStringLiteral("logoImage"));
        logoImage->setGeometry(QRect(760, 0, 111, 111));
        logoImage->setPixmap(QPixmap(QString::fromUtf8("../openflexureplus/openflexure/logo.png")));
        logoImage->setScaledContents(true);
        GUI->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(GUI);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 876, 28));
        GUI->setMenuBar(menuBar);
        mainToolBar = new QToolBar(GUI);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        GUI->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(GUI);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        GUI->setStatusBar(statusBar);

        retranslateUi(GUI);

        QMetaObject::connectSlotsByName(GUI);
    } // setupUi

    void retranslateUi(QMainWindow *GUI)
    {
        GUI->setWindowTitle(QApplication::translate("GUI", "OpenFlexure+", nullptr));
        scopeVideoFeed->setText(QString());
        logoImage->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class GUI: public Ui_GUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
