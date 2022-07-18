#include "multiinterface.h"
#include <QDebug>

MultiInterface *pMainFrm;
#define CUSTOMALERT 3
//#define JIAMI_INITIA
#ifdef JIAMI_INITIA
	#include "ProgramLicense.h"
	CProgramLicense m_ProgramLicense;
	#pragma comment(lib,"DHProgramLicense64.lib")
#endif
MultiInterface::MultiInterface(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	setWindowFlags (Qt::FramelessWindowHint);
	pMainFrm = this;
	setWindowIcon(QIcon("./Resources/LOGO.png"));
	setCentralWidget(ui.centralWidget);
	InitConfig();
	InitSocket();
	InitConnect();
	m_Datebase =new DataBase(AppPaths.AppPath);
	for(int i=0;i<256;i++)
	{
		nSendData[i].id = 0;
		nSendData[i].nErrorArea = 0;
		nSendData[i].nType = 0;
	}
	connect(nWidgetCount ,SIGNAL(updateRecordSet()),this,SLOT(slots_UpdateRecordSet()));
	connect(nWidgetCount ,SIGNAL(updateShiftSet()),this,SLOT(slots_UpdateShiftSet()));
	connect(nWidgetCount,SIGNAL(signal_SaveRecord()),this,SLOT(slots_SaveRecord()));

	timerSaveList = new QTimer(this);
	timerSaveList->setInterval(60*1000);//每分钟触发一次
	connect(timerSaveList, SIGNAL(timeout()), this, SLOT(slots_SaveCountBytime()));  
	connect(timerSaveList, SIGNAL(timeout()), this, SLOT(slots_SaveCountByShift()));  
	timerSaveList->start();

	m_Datebase->queryLastData(nAllCheckNum,nAllFailNum,nRunInfo);
	m_Datebase->queryLastTimeData(LastRunInfo);
	UpdateCountForShow(true);
}

MultiInterface::~MultiInterface()
{
}
void MultiInterface::closeEvent(QCloseEvent *event)
{
	nOver  = false;
	delete nWarning;
	delete nAlert;
	delete nWidgetMode;
	nIOprence->close();
}
void MultiInterface::InitConfig()
{
	QString path = QApplication::applicationFilePath();  
	AppPaths.AppPath = path.left(path.findRev("/")+1);
	AppPaths.configPath = AppPaths.AppPath + "Config/config.ini";
	AppPaths.PLCAlertPath = AppPaths.AppPath + "../Config/PLCAlertType.ini";
	AppPaths.errorTypePath = AppPaths.AppPath + "../Config/ErrorType.ini";
	AppPaths.modelTypePath = AppPaths.AppPath + "Config/ModeType.ini";

	QSettings erroriniset(AppPaths.errorTypePath,QSettings::IniFormat);
	erroriniset.setIniCodec(QTextCodec::codecForName("GBK"));
	m_ErrorTypeInfo.iErrorTypeCount = erroriniset.value("/ErrorType/total",0).toInt();
	m_ErrorTypeInfo.iErrorType.clear();
	for (int i=0;i<=m_ErrorTypeInfo.iErrorTypeCount;i++)
	{
		if (0 == i)
		{
			m_ErrorTypeInfo.iErrorType.append(tr("Good"));
		}
		else
		{
			QString strSession = QString("/ErrorType/%1").arg(i);
			QString errorstr=erroriniset.value(strSession,"").toString();
			m_ErrorTypeInfo.iErrorType.append(QString::fromLocal8Bit(errorstr));
			//qDebug()<<QString::fromLocal8Bit(errorstr)<<":"<<errorstr.length();
		}
	}

	QSettings SystemConfigSet(AppPaths.configPath,QSettings::IniFormat);
	SystemConfigSet.setIniCodec(QTextCodec::codecForName("GBK"));
	SysConfigInfo.iSaveRecordInterval=SystemConfigSet.value("System/iSaveRecordInterval",30).toInt();
	SysConfigInfo.isSaveRecord = SystemConfigSet.value("System/isSaveRecord",true).toBool();
	SysConfigInfo.shift1Time = QTime::fromString(SystemConfigSet.value("System/shift1Time","060000").toString(),"hhmmss");
	SysConfigInfo.shift2Time = QTime::fromString(SystemConfigSet.value("System/shift2Time","150000").toString(),"hhmmss");
	SysConfigInfo.shift3Time = QTime::fromString(SystemConfigSet.value("System/shift3Time","230000").toString(),"hhmmss");
	SysConfigInfo.isAutoClear = SystemConfigSet.value("System/isAutoClear",true).toBool();

	QTime currentTm=QTime::currentTime();
	if(currentTm >= SysConfigInfo.shift1Time &&  currentTm < SysConfigInfo.shift2Time)
		currentShift = 0;
	else if(currentTm >= SysConfigInfo.shift2Time &&  currentTm < SysConfigInfo.shift3Time)
		currentShift = 1;
	else if(currentTm <SysConfigInfo.shift1Time || currentTm >= SysConfigInfo.shift3Time)
		currentShift = 2;
	
	//获取PLC的报警列表
	QSettings PLCStatusiniset(AppPaths.PLCAlertPath,QSettings::IniFormat);
	PLCStatusiniset.setIniCodec(QTextCodec::codecForName("GB2312"));
	QString strSession = QString("/StatusType/total");
	StatusTypeNumber = PLCStatusiniset.value(strSession,0).toInt();
	for (int i=1;i<=StatusTypeNumber;i++)
	{
		strSession = QString("/StatusType/%1").arg(i);
		m_PLCAlertType<<QString::fromLocal8Bit(PLCStatusiniset.value(strSession,"NULL").toString());
	}
	strSession = QString("/CutomAlert/total");
	StatusTypeNumber = PLCStatusiniset.value(strSession,0).toInt();
	for (int i=1;i <= CUSTOMALERT;i++)
	{
		strSession = QString("/CutomAlert/%1").arg(i);
		m_CustomAlertType<<QString::fromLocal8Bit(PLCStatusiniset.value(strSession,"NULL").toString());
	}
	nErrorCount = m_PLCAlertType.count() + m_CustomAlertType.count();
	Logfile = new CLogFile();
	Logfile->write("start check!",OperationLog);
	nOver  = true;
	CreateThread( NULL, 0, (LPTHREAD_START_ROUTINE)DataHanldThread, this, 0, NULL );
	CreateThread( NULL, 0, (LPTHREAD_START_ROUTINE)DataCountThread, this, 0, NULL );

	//nSaveDataAddress = new int[HORIZONTAL24];
	nSaveDataAddress = new int[24];
	
	IpStruct nIptemp;
	nIptemp.ipAddress=IP1;
	nIptemp.nstate = false;
	IPAddress<<nIptemp;
	nIptemp.ipAddress=IP2;
	nIptemp.nstate = false;
	IPAddress<<nIptemp;
	nIptemp.ipAddress=IP3;
	nIptemp.nstate = false;
	IPAddress<<nIptemp;
	nSheetPage = MAININTERFACE;
	
	n_StartTime = QDateTime::currentDateTime();
	GetCursorPos(&gcPosition);
}

