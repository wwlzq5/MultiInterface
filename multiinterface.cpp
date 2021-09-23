#include "multiinterface.h"
//#define TESTREMOTE
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
	for(int i=0;i<256;i++)
	{
		nSendData[i].id = 0;
		nSendData[i].nErrorArea = 0;
		nSendData[i].nType = 0;
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
	delete nWidgetMode;
	nIOprence->close();
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
	CreateThread( NULL, 0, (LPTHREAD_START_ROUTINE)DataCountThread, this, 0, NULL );
	nSqliteBase = new DataBase();
	nSaveDataAddress = new int[HORIZONTAL24];
	
	IpStruct nIptemp;
#ifdef TESTREMOTE
	nIptemp.ipAddress="192.168.20.101";
	nIptemp.nstate = false;
	IPAddress<<nIptemp;
	nIptemp.ipAddress="192.168.20.124";
	nIptemp.nstate = false;
	IPAddress<<nIptemp;
	nIptemp.ipAddress="192.168.20.116";
	nIptemp.nstate = false;
#else
	nIptemp.ipAddress="192.168.250.201";//124
	nIptemp.nstate = false;
	IPAddress<<nIptemp;
	nIptemp.ipAddress="192.168.250.202";
	nIptemp.nstate = false;
	IPAddress<<nIptemp;
	nIptemp.ipAddress="192.168.250.203";
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
	connect(nWidgetMode,SIGNAL(signal_ModeState(StateEnum,QString)),this,SLOT(slots_ModeState(StateEnum,QString)));

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
void MultiInterface::ChangeVncState(int nTest)
{
	SendBasicNet(IMAGE,NULL);
	m_sever[2]->close();
	m_sever[1]->close();
	m_sever[0]->close();
	Sleep(1000);
	m_sever[nTest]->SetParam(2500,1500);
	m_sever[nTest]->show();
}
void MultiInterface::slots_ModeState(StateEnum nState,QString nTemp)
{
	SendBasicNet(nState,nTemp);
}
void MultiInterface::SendBasicNet(StateEnum nState,QString nTemp)
{
	QList<QTcpSocket *> m_tcps = m_temptcpServer->findChildren<QTcpSocket *>();
	foreach (QTcpSocket *tcp, m_tcps)
	{
		MyStruct nData;
		nData.nState = nState;
		nData.nTemp = nTemp;
		tcp->write((char*)&nData,sizeof(MyStruct));
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
		nIOprence->raise();
		nIOprence->show();
		Logfile->write(tr("into IOCard Interface"),OperationLog);
		break;
	case 4:
		nAlert->raise();
		nAlert->show();
		Logfile->write(tr("into Alert Interface"),OperationLog);
		break;
	case 5:
		for(int i=0;i<3;i++)
		{
			nDataCount[i].clear();
		}
		SendBasicNet(CLEAR,NULL);
		Logfile->write(tr("into Clear Interface"),OperationLog);
		break;
	case 6:
		nWidgetMode->raise();
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
	//没人操作锁屏
	time(&n_EndTime);
	if(difftime(n_StartTime,n_EndTime)> 5*60)
	{
		nUserWidget->ShowInterfance();
	}
}
void MultiInterface::SaveCountInfo()
{
	bool bIsEmptyFile = false;
	QString strFileName;
	strFileName = "./CountInfo/HalfCount/";
	QDir *temp = new QDir;
	bool exist = temp->exists(strFileName);
	if(!exist)
	{
		bool ok = temp->mkdir(strFileName);
	}
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
	if(true)
	{
		if (!bIsEmptyFile)
		{
			writeStream<<"\n";
		}

		QTime time = QTime::currentTime();
		writeStream<<QString(tr("Time:  %1:%2:%3")).arg(time.hour()).arg(time.minute()).arg(time.second())<<"\t";
		writeStream<<QString(tr("Product Number:  %1")).arg(nAllCheckNum)<<"\t";
		writeStream<<QString(tr("Reject Number:  %1")).arg(nAllFailNum)<<"\t";
		double dFailurRate=0.0;
		if (0 != nAllCheckNum)
		{
			dFailurRate = 1.0*nAllFailNum/nAllCheckNum*100;
		}
		writeStream<<QString(tr("Reject Rate:  %1%")).arg(dFailurRate)<<"\n";

		writeStream<<"\n";
		writeStream<<tr("The statistical results")<<"\t\t";
		writeStream<<tr("Count")<<"\t";

		writeStream<<"\n";
		int iShownCount[50]={0};
		for(int i=0;i<256;i++)
		{
			if(nSendData[i].nType != 0)
			{
				iShownCount[nSendData[i].nType]++;
			}
		}
		for (int j = 1;j<nAlert->nErrorType.count();j++)
		{
			if (0 != iShownCount[j])
			{
				QString tempString = nAlert->nErrorType.at(j);
				writeStream<<tempString;
				if (tempString.length()<=4)
				{
					writeStream<<"\t"<<"\t";
				}
				else
				{
					writeStream<<"\t";
				}
				writeStream<<QString::number(iShownCount[j])<<"\t";
				writeStream<<"\n";
			}
		}
		writeStream<<"\n";
	}
	if (!writeFile.open(QFile::Append | QIODevice::Text))
	{
		return;
	}
	writeStream.flush();//写入流到文件
	writeFile.close();
	delete temp;
	return;
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
	
	if(((MyStruct*)buffer.data())->nState == SENDDATA)
	{
		nCountLock.lock();
		if(((MyStruct*)buffer.data())->nUnit = LEADING)
		{
			Logfile->write("1 get data",CheckLog);
			nDataCount[0].push_back(buffer);
		}else if(((MyStruct*)buffer.data())->nUnit = CLAMPING)
		{
			Logfile->write("2 get data",CheckLog);
			nDataCount[1].push_back(buffer);
		}else if(((MyStruct*)buffer.data())->nUnit = BACKING)
		{
			Logfile->write("3 get data",CheckLog);
			nDataCount[2].push_back(buffer);
		}
		nCountLock.unlock();
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
		nDataLock.lock();
		nDataList.push_back(buffer);
		nDataLock.unlock();
	}else if(((MyStruct*)buffer.data())->nState == SEVERS)//从第四块接口卡获取过检总数和踢废总数
	{
		/*if(((MyStruct*)buffer.data())->nUnit = CLAMPING)
		{
		char* t_ptr = buffer.data();
		t_ptr+=sizeof(MyStruct);
		}*/
		//nAllCheckNum = ((MyStruct*)buffer.data())->nCount;
		//nAllFailNum = ((MyStruct*)buffer.data())->nFail;
	}else if(((MyStruct*)buffer.data())->nState == NLEADING)// 切换到前端界面
	{
		if(nSheetPage != NLEADING)
		{
			Sleep(1000);
			ChangeVncState(0);
			nSheetPage = NLEADING;
		}
	}else if(((MyStruct*)buffer.data())->nState == NCLAMPING)
	{
		if(nSheetPage != NCLAMPING)
		{
			Sleep(1000);
			ChangeVncState(1);
			nSheetPage = NCLAMPING;
		}
	}else if(((MyStruct*)buffer.data())->nState == NBACKING)
	{
		if(nSheetPage != NBACKING)
		{
			Sleep(1000);
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
DWORD WINAPI MultiInterface::DataCountThread( void *arg )
{
	MultiInterface* pThis = ( MultiInterface* )arg;
	MyErrorType nErrorFristData[256];
	MyErrorType nErrorClampData[256];
	MyErrorType nErrorBACKData[256];
	QByteArray buffer[3];
	char* ptr[3];
	while (pThis->nOver)
	{
		pThis->nCountLock.lock();
		if(pThis->nDataCount[0].count()>0 && pThis->nDataCount[1].count()>0 && pThis->nDataCount[2].count()>0)
		{
			for(int i=0;i<3;i++)
			{
				buffer[i] = pThis->nDataCount[i].first();
				pThis->nDataCount[i].removeFirst();
				ptr[i] = buffer[i].data();
				ptr[i] += sizeof(MyStruct);
			}
			pThis->nCountLock.unlock();
			pThis->Logfile->write("fenxi data",CheckLog);
			//处理数据
			memcpy(&nErrorFristData,ptr[0],sizeof(MyErrorType)*256);
			memcpy(&nErrorClampData,ptr[1],sizeof(MyErrorType)*256);
			memcpy(&nErrorBACKData,ptr[2],sizeof(MyErrorType)*256);

			for(int i=0;i<256;i++) // 通过循环所有综合数据保存在 nErrorFristData中
			{
				if(nErrorFristData[i].nType != 0 || nErrorClampData[i].nType != 0 || nErrorBACKData[i].nType != 0)//综合有缺陷，计数加1
				{
					pThis->nAllFailNum++;
					//THREE_MAX(nErrorFristData[i].nErrorArea,nErrorClampData[i].nErrorArea,nErrorBACKData[i].nErrorArea);
					if(nErrorFristData[i].nErrorArea <= nErrorClampData[i].nErrorArea && nErrorClampData[i].nErrorArea >= nErrorBACKData[i].nErrorArea)
					{
						pThis->nSendData[i] = nErrorClampData[i];
					}else if(nErrorFristData[i].nErrorArea <= nErrorBACKData[i].nErrorArea && nErrorClampData[i].nErrorArea <= nErrorBACKData[i].nErrorArea)
					{
						pThis->nSendData[i] = nErrorBACKData[i];
					}else if(nErrorFristData[i].nErrorArea >= nErrorClampData[i].nErrorArea && nErrorFristData[i].nErrorArea >= nErrorBACKData[i].nErrorArea)
					{
						pThis->nSendData[i] = nErrorFristData[i];
					}
				}
			}
			pThis->SaveCountInfo();
		}else{
			for(int i=0;i<3;i++)
			{
				if(pThis->nDataCount[i].count()>500)
				{
					pThis->nDataCount[i].pop_front();
				}
			}
			pThis->nCountLock.unlock();
			Sleep(20);
		}
	}
	return true;
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
	int nUnit = ((MyStruct*)t_ptr)->nUnit;
	if(((MyStruct*)t_ptr)->nState == ALERT)
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
	if(IPAddress == "192.168.20.101")
	{
		ui.checkBox->setChecked(nState);
	}else if(IPAddress == "192.168.20.116")
	{
		ui.checkBox_2->setChecked(nState);
	}else if(IPAddress == "192.168.20.124")
	{
		ui.checkBox_3->setChecked(nState);
	}
#else
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
#endif
}