#pragma once
#include<vector>
#include<QVariant>
#include<QString>
namespace CommonData 
{
	struct DevCanParam
	{
		char cChannel;
		unsigned int uCANType;
		unsigned int uBaudRate;
		

	};
	Q_DECLARE_METATYPE(CommonData::DevCanParam)
		struct DevLINParam
	{
		char cChannel;
		unsigned int uLINType;
		unsigned int uBaudRate;
	};
	Q_DECLARE_METATYPE(CommonData::DevLINParam)
	struct conectProperties
	{
		unsigned int objId;
		unsigned short portIndex;
	};
	struct NodeData
	{
		unsigned int uId;
		std::vector<conectProperties>vecPreId;
		std::vector<conectProperties>vecNextId;
		QVariant ModelParam;
		QString nodeName;
		QString paraType;
	};
	Q_DECLARE_METATYPE(CommonData::NodeData)

	enum _NodeType {
		DEVICE_CAN = 0,
		DEVICE_LIN = 0,
		OPERATE_SEND = 0,
	};
}
