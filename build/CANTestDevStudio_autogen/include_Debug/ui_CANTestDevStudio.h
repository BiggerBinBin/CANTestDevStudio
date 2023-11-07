/********************************************************************************
** Form generated from reading UI file 'CANTestDevStudio.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CANTESTDEVSTUDIO_H
#define UI_CANTESTDEVSTUDIO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CANTestDevStudioClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CANTestDevStudioClass)
    {
        if (CANTestDevStudioClass->objectName().isEmpty())
            CANTestDevStudioClass->setObjectName(QString::fromUtf8("CANTestDevStudioClass"));
        CANTestDevStudioClass->resize(600, 400);
        menuBar = new QMenuBar(CANTestDevStudioClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        CANTestDevStudioClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CANTestDevStudioClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        CANTestDevStudioClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(CANTestDevStudioClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        CANTestDevStudioClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(CANTestDevStudioClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        CANTestDevStudioClass->setStatusBar(statusBar);

        retranslateUi(CANTestDevStudioClass);

        QMetaObject::connectSlotsByName(CANTestDevStudioClass);
    } // setupUi

    void retranslateUi(QMainWindow *CANTestDevStudioClass)
    {
        CANTestDevStudioClass->setWindowTitle(QCoreApplication::translate("CANTestDevStudioClass", "CANTestDevStudio", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CANTestDevStudioClass: public Ui_CANTestDevStudioClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CANTESTDEVSTUDIO_H
