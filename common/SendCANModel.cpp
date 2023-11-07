#include "SendCANModel.h"
#include "./common/DecimalData.h"
#include <QTableWidget>
//DeviceModel::DeviceModel(QObject *parent)
//	: NodeDelegateModel(parent)
//{}

unsigned int SendCANModel::nPorts(PortType portType) const
{
	unsigned int result;
	if (portType == PortType::In)
		result = 1;
	else
		result = 1;

	return result;
}

NodeDataType SendCANModel::dataType(PortType portType, PortIndex portIndex) const
{
	return DecimalData().type();
}

std::shared_ptr<NodeData> SendCANModel::outData(PortIndex port)
{
	return std::static_pointer_cast<NodeData>(_result);
}

void SendCANModel::setInData(std::shared_ptr<NodeData> data, PortIndex portIndex)
{
	auto numberData = std::dynamic_pointer_cast<DecimalData>(data);

	if (!data) {
		Q_EMIT dataInvalidated(0);
	}

	if (portIndex == 0) {
		_number1 = numberData;
	}
	else {
		_number2 = numberData;
	}
	PortIndex const outPortIndex = 0;

	auto n1 = _number1.lock();
	auto n2 = _number2.lock();

	if (n1 && n2) {
		_result = std::make_shared<DecimalData>(n1->number() + n2->number());
	}
	else {
		_result.reset();
	}

	Q_EMIT dataUpdated(outPortIndex);
	//compute();
}

QWidget* SendCANModel::embeddedWidget()
{
	return nullptr;
}

QString SendCANModel::caption() const
{
	return QStringLiteral("SendCANMsg");
}

QString SendCANModel::name() const
{
	return QStringLiteral("SendCANMsg");
}

QTableWidget* SendCANModel::propertyTable()
{
	if (!peopertytable)
	{
		peopertytable = new QTableWidget();
		peopertytable->setColumnCount(2);

	}
	return peopertytable;
}

//DeviceModel::~DeviceModel()
//{}
