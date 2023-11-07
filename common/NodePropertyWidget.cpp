#include "NodePropertyWidget.h"
#include "common/CommonDataStruct.h"
#include "common/NodeGlobeData.h"
#include <QTableWidget>
#include <QHBoxLayout>

#include <QComboBox>
#pragma execution_character_set("utf-8") 
NodePropertyWidget::NodePropertyWidget(DataFlowGraphModel* model, DataFlowGraphicsScene* grapshics,QWidget *parent)
	:m_model(model), m_grapshics(grapshics), QWidget(parent)
{
	ui.setupUi(this);
	
	ParamInit();
	UiInit();
}

NodePropertyWidget::~NodePropertyWidget()
{

}

void NodePropertyWidget::nodeClickedReacting(NodeId id)
{
	if (!m_model)
	{
		return;
	}
	if (!m_grapshics) 
	{ 
		return; 
	}
	if ("CAN" == m_model->nodeData(id, QtNodes::NodeRole::Type))
	{
		nodeDeviceCANPropertyShow(id);
	}
	else if ("LIN" == m_model->nodeData(id, QtNodes::NodeRole::Type))
	{
		nodeDeviceLINPropertyShow(id);
	}
}

void NodePropertyWidget::nodeDeviceCANPropertyShow(NodeId id)
{
	if (!m_propertyTable)
	{
		return;
	}
	//Reset the Table
	int rowcount = m_propertyTable->rowCount();
	for (int i = 0; i < rowcount; i++)
		m_propertyTable->removeRow(rowcount - i - 1);//remove from back to front


	NodeGlobeData& pGd = NodeGlobeData::getInstance();
	//if ID not find in map,break;
	if (pGd.pData.find(id) == pGd.pData.end())
	{
		return;
	}
	//get data by Id
	CommonData::NodeData& nData = pGd.pData.at(id);
	//Convert data type
	CommonData::DevCanParam devParem = nData.ModelParam.value<CommonData::DevCanParam>();
	m_propertyTable->setRowCount(5);
	m_propertyTable->setColumnCount(2);
	//Node name
	m_propertyTable->setItem(0, 0, new QTableWidgetItem(QString::fromLocal8Bit("Node名称 ")));
	m_propertyTable->setItem(0, 1, new QTableWidgetItem(nData.nodeName));
	//Node id
	m_propertyTable->setItem(1, 0, new QTableWidgetItem(QString::fromLocal8Bit("NodeID")));
	m_propertyTable->setItem(1, 1, new QTableWidgetItem(QString::number(nData.uId)));
	QTableWidgetItem* titem = m_propertyTable->item(1, 1);
	//No Editable
	if (titem) { titem->setFlags(titem->flags() & (~Qt::ItemIsEditable)); }

	//CAN type
	m_propertyTable->setItem(2, 0, new QTableWidgetItem(QString::fromLocal8Bit("CAN类型 ")));
	QComboBox* qCombox = new QComboBox(m_propertyTable);
	qCombox->addItems(m_qsCANType);
	qCombox->setCurrentIndex(devParem.uCANType);
	m_propertyTable->setCellWidget(2,1, qCombox);

	//CAN channel
	m_propertyTable->setItem(3, 0, new QTableWidgetItem(QString::fromLocal8Bit("CAN通道 ")));
	QComboBox* qComboxChannel = new QComboBox(m_propertyTable);
	qComboxChannel->addItems(m_qsCANChannel);
	qComboxChannel->setCurrentIndex(devParem.cChannel);
	m_propertyTable->setCellWidget(3, 1, qComboxChannel);

	//CAN bundrate
	m_propertyTable->setItem(4, 0, new QTableWidgetItem(QString::fromLocal8Bit("波特率")));
	QComboBox* qComboxBaud = new QComboBox(m_propertyTable);
	for (auto i : m_qlBaudRate)
	{
		qComboxBaud->addItem(QString::number(i));
	}
	qComboxBaud->setCurrentIndex(m_qlBaudRate.indexOf(devParem.uBaudRate));
	m_propertyTable->setCellWidget(4, 1, qComboxBaud);

	//Build slots, Notic:using QOVerload<param...>of(& arg)
	connect(qCombox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &NodePropertyWidget::on_CANTypeCombobox_IndexChanged);
	connect(qComboxChannel, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &NodePropertyWidget::on_CANTypeCombobox_IndexChanged);
	connect(qComboxBaud, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &NodePropertyWidget::on_CANTypeCombobox_IndexChanged);
}

