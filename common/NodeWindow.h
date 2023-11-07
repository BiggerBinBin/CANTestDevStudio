#pragma once

#include <QWidget>
#include "ui_NodeWindow.h"
#include <Definitions.hpp>
#include <DataFlowGraphicsScene>
using QtNodes::NodeId;
using QtNodes::DataFlowGraphicsScene;
class NodePropertyWidget;
class QHBoxLayout;
class NodeWindow : public QWidget
{
	Q_OBJECT

public:
	NodeWindow(QWidget *parent = nullptr);
	~NodeWindow();

private:
	Ui::NodeWindowClass ui;
	QWidget* window;
	QHBoxLayout* h = nullptr;
	NodePropertyWidget* npro = nullptr;
	DataFlowGraphicsScene* m_DflowGraphics = nullptr;
private Q_SLOTS:
	void on_upNodeProperty_slot(NodeId id);
};
