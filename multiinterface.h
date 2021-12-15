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
#include <QTime>
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

struct SystemConfigInfo
{
	int iSaveRecordInterval;
	bool isSaveRecord;
	QTime shift1Time;
	QTime shift2Time;
	QTime shift3Time;
	bool isAutoClear;
};

struct Paths
{
	QString AppPath;
	QString configPath;
	QString PLCAlertPath;
	QString errorTypePath;
	QString modelTypePath;
	QString LastdataPath;
};

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
	void ClearCount(bool isChangeShift = true);
	void UpdateCountForShow(bool isFirst=false);
	void SaveCountInfo();
	void SaveToDatebase();
	void SendBasicNet(StateEnum,QString);
	void ChangeVncState(int);

public:
	int nSheetPage;
	bool nOver;
	int* nSaveDataAddress;
signals:
	void sianal_WarnMessage(int,QString);
	void UpdateIOCard(int*,int);
	void sianal_updateCountInfo(int,int,float);
	void sianal_UpdateTable1(cErrorInfo);
public slots:
	void slots_ModeState(StateEnum,QString);
	void slots_clickAccont(int);
	void ServerNewConnection();
	void onServerDataReady();
	void slots_ConnectState();
	void slots_OnUpdateIOCard(int*,int);
	void slots_SaveCountBytime();
	void slots_SaveCountByShift();
	void slots_UpdateRecordSet();
	void slots_UpdateShiftSet();
	void slots_CloseConnect();
	void slot_StateChanged(QAbstractSocket::SocketState);
	void slots_loginState(int);
public:
	static DWORD WINAPI DataHanldThread( void *arg );
	static DWORD WINAPI DataCountThread( void *arg );
public:
	Paths AppPaths;
	s_ErrorInfo m_ErrorTypeInfo;
	QMutex nDataLock;
	QMutex nCountLock;
	QTimer* nConnectState;
	QStringList m_PLCAlertType;
	QVector<IpStruct> IPAddress;
	QTcpServer* m_temptcpServer;
	QSignalMapper* signal_mapper;
	DataBase* m_Datebase;
	QList<QByteArray> nDataList;
	VNC_widget* mVNC_window;
	IOCardClass* nIOCard[3];
	CLogFile* Logfile;
	QWidget * nIOprence;
	UserWidget* nUserWidget;
	Widget_Warning* nWarning;
	widget_Alert* nAlert;
	widget_count* nWidgetCount;
	widget_Mode* nWidgetMode;
	QList<QByteArray> nDataCount[3];
	MyErrorType nSendData[256];
	cErrorInfo nRunInfo,LastRunInfo,nTmpcountData;
	SystemConfigInfo SysConfigInfo;
public:
	int nAllCheckNum;
	int nAllFailNum;
	QDateTime n_StartTime;
	QTimer *nScreenTime;
	QTimer *timerSaveList;
	int currentShift;
	POINT gcPosition;
	QByteArray m_buffer;
private:
	Ui::MultiInterfaceClass ui;
};

#endif // MULTIINTERFACE_H
