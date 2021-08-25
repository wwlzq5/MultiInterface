#include "database.h"
#include <Qdebug>
DataBase::DataBase()
{
	createConnection();
	createTable();
	memset(&m_MyData,0,sizeof(TemporaryData));
}
//建立一个数据库连接
bool DataBase::createConnection()
{
	//QStringList strlist = QSqlDatabase::drivers();
	//以后就可以用"sqlite1"与数据库进行连接了
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "sqlite1");
	db.setDatabaseName(".//Report.db");
	if( !db.open())
	{
		return false;
	}
	nName[0] = "Leading";
	nName[1] = "Clamping";
	nName[2] = "Backing";
	nCountCamera[0]=24;
	nCountCamera[1]=4;
	nCountCamera[2]=24;
	return true;
}

//创建数据库表
bool DataBase::createTable()
{
	QSqlDatabase db = QSqlDatabase::database("sqlite1"); //建立数据库连接
	QSqlQuery query(db);
	for(int i=0;i<3;i++)
	{
		QString sql = QString("create table %1(id varchar,AllCount int,TickCount int,type int,failCount int").arg(nName[i]);
		for(int j=1;j<=nCountCamera[i];j++)
		{
			sql+=QString(",camera%1 int").arg(j);
		}
		sql+=")";
		query.exec(sql);
	}
	return true;
}

//向数据库中插入记录
bool DataBase::insert(QString id,TemporaryData temp,int NameID)
{
	QSqlDatabase db = QSqlDatabase::database("sqlite1"); //建立数据库连接
	QSqlQuery query(db);
	QString sql="";
	for(int i=1;i<50;i++)
	{
		if(temp.nCameraTypeCount[i] == 0)
		{
			continue;
		}
		sql +=QString("insert into %1 values(").arg(nName[NameID]);
		sql += id;
		sql+=QString(",%1").arg(temp.nAllCount);
		sql+=QString(",%1").arg(temp.nFailCount);
		sql+=QString(",%1").arg(i);
		sql+=QString(",%1").arg(temp.nCameraTypeCount[i]);
		for(int j=0; j < nCountCamera[NameID]; j++)
		{
			sql+=QString(",%1").arg(temp.nTypeCount[j][i]);
		}
		sql+=")";
		query.exec(sql);
		sql.clear();
	}
	return true;
}

//查询所有信息
QList<SeleteData> DataBase::queryAll(QString id,int NameID)
{
	QSqlDatabase db = QSqlDatabase::database("sqlite1"); //建立数据库连接
	QSqlQuery query(db);
	query.exec(QString("select * from %1 where id like '%2%'").arg(nName[NameID]).arg(id));//20200921____
	QSqlRecord rec = query.record();
	QList<SeleteData> m_SeleteData;
	while(query.next())
	{
		SeleteData m_data;
		m_data.id = query.value(0).toLongLong();
		m_data.nAllCount = query.value(1).toInt();
		m_data.nFailCount = query.value(2).toInt();
		m_data.nType = query.value(3).toInt();
		m_data.nCameraTypeCount = query.value(4).toInt();
		for(int i = 0;i<nCountCamera[NameID];i++)
		{
			m_data.nTypeCount[i] = query.value(i+5).toInt();
		}
		m_SeleteData<<m_data;
	}
	return m_SeleteData;
}

QList<SeleteData> DataBase::queryAll(QString startTime,QString endTime,int NameID)
{
	QSqlDatabase db = QSqlDatabase::database("sqlite1"); //建立数据库连接
	QSqlQuery query(db);
	QString abc = QString("select * from %1 where id > %2 and id <= %3 ").arg(nName[NameID]).arg(startTime).arg(endTime);
	query.exec(abc);//20200921____

	QSqlRecord rec = query.record();
	QList<SeleteData> m_SeleteData;
	while(query.next())
	{
		SeleteData m_data;
		m_data.id = query.value(0).toLongLong();
		m_data.nAllCount = query.value(1).toInt();
		m_data.nFailCount = query.value(2).toInt();
		m_data.nType = query.value(3).toInt();
		m_data.nCameraTypeCount = query.value(4).toInt();
		for(int i = 0;i<nCountCamera[NameID];i++)
		{
			m_data.nTypeCount[i] = query.value(i+5).toInt();
		}
		m_SeleteData<<m_data;
	}
	return m_SeleteData;
}

