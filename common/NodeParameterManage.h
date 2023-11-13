#pragma once
#include <string>
#include <functional>
#include <map>
namespace NodeParameterCreate
{
#define _CAN_ "CAN"
#define _LIN_ "LIN"
#define _SEND_CAN_ "SEND_CAN"
#define _SEND_LIN_ "SEND_LIN"
	enum TypeN{
		NODE_CAN = 0,
		NODE_LIN,
		NODE_SEND_CAN,
		NODE_SEND_LIN
	};
	class BindKeyStr
	{
	public:
		static std::map<std::string,TypeN> createMap()
		{
			std::map<std::string, TypeN> cmap;
			cmap.insert(std::pair<std::string,TypeN>( _CAN_, NODE_CAN));
			cmap.insert(std::pair<std::string, TypeN>(_LIN_,NODE_LIN));
			cmap.insert(std::pair<std::string, TypeN>(_SEND_CAN_,NODE_SEND_CAN));
			cmap.insert(std::pair<std::string, TypeN>(_SEND_LIN_,NODE_SEND_CAN));
			return cmap;
		}
		static  std::map<std::string,TypeN>keyToStr;
	};
	bool createNodeParamter(const std::string& type, uint32_t id);
	bool deteleNodeParamter(uint32_t id);
	void createCAN(uint32_t id);
	void createLIN(uint32_t id);
	void createSendCAN(uint32_t id);
	void createSendLIN(uint32_t id);
};

