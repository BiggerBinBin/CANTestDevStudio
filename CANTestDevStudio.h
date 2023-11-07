#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_CANTestDevStudio.h"
#include "./common/NodeWindow.h"
class CANTestDevStudio : public QMainWindow
{
    Q_OBJECT

public:
    CANTestDevStudio(QWidget *parent = nullptr);
    ~CANTestDevStudio();

private:
    Ui::CANTestDevStudioClass ui;
    NodeWindow* nodewidget;
private:
    void InitializationUI();
    void menuInitialization();
    void toolsBarInitialization();
private Q_SLOTS:
    void on_openNodeWindow_clicked(bool b);
};
