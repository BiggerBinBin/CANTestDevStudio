#pragma once

#include <QObject>
#include <Definitions>
#include <DataFlowGraphModel>
#include <DataFlowGraphicsScene.hpp>
using QtNodes::DataFlowGraphModel;
using QtNodes::DataFlowGraphicsScene;
using QtNodes::ConnectionId;
using QtNodes::NodeId;
class NodeFunctionStack  : public QObject
{
	Q_OBJECT

public:
	NodeFunctionStack(DataFlowGraphModel& _model, DataFlowGraphicsScene* graphic,QObject *parent=nullptr);
	~NodeFunctionStack();

public Q_SLOTS:
	void connectionCreated(ConnectionId const connectionId);
	void connectionDeleted(ConnectionId const connectionId);
	void nodeCreated(NodeId const connectionId);
	void nodeDeleted(NodeId const connectionId);
private:
	DataFlowGraphModel& _model;
	DataFlowGraphicsScene* _graphic;
};
