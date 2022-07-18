#include "widgetAlert.h"
widget_Alert::widget_Alert()
{
	ui.setupUi(this);
	setWindowIcon(QIcon("./Resources/LOGO.png"));
	setWindowTitle(tr("Detect Alert"));
	initConfig();
	initSocket();
}
widget_Alert::~widget_Alert()
{
	close();
}
void widget_Alert::initSocket()
{
	connect(nErrorTimer,SIGNAL(timeout()),this,SLOT(slot_JudgeAlert()));
	connect(ui.pushButton_set,SIGNAL(clicked()),this,SLOT(slot_PushAlretAdd()));
	connect(ui.pushButton_delete,SIGNAL(clicked()),this,SLOT(slot_PushAlretDelete()));
	connect(ui.pushButton_Sure,SIGNAL(clicked()),this,SLOT(slot_Sure()));
}
void widget_Alert::initConfig()
{
	//读取配置错误信息
	QSettings erroriniset("../Config/ErrorType.ini",QSettings::IniFormat);
	erroriniset.setIniCodec(QTextCodec::codecForName("GBK"));
	QString strSession;
	strSession = QString("/ErrorType/total");
	int nMaxTypeCount = erroriniset.value(strSession,0).toInt();

	for (int i=1;i<=nMaxTypeCount;i++)
	{
		strSession = QString("/ErrorType/%1").arg(i);
		nErrorType<<QString::fromLocal8Bit(erroriniset.value(strSession,"NULL").toString());
	}
	ui.comboBox->addItems(nErrorType);
	nErrorType.push_front(tr("Good"));
	//读取配置参数信息

	//增加列表信息
	nAlertModel = new QStandardItemModel();
	nAlertModel->setColumnCount(2);
	nAlertModel->setHeaderData(0,Qt::Horizontal,tr("ErrorType"));
	nAlertModel->setHeaderData(1,Qt::Horizontal,tr("Condition"));
	ui.tableView->setModel(nAlertModel); 
	//表头信息显示居左 
	ui.tableView->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
	ui.tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);	//禁止编辑
	ui.tableView->setSelectionBehavior(QAbstractItemView::SelectRows); //整行选中
	ui.tableView->setSelectionMode(QAbstractItemView::SingleSelection); //单个选中目标
	//设置列宽不可变 
	ui.tableView->horizontalHeader()->setResizeMode(0,QHeaderView::Fixed); 
	ui.tableView->horizontalHeader()->setResizeMode(1,QHeaderView::Fixed);
	ui.tableView->setColumnWidth(0,180); 
	ui.tableView->setColumnWidth(1,500);

	nErrorTimer = new QTimer();
	nErrorTimer->setInterval(10000);
	nErrorTimer->start();
}
void widget_Alert::slot_JudgeAlert()
{

}
void widget_Alert::slot_Sure()
{

}

void widget_Alert::slot_PushAlretDelete()
{
	int curRow = ui.tableView->currentIndex().row();
	nAlertModel->removeRow(curRow);
	if(nAlertList.count()>0)
	{
		nAlertList.removeAt(curRow);
	}
}

void widget_Alert::slot_PushAlretAdd()
{
	MyErrorStruct nTemp;
	int mErrorIndex = ui.comboBox->currentIndex() + 1;//从0开始，所以要加1表示对应缺陷列表
	nTemp.nTypeID = mErrorIndex;
	QStandardItem *item1 = new QStandardItem(QObject::tr("%1").arg(nErrorType.at(mErrorIndex)));
	mErrorIndex = ui.comboBox_2->currentIndex();
	if(mErrorIndex)
	{
		nTemp.mContinued = false;
	}else{
		nTemp.mContinued = true;
	}
	nTemp.mRequirementMin = ui.spinBox->text().toInt();
	nTemp.mRequirementBottle = ui.spinBox_2->text().toInt();
	QStandardItem *item2 = new QStandardItem(QObject::tr("%1").arg(ui.spinBox->text()+ui.label_5->text()+ui.comboBox_2->text(mErrorIndex)+ui.label_7->text()+ui.spinBox_2->text()+ui.label_6->text()));
	nAlertList<<nTemp;
	QList<QStandardItem*> item;
	item<<item1<<item2;
	nAlertModel->insertRow(0,item);
	ui.tableView->showRow(0);
	if (10 < nAlertModel->rowCount())
	{
		QList<QStandardItem*>  item = nAlertModel->takeRow(nAlertModel->rowCount()-1);
		if (!item.isEmpty())
		{
			qDeleteAll(item);
			item.clear();
			nAlertList.removeAt(10);
		}
	}
}