void MultiInterface::InitSocket()
{
	m_temptcpServer = new QTcpServer(this);
	m_temptcpServer->listen(QHostAddress::Any,8088);
	connect(m_temptcpServer, SIGNAL(newConnection()), this, SLOT(ServerNewConnection()));
	nAllCheckNum = 0;
	nAllFailNum = 0;
}

void MultiInterface::InitConnect()
{
	qRegisterMetaType<cErrorInfo>("cErrorInfo"); 
	ui.checkBox->setEnabled(false);
	ui.checkBox_2->setEnabled(false);
	ui.checkBox_3->setEnabled(false);
	ui.checkBox->setStyleSheet("QCheckBox::indicator {width:15px;height:15px;border-radius:7px}""QCheckBox::indicator:checked {background-color:green;}""QCheckBox::indicator:unchecked {background-color:red;}");
	ui.checkBox_2->setStyleSheet("QCheckBox::indicator {width:15px;height:15px;border-radius:7px}""QCheckBox::indicator:checked {background-color:green;}""QCheckBox::indicator:unchecked {background-color:red;}");
	ui.checkBox_3->setStyleSheet("QCheckBox::indicator {width:15px;height:15px;border-radius:7px}""QCheckBox::indicator:checked {background-color:green;}""QCheckBox::indicator:unchecked {background-color:red;}");
	
	nIOprence = new QWidget();
	nIOprence->setFixedSize(650,920);
	nIOprence->setWindowIcon(QIcon("./Resources/LOGO.png"));
	nIOprence->setWindowTitle(tr("IOData"));

	QVBoxLayout * nVboxLayout = new QVBoxLayout;
	for(int i=0;i<3;i++)
	{
		nIOCard[i] = new IOCardClass;
		nVboxLayout->addWidget(nIOCard[i]);
	}
	nVboxLayout->setMargin(0);
	nVboxLayout->setSpacing(10);
	nIOprence->setLayout(nVboxLayout);
	connect(this,SIGNAL(UpdateIOCard(int*,int)),this,SLOT(slots_OnUpdateIOCard(int*,int)));

	nConnectState = new QTimer;
	nConnectState->setInterval(10*1000);
	connect(nConnectState,SIGNAL(timeout()),this,SLOT(slots_ConnectState()));
	nConnectState->start();
	nScreenTime = new QTimer;
	nScreenTime->setInterval(60*1000*5);//5分钟没人操作就关闭
	connect(nScreenTime,SIGNAL(timeout()),this,SLOT(slots_CloseConnect()));
	nScreenTime->start();

 	nUserWidget = new UserWidget();
	connect(nUserWidget,SIGNAL(signal_LoginState(int)),this,SLOT(slots_loginState(int)));

	nWarning = new Widget_Warning();
	connect(this,SIGNAL(sianal_WarnMessage(int,QString)),nWarning,SLOT(slot_ShowMessage(int,QString)));

	nAlert = new widget_Alert();
	
	nWidgetMode = new widget_Mode();
	connect(nWidgetMode,SIGNAL(signal_ModeState(StateEnum,QString)),this,SLOT(slots_ModeState(StateEnum,QString)));
	

	nWidgetCount = new widget_count;
	ui.stackedWidget->addWidget(nWidgetCount);
	ui.stackedWidget->addWidget(nIOprence);
	ui.stackedWidget->addWidget(nAlert);
	ui.stackedWidget->addWidget(nWidgetMode);
	ui.stackedWidget->setCurrentWidget(nWidgetCount);
	connect(this,SIGNAL(sianal_updateCountInfo(int,int,float)),nWidgetCount,SLOT(slots_updateCountInfo(int,int,float)));
	connect(this,SIGNAL(sianal_UpdateTable1(cErrorInfo)),nWidgetCount,SLOT(slots_UpdateTable1(cErrorInfo)));

	signal_mapper = new QSignalMapper(this);
	connect(ui.pushButton_open1,SIGNAL(clicked()),signal_mapper,SLOT(map()));
	connect(ui.pushButton_open2,SIGNAL(clicked()),signal_mapper,SLOT(map()));
	connect(ui.pushButton_open3,SIGNAL(clicked()),signal_mapper,SLOT(map()));
	connect(ui.pushButton_IO,SIGNAL(clicked()),signal_mapper,SLOT(map()));
	connect(ui.pushButton_Alert,SIGNAL(clicked()),signal_mapper,SLOT(map()));
	connect(ui.pushButton_2,SIGNAL(clicked()),signal_mapper,SLOT(map()));
	connect(ui.pushButton_Mode,SIGNAL(clicked()),signal_mapper,SLOT(map()));
	connect(ui.pushButton_home,SIGNAL(clicked()),signal_mapper,SLOT(map()));
	connect(ui.pushButton_lock,SIGNAL(clicked()),signal_mapper,SLOT(map()));

	signal_mapper->setMapping(ui.pushButton_open1,0);
	signal_mapper->setMapping(ui.pushButton_open2,1);
	signal_mapper->setMapping(ui.pushButton_open3,2);
	signal_mapper->setMapping(ui.pushButton_IO,3);
	signal_mapper->setMapping(ui.pushButton_Alert,4);
	signal_mapper->setMapping(ui.pushButton_2,5);
	signal_mapper->setMapping(ui.pushButton_Mode,6);
	signal_mapper->setMapping(ui.pushButton_home,7);
	signal_mapper->setMapping(ui.pushButton_lock,8);
	connect(signal_mapper, SIGNAL(mapped(int)), this, SLOT(slots_clickAccont(int)));

	ui.pushButton_open1->setVisible(false);
	//ui.pushButton_open2->setVisible(false);夹持要显示出来
	ui.pushButton_open3->setVisible(false);
	ui.pushButton_Alert->setVisible(false);
	ui.pushButton_Mode->setVisible(false);
	ui.pushButton_lock->setVisible(false);
	//ui.pushButton_IO->setVisible(false);
	nUserWidget->hide();
}

