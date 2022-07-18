#include "WidgetWarning.h"
#include <QDesktopWidget>
#include <QApplication>
#include <QLayout>
#include <windows.h>

#include "multiinterface.h"
extern MultiInterface *pMainFrm;

Widget_Warning::Widget_Warning(QWidget *parent)
	: QWidget(parent)
{
	setStyleSheet(QString::fromUtf8("background-color: rgb(138,171,140);"));
	bIsShow = true;
	setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);
	labelWarningPic = new QLabel();
	QPixmap pixmapWarning(":/MultiInterface/ALERT");
	labelWarningPic->setPixmap(pixmapWarning);
	labelWarningPic->setFixedSize(pixmapWarning.size());
	labelWarningInfo = new QLabel();
	QFont font("宋体",20,QFont::DemiBold,false);
	labelWarningInfo->setFont(font);
	labelWarningInfo->setText(tr("Alert Info!"));
	labelWarningInfo->setAlignment(Qt::AlignCenter);
	Init();
}

Widget_Warning::~Widget_Warning()
{
	close();
}
void Widget_Warning::Init()
{
	setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);//去掉标题栏
	desktopWidget = QApplication::desktop();
	setMinimumSize(400,300);
	QVBoxLayout *layoutInfo = new QVBoxLayout();
	layoutInfo->addWidget(labelWarningInfo,Qt::AlignCenter);
	
	QHBoxLayout *layoutBody = new QHBoxLayout();
	layoutBody->addWidget(labelWarningPic,Qt::AlignCenter);
	layoutBody->addLayout(layoutInfo,Qt::AlignCenter);
	layoutBody->setContentsMargins(10,0,10,0);
	layoutBody->setStretch(0,1);
	layoutBody->setStretch(1,1);

	QVBoxLayout *layoutMain = new QVBoxLayout(this);
	layoutMain->addLayout(layoutBody);
	layoutMain->setContentsMargins(0,0,0,0);
	iWarningType = -2;
}
bool Widget_Warning::IsShowWarning()
{
	return bIsShow;
}
void Widget_Warning::slot_ShowMessage(int warningType, QString warningInfo)
{
	if(iWarningType == warningType)
	{
		return;
	}
	iWarningType = warningType;
	if(warningType == -1)
	{
		pMainFrm->SendBasicNet(SEVERS,"NULL");
	}else{
		labelWarningInfo->setText(warningInfo);
		QDesktopWidget* desktopWidget = QApplication::desktop();
		move(desktopWidget->width()-400,desktopWidget->height()-300);
		if(warningInfo != "")
		{
			pMainFrm->SendBasicNet(SEVERS,warningInfo);
		}
	}
}
void Widget_Warning::slots_HideWidget()
{
	hide();
}
void Widget_Warning::slots_StopAlert()
{
	/*bIsShow = false;
	m_delayTime->start();
	hide();*/
}