//根据ID删除记录
bool DataBase::deleteById(int id)
{
	QSqlDatabase db = QSqlDatabase::database("sqlite1"); //建立数据库连接
	QSqlQuery query(db);
	query.prepare(QString("delete from Report where id = %1").arg(id));
	if(!query.exec())
	{
		return false;
	}
	return true;
}

bool DataBase::deleteFromDate(QString dateId)
{
	QString pData = dateId + "0000";
	QSqlDatabase db = QSqlDatabase::database("sqlite1"); //建立数据库连接
	QSqlQuery query(db);
	query.prepare(QString("delete from Report where id in ( select id from Report where id < %1 )").arg(pData));
	if(!query.exec())
	{
		return false;
	}
	return true;
}

//根据ID更新记录
bool DataBase::updateById(int id)
{
	//query.exec();
	return true;
}

//排序
QList<SeleteData> DataBase::sortById(QString id)
{
	QSqlDatabase db = QSqlDatabase::database("sqlite1"); //建立数据库连接
	QSqlQuery query(db);
	bool success=query.exec(QString("select * from Report where id = %1 order by failCount desc ").arg(id));  //降序
	QSqlRecord rec = query.record();
	QList<SeleteData> m_SeleteData;
	while(query.next())
	{
		SeleteData m_data;
		m_data.id = query.value(0).toLongLong();
		m_data.nAllCount = query.value(1).toInt();
		m_data.nFailCount = query.value(2).toInt();
		m_data.nType = query.value(3).toInt();
		m_data.nCameraTypeCount = query.value(4).toInt();
		for(int i = 0;i<nCountCamera[i];i++)
		{
			m_data.nTypeCount[i] = query.value(i+5).toInt();
		}
		m_SeleteData<<m_data;
		m_data.SeleteDatClear();
	}
	return m_SeleteData;
}

QList<SeleteData> DataBase::queryAllByOrder( QString id )
{	//查询当天所有数据 按时间和不同缺陷的缺陷数 升序 查询
	QSqlDatabase db = QSqlDatabase::database("sqlite1"); //建立数据库连接
	QSqlQuery query(db);
	query.exec(QString("select * from Report where id like '%1%' order by id,failCount").arg(id));//20200921____
	QSqlRecord rec = query.record();
	QList<SeleteData> m_SeleteData;
	while(query.next())
	{
		SeleteData m_data;
		m_data.id = query.value(0).toLongLong();
		m_data.nAllCount = query.value(1).toInt();
		m_data.nFailCount = query.value(2).toInt();
		m_data.nType = query.value(3).toInt();
		m_data.nCameraTypeCount = query.value(4).toInt();
		for(int i = 0;i<nCountCamera[i];i++)
		{
			m_data.nTypeCount[i] = query.value(i+5).toInt();
		}
		m_SeleteData<<m_data;
		m_data.SeleteDatClear();
	}
	return m_SeleteData;
}

QList<SeleteData> DataBase::queryOnce( QString id )
{
	QSqlDatabase db = QSqlDatabase::database("sqlite1"); //建立数据库连接
	QSqlQuery query(db);
	bool success=query.exec(QString("select * from Report where id = %1 order by failCount").arg(id));  //缺陷数升序
	QSqlRecord rec = query.record();
	QList<SeleteData> m_SeleteData;
	while(query.next())
	{
		SeleteData m_data;
		m_data.id = query.value(0).toLongLong();
		m_data.nAllCount = query.value(1).toInt();
		m_data.nFailCount = query.value(2).toInt();
		m_data.nType = query.value(3).toInt();
		m_data.nCameraTypeCount = query.value(4).toInt();
		for(int i = 0;i<nCountCamera[i];i++)
		{
			m_data.nTypeCount[i] = query.value(i+5).toInt();
		}
		m_SeleteData<<m_data;
		m_data.SeleteDatClear();
	}
	return m_SeleteData;
}
