#ifndef WIDGETALERT_H
#define WIDGETALERT_H
#include <QLabel>
#include <QSpinBox>
#include <QGridLayout>
#include <QSpinBox>
#include <QStringList>
#include <QCheckBox>
#include <QTimer>
#include <QTime>
#include <QList>
#include <QMainWindow>
#include "ui_AlertWidget.h"
#include <QSettings>
#include <QTextCodec>
#include <QStandardItemModel>
#include <QMouseEvent>
struct MyErrorStruct
{
	int nTypeID;
	int mRequirementMin;
	bool mContinued;
	int mRequirementBottle;
};
class widget_Alert: public QMainWindow
{
	Q_OBJECT
public:
	widget_Alert();
	~widget_Alert();
public:
	void initConfig();
	void initSocket();
signals:
	//void LastTime(QTime);
public slots:
	void slot_JudgeAlert();
	void slot_PushAlretDelete();
	void slot_PushAlretAdd();
	void slot_Sure();
public:

public:
	QList<MyErrorStruct> nAlertList;
	QStandardItemModel *nAlertModel; 
	QStringList nErrorType;
	QTimer* nErrorTimer;
public:
	Ui::AletrWindow ui;
};




#endif