void MultiInterface::slots_ModeState(StateEnum nState,QString nTemp)
{
	SendBasicNet(nState,nTemp);
}
void MultiInterface::slots_loginState(int nPermiss)
{
	if(nPermiss == 3)//如果是三级权限表示只能让客户操作查询日志
	{
		ui.pushButton_open1->setEnabled(false);
		//ui.pushButton_open2->setEnabled(false);
		ui.pushButton_open3->setEnabled(false);
		//ui.pushButton_2->setEnabled(false);
		ui.pushButton_IO->setEnabled(false);
		ui.pushButton_Alert->setEnabled(false);
		ui.pushButton_Mode->setEnabled(false);
		ui.pushButton_lock->setEnabled(true);
	}else//二级权限暂时提供所有功能 
	{
		ui.pushButton_open1->setEnabled(true);
		//ui.pushButton_open2->setEnabled(true);
		ui.pushButton_open3->setEnabled(true);
		//ui.pushButton_2->setEnabled(true);
		ui.pushButton_IO->setEnabled(true);
		ui.pushButton_Alert->setEnabled(true);
		ui.pushButton_Mode->setEnabled(true);
		ui.pushButton_lock->setEnabled(true);
	}
	nUserWidget->nPermission = nPermiss;
	//SendBasicNet(FRONTSTATE,QString::number(nPermiss));
}