void NodePropertyWidget::nodeDeviceLINPropertyShow(NodeId id)
{
	if (!m_propertyTable)
	{
		return;
	}
	//Reset the Table
	int rowcount = m_propertyTable->rowCount();
	for (int i = 0; i < rowcount; i++)
		m_propertyTable->removeRow(rowcount - i - 1);//remove from back to front


	NodeGlobeData& pGd = NodeGlobeData::getInstance();
	//if ID not find in map,break;
	if (pGd.pData.find(id) == pGd.pData.end())
	{
		return;
	}
	//get data by Id
	CommonData::NodeData& nData = pGd.pData.at(id);
	//Convert data type
	CommonData::DevLINParam devParem = nData.ModelParam.value<CommonData::DevLINParam>();
	m_propertyTable->setRowCount(5);
	m_propertyTable->setColumnCount(2);
	//Node name
	m_propertyTable->setItem(0, 0, new QTableWidgetItem(QString::fromLocal8Bit("Node名称 ")));
	m_propertyTable->setItem(0, 1, new QTableWidgetItem(nData.nodeName));
	//Node id
	m_propertyTable->setItem(1, 0, new QTableWidgetItem(QString::fromLocal8Bit("NodeID")));
	m_propertyTable->setItem(1, 1, new QTableWidgetItem(QString::number(nData.uId)));
	QTableWidgetItem* titem = m_propertyTable->item(1, 1);
	//No Editable
	if (titem) { titem->setFlags(titem->flags() & (~Qt::ItemIsEditable)); }

	//LIN type
	m_propertyTable->setItem(2, 0, new QTableWidgetItem(QString::fromLocal8Bit("LIN类型 ")));
	QComboBox* qCombox = new QComboBox(m_propertyTable);
	qCombox->addItems(m_qsLINType);
	qCombox->setCurrentIndex(devParem.uLINType);
	m_propertyTable->setCellWidget(2, 1, qCombox);

	//LIN channel
	m_propertyTable->setItem(3, 0, new QTableWidgetItem(QString::fromLocal8Bit("LIN通道 ")));
	QComboBox* qComboxChannel = new QComboBox(m_propertyTable);
	qComboxChannel->addItems(m_qsCANChannel);
	qComboxChannel->setCurrentIndex(devParem.cChannel);
	m_propertyTable->setCellWidget(3, 1, qComboxChannel);

	//LIN bundrate
	m_propertyTable->setItem(4, 0, new QTableWidgetItem(QString::fromLocal8Bit("波特率")));
	QComboBox* qComboxBaud = new QComboBox(m_propertyTable);
	for (auto i : m_qlBaudRate)
	{
		qComboxBaud->addItem(QString::number(i));
	}
	qComboxBaud->setCurrentIndex(m_qlBaudRate.indexOf(devParem.uBaudRate));
	m_propertyTable->setCellWidget(4, 1, qComboxBaud);

	
}
void NodePropertyWidget::on_CANTypeCombobox_IndexChanged(int index)
{
	if (!m_grapshics) { return; }
	if (!m_propertyTable) { return; }
	//Get Node Id from table
	uint nId = m_propertyTable->item(1, 1)->text().toUInt();
	//Find the ID from selectedNodes
	//auto result = std::find_if(m_grapshics->selectedNodes().cbegin(), m_grapshics->selectedNodes().cend(), [nId](uint x) {return x == nId; });
	bool b_find = false;
	for (auto i : m_grapshics->selectedNodes())
	{
		if (i == nId)
		{
			b_find = true;
		}
	}
	//if the node not select,return
	if(!b_find)
	{
		return;
	}
	
	int current_row = m_propertyTable->currentRow();
	if (current_row < 0) { return; }

	QComboBox* cb = dynamic_cast<QComboBox*>(sender());
	if (!cb) { return; }

	NodeGlobeData& pGd = NodeGlobeData::getInstance();
	//if ID not find in map,break;
	if (pGd.pData.find(nId) == pGd.pData.end())
	{
		return;
	}
	//get data by Id
	CommonData::NodeData& nData = pGd.pData.at(nId);
	//Convert data type
	CommonData::DevCanParam devParem = nData.ModelParam.value<CommonData::DevCanParam>();
	switch (current_row)
	{
	case 2:
		devParem.uCANType = index;
		break;
	case 3:
		devParem.cChannel = index;
		break;
	case 4:
	{
		switch (index)
		{
		case 0:
			devParem.uBaudRate = 19200;
			break;
		case 1:
			devParem.uBaudRate = 125000;
			break;
		case 2:
			devParem.uBaudRate = 250000;
			break;
		case 3:
			devParem.uBaudRate = 500000;
			break;
		default:
			break;
		}
	}
		break;
	default:
		break;
	}
	pGd.pData.at(nId).ModelParam = QVariant::fromValue(devParem);
}
void NodePropertyWidget::UiInit()
{
	m_propertyTable = new QTableWidget(this);
	QHBoxLayout* hlayout = new QHBoxLayout(this);
	hlayout->addWidget(m_propertyTable);
	m_propertyTable->setColumnCount(2);
	QStringList headername{ QString::fromLocal8Bit("参数"),QString::fromLocal8Bit("值") };
	m_propertyTable->setHorizontalHeaderLabels(headername);
	hlayout->setContentsMargins(1, 0, 0, 0);
	hlayout->setSpacing(0);
}

void NodePropertyWidget::ParamInit()
{
	m_qsCANType.append("PCAN");
	m_qsCANType.append("CANalyst");
	m_qsCANType.append("ZLG2EU");
	m_qsLINType.append("PLIN");
	m_qsLINType.append("TLIN");
	m_qsLINType.append("ZLIN");
	m_qsCANChannel.append("Ch-1");
	m_qsCANChannel.append("Ch-2");
	m_qlBaudRate.append(19200);
	m_qlBaudRate.append(125000);
	m_qlBaudRate.append(250000);
	m_qlBaudRate.append(500000);
}
