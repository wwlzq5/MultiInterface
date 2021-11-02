#ifndef DATABASE_H
#define DATABASE_H

#include "qsqldatabase.h"
#include "qsqlquery.h"
#include "qsqldriver.h"
#include "qsqlrecord.h"
#include <QVariant>
#include "widget_count.h"

class DataBase
{
public:
	DataBase(QString spath);

public:
	bool createConnection();  //创建一个连接
	bool createReportTable();       //创建数据库表
	bool createLastDataTable();       //创建用于保存上一次历史数据的表
	bool insert(QString timestr,cErrorInfo info);
	bool queryByOnce(QString timeStr,long long &ptime,cErrorInfo &info);										//timeStr: yyyyMMddhhmm
	bool queryByDay(QString dayStr,QList<long long> &pTimes,QList<cErrorInfo> &infos);							//daystr : yyyyMMdd
	bool queryByShift(QString pStartTime,QString pEndTime,QList<long long> &pTimes,QList<cErrorInfo> &infos);	//daystr : yyyyMMdd
	bool insertLastData(int AllCount,int failCount,cErrorInfo info);																		//插入历史数据
	bool queryLastData(int &AllCount,int &failCount,cErrorInfo &info);																		//查询历史数据

private:
	QString sqlConnectName;
	QString AppPath;
};
#endif