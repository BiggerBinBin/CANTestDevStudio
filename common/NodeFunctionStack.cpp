#include "NodeFunctionStack.h"
#include <QMessageBox>
#include <QDebug>
//#include "common/CommonDataStruct.h"
#include "common/NodeGlobeData.h"
#include "common/DeviceCANModel.h"
#include "common/NodeParameterManage.h"
NodeFunctionStack::NodeFunctionStack(DataFlowGraphModel& model, DataFlowGraphicsScene* graphic,QObject *parent)
	: _model(model), _graphic(graphic), QObject(parent)
{

}

NodeFunctionStack::~NodeFunctionStack()
{

}

void NodeFunctionStack::connectionCreated(ConnectionId const connectionId)
{
	qDebug() << "In_ID:" << connectionId.inNodeId;
	qDebug() << "Out_ID:" << connectionId.outNodeId;
	
}

void NodeFunctionStack::connectionDeleted(ConnectionId const connectionId)
{
	qDebug() << "In_ID:" << connectionId.inNodeId;
	qDebug() << "Out_ID:" << connectionId.outNodeId;
}

void NodeFunctionStack::nodeCreated(NodeId const Id)
{
	//QMessageBox::information(nullptr, tr("Tips"), tr("Node delete"));
	qDebug() << "ID:" << Id;
	qDebug() << _model.nodeData(Id, QtNodes::NodeRole::Type);
	
	NodeGlobeData&pGd = NodeGlobeData::getInstance();
	NodeParameterCreate::createNodeParamter(_model.nodeData(Id, QtNodes::NodeRole::Type).toString().toStdString(), Id);
	
}

void NodeFunctionStack::nodeDeleted(NodeId const Id)
{
	qDebug()<<"select id:"<<_graphic->selectedNodes().size();
}