void MultiInterface::slots_SaveRecord()
{
	//nTmpcountData = nRunInfo;
	SaveCountInfo(ByTime,tr("Save"));
}
/*
void MultiInterface::slots_disConnected()
{
	Logfile->write(tr("disconnect"),OperationLog);
	QTcpSocket* tcp = static_cast<QTcpSocket*>(sender());
	onServerConnected(tcp->peerAddress().toString(),false);
}
*/
void MultiInterface::SendBasicNet(StateEnum nState,QString nTemp)
{
	SockectMutex.lock();
	for (int i=0;i<clientSocket.count();i++)
	{
		MyStruct nData;
		nData.nState = nState;
		nData.nCount = sizeof(MyStruct);
		nData.nCheckNum = nAllCheckNum;
		nData.nFail = nAllFailNum;
		if(nTemp != "NULL")
		{
			strcpy_s(nData.nTemp,nTemp.toLocal8Bit().data());
		}else{
			strcpy_s(nData.nTemp,nTemp.toStdString().c_str());
		}
		int ret = clientSocket[i]->write((char*)&nData,sizeof(MyStruct));
		if(ret == -1)
		{
			Logfile->write(QString("TcpSever write to %3 nState:%1,writelen:%2").arg(nState).arg(ret).arg(clientSocket[i]->peerAddress().toString()),CheckLog);
		}
	}
	SockectMutex.unlock();
}
void MultiInterface::slots_clickAccont(int nTest)
{
	switch (nTest)
	{
	case 0:
		nSheetPage = NLEADING;
		Logfile->write(tr("into Front Interface"),OperationLog);
		break;
	case 1:
		hide();
		if(nUserWidget->nPermission == 3)
		{
			SendBasicNet(ONLYSHOWSEVER,"LIMIT");
		}else{
			SendBasicNet(ONLYSHOWSEVER,"NULL");
		}
		nSheetPage = NCLAMPING;
		Logfile->write(QString("into Clamping Interface %1").arg(nUserWidget->nPermission),OperationLog);
		break;
	case 2:
		nSheetPage = NBACKING;
		Logfile->write(tr("into Backing Interface"),OperationLog);
		break;
	case 3:
		ui.stackedWidget->setCurrentWidget(nIOprence);
		Logfile->write(tr("into IOCard Interface"),OperationLog);
		break;
	case 4:
		ui.stackedWidget->setCurrentWidget(nAlert);
		Logfile->write(tr("into Alert Interface"),OperationLog);
		break;
	case 5:
		ClearCount(false);
		Logfile->write(tr("into Clear Interface"),OperationLog);
		break;
	case 6:
		ui.stackedWidget->setCurrentWidget(nWidgetMode);
		Logfile->write(tr("into Mode Interface"),OperationLog);
		break;
	case 7:
		ui.stackedWidget->setCurrentWidget(nWidgetCount);
		Logfile->write(tr("into Count Interface"),OperationLog);
		break;
	case 8:
		nUserWidget->show();
		//SendBasicNet(LOCKSCREEN,"3");
		Logfile->write(tr("into lock Interface"),OperationLog);
		break;
	}
}

