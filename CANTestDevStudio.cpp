#include "CANTestDevStudio.h"
#include <QMenu>
#include <QAction>
#include <ConnectionStyle>
#include <DataFlowGraphModel>
#include <DataFlowGraphicsScene>
#include <GraphicsView>
#include <NodeData>
#include <NodeDelegateModelRegistry>
#include <QPushButton>
#include <QtGui/QScreen>

CANTestDevStudio::CANTestDevStudio(QWidget *parent)
    : QMainWindow(parent), nodewidget(nullptr)
{
    ui.setupUi(this);
    InitializationUI();
}

CANTestDevStudio::~CANTestDevStudio()
{
    if (nodewidget)
    {
        delete nodewidget;
        nodewidget = nullptr;
    }
}

void CANTestDevStudio::InitializationUI()
{
    menuInitialization();
    toolsBarInitialization();
}

void CANTestDevStudio::toolsBarInitialization()
{
    QPushButton* openNodeWindow = new QPushButton(this);
    openNodeWindow->setText(tr("NodeWindow"));
    openNodeWindow->setCheckable(true);
    connect(openNodeWindow, &QPushButton::clicked, this, &CANTestDevStudio::on_openNodeWindow_clicked);
    ui.mainToolBar->addWidget(openNodeWindow);
}

void CANTestDevStudio::menuInitialization()
{
    QMenu* menu = new QMenu(this);
    menu->setTitle("File");
    QAction* newfile = new QAction(this);
    newfile->setText(tr("New"));
    QAction* openfile = new QAction(this);
    openfile->setText(tr("Open"));
    QAction* savefile = new QAction(this);
    savefile->setText(tr("Save"));
    menu->addAction(newfile);
    menu->addAction(openfile);
    menu->addAction(savefile);
    ui.menuBar->addMenu(menu);
}
void CANTestDevStudio::on_openNodeWindow_clicked(bool b)
{
    if (b)
    {
        if (!nodewidget)
        {
            nodewidget = new NodeWindow();
            
        }
        nodewidget->show();
    }
}