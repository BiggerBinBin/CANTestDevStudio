#include <qapplication.h>
#include <qmessagebox.h>
#include <QDir>
#include <QJsonDocument>	// ����Json
#include <QJsonArray>		// [ ]
#include <QJsonObject>		// { }
#include <QJsonValue>		// int float double null { } [ ]
#include <QJsonParseError>
#include <QMutex>
#include "NodeGlobeData.h"

//NodeGlobeData::NodeGlobeData()
//{
//}
//
//NodeGlobeData::~NodeGlobeData()
//{
//}

void NodeGlobeData::saveGlobeData()
{
	QMutex mutex;
	QString appPath = QApplication::applicationDirPath() + "/Data";
	QDir dir(appPath);
	if (!dir.exists())
	{
		if (!dir.mkpath(appPath))
		{
			QMessageBox::warning(NULL, QObject::tr("warning"), QObject::tr("��������Ŀ¼ʧ�� "));
			return;
		}
	}

	QJsonObject mItemObjRoot;
	//for (int i = 0; i < pData.size(); ++i)
	for(auto it = pData.cbegin();it!=pData.cend();it++)
	{
		QJsonObject mItem;
		mItem.insert("nodeType", it->second.paraType);
		mItem.insert("nodeName", it->second.nodeName);

		//input data id and port
		QJsonObject mPreIDItem;
		for (int i = 0; i < it->second.vecPreId.size(); i++)
		{
			QJsonArray preID;
			preID.append((int)it->second.vecPreId.at(i).objId);
			preID.append((int)it->second.vecPreId.at(i).portIndex);
			mPreIDItem.insert(QString::number(i), preID);
		}
		mItem.insert("mPreIDItem", mPreIDItem);

		//output data id and port
		QJsonObject mNextIDItem;
		for (int i = 0; i < it->second.vecNextId.size(); i++)
		{
			QJsonArray nextID;
			nextID.append((int)it->second.vecNextId.at(i).objId);
			nextID.append((int)it->second.vecNextId.at(i).portIndex);
			mNextIDItem.insert(QString::number(i), nextID);
		}
		mItem.insert("mNextIDItem", mNextIDItem);
		//output end=======
		
		//real struct data from different Node type;
		QJsonObject realParamItem = qvariantToRealType(it->second.paraType, it->second.ModelParam);
		mItem.insert("realParamItem", realParamItem);

		//root item
		mItemObjRoot.insert(QString::number(it->first), mItem);
	}

	// ��json�����������ת��Ϊ�ַ���
	QJsonDocument doc;
	// ��object����λ���ĵ�����Ҫ����
	doc.setObject(mItemObjRoot);
	appPath += "/appData.json";
	QFile file(appPath);
	if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate))
	{
		return;
	}
	QTextStream stream(&file);
	stream.setCodec("UTF-8");
	stream << doc.toJson();
	file.close();
}