void MultiInterface::slots_SaveCountBytime()
{
	if(!SysConfigInfo.isSaveRecord)
		return;
	static bool isSave=false;
	QTime time = QTime::currentTime();
	if(SysConfigInfo.iSaveRecordInterval == 30)
	{
		if ( 30 == time.minute()||0 == time.minute() )
		{
			if (!isSave)
			{
				SaveToDatebase();
				SaveCountInfo(ByTime);
				isSave =true;
			}
		}
		else
			isSave =false;
	}
	else
	{
		if (0 == time.minute())
		{
			if (!isSave)  
			{
				SaveToDatebase();
				SaveCountInfo(ByTime);
				isSave =true;
			}
		}
		else
			isSave =false;
	}
}
void MultiInterface::slots_SaveCountByShift()
{
	if(!SysConfigInfo.isAutoClear)
		return;
	QTime currentTm=QTime::currentTime();
	if(currentTm >SysConfigInfo.shift1Time &&  currentTm < SysConfigInfo.shift2Time)
	{
		if(currentShift != 0)
		{
			//qDebug()<<"Shift1";
			SaveCountInfo(ByShift,tr("Shift1"));
			ClearCount();
			currentShift = 0;
		}
	}
	else if(currentTm >SysConfigInfo.shift2Time &&  currentTm < SysConfigInfo.shift3Time)
	{
		if(currentShift != 1)
		{
			//qDebug()<<"Shift2";
			SaveCountInfo(ByShift,tr("Shift2"));
			ClearCount();
			currentShift = 1;
		}
	}
	else if(currentTm <SysConfigInfo.shift1Time || currentTm > SysConfigInfo.shift3Time)
	{
		if(currentShift != 2)
		{
			//qDebug()<<"Shift3";
			SaveCountInfo(ByShift,tr("Shift3"));
			ClearCount();
			CheckLicense();
			currentShift = 2;
		}
	}

}
void MultiInterface::slots_UpdateRecordSet()
{
	QSettings SystemConfigSet(AppPaths.configPath,QSettings::IniFormat);
	SystemConfigSet.setIniCodec(QTextCodec::codecForName("GBK"));
	SysConfigInfo.iSaveRecordInterval=SystemConfigSet.value("System/iSaveRecordInterval",30).toInt();
	SysConfigInfo.isSaveRecord = SystemConfigSet.value("System/isSaveRecord",true).toBool();

	if(SysConfigInfo.isSaveRecord)
	{
		if(!timerSaveList->isActive())
		{
			timerSaveList->start();
		}
	}
	else
	{
		if(timerSaveList->isActive())
		{
			timerSaveList->stop();
		}
	}	   
}
void MultiInterface::slots_UpdateShiftSet()
{
	QSettings SystemConfigSet(AppPaths.configPath,QSettings::IniFormat);
	SystemConfigSet.setIniCodec(QTextCodec::codecForName("GBK"));
	SysConfigInfo.shift1Time = QTime::fromString(SystemConfigSet.value("System/shift1Time","060000").toString(),"hhmmss");
	SysConfigInfo.shift2Time = QTime::fromString(SystemConfigSet.value("System/shift2Time","150000").toString(),"hhmmss");
	SysConfigInfo.shift3Time = QTime::fromString(SystemConfigSet.value("System/shift3Time","230000").toString(),"hhmmss");
	SysConfigInfo.isAutoClear = SystemConfigSet.value("System/isAutoClear",true).toBool();
}
void MultiInterface::slots_CloseConnect()
{
	POINT tgcPosition;
	GetCursorPos( &tgcPosition );
	if((tgcPosition.x == gcPosition.x) && (tgcPosition.y == gcPosition.y) && !isHidden())
	{
		nUserWidget->nPermission = 3;
		slots_clickAccont(1);
	}else{
		gcPosition.x = tgcPosition.x;
		gcPosition.y = tgcPosition.y;
	}
}
void MultiInterface::slots_ConnectState()
{
	SendBasicNet(FRONTSTATE,"NULL");
}
void MultiInterface::SaveCountInfo(SaveReportType pType,QString pTxt)
{
	bool bIsEmptyFile = false;
	QString strFileName;
	if(pType == ByTime)
		strFileName = AppPaths.AppPath + "CountInfo/timeCount/";
	else if(pType == ByShift)
		strFileName = AppPaths.AppPath + "CountInfo/shiftCount/";
	else
		strFileName = AppPaths.AppPath + "CountInfo/otherCount/";
	QDir temp;
	bool exist = temp.exists(strFileName);
	if(!exist)
		temp.mkpath(strFileName);

	QDate date = QDate::currentDate();
	strFileName = strFileName +	date.toString(Qt::ISODate) + ".txt";
	if(!QFile::exists(strFileName))
	{
		QFile createFile(strFileName);
		if(!createFile.open(QFile::WriteOnly | QIODevice::Text))
		{
			return;
		}
		bIsEmptyFile = true;
		createFile.close();
	}
	QFile readFile(strFileName);
	if (!readFile.open(QFile::Append | QIODevice::Text))
	{
		return;
	}
	cErrorInfo wData;
	/*if (pType == ByShift)*/
		wData = nRunInfo;
// 	else
// 		wData = nTmpcountData;
	QFile writeFile(strFileName);
	//读入流和写入流
	QTextStream writeStream(&writeFile);
	if (!bIsEmptyFile)
	{
		writeStream<<"\n";
	}
	QTime time = QTime::currentTime();
	if(pType == ByShift)
		writeStream<<tr("Shift:%1").arg(pTxt)<<"\t";
	else if(pType == ByTime && pTxt != "")
		writeStream<<QString("%1").arg(pTxt)<<"\t";
	writeStream<<tr("Time:%1:%2:%3").arg(time.hour()).arg(time.minute()).arg(time.second())<<"\t";
	writeStream<<tr("All Count:  %1").arg(/*nAllCheckNum*/wData.iAllCount)<<"\t";
	writeStream<<tr("Fail Count:  %1").arg(/*nAllFailNum*/wData.GetFailCount())<<"\t";
	writeStream<<tr("Fail Rate:  %1%").arg(wData.GetFailRate()*100 ,2,'f',2)<<"\n";

	writeStream<<tr("Front Count:  %1").arg(wData.GetFrontCount())<<"\t";
	writeStream<<tr("Clamp Count:  %1").arg(wData.GetClampCount())<<"\t";
	writeStream<<tr("Rear Count:  %1").arg(wData.GetRearCount())<<"\n";

	for(int i=1;i<=m_ErrorTypeInfo.iErrorTypeCount;i++)
	{
		writeStream<<m_ErrorTypeInfo.iErrorType[i] + ":" + QString::number(wData.GetErrorByTypeCount(i))<<"\t";
	}
	writeStream<<"\n";
	writeStream<<tr("Results")<<"\t\t";
	writeStream<<tr("Count")<<"\t";
	writeStream<<tr("front")<<"\t";
	writeStream<<tr("clamp")<<"\t";
	writeStream<<tr("rear") <<"\t";
	writeStream<<"\n";

	for(int i=1;i<= m_ErrorTypeInfo.iErrorTypeCount;i++)
	{
		int pErrorByType = wData.GetErrorByTypeCount(i);
		QString tempString=m_ErrorTypeInfo.iErrorType[i];
		int tt = tempString.length();
		while(tempString.length()<12)
		{
			tempString+=" ";
			if(tt <4)
			{
				if(tempString.length() == 12)
				{
					writeStream<<tempString<<"\t";
					break;
				}
			}else{
				if(tempString.length() == 8)
				{
					writeStream<<tempString<<"\t";
					break;
				}
			}
		}
		writeStream<<QString::number(pErrorByType)<<"\t";
		writeStream<<QString::number(wData.iFrontErrorByType[i])<<"\t";
		writeStream<<QString::number(wData.iClampErrorByType[i])<<"\t";
		writeStream<<QString::number(wData.iRearErrorByType[i])<<"\n";
	}
	writeStream<<"\n";
	if (!writeFile.open(QFile::Append | QIODevice::Text))
	{
		return;
	}
	writeStream.flush();//写入流到文件
	writeFile.close();

	return;
}
void MultiInterface::SaveToDatebase()
{
	QDateTime dateTime = QDateTime::currentDateTime();
	nTmpcountData = nRunInfo - LastRunInfo;
	LastRunInfo = nRunInfo;

	m_Datebase->insertLastTimeData(LastRunInfo);

	bool ret = m_Datebase->insert(dateTime.toString("yyyyMMddhhmm"),nTmpcountData);
	QDate dateSelecte = QDate::currentDate();
	QString temp = dateSelecte.toString(Qt::ISODate);
	temp.replace("-", "");
	QList<long long> tmpTimes;
	QList<cErrorInfo> tmpInfos;
	m_Datebase->queryByDay(temp ,tmpTimes,tmpInfos);
	nWidgetCount->slots_UpdateTable2(tmpTimes,tmpInfos);
	/*
	long long iTime=0;
	cErrorInfo info;
	m_Datebase->queryByOnce(dateTime.toString("yyyyMMddhhmm"),iTime,info);

	QDateTime pTime = QDateTime::fromString(QString::number(iTime),"yyyyMMddhhmm");
	QString timeString= pTime.toString("yyyy-MM-dd hh:mm");
	nWidgetCount->slots_UpdateTable2(timeString,info);
	*/
	return;
}
void MultiInterface::ServerNewConnection()
{
	QTcpSocket* tcp = m_temptcpServer->nextPendingConnection(); //获取新的客户端信息
	Logfile->write(QString("connected IP:%1").arg(tcp->peerAddress().toString()),CheckLog);
	SockectMutex.lock();
	clientSocket.push_back(tcp);
	SockectMutex.unlock();
	onServerConnected(tcp->peerAddress().toString(),true);
	connect(tcp, SIGNAL(readyRead()), this, SLOT(onServerDataReady()));
	connect(tcp, SIGNAL(stateChanged(QAbstractSocket::SocketState )), this, SLOT(slot_StateChanged( QAbstractSocket::SocketState )));
}

