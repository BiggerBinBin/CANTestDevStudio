#include "NodeParameterManage.h"
#include "common/CommonDataStruct.h"
#include "common/NodeGlobeData.h"


namespace NodeParameterCreate
{
	std::map<std::string,TypeN> BindKeyStr::keyToStr = BindKeyStr::createMap();
	bool createNodeParamter(const std::string& type, uint32_t id)
	{
		TypeN key = BindKeyStr::keyToStr.at(type);
		switch (key)
		{
		case NODE_CAN:
			createCAN(id);
			break;
		case NODE_LIN:
			createLIN(id);
			break;
		case NODE_SEND_CAN:
			createSendCAN(id);
			break;
		case NODE_SEND_LIN:
			createSendLIN(id);
			break;
		default:
			break;
		}
		
		return true;
	}

	bool deteleNodeParamter(uint32_t id)
	{
		return false;
	}
	void createCAN(uint32_t id)
	{
		NodeGlobeData& pGd = NodeGlobeData::getInstance();
		CommonData::NodeData str;
		CommonData::DevCanParam devcan;
		devcan.cChannel = 0;
		devcan.uBaudRate = 250000;
		devcan.uCANType = 0;
		str.ModelParam = QVariant::fromValue(devcan);
		str.nodeName = "CAN";
		str.uId = id;
		str.paraType = "CAN";
		pGd.pData.insert(std::make_pair(id, str));
	}
	void createLIN(uint32_t id)
	{
		NodeGlobeData& pGd = NodeGlobeData::getInstance();
		CommonData::NodeData str;
		CommonData::DevLINParam devcan;
		devcan.cChannel = 0;
		devcan.uBaudRate = 19200;
		devcan.uLINType = 0;
		str.ModelParam = QVariant::fromValue(devcan);
		str.nodeName = "LIN";
		str.uId = id;
		str.paraType = "LIN";
		pGd.pData.insert(std::make_pair(id, str));
	}
	void createSendCAN(uint32_t id)
	{

	}
	void createSendLIN(uint32_t id)
	{

	}
}