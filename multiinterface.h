#ifndef MULTIINTERFACE_H
#define MULTIINTERFACE_H
#include <windows.h>
#include "ui_multiinterface.h"
#include <QCloseEvent>
#include "widgetSever.h"
#include <QTcpServer>
#include <QTcpSocket>
#include <QList>
#include <QTimer>
#include <QMutex>
#include <QVector>
#include <QSignalMapper>
#include <QSettings>
#include <QTextCodec>
#include <QDateTime>
#include "database.h"
#include "clogfile.h"
#include "Stool.h"
#include <Tlhelp32.h>
#include "IOCard.h"
#include "widgetUser.h"
#include "WidgetWarning.h"
#include <widgetAlert.h>
#include "widget_count.h"
#include "widgetMode.h"
#include <time.h>
class MultiInterface : public QMainWindow
{
	Q_OBJECT

public:
	MultiInterface(QWidget *parent = 0);
	~MultiInterface();
public:
	void InitConnect();
	void InitSocket();
	void InitConfig();
	void closeEvent(QCloseEvent *event);
	void CalculateData(QByteArray);
	void onServerConnected(QString IPAddress,bool nState);
	void slots_SaveCountInfo(QVector<TemporaryData>);
	void mouseMoveEvent(QMouseEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void SendBasicNet(StateEnum);
	void ChangeVncState(int);
public:
	int nSheetPage;
	bool nOver;
	int* nSaveDataAddress;
signals:
	void sianal_WarnMessage(int,QString);
	void UpdateIOCard(int*,int);
public slots:
	void slots_clickAccont(int);
	void ServerNewConnection();
	void onServerDataReady();
	void slots_ConnectState();
	void slots_OnUpdateIOCard(int*,int);
	void slots_TimeLogin(QTime);
	void slots_LoadMode(QString);
public:
	static DWORD WINAPI DataHanldThread( void *arg );
public:
	QMutex nDataLock;
	QTimer* nConnectState;
	QStringList m_PLCAlertType;
	QVector<IpStruct> IPAddress;
	QTcpServer* m_temptcpServer;
	QSignalMapper* signal_mapper;
	DataBase* nSqliteBase;
	QList<QByteArray> nDataList;
	Widget_Sever* m_sever[3];
	IOCardClass* nIOCard[3];
	CLogFile* Logfile;
	QWidget * nIOprence;
	UserWidget* nUserWidget;
	Widget_Warning* nWarning;
	widget_Alert* nAlert;
	widget_count* nWidgetCount;
	widget_Mode* nWidgetMode;
public:
	int nAllCheckNum;
	int nAllFailNum;
	time_t n_StartTime;
	time_t n_EndTime;
private:
	Ui::MultiInterfaceClass ui;
};

#endif // MULTIINTERFACE_H
