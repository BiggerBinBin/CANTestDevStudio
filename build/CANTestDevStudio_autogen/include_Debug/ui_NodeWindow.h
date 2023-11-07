/********************************************************************************
** Form generated from reading UI file 'NodeWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NODEWINDOW_H
#define UI_NODEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NodeWindowClass
{
public:

    void setupUi(QWidget *NodeWindowClass)
    {
        if (NodeWindowClass->objectName().isEmpty())
            NodeWindowClass->setObjectName(QString::fromUtf8("NodeWindowClass"));
        NodeWindowClass->resize(600, 400);

        retranslateUi(NodeWindowClass);

        QMetaObject::connectSlotsByName(NodeWindowClass);
    } // setupUi

    void retranslateUi(QWidget *NodeWindowClass)
    {
        NodeWindowClass->setWindowTitle(QCoreApplication::translate("NodeWindowClass", "NodeWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NodeWindowClass: public Ui_NodeWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NODEWINDOW_H
