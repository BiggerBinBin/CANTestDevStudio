#include "NodeFunctionStack.h"
#include <QMessageBox>
#include <QDebug>
//#include "common/CommonDataStruct.h"
#include "common/NodeGlobeData.h"
#include "common/DeviceCANModel.h"
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
	if (_model.nodeData(Id, QtNodes::NodeRole::Type) == "CAN")
	{
		CommonData::NodeData str;
		CommonData::DevCanParam devcan;
		devcan.cChannel = 0;
		devcan.uBaudRate = 250000;
		devcan.uCANType = 0;
		str.ModelParam = QVariant::fromValue(devcan);
		str.nodeName = "CAN";
		str.uId = Id;
		str.paraType = "CAN";
		pGd.pData.insert(std::make_pair(Id, str));

	}
	else if (_model.nodeData(Id, QtNodes::NodeRole::Type) == "LIN")
	{
		CommonData::NodeData str;
		CommonData::DevLINParam devcan;
		devcan.cChannel = 0;
		devcan.uBaudRate = 19200;
		devcan.uLINType = 0;
		str.ModelParam = QVariant::fromValue(devcan);
		str.nodeName = "LIN";
		str.uId = Id;
		str.paraType = "LIN";
		pGd.pData.insert(std::make_pair(Id, str));

	}
}

void NodeFunctionStack::nodeDeleted(NodeId const Id)
{
	qDebug()<<"select id:"<<_graphic->selectedNodes().size();
}
