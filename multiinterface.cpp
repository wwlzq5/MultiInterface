#include "multiinterface.h"
#include <QDebug>

MultiInterface *pMainFrm;

MultiInterface::MultiInterface(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	pMainFrm = this;
	setWindowIcon(QIcon("./Resources/LOGO.png"));
	setCentralWidget(ui.centralWidget);

	InitConfig();
	InitSocket();
	InitConnect();
	m_Datebase =new DataBase(AppPaths.AppPath);
	mVNC_window=new VNC_widget();
	for(int i=0;i<256;i++)
	{
		nSendData[i].id = 0;
		nSendData[i].nErrorArea = 0;
		nSendData[i].nType = 0;
	}
	connect(nWidgetCount ,SIGNAL(updateRecordSet()),this,SLOT(slots_UpdateRecordSet()));
	connect(nWidgetCount ,SIGNAL(updateShiftSet()),this,SLOT(slots_UpdateShiftSet()));

	timerSaveList = new QTimer(this);
	timerSaveList->setInterval(60*1000);//每分钟触发一次
	connect(timerSaveList, SIGNAL(timeout()), this, SLOT(slots_SaveCountBytime()));  
	connect(timerSaveList, SIGNAL(timeout()), this, SLOT(slots_SaveCountByShift()));  
	timerSaveList->start();

	m_Datebase->queryLastData(nAllCheckNum,nAllFailNum,nRunInfo);
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
	AppPaths.PLCAlertPath = AppPaths.AppPath + "Config/PLCAlertType.ini";
	AppPaths.errorTypePath = AppPaths.AppPath + "Config/ErrorType.ini";
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
	int  StatusTypeNumber= PLCStatusiniset.value(strSession,0).toInt();
	for (int i=1;i<=StatusTypeNumber;i++)
	{
		strSession = QString("/StatusType/%1").arg(i);
		m_PLCAlertType<<QString::fromLocal8Bit(PLCStatusiniset.value(strSession,"NULL").toString());
	}
	Logfile = new CLogFile();
	nOver  = true;
	CreateThread( NULL, 0, (LPTHREAD_START_ROUTINE)DataHanldThread, this, 0, NULL );
	CreateThread( NULL, 0, (LPTHREAD_START_ROUTINE)DataCountThread, this, 0, NULL );

	nSaveDataAddress = new int[HORIZONTAL24];
	
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
	nConnectState->setInterval(60*1000);
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

	nUserWidget->hide();
	slots_loginState(2);
}
void MultiInterface::ChangeVncState(int nTest)
{
	mVNC_window->ShowWidget(nTest);
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
		ui.pushButton_open2->setEnabled(false);
		ui.pushButton_open3->setEnabled(false);
		ui.pushButton_2->setEnabled(false);
		ui.pushButton_IO->setEnabled(false);
		ui.pushButton_Alert->setEnabled(false);
		ui.pushButton_Mode->setEnabled(false);
		ui.pushButton_lock->setEnabled(true);
	}else//二级权限暂时提供所有功能 
	{
		ui.pushButton_open1->setEnabled(true);
		ui.pushButton_open2->setEnabled(true);
		ui.pushButton_open3->setEnabled(true);
		ui.pushButton_2->setEnabled(true);
		ui.pushButton_IO->setEnabled(true);
		ui.pushButton_Alert->setEnabled(true);
		ui.pushButton_Mode->setEnabled(true);
		ui.pushButton_lock->setEnabled(false);
	}
}
void MultiInterface::SendBasicNet(StateEnum nState,QString nTemp)
{
	QList<QTcpSocket *> m_tcps = m_temptcpServer->findChildren<QTcpSocket *>();
	foreach (QTcpSocket *tcp, m_tcps)
	{
		MyStruct nData;
		nData.nState = nState;
		nData.nCount = sizeof(MyStruct);
		if(nTemp != "NULL")
		{
			strcpy_s(nData.nTemp,nTemp.toLocal8Bit().data());
		}else{
			strcpy_s(nData.nTemp,nTemp.toStdString().c_str());
		}
		tcp->write((char*)&nData,sizeof(MyStruct));
	}
}
void MultiInterface::slots_clickAccont(int nTest)
{
	switch (nTest)
	{
	case 0:
		ChangeVncState(0);
		nSheetPage = NLEADING;
		Logfile->write(tr("into Front Interface"),OperationLog);
		break;
	case 1:
		ChangeVncState(1);
		nSheetPage = NCLAMPING;
		Logfile->write(tr("into Clamping Interface"),OperationLog);
		break;
	case 2:
		ChangeVncState(2);
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
		//nUserWidget->show();
		//Logfile->write(tr("into lock Interface"),OperationLog);
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
				SaveCountInfo();
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
				SaveCountInfo();
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
			ClearCount();
			currentShift = 0;
		}
	}
	else if(currentTm >SysConfigInfo.shift2Time &&  currentTm < SysConfigInfo.shift3Time)
	{
		if(currentShift != 1)
		{
			//qDebug()<<"Shift2";
			ClearCount();
			currentShift = 1;
		}
	}
	else if(currentTm <SysConfigInfo.shift1Time || currentTm > SysConfigInfo.shift3Time)
	{
		if(currentShift != 2)
		{
			//qDebug()<<"Shift3";
			ClearCount();
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
		if(!timerSaveList->isActive())  timerSaveList->start();
	else
		if(timerSaveList->isActive())   timerSaveList->stop();
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
	if((tgcPosition.x == gcPosition.x) && (tgcPosition.y == gcPosition.y))
	{
		//关闭远程界面
		Logfile->write(QString("Auto disconnect!"),OperationLog);
		mVNC_window->CloseWidget();
		Sleep(2000);
		//nUserWidget->show();
	}else{
		gcPosition.x = tgcPosition.x;
		gcPosition.y = tgcPosition.y;
	}
}
void MultiInterface::slots_ConnectState()
{
	for(int i=0;i<3;i++)
	{
		if(IPAddress[i].nstate)
		{
			//心跳机制，判断是否断开连接
			int timeLength = QTime::currentTime().minute();
			if((timeLength-IPAddress[i].startTime+60)%60 >5)
			{
				onServerConnected(IPAddress[i].ipAddress,0);
				IPAddress[i].nstate = false;
				Logfile->write(QString("%1-lost connect %2--%3!").arg(i).arg(timeLength).arg(IPAddress[i].startTime),OperationLog);
			}else{
				onServerConnected(IPAddress[i].ipAddress,1);
			}
		}
	}
}
void MultiInterface::SaveCountInfo()
{
	bool bIsEmptyFile = false;
	QString strFileName;
	strFileName = AppPaths.AppPath + "CountInfo/timeCount/";
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
	QFile writeFile(strFileName);
	//读入流和写入流
	QTextStream writeStream(&writeFile);
	if (!bIsEmptyFile)
	{
		writeStream<<"\n";
	}
	QTime time = QTime::currentTime();
	writeStream<<tr("Time:  %1:%2:%3").arg(time.hour()).arg(time.minute()).arg(time.second())<<"\t";
	writeStream<<tr("All Count:  %1").arg(nTmpcountData.iAllCount)<<"\t";
	writeStream<<tr("Fail Count:  %1").arg(nTmpcountData.GetFailCount())<<"\t";
	writeStream<<tr("Fail Rate:  %1%").arg(nTmpcountData.GetFailRate()*100 ,2,'f',2)<<"\n";

	writeStream<<tr("Front Count:  %1").arg(nTmpcountData.GetFrontCount())<<"\t";
	writeStream<<tr("Clamp Count:  %1").arg(nTmpcountData.GetClampCount())<<"\t";
	writeStream<<tr("Rear Count:  %1").arg(nTmpcountData.GetRearCount())<<"\n";

	for(int i=1;i<=m_ErrorTypeInfo.iErrorTypeCount;i++)
	{
		writeStream<<m_ErrorTypeInfo.iErrorType[i] + ":" + QString::number(nTmpcountData.GetErrorByTypeCount(i))<<"\t";
	}
	writeStream<<"\n";
	writeStream<<tr("Results")<<"\t\t";
	writeStream<<tr("Count")<<"\t";
	writeStream<<tr("front")<<"\t";
	writeStream<<tr("clamp")<<"\t";
	writeStream<<tr("rear") <<"\t";
	writeStream<<"\n";

	for(int i=1;i<m_ErrorTypeInfo.iErrorTypeCount;i++)
	{
		int pErrorByType = nTmpcountData.GetErrorByTypeCount(i);
		if(pErrorByType != 0)
		{
			QString tempString=m_ErrorTypeInfo.iErrorType[i];
			writeStream<<tempString;
			if (tempString.length() <= 4 )
				writeStream<<"\t\t";
			else
				writeStream<<"\t";
			writeStream<<QString::number(pErrorByType)<<"\t";
			writeStream<<QString::number(nTmpcountData.iFrontErrorByType[i])<<"\t";
			writeStream<<QString::number(nTmpcountData.iClampErrorByType[i])<<"\t";
			writeStream<<QString::number(nTmpcountData.iRearErrorByType[i])<<"\n";
		}
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
	nTmpcountData += nRunInfo - LastRunInfo;
// 	bool ret = m_Datebase->insert(dateTime.toString("yyyyMMddhhmm")
// 					,nTmpcountData.iAllCount
// 					,nTmpcountData.iFrontErrorByType
// 					,nTmpcountData.iClampErrorByType
// 					,nTmpcountData.iRearErrorByType  );

	bool ret = m_Datebase->insert(dateTime.toString("yyyyMMddhhmm"),nTmpcountData);

	LastRunInfo = nRunInfo;


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
	if(tcp->peerAddress().toString() == IP1)
	{
		ui.checkBox->setChecked(true);
	}
	else if(tcp->peerAddress().toString() == IP2)
	{
		ui.checkBox_2->setChecked(true);
	}
	else if(tcp->peerAddress().toString() == IP3)
	{
		ui.checkBox_3->setChecked(true);
	}
	connect(tcp, SIGNAL(readyRead()), this, SLOT(onServerDataReady()));
	connect(tcp,SIGNAL(stateChanged(QAbstractSocket::SocketState)),this,SLOT(slot_StateChanged(QAbstractSocket::SocketState)));
}
void MultiInterface::slot_StateChanged(QAbstractSocket::SocketState state)
{
	switch(state)
	{
	case QAbstractSocket::ConnectedState:
		Logfile->write("ConnectedState",CheckLog);
		break;
	case QAbstractSocket::ConnectingState:
		Logfile->write("ConnectingState",CheckLog);
		break;
	case QAbstractSocket::ClosingState:
		Logfile->write("ClosingState",CheckLog);
		break;
	case QAbstractSocket::UnconnectedState:
		Logfile->write("UnconnectedState",CheckLog);
		break;
	default:
		break;
	}
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
				}else{
					Logfile->write("data lost!",CheckLog);
				}
				break;
			case CONNECT:
				if(((MyStruct*)m_buffer.data())->nUnit == LEADING)
				{
					IPAddress[0].nstate = true;
					IPAddress[0].startTime = nTime.minute();
				}else if(((MyStruct*)m_buffer.data())->nUnit == CLAMPING)
				{
					IPAddress[1].nstate = true;
					IPAddress[1].startTime = nTime.minute();
				}else if(((MyStruct*)m_buffer.data())->nUnit == BACKING)
				{
					IPAddress[2].nstate = true;
					IPAddress[2].startTime = nTime.minute();
				}
				SendBasicNet(CONNECT,"NULL");
				break;
			case LOCKSCREEN:
				nUserWidget->hide();
				m_ScreenLevel = QString::number(((MyStruct*)m_buffer.data())->nFail);
				slots_loginState(m_ScreenLevel.toInt());
				SendBasicNet(LOCKSCREEN,m_ScreenLevel);
				break;
			case ALERT:
				if(nCount == sizeof(MyStruct)+24*sizeof(int))
				{
					TempBuffer = m_buffer.left(nCount);
					nDataList.push_back(TempBuffer);
				}
				break;
			case MAININTERFACE:
				mVNC_window->CloseWidget();
				nSheetPage = MAININTERFACE;
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
	MyErrorType nErrorFristData[256]={0};
	MyErrorType nErrorClampData[256]={0};
	MyErrorType nErrorBACKData[256]={0};
	QByteArray buffer[3]={0};
	char* ptr[3];
	int nDataSize = 256;
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
					if(nErrorFristData[i].nErrorArea < nErrorClampData[i].nErrorArea && nErrorClampData[i].nErrorArea > nErrorBACKData[i].nErrorArea)
					{
						pThis->nRunInfo.ClampCount += 1;
						pThis->nRunInfo.iClampErrorByType[nErrorClampData[i].nType] += 1;
						pThis->nRunInfo.iErrorByType[nErrorClampData[i].nType] += 1;
						pThis->nSendData[i] = nErrorClampData[i];
					}
					else if(nErrorFristData[i].nErrorArea < nErrorBACKData[i].nErrorArea && nErrorClampData[i].nErrorArea < nErrorBACKData[i].nErrorArea)
					{
						pThis->nRunInfo.RearCount += 1;
						pThis->nRunInfo.iRearErrorByType[nErrorBACKData[i].nType] += 1;
						pThis->nRunInfo.iErrorByType[nErrorBACKData[i].nType] += 1;
						pThis->nSendData[i] = nErrorBACKData[i];
					}
					else if(nErrorFristData[i].nErrorArea > nErrorClampData[i].nErrorArea && nErrorFristData[i].nErrorArea > nErrorBACKData[i].nErrorArea)
					{
						pThis->nRunInfo.FrontCount += 1;
						pThis->nRunInfo.iFrontErrorByType[nErrorFristData[i].nType] += 1;
						pThis->nRunInfo.iErrorByType[nErrorFristData[i].nType] += 1;
						pThis->nSendData[i] = nErrorFristData[i];
					}
				}
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
			if(nPlcTypeid == -1)
			{
				emit sianal_WarnMessage(nPlcTypeid,NULL);
			}else{
				emit sianal_WarnMessage(nPlcTypeid,m_PLCAlertType.at(nPlcTypeid));
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
		nTmpcountData.Clear();
		nRunInfo.Clear();
		LastRunInfo.Clear();
		SendBasicNet(CLEAR,"NULL");
	}
	else
	{
		nTmpcountData += nRunInfo - LastRunInfo;
		nRunInfo.Clear();
		LastRunInfo.Clear();
		SendBasicNet(CLEAR,"Clear");
	}
	for(int i=0;i<3;i++)
	{
		nDataCount[i].clear();
	}
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
