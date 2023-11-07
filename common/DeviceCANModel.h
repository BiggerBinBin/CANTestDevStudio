#pragma once

#include <NodeDelegateModel>
#include <QtCore/QJsonObject>
#include <QtCore/QObject>
#include <QtWidgets/QLabel>
#include <iostream>
class QTableWidget;
class DecimalData;
using QtNodes::NodeData;
using QtNodes::NodeDataType;
using QtNodes::NodeDelegateModel;
using QtNodes::PortIndex;
using QtNodes::PortType;
class DeviceCANModel : public NodeDelegateModel
{
	Q_OBJECT

public:
	//DeviceModel(QObject *parent);
	~DeviceCANModel()=default;
public:
	unsigned int nPorts(PortType portType) const override; //OK
	NodeDataType dataType(PortType portType, PortIndex portIndex) const override; //OK
	std::shared_ptr<NodeData> outData(PortIndex port) override; //OK
	void setInData(std::shared_ptr<NodeData>data, PortIndex portIndex) override;
	QWidget* embeddedWidget() override;
	/// Caption is used in GUI
	QString caption() const override;
	/// Name makes this model unique
	QString name() const override;
	QTableWidget* propertyTable()override;

protected:
	std::weak_ptr<DecimalData> _number1;
	std::weak_ptr<DecimalData> _number2;
	std::shared_ptr<DecimalData> _result;
	QTableWidget* peopertytable = nullptr;
};
