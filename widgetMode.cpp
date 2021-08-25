#include "widgetMode.h"
widget_Mode::widget_Mode()
{
	ui.setupUi(this);
	initConfig();
	initSocket();
}
widget_Mode::~widget_Mode()
{

}
void widget_Mode::initSocket()
{
	ui.label->setVisible(false);
	ui.pushButton_sure->setVisible(false);
	ui.lineEdit->setVisible(false);
	connect(ui.pushButton_new,SIGNAL(clicked()),this,SLOT(slot_showAddMode()));
	connect(ui.pushButton_sure,SIGNAL(clicked()),this,SLOT(slot_addMode()));
	connect(ui.pushButton_delete,SIGNAL(clicked()),this,SLOT(slot_deleteMode()));
	connect(ui.pushButton_add,SIGNAL(clicked()),this,SLOT(slot_loadMode()));
	connect(ui.tableView, SIGNAL(clicked(QModelIndex)), this, SLOT(slots_ShowSelectImage(QModelIndex)));
}
void widget_Mode::initConfig()
{
	setWindowTitle(tr("mode set"));
	nModelExcel = new QStandardItemModel();
	nModelExcel->setColumnCount(3);
	nModelExcel->setHeaderData(0,Qt::Horizontal,tr("id"));
	nModelExcel->setHeaderData(1,Qt::Horizontal,tr("Mode Name"));
	nModelExcel->setHeaderData(2,Qt::Horizontal,tr("Create Time"));
	//���ñ������
	ui.tableView->setModel(nModelExcel); 
	//��ͷ��Ϣ��ʾ���� 
	ui.tableView->horizontalHeader()->setDefaultAlignment(Qt::AlignHCenter);
	ui.tableView->horizontalHeader()->setResizeMode(0,QHeaderView::Fixed); 
	ui.tableView->horizontalHeader()->setResizeMode(1,QHeaderView::Stretch); 
	ui.tableView->horizontalHeader()->setResizeMode(2,QHeaderView::Stretch);
	ui.tableView->setColumnWidth(0,20);

	ui.tableView->verticalHeader()->setVisible(false);					//������ͷ
	ui.tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);	//��ֹ�༭
	ui.tableView->setSelectionBehavior(QAbstractItemView::SelectRows); //����ѡ��
	//��ȡ�����ļ��е�ģ������
	QSettings erroriniset("./Config/ModeType.ini",QSettings::IniFormat);
	erroriniset.setIniCodec(QTextCodec::codecForName("UTF-8"));
	QString strSession;
	strSession = QString("/ModeType/total");
	int nMaxTypeCount = erroriniset.value(strSession,0).toInt();

	for (int i = 1 ;i <= nMaxTypeCount;i++)
	{
		MyModeList nTemp;
		strSession = QString("/name/%1").arg(i);
		nTemp.sModeName = erroriniset.value(strSession,"NULL").toString();
		strSession = QString("/time/%1").arg(i);
		nTemp.sModeTime = QString::fromLocal8Bit(erroriniset.value(strSession,"NULL").toString());

		QStandardItem *item1 = new QStandardItem(QObject::tr("%1").arg(i));
		QStandardItem *item2 = new QStandardItem(QObject::tr("%1").arg(nTemp.sModeName));
		QStandardItem *item3 = new QStandardItem(QObject::tr("%1").arg(nTemp.sModeTime));
		QList<QStandardItem*> item;
		item<<item1<<item2<<item3;
		int tCount = nModelExcel->rowCount();
		nModelExcel->insertRow(tCount,item);
		ui.tableView->showRow(0);
		if (30 < tCount)
		{
			QList<QStandardItem*>  item = nModelExcel->takeRow(tCount-1);
			if (!item.isEmpty())
			{
				qDeleteAll(item);
				item.clear();
			}
		}
		nModeList << nTemp;
	}
	nListNo = -1;
}
void widget_Mode::slots_ShowSelectImage(QModelIndex modelIndex)
{
	nModelIndex = modelIndex;
	nListNo = modelIndex.row();
}
void widget_Mode::slot_showAddMode()
{
	ui.label->setText(tr("enter a mode name:"));
	ui.label->setVisible(true);
	ui.lineEdit->setVisible(true);
	ui.pushButton_sure->setVisible(true);
}
void widget_Mode::slot_addMode()
{
	MyModeList nTemp;
	nTemp.sModeName = ui.lineEdit->text();
	nTemp.sModeTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
	nModeList<<nTemp;

	QStandardItem *item1 = new QStandardItem(QObject::tr("%1").arg(nModeList.count()+1));
	QStandardItem *item2 = new QStandardItem(QObject::tr("%1").arg(nTemp.sModeName));
	QStandardItem *item3 = new QStandardItem(QObject::tr("%1").arg(nTemp.sModeTime));
	QList<QStandardItem*> item;
	item<<item1<<item2<<item3;
	int tCount = nModelExcel->rowCount();
	nModelExcel->insertRow(tCount,item);
	ui.tableView->showRow(0);
	if (30 < tCount)
	{
		QList<QStandardItem*>  item = nModelExcel->takeRow(tCount-1);
		if (!item.isEmpty())
		{
			qDeleteAll(item);
			item.clear();
		}
	}
}
void widget_Mode::slot_deleteMode()
{
	if(nListNo>=0)
	{
		nModeList.removeAt(nListNo);
		QList<QStandardItem*>  item = nModelExcel->takeRow(nListNo);
		if (!item.isEmpty())
		{
			qDeleteAll(item);
			item.clear();
		}
	}else{
		QMessageBox::information(this,tr("Information"),tr("please check a mode"));
	}
}
void widget_Mode::slot_loadMode()
{
	if(nListNo>=0)
	{
		setWindowTitle(tr("current mode")+": "+nModeList.at(nListNo).sModeName);
		emit signal_loadMode(nModeList.at(nListNo).sModeName);
	}else{
		QMessageBox::information(this,tr("Information"),tr("please check a mode"));
	}
}
void widget_Mode::closeEvent(QCloseEvent *event)
{
	QSettings settings("./Config/ModeType.ini",QSettings::IniFormat);
	settings.setIniCodec("UTF-8");
	QString strSession;
	QDateTime dateTime=QDateTime::currentDateTime();
	strSession = QString("/ModeType/total");
	settings.setValue(strSession,nModeList.count());

	for (int i = 1 ;i <= nModeList.count();i++)
	{
		MyModeList nTemp;
		strSession = QString("/name/%1").arg(i);
		settings.setValue(strSession,nModeList.at(i-1).sModeName);
		strSession = QString("/time/%1").arg(i);
		settings.setValue(strSession,nModeList.at(i-1).sModeTime);
	}
}