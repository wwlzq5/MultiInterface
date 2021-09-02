#include "multiinterface.h"
#define TESTREMOTE
MultiInterface::MultiInterface(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	setWindowIcon(QIcon("./Resources/LOGO.png"));
	setCentralWidget(ui.centralWidget);
	nWidgetCount = new widget_count(3,ui.widget_Count);
	QHBoxLayout * nBoxLayout = new QHBoxLayout(ui.widget_Count);
	ui.widget_Count->setLayout(nBoxLayout);
	nBoxLayout->addWidget(nWidgetCount);
	for(int i=0;i<3;i++)
	{
		m_sever[i] = new Widget_Sever(parent,i+1);
	}
	InitSocket();
	InitConnect();
	InitConfig();
}

MultiInterface::~MultiInterface()
{
}
void MultiInterface::closeEvent(QCloseEvent *event)
{
	nOver  = false;
	delete m_sever[0];
	delete m_sever[1];
	delete m_sever[2];
	delete nUserWidget;
	delete nWarning;
	delete nAlert;
}
void MultiInterface::InitConfig()
{
	//ui.widget->setWidgetName(tr("Count Info"));
	//获取PLC的报警列表
	QSettings PLCStatusiniset("./Config/PLCAlertType.ini",QSettings::IniFormat);
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
	nSqliteBase = new DataBase();
	nSaveDataAddress = new int[HORIZONTAL24];
	
	IpStruct nIptemp;
#ifdef TESTREMOTE
	nIptemp.ipAddress="192.168.250.201";
	nIptemp.nstate = false;
	IPAddress<<nIptemp;
	nIptemp.ipAddress="192.168.250.202";
	nIptemp.nstate = false;
	IPAddress<<nIptemp;
	nIptemp.ipAddress="192.168.250.203";
	nIptemp.nstate = false;
#else
	nIptemp.ipAddress="192.168.20.101";//124
	nIptemp.nstate = false;
	IPAddress<<nIptemp;
	nIptemp.ipAddress="192.168.250.202";
	nIptemp.nstate = false;
	IPAddress<<nIptemp;
	nIptemp.ipAddress="192.168.20.116";
	nIptemp.nstate = false;
#endif
	IPAddress<<nIptemp;
	nSheetPage = 0;
	time(&n_StartTime);
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
	ui.checkBox->setEnabled(false);
	ui.checkBox_2->setEnabled(false);
	ui.checkBox_3->setEnabled(false);
	ui.checkBox->setStyleSheet("QCheckBox::indicator {width:15px;height:15px;border-radius:7px}""QCheckBox::indicator:checked {background-color:green;}""QCheckBox::indicator:unchecked {background-color:red;}");
	ui.checkBox_2->setStyleSheet("QCheckBox::indicator {width:15px;height:15px;border-radius:7px}""QCheckBox::indicator:checked {background-color:green;}""QCheckBox::indicator:unchecked {background-color:red;}");
	ui.checkBox_3->setStyleSheet("QCheckBox::indicator {width:15px;height:15px;border-radius:7px}""QCheckBox::indicator:checked {background-color:green;}""QCheckBox::indicator:unchecked {background-color:red;}");
	
	nIOprence = new QWidget();
	QVBoxLayout * nVboxLayout = new QVBoxLayout();
	for(int i=0;i<3;i++)
	{
		nIOCard[i] = new IOCardClass(this);
		nVboxLayout->addWidget(nIOCard[i]);
	}
	nIOprence->setWindowIcon(QIcon("./Resources/LOGO.png"));
	nIOprence->setWindowTitle(tr("IOData"));
	nIOprence->setMinimumWidth(720);
	nIOprence->setMinimumHeight(1000);
	nIOprence->setLayout(nVboxLayout);
	connect(this,SIGNAL(UpdateIOCard(int*,int)),this,SLOT(slots_OnUpdateIOCard(int*,int)));

	nConnectState = new QTimer;
	nConnectState->setInterval(10000);
	connect(nConnectState,SIGNAL(timeout()),this,SLOT(slots_ConnectState()));
	nConnectState->start();

	nUserWidget = new UserWidget();
	connect(nUserWidget,SIGNAL(signal_TimeLogin(QTime)),this,SLOT(slots_TimeLogin(QTime)));

	nWarning = new Widget_Warning();
	connect(this,SIGNAL(sianal_WarnMessage(int,QString)),nWarning,SLOT(slot_ShowMessage(int,QString)));

	nAlert = new widget_Alert();
	
	nWidgetMode = new widget_Mode();
	connect(nWidgetMode,SIGNAL(signal_loadMode(QString)),this,SLOT(slots_LoadMode(QString)));

	signal_mapper = new QSignalMapper(this);
	connect(ui.pushButton_open1,SIGNAL(clicked()),signal_mapper,SLOT(map()));
	connect(ui.pushButton_open2,SIGNAL(clicked()),signal_mapper,SLOT(map()));
	connect(ui.pushButton_open3,SIGNAL(clicked()),signal_mapper,SLOT(map()));
	connect(ui.pushButton_IO,SIGNAL(clicked()),signal_mapper,SLOT(map()));
	connect(ui.pushButton_Alert,SIGNAL(clicked()),signal_mapper,SLOT(map()));
	connect(ui.pushButton_2,SIGNAL(clicked()),signal_mapper,SLOT(map()));
	connect(ui.pushButton_Mode,SIGNAL(clicked()),signal_mapper,SLOT(map()));

	signal_mapper->setMapping(ui.pushButton_open1,0);
	signal_mapper->setMapping(ui.pushButton_open2,1);
	signal_mapper->setMapping(ui.pushButton_open3,2);
	signal_mapper->setMapping(ui.pushButton_IO,3);
	signal_mapper->setMapping(ui.pushButton_Alert,4);
	signal_mapper->setMapping(ui.pushButton_2,5);
	signal_mapper->setMapping(ui.pushButton_Mode,6);
	connect(signal_mapper, SIGNAL(mapped(int)), this, SLOT(slots_clickAccont(int)));
}

