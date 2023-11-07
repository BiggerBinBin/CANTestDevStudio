#include <ConnectionStyle>

#include <DataFlowGraphicsScene>
#include <GraphicsView>
#include <NodeData>
#include <NodeDelegateModelRegistry>

#include <QtGui/QScreen>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QVBoxLayout>

#include <QtGui/QScreen>
#include "NodeWindow.h"
#include "./common/DeviceLINModel.h"
#include "./common/DeviceCANModel.h"
#include "./common/SendCANModel.h"
#include <DataFlowGraphModel>

#include "NodeFunctionStack.h"
#include "./common/NodePropertyWidget.h"
#include <qdebug.h>
using QtNodes::ConnectionStyle;
using QtNodes::DataFlowGraphModel;
//using QtNodes::DataFlowGraphicsScene;
using QtNodes::GraphicsView;
using QtNodes::NodeDelegateModelRegistry;
/*namespace NodeParam*/ 

    static std::shared_ptr<NodeDelegateModelRegistry> registerDataModels()
    {
        auto ret = std::make_shared<NodeDelegateModelRegistry>();

        ret->registerModel<DeviceLINModel>(QString::fromLocal8Bit("设备"));
        ret->registerModel<DeviceCANModel>(QString::fromLocal8Bit("设备"));
        ret->registerModel<SendCANModel>(QString::fromLocal8Bit("Operator"));

        return ret;
    }

    static void _setStyle()
    {
        ConnectionStyle::setConnectionStyle(
            R"(
  {
    "ConnectionStyle": {
      "ConstructionColor": "gray",
      "NormalColor": "black",
      "SelectedColor": "gray",
      "SelectedHaloColor": "deepskyblue",
      "HoveredColor": "deepskyblue",

      "LineWidth": 3.0,
      "ConstructionLineWidth": 2.0,
      "PointDiameter": 10.0,

      "UseDataDefinedColors": true
    }
  }
  )");
    
}
std::shared_ptr<NodeDelegateModelRegistry> registry = registerDataModels();
static DataFlowGraphModel dataFlowGraphModel(registry);
NodeWindow::NodeWindow(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
    //window = new QWidget(this);
    _setStyle();
    

    auto menuBar = new QMenuBar();
    QMenu* menu = menuBar->addMenu("File");
    auto saveAction = menu->addAction("Save Scene");
    auto loadAction = menu->addAction("Load Scene");
    QVBoxLayout* l = new QVBoxLayout(this);
    /*QHBoxLayout* */h = new QHBoxLayout(this);
    //这个数据结构不能是局部变量
   
    l->addWidget(menuBar);
    m_DflowGraphics = new DataFlowGraphicsScene(dataFlowGraphModel,this);
    auto view = new GraphicsView(m_DflowGraphics);
    /*NodePropertyWidget* */npro = new NodePropertyWidget(&dataFlowGraphModel, m_DflowGraphics,this);
    qDebug() << "npro:" << npro;
    h->addWidget(npro);
    h->addWidget(view);
    h->setStretch(0, 1);
    h->setStretch(1, 4);
    l->addLayout(h);
    /*l->addWidget(view);*/
    l->setContentsMargins(0, 0, 0, 0);
    l->setSpacing(2);

    QObject::connect(saveAction, &QAction::triggered, m_DflowGraphics, &DataFlowGraphicsScene::save);

    QObject::connect(loadAction, &QAction::triggered, m_DflowGraphics, &DataFlowGraphicsScene::load);

    QObject::connect(m_DflowGraphics, &DataFlowGraphicsScene::sceneLoaded, view, &GraphicsView::centerScene);
    static NodeFunctionStack nfs(dataFlowGraphModel, m_DflowGraphics);
    QObject::connect(&dataFlowGraphModel, &DataFlowGraphModel::nodeCreated, &nfs, &NodeFunctionStack::nodeCreated);
    QObject::connect(&dataFlowGraphModel, &DataFlowGraphModel::connectionCreated, &nfs, &NodeFunctionStack::connectionCreated);
    QObject::connect(&dataFlowGraphModel, &DataFlowGraphModel::connectionDeleted, &nfs, &NodeFunctionStack::connectionDeleted);
    QObject::connect(&dataFlowGraphModel, &DataFlowGraphModel::nodeDeleted, &nfs, &NodeFunctionStack::nodeDeleted);
    QObject::connect(m_DflowGraphics, &DataFlowGraphicsScene::nodeHoverLeft, &nfs, &NodeFunctionStack::nodeDeleted);
    QObject::connect(m_DflowGraphics, &DataFlowGraphicsScene::nodeClicked, this, &NodeWindow::on_upNodeProperty_slot);
    this->resize(800, 600);
}

NodeWindow::~NodeWindow()
{

}

void NodeWindow::on_upNodeProperty_slot(NodeId id)
{
   
   // npro->nodeClickedReacting(id, m_DflowGraphics);
    npro->nodeClickedReacting(id);
}