void NodeGlobeData::loadGlobeData()
{
	pData.clear();
	QString appPath = QApplication::applicationDirPath() + "/Data/appData.json";
	QFile file(appPath);
	if (!file.exists())
	{
		QMessageBox::warning(NULL, QObject::tr("warning"), QObject::tr("���ݲ����ڣ���ʼ������ʧ�� "));
		return;
	}
	//���ļ���ֻ��ģʽ�����ʧ�ܣ���return
	if (!file.open(QFile::ReadOnly))
	{
		QMessageBox::warning(NULL, QObject::tr("warning"), QObject::tr("���ݲ����ڣ���ʼ������ʧ�� "));
		return;
	}
	QTextStream readStream(&file);

	//��text�������ڴ���
	QTextStream readStrem(&file);
	//���ø�ʽΪutf-8
	readStrem.setCodec("UTF-8");
	//��ȡ����
	QString str = readStrem.readAll();
	//����֮��ǵ�Ҫclose����ֹ�����쳣�˳���������
	file.close();

	QJsonParseError jsonError;
	//����Ϊjson�ĵ�
	QJsonDocument doc = QJsonDocument::fromJson(str.toUtf8(), &jsonError);
	if (jsonError.error != QJsonParseError::NoError)
	{
		QMessageBox::warning(NULL, QObject::tr("warning"), QString(QObject::tr("����jsonʧ�ܣ� ") + jsonError.errorString()));
		return;
	}
	//ת����json object
	QJsonObject rootObj = doc.object();
	//��ȡ����key
	QStringList keyList = rootObj.keys();
	//����key���б���
	for (int i = 0; i < keyList.size(); i++)
	{
		if (rootObj[keyList.at(i)].type() != QJsonValue::Object)
			continue;
		QJsonObject rootSecond = rootObj[keyList.at(i)].toObject();

		CommonData::NodeData node;
		node.uId = keyList.at(i).toInt();
		node.nodeName = rootSecond["nodeName"].toString();
		node.paraType = rootSecond["nodeType"].toString();
		//��ȡ�����Node��Id��port
		if (rootSecond["mPreIDItem"].type() == QJsonValue::Object)
		{
			QJsonObject rootthrid = rootSecond["mPreIDItem"].toObject();
			//��ȡ�������еļ�ֵ
			QStringList keyListthrid = rootthrid.keys();
			for (int j = 0; j < keyListthrid.size(); j++)
			{
				//��������ͽ�������
				if (rootthrid[keyListthrid.at(j)].type() != QJsonValue::Array)
					continue;
				QJsonArray preJson = rootthrid[keyListthrid.at(j)].toArray();
				CommonData::conectProperties cp;
				//����������2������2�Ϳ��ܳ�����
				if (preJson.size() < 2)
					continue;
				cp.objId = preJson[0].toInt();
				cp.portIndex = preJson[1].toInt();
				node.vecPreId.emplace_back(cp);
			}
		}

		//��ȡ�����Node��Id��port
		if (rootSecond["mNextIDItem"].type() == QJsonValue::Object)
		{
			QJsonObject rootthrid = rootSecond["mNextIDItem"].toObject();
			//��ȡ�������еļ�ֵ
			QStringList keyListthrid = rootthrid.keys();
			for (int j = 0; j < keyListthrid.size(); j++)
			{
				//��������ͽ�������
				if (rootthrid[keyListthrid.at(j)].type() != QJsonValue::Array)
					continue;
				QJsonArray preJson = rootthrid[keyListthrid.at(j)].toArray();
				CommonData::conectProperties cp;
				//����������2������2�Ϳ��ܳ�����
				if (preJson.size() < 2)
					continue;
				cp.objId = preJson[0].toInt();
				cp.portIndex = preJson[1].toInt();
				node.vecNextId.emplace_back(cp);
			}
		}
		QVariant var = ObjectToQvariant(node.paraType, rootSecond["realParamItem"].toObject());
		node.ModelParam = var;
		pData.insert(std::pair<uint, CommonData::NodeData>(node.uId, node));
	}

}

QJsonObject NodeGlobeData::qvariantToRealType(const QString& type, const QVariant& var)
{
	QJsonObject obj;
	if ("CAN" == type)
	{
		CommonData::DevCanParam dp = var.value<CommonData::DevCanParam>();
		obj.insert("cChannel", dp.cChannel);
		obj.insert("uBaudRate", (int)dp.uBaudRate);
		obj.insert("uCANType", (int)dp.uCANType);
	}
	else if ("LIN" == type)
	{
		CommonData::DevLINParam dp = var.value<CommonData::DevLINParam>();
		obj.insert("cChannel", dp.cChannel);
		obj.insert("uBaudRate", (int)dp.uBaudRate);
		obj.insert("uLINType", (int)dp.uLINType);
	}
	return obj;
}

QVariant NodeGlobeData::ObjectToQvariant(const QString& type, const QJsonObject& obj)
{
	QVariant var;
	if ("CAN" == type)
	{
		CommonData::DevCanParam dp;
		dp.cChannel = obj["cChannel"].toInt(0);
		dp.uBaudRate = obj["uBaudRate"].toInt(250000);
		dp.uCANType = obj["uCANType"].toInt(0);
		var = QVariant::fromValue(dp);
	}
	else if ("LIN" == type)
	{
		CommonData::DevLINParam dp;
		dp.cChannel = obj["cChannel"].toInt(0);
		dp.uBaudRate = obj["uBaudRate"].toInt(250000);
		dp.uLINType = obj["uLINType"].toInt(0);
		var = QVariant::fromValue(dp);
	}
	return var;
}

