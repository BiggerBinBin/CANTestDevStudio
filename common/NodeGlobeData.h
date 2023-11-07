#pragma once
#include "CommonDataStruct.h"
#include <unordered_map>
class NodeGlobeData
{
public:
	static NodeGlobeData& getInstance()
	{
		static NodeGlobeData instance;
		return instance;
	}
public:
	std::unordered_map<uint, CommonData::NodeData>pData;
private:
	//static NodeGlobeData& pNodeGlobeData;
	NodeGlobeData() {}
	NodeGlobeData(const NodeGlobeData&) = delete;
	NodeGlobeData& operator=(const NodeGlobeData&) = delete;
	
};

