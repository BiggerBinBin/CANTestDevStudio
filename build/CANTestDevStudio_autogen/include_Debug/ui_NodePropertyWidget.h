/********************************************************************************
** Form generated from reading UI file 'NodePropertyWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NODEPROPERTYWIDGET_H
#define UI_NODEPROPERTYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NodePropertyWidgetClass
{
public:

    void setupUi(QWidget *NodePropertyWidgetClass)
    {
        if (NodePropertyWidgetClass->objectName().isEmpty())
            NodePropertyWidgetClass->setObjectName(QString::fromUtf8("NodePropertyWidgetClass"));
        NodePropertyWidgetClass->resize(600, 400);

        retranslateUi(NodePropertyWidgetClass);

        QMetaObject::connectSlotsByName(NodePropertyWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *NodePropertyWidgetClass)
    {
        NodePropertyWidgetClass->setWindowTitle(QCoreApplication::translate("NodePropertyWidgetClass", "NodePropertyWidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NodePropertyWidgetClass: public Ui_NodePropertyWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NODEPROPERTYWIDGET_H