void MultiInterface::slots_LoadMode(QString nModeName)
{
	QList<QTcpSocket *> m_tcps = m_temptcpServer->findChildren<QTcpSocket *>();
	foreach (QTcpSocket *tcp, m_tcps)
	{
		MyStruct temp;
		temp.nState = SYSTEMMODE;
		temp.nTemp = nModeName;
		tcp->write((char*)&temp,sizeof(MyStruct));
	}
}
void MultiInterface::ChangeVncState(int nTest)
{
	SendBasicNet(IMAGE);
	for(int i = 0;i<3;i++)
	{
		m_sever[i]->close();
	}
	Sleep(2000);
	m_sever[nTest]->SetParam(2500,1500);
	m_sever[nTest]->show();
}
void MultiInterface::SendBasicNet(StateEnum nState)
{
	QList<QTcpSocket *> m_tcps = m_temptcpServer->findChildren<QTcpSocket *>();
	foreach (QTcpSocket *tcp, m_tcps)
	{
		MyStruct temp;
		temp.nState = nState;
		tcp->write((char*)&temp,sizeof(MyStruct));
	}
}
void MultiInterface::slots_clickAccont(int nTest)
{
	switch (nTest)
	{
	case 0:
		ChangeVncState(0);
		Logfile->write(tr("into Front Interface"),OperationLog);
		break;
	case 1:
		ChangeVncState(1);
		Logfile->write(tr("into Clamping Interface"),OperationLog);
		break;
	case 2:
		ChangeVncState(2);
		Logfile->write(tr("into Backing Interface"),OperationLog);
		break;
	case 3:
		nIOprence->show();
		Logfile->write(tr("into IOCard Interface"),OperationLog);
		break;
	case 4:
		nAlert->show();
		Logfile->write(tr("into Alert Interface"),OperationLog);
		break;
	case 5:
		SendBasicNet(CLEAR);
		Logfile->write(tr("into Clear Interface"),OperationLog);
		break;
	case 6:
		nWidgetMode->show();
		Logfile->write(tr("into Mode Interface"),OperationLog);
		break;
	}
}
void MultiInterface::slots_TimeLogin(QTime nTime)
{
	time(&n_StartTime);
}
void MultiInterface::mouseMoveEvent(QMouseEvent *event)
{
	time(&n_StartTime);
}
void MultiInterface::mousePressEvent(QMouseEvent *event)
{
	time(&n_StartTime);
}
void MultiInterface::slots_ConnectState()
{
	for(int i=0;i<3;i++)
	{
		//心跳机制，判断是否断开连接
		int timeLength = QTime::currentTime().second();
		if(IPAddress[i].nstate)
		{
			if((timeLength-IPAddress[i].startTime+60)%60 >15)
			{
				onServerConnected(IPAddress[i].ipAddress,0);
				IPAddress[i].nstate = false;
			}else{
				onServerConnected(IPAddress[i].ipAddress,1);
			}
		}
	}
	//TemporaryData temp={0};
	//QVector<TemporaryData> nData;
	//nData<<temp<<temp<<temp;
	//QTime nTime = QTime::currentTime();
	//if((nTime.minute()==30||nTime.minute()==0)&&(nTime.second()<=20&&nTime.second()>10))//自动存储数据到报表中
	//{
	//	QList<QTcpSocket *> m_tcps = m_temptcpServer->findChildren<QTcpSocket *>();
	//	foreach (QTcpSocket *tcp, m_tcps)
	//	{
	//		MyStruct temp;
	//		temp.nState = SEVERS;
	//		tcp->write((char*)&temp,sizeof(MyStruct));
	//	}
	//	for(int i=0;i<3;i++)
	//	{
	//		QList<SeleteData> m_temp = nSqliteBase->queryAll(QDateTime::currentDateTime().addSecs(-30*60).toString("yyMMddhhmmss"),QDateTime::currentDateTime().toString("yyMMddhhmmss"),i);
	//		for(int j=0;j<m_temp.count();j++)
	//		{
	//			for(int k =0;k<30;k++)
	//			{
	//				nData[i].nTypeCount[k][m_temp[j].nType] += m_temp[j].nTypeCount[k];
	//			}
	//			nData[i].nCameraTypeCount[m_temp[j].nType] += m_temp[j].nCameraTypeCount;
	//		}
	//	}
	//	//导入报表
	//	slots_SaveCountInfo(nData);
	//}
	//没人操作锁屏
	time(&n_EndTime);
	if(difftime(n_StartTime,n_EndTime)> 5*60)
	{
		nUserWidget->ShowInterfance();
	}
}
void MultiInterface::slots_SaveCountInfo(QVector<TemporaryData> nData)
{
	
}
void MultiInterface::ServerNewConnection()
{
	QTcpSocket* tcp = m_temptcpServer->nextPendingConnection(); //获取新的客户端信息
	onServerConnected(tcp->peerAddress().toString(),1);
	connect(tcp, SIGNAL(readyRead()), this, SLOT(onServerDataReady()));
}
void MultiInterface::onServerDataReady()
{
	QTcpSocket* m_tcpSocket = dynamic_cast<QTcpSocket*>(sender());
	QByteArray buffer = m_tcpSocket->readAll();
	
	if (((MyStruct*)buffer.data())->nState == SENDDATA)
	{
		if(buffer.length() == sizeof(MyStruct)+((MyStruct*)buffer.data())->nCount*HORIZONTAL24 || buffer.length() == sizeof(MyStruct)+((MyStruct*)buffer.data())->nCount*HORIZONTAL4)
		{
			nDataLock.lock();
			nDataList.push_back(buffer);
			nDataLock.unlock();
		}
	}else if(((MyStruct*)buffer.data())->nState == CONNECT)//心跳包，用于判断是否掉线
	{
		QTime nTime =  QTime::currentTime();
		for(int i=0;i<3;i++)
		{
			if(m_tcpSocket->peerAddress().toString() == IPAddress[i].ipAddress)
			{
				IPAddress[i].nstate = true;
				IPAddress[i].startTime = nTime.second();
				MyStruct temp;
				temp.nState = CONNECT;
				m_tcpSocket->write((char*)&temp,sizeof(MyStruct));
			}
		}
	}else if(((MyStruct*)buffer.data())->nState == LOCKSCREEN)
	{
		time(&n_StartTime);
	}else if(((MyStruct*)buffer.data())->nState == ALERT)//接口卡和错误显示
	{
		if(buffer.length() == sizeof(MyStruct)+HORIZONTAL24)//12路输出信号+4路补充信息+错误缺陷
		{
			nDataLock.lock();
			nDataList.push_back(buffer);
			nDataLock.unlock();
		}
	}else if(((MyStruct*)buffer.data())->nState == SEVERS)//从第四块接口卡获取过检总数和踢废总数
	{
		nAllCheckNum = ((MyStruct*)buffer.data())->nCount;
		nAllFailNum = ((MyStruct*)buffer.data())->nFail;
	}else if(((MyStruct*)buffer.data())->nState == NLEADING)// 切换到前端界面
	{
		if(nSheetPage != NLEADING)
		{
			ChangeVncState(0);
			nSheetPage = NLEADING;
		}
	}else if(((MyStruct*)buffer.data())->nState == NCLAMPING)
	{
		if(nSheetPage != NCLAMPING)
		{
			ChangeVncState(1);
			nSheetPage = NCLAMPING;
		}
	}else if(((MyStruct*)buffer.data())->nState == NBACKING)
	{
		if(nSheetPage != NBACKING)
		{
			ChangeVncState(2);
			nSheetPage = NBACKING;
		}
	}else if(((MyStruct*)buffer.data())->nState == MAININTERFACE)
	{
		m_sever[2]->close();
		m_sever[1]->close();
		m_sever[0]->close();
	}
}
DWORD WINAPI MultiInterface::DataHanldThread( void *arg )
{
	MultiInterface* pThis = ( MultiInterface* )arg;
	while (pThis->nOver)
	{
		QByteArray buffer;
		pThis->nDataLock.lock();
		if(pThis->nDataList.count()>0)
		{
			buffer = pThis->nDataList.first();
			pThis->nDataList.removeFirst();
			pThis->CalculateData(buffer);
		}
		pThis->nDataLock.unlock();
		Sleep(50);
	}
	return true;
}
void MultiInterface::CalculateData(QByteArray buffer)
{
	char* t_ptr = buffer.data();
	int nCameraUnit = nSqliteBase->nCountCamera[((MyStruct*)t_ptr)->nUnit];
	int nCount = ((MyStruct*)t_ptr)->nCount;
	int nFail = ((MyStruct*)t_ptr)->nFail;
	int nUnit = ((MyStruct*)t_ptr)->nUnit;
	if(((MyStruct*)t_ptr)->nState == SENDDATA)
	{
		/*TemporaryData nTemp={0};
		t_ptr+=sizeof(MyStruct);
		for(int i = 0 ; i < nCount; i++)
		{
		memcpy(nSaveDataAddress,t_ptr,sizeof(int)*nCameraUnit);
		for(int j = 0 ; j < nCameraUnit; j++)
		{
		int FailType = nSaveDataAddress[j];
		if(FailType > 0 && FailType < 50)
		{
		nTemp.nTypeCount[j][FailType]++;
		nTemp.nCameraTypeCount[FailType]++;

		}
		}
		t_ptr += sizeof(int)*nCameraUnit;
		}
		nTemp.nAllCount = nCount;
		nTemp.nFailCount = nFail;
		nSqliteBase->insert(QDateTime::currentDateTime().toString("yyMMddhhmmss"),nTemp,nUnit);*/
	}else if(((MyStruct*)t_ptr)->nState == ALERT)
	{
		memcpy(nSaveDataAddress,t_ptr+sizeof(MyStruct),HORIZONTAL24);
		//发送信号界面UI显示
		emit UpdateIOCard(nSaveDataAddress,nUnit);
		if(nUnit ==1)//报警标志位
		{
			int nPlcTypeid = nSaveDataAddress[23];
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
	
#ifdef TESTREMOTE
	if(IPAddress == "192.168.250.201")
	{
		ui.checkBox->setChecked(nState);
	}else if(IPAddress == "192.168.250.202")
	{
		ui.checkBox_2->setChecked(nState);
	}else if(IPAddress == "192.168.250.203")
	{
		ui.checkBox_3->setChecked(nState);
	}
#else
	if(IPAddress == "192.168.20.101")
	{
		ui.checkBox->setChecked(nState);
	}else if(IPAddress == "192.168.250.202")
	{
		ui.checkBox_2->setChecked(nState);
	}else if(IPAddress == "192.168.20.116")
	{
		ui.checkBox_3->setChecked(nState);
	}
#endif
}