void MultiInterface::slot_StateChanged(QAbstractSocket::SocketState state)
{
	QTcpSocket* tcp = static_cast<QTcpSocket*>(sender());
	switch(state)
	{
	case QAbstractSocket::ConnectedState:
		Logfile->write("ConnectedState",CheckLog);
		break;
	default:
		if(tcp->peerAddress().toString() == IP1)
		{
			ui.checkBox->setChecked(false);
		}
		else if(tcp->peerAddress().toString() == IP2)
		{
			ui.checkBox_2->setChecked(false);
		}
		else if(tcp->peerAddress().toString() == IP3)
		{
			ui.checkBox_3->setChecked(false);
		}
		break;
	}
	SockectMutex.lock();
	for(int i=0;i<clientSocket.size();i++)
	{
		if(!clientSocket[i]->isValid())
		{
			clientSocket.removeAt(i);
			i--;
		}
	}
	SockectMutex.unlock();
}
void MultiInterface::onServerDataReady()
{
	QTcpSocket* m_tcpSocket = dynamic_cast<QTcpSocket*>(sender());
	QByteArray buffer = m_tcpSocket->readAll();
	QByteArray TempBuffer;
	m_buffer.append(buffer);
	int totalLen = m_buffer.size();
	QTime nTime =  QTime::currentTime();
	QString m_ScreenLevel=0;
	while(totalLen)  
	{
		if( totalLen < sizeof(MyStruct))  
		{
			break;
		}
		int nCount = ((MyStruct*)m_buffer.data())->nCount;
		if(totalLen < nCount)
		{
			break;
		}
		switch(((MyStruct*)m_buffer.data())->nState)
		{
			case SENDDATA:
				if(((MyStruct*)m_buffer.data())->nUnit == LEADING)
				{
					TempBuffer = m_buffer.left(nCount);
					nDataCount[0].push_back(TempBuffer);
				}else if(((MyStruct*)m_buffer.data())->nUnit == CLAMPING)
				{
					TempBuffer = m_buffer.left(nCount);
					nDataCount[1].push_back(TempBuffer);
				}else if(((MyStruct*)m_buffer.data())->nUnit == BACKING)
				{
					TempBuffer = m_buffer.left(nCount);
					nDataCount[2].push_back(TempBuffer);
				}
				break;
			case CONNECT:
				if(((MyStruct*)m_buffer.data())->nUnit == LEADING)
				{
					IPAddress[0].nstate = true;
					IPAddress[0].startTime = nTime.second();
				}else if(((MyStruct*)m_buffer.data())->nUnit == CLAMPING)
				{
					IPAddress[1].nstate = true;
					IPAddress[1].startTime = nTime.second();
				}else if(((MyStruct*)m_buffer.data())->nUnit == BACKING)
				{
					IPAddress[2].nstate = true;
					IPAddress[2].startTime = nTime.second();
				}
				break;
			case ALERT:
				if(nCount == sizeof(MyStruct)+24*sizeof(int))
				{
					TempBuffer = m_buffer.left(nCount);
					nDataList.push_back(TempBuffer);
				}
				break;
			case ONLYSHOWSEVER:
				show();
				m_ScreenLevel = QString::number(((MyStruct*)m_buffer.data())->nFail);
				slots_loginState(m_ScreenLevel.toInt());
				Logfile->write("into onlyshow",CheckLog);
				break;
		}
		buffer = m_buffer.right(totalLen - nCount);  
		//更新长度
		totalLen = buffer.size();
		//更新多余数据
		m_buffer = buffer;  
	}
}
DWORD WINAPI MultiInterface::DataCountThread( void *arg )
{
	MultiInterface* pThis = ( MultiInterface* )arg;
	MyErrorType nErrorFristData[10]={0};
	MyErrorType nErrorClampData[10]={0};
	MyErrorType nErrorBACKData[10]={0};
	QByteArray buffer[3]={0};
	char* ptr[3];
	int nDataSize = 10;
	while (pThis->nOver)
	{
		if(pThis->nDataCount[0].count()>0 && pThis->nDataCount[1].count()>0 && pThis->nDataCount[2].count()>0)
		{
			for(int i=0;i<3;i++)
			{
				buffer[i] = pThis->nDataCount[i].first();
				pThis->nDataCount[i].removeFirst();
				ptr[i] = buffer[i].data();
				ptr[i] += sizeof(MyStruct);
			}
			//处理数据
			memcpy(&nErrorFristData,ptr[0],sizeof(MyErrorType)*nDataSize);
			memcpy(&nErrorClampData,ptr[1],sizeof(MyErrorType)*nDataSize);
			memcpy(&nErrorBACKData,ptr[2],sizeof(MyErrorType)*nDataSize);

			for(int i=0;i<nDataSize;i++) // 通过循环所有综合数据保存在 nErrorFristData中
			{
				pThis->nRunInfo.iAllCount += 1;
				if((nErrorFristData[i].nType > 0 && nErrorFristData[i].nType < 50)||(nErrorClampData[i].nType > 0 && nErrorClampData[i].nType < 50)||(nErrorBACKData[i].nType > 0 && nErrorBACKData[i].nType<50))//综合有缺陷，计数加1
				{
					pThis->nRunInfo.iFailCount += 1;
					if(nErrorFristData[i].nErrorArea <= nErrorClampData[i].nErrorArea && nErrorClampData[i].nErrorArea >= nErrorBACKData[i].nErrorArea)
					{
						pThis->nRunInfo.ClampCount += 1;
						pThis->nRunInfo.iClampErrorByType[nErrorClampData[i].nType] += 1;
						pThis->nRunInfo.iErrorByType[nErrorClampData[i].nType] += 1;
						pThis->nSendData[i] = nErrorClampData[i];
					}
					else if(nErrorFristData[i].nErrorArea <= nErrorBACKData[i].nErrorArea && nErrorClampData[i].nErrorArea <= nErrorBACKData[i].nErrorArea)
					{
						pThis->nRunInfo.RearCount += 1;
						pThis->nRunInfo.iRearErrorByType[nErrorBACKData[i].nType] += 1;
						pThis->nRunInfo.iErrorByType[nErrorBACKData[i].nType] += 1;
						pThis->nSendData[i] = nErrorBACKData[i];
					}
					else if(nErrorFristData[i].nErrorArea >= nErrorClampData[i].nErrorArea && nErrorFristData[i].nErrorArea >= nErrorBACKData[i].nErrorArea)
					{
						pThis->nRunInfo.FrontCount += 1;
						pThis->nRunInfo.iFrontErrorByType[nErrorFristData[i].nType] += 1;
						pThis->nRunInfo.iErrorByType[nErrorFristData[i].nType] += 1;
						pThis->nSendData[i] = nErrorFristData[i];
					}
				}
			}
			for(int i=0;i<3;i++)
			{
				pThis->nDataCount[i].clear();
			}
			pThis->UpdateCountForShow();
		}else{
			for(int i=0;i<3;i++)
			{
				if(pThis->nDataCount[i].count()>5)
				{
					pThis->nDataCount[i].pop_front();
				}
			}
			Sleep(20);
		}
		Sleep(1);
	}
	return true;
}
DWORD WINAPI MultiInterface::DataHanldThread( void *arg )
{
	MultiInterface* pThis = ( MultiInterface* )arg;
	while (pThis->nOver)
	{
		QByteArray buffer;
		if(pThis->nDataList.count()>0)
		{
			buffer = pThis->nDataList.first();
			pThis->nDataList.removeFirst();
			pThis->CalculateData(buffer);
		}
		if(pThis->nDataList.count()>20)
		{
			pThis->nDataList.clear();
			pThis->Logfile->write("clear data!",CheckLog);
		}
		Sleep(20);
	}
	return true;
}
void MultiInterface::CalculateData(QByteArray buffer)
{
	char* t_ptr = buffer.data();
	int nUnit = ((MyStruct*)t_ptr)->nUnit;
	if(((MyStruct*)t_ptr)->nState == ALERT)
	{
		memcpy(nSaveDataAddress,t_ptr+sizeof(MyStruct),HORIZONTAL24);
		//发送信号界面UI显示
		emit UpdateIOCard(nSaveDataAddress,nUnit);
		if(nUnit == CLAMPING)//报警标志位
		{
			int nPlcTypeid = nSaveDataAddress[23];
			nAllCheckNum = nSaveDataAddress[21];
			nAllFailNum = nSaveDataAddress[22];
			emit sianal_updateCountInfo(nAllCheckNum,nAllFailNum,0);
			if(nPlcTypeid >= -1 && nPlcTypeid < nErrorCount)
			{
				if(nPlcTypeid == -1)
				{
					emit sianal_WarnMessage(nPlcTypeid,NULL);
				}else{
					if(nPlcTypeid<32)//传统报警
					{
						emit sianal_WarnMessage(nPlcTypeid,m_PLCAlertType.at(nPlcTypeid));
					}else{//自定义报警
						int temp = nPlcTypeid - 32;
						if(temp < StatusTypeNumber && temp > 0)
							emit sianal_WarnMessage(nPlcTypeid,m_CustomAlertType.at(temp));
					}
				}
			}
		}
	}
}
void MultiInterface::slots_OnUpdateIOCard(int* test,int ID)
{
	nIOCard[ID]->setEditValue(test,nAlert->nErrorType.at(test[17]));
}
void MultiInterface::onServerConnected(QString IPAddress,bool nState)
{
	if(IPAddress == IP1)
	{
		ui.checkBox->setChecked(nState);
	}
	else if(IPAddress == IP2)
	{
		ui.checkBox_2->setChecked(nState);
	}
	else if(IPAddress == IP3)
	{
		ui.checkBox_3->setChecked(nState);
	}
}
void MultiInterface::ClearCount(bool isChangeShift)
{
	if(!isChangeShift)
	{
		if (QMessageBox::No == QMessageBox::question(this,tr("clear"),
			tr("Are you sure to clear?")+"\n"+tr("For Report statistical accuracy.")+"\n"+tr("Please make sure there are no bottles in the cabinet"),
			QMessageBox::Yes | QMessageBox::No))	
		{
			return;
		}
	}
	if(isChangeShift)
	{
		SendBasicNet(CLEAR,"NULL");
	}
	else
	{
		SaveCountInfo(ByTime,tr("CountClear"));
		SaveCountInfo(ByShift,tr("CountClear"));
		SendBasicNet(CLEAR,"Clear");
		for(int i=0;i<3;i++)
		{
			nDataCount[i].clear();
		}
	}
	nTmpcountData.Clear();
	nRunInfo.Clear();
	LastRunInfo.Clear();
	
	nAllCheckNum = 0;
	nAllFailNum = 0;
	UpdateCountForShow();
}
void MultiInterface::UpdateCountForShow(bool isFirst)
{
	emit sianal_updateCountInfo(nAllCheckNum,nAllFailNum,0);
	emit sianal_UpdateTable1(nRunInfo);
	
	if (!isFirst)
	{
		m_Datebase->insertLastData(nAllCheckNum,nAllFailNum,nRunInfo);
	}
}
#ifdef JIAMI_INITIA
bool MultiInterface::CheckLicense()
{
	QString  g_UidChar = "06a6914a-d863-43e1-800e-7e2eece22fd7";
	ver_code uucode;
	m_ProgramLicense.GetVerCode(&uucode);
	QString strCode = QString("%1-%2-%3-%4%5-%6%7%8%9%10%11")
		.arg(uucode.Data1,8,16,QChar('0')).arg(uucode.Data2,4,16,QChar('0')).arg(uucode.Data3,4,16,QChar('0'))
		.arg((int)uucode.Data4[0],2,16,QChar('0')).arg((int)uucode.Data4[1],2,16,QChar('0'))
		.arg((int)uucode.Data4[2],2,16,QChar('0')).arg((int)uucode.Data4[3],2,16,QChar('0'))
		.arg((int)uucode.Data4[4],2,16,QChar('0')).arg((int)uucode.Data4[5],2,16,QChar('0'))
		.arg((int)uucode.Data4[6],2,16,QChar('0')).arg((int)uucode.Data4[7],2,16,QChar('0'));
	if (g_UidChar == strCode)
	{
		//验证License
		s_KeyVerfResult res = m_ProgramLicense.CheckLicenseValid(true);
		if (res.nError <= 0)//未超时
		{
			surplusDays = m_ProgramLicense.ReadHardwareID("getexpdate");
			ui.label_version->setText(QString::fromLocal8Bit("设备剩余使用时间:%1天").arg(surplusDays));
			//传递窗口句柄
			m_ProgramLicense.SetMainWnd((HWND)this->winId());
			return true; 
		}
		else
		{
			QMessageBox::information(this,tr("Error"),tr("License expired or dongle abnormal! Error code: %1").arg(res.nError)); //License过期或加密狗异常！错误代码：%1
			exit(0);
		}
	}
	else
	{
		QMessageBox::information(this,tr("Error"),tr("Encryption authentication failed!")); //加密验证失败
		exit(0);
	}
	return true;
}
#else
bool MultiInterface::CheckLicense()
{
	return TRUE;
}
#endif // JIAMI_INITIA
