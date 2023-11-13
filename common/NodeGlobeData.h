#pragma once
#include "CommonDataStruct.h"
#include <unordered_map>
class QJsonObject;
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
	void saveGlobeData();
	void loadGlobeData();
private:
	//static NodeGlobeData& pNodeGlobeData;
	NodeGlobeData() {}
	NodeGlobeData(const NodeGlobeData&) = delete;
	NodeGlobeData& operator=(const NodeGlobeData&) = delete;

	QJsonObject qvariantToRealType(const QString &type,const QVariant&);
	QVariant ObjectToQvariant(const QString &type,const QJsonObject&);
};

