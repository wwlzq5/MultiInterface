#ifndef DATABASE_H
#define DATABASE_H
#include "qsqldatabase.h"
#include "qsqlquery.h"
#include "qsqldriver.h"
#include "qsqlrecord.h"
struct TemporaryData{
	long long id[50];
	int nCameraTypeCount[50]; //ĳ��ȱ�ݵ��߷�����
	int nAllCount; //��ǰ������Ŀ
	int nFailCount; //��ǰ�߷���Ŀ
	int nTypeCount[30][50]; //ÿ�������Ӧ��һ��ȱ���߷���
};
struct SeleteData{
	long long id;
	int nCameraTypeCount; //ĳ��ȱ�ݵ��߷�����
	int nAllCount; //��ǰ������Ŀ
	int nFailCount; //��ǰ�߷���Ŀ
	int nType; //��������
	int nTypeCount[30]; //ÿ�������Ӧ��һ��ȱ���߷���
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
	bool createConnection();  //����һ������
	bool createTable();       //�������ݿ��
	bool insert(QString,TemporaryData,int);            //��������
	QList<SeleteData> queryAll(QString id,int);          //��ѯһ��������Ϣ
	QList<SeleteData> queryAllByOrder(QString id);          //��ѯһ��������Ϣ ����
	QList<SeleteData> queryAll(QString startTime,QString endTime,int);          //��ѯ������Ϣ
	QList<SeleteData> queryOnce(QString id);          //��ѯһ�μ�¼����
	bool updateById(int id);  //����
	bool deleteById(int id);  //ɾ��
	bool deleteFromDate(QString dateId);  //ɾ��ָ������֮ǰ�����ݼ�¼
	QList<SeleteData> sortById(QString);          //����
public:
	TemporaryData m_MyData;
	QString nName[3];
	int nCountCamera[3];
};
#endif