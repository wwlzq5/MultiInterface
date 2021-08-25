#ifndef DATABASE_H
#define DATABASE_H
#include "qsqldatabase.h"
#include "qsqlquery.h"
#include "qsqldriver.h"
#include "qsqlrecord.h"
struct TemporaryData{
	long long id[50];
	int nCameraTypeCount[50]; //某种缺陷的踢废总数
	int nAllCount; //当前过检数目
	int nFailCount; //当前踢废数目
	int nTypeCount[30][50]; //每个相机对应的一种缺陷踢废数
};
struct SeleteData{
	long long id;
	int nCameraTypeCount; //某种缺陷的踢废总数
	int nAllCount; //当前过检数目
	int nFailCount; //当前踢废数目
	int nType; //错误类型
	int nTypeCount[30]; //每个相机对应的一种缺陷踢废数
	void SeleteDatClear()
	{
		memset(this,0,sizeof(SeleteData));
	}
};
class DataBase
{
public:
	DataBase();

	enum QueryFlags{
		ByHalfanHour = 0 ,
		ByanHour
	};

public:
	bool createConnection();  //创建一个连接
	bool createTable();       //创建数据库表
	bool insert(QString,TemporaryData,int);            //出入数据
	QList<SeleteData> queryAll(QString id,int);          //查询一天所有信息
	QList<SeleteData> queryAllByOrder(QString id);          //查询一天所有信息 降序
	QList<SeleteData> queryAll(QString startTime,QString endTime,int);          //查询所有信息
	QList<SeleteData> queryOnce(QString id);          //查询一次记录数据
	bool updateById(int id);  //更新
	bool deleteById(int id);  //删除
	bool deleteFromDate(QString dateId);  //删除指定日期之前的数据记录
	QList<SeleteData> sortById(QString);          //排序
public:
	TemporaryData m_MyData;
	QString nName[3];
	int nCountCamera[3];
};
#endif