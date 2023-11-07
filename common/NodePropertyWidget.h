#pragma once

#include <QWidget>
#include "ui_NodePropertyWidget.h"
#include <DataFlowGraphicsScene.hpp>
#include <DataFlowGraphModel>
class QStringList;
using QtNodes::DataFlowGraphicsScene;
using QtNodes::DataFlowGraphModel;
class QTableWidget;
using QtNodes::NodeId;
class NodePropertyWidget : public QWidget
{
	Q_OBJECT

public:
	NodePropertyWidget(DataFlowGraphModel* model, DataFlowGraphicsScene* grapshics,QWidget *parent = nullptr);
	~NodePropertyWidget();
	void nodeClickedReacting(NodeId id);
private:
	Ui::NodePropertyWidgetClass ui;
	QTableWidget* m_propertyTable = nullptr;
	DataFlowGraphModel* m_model = nullptr;
	DataFlowGraphicsScene* m_grapshics = nullptr;
	//CAN type list,such as PCAN,CANalyst,ZLG...
	QStringList m_qsCANType;	
	//LIN type list,such as PLIN,Toosmoss,ZLIN...
	QStringList m_qsLINType;	
	//CAN channel list ,such as ch1,ch2...
	QStringList m_qsCANChannel;
	//CAN baudrate list,such as 19200,125000,250000,500000
	QList<uint32_t> m_qlBaudRate;

private:
	void nodeDeviceCANPropertyShow(NodeId id);
	void nodeDeviceLINPropertyShow(NodeId id);

private:
	void UiInit();
	void ParamInit();
private Q_SLOTS:
	void on_CANTypeCombobox_IndexChanged(int index);
};
