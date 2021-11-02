#ifndef WIDGETMODE_H
#define WIDGETMODE_H
#include "ui_ProdectMode.h"
#include <QStandardItemModel>
#include <QSettings>
#include <QTextCodec>
#include <QTime>
#include <QList>
#include <QMessageBox>
#include "Stool.h"
struct MyModeList
{
	QString sModeName;
	QString sModeTime;
};
class widget_Mode : public QWidget
{
	Q_OBJECT
public:
	widget_Mode();
	~widget_Mode();
public:
	void initConfig();
	void InsertTableExcel(int,QString);
	void initSocket();
	void closeEvent(QCloseEvent *event);
signals:
	void signal_ModeState(StateEnum,QString);
public slots:
	void slot_Refresh();
	void slot_loadMode();
	void slot_deleteMode();
	void slot_showAddMode();
	void slot_addMode();
	void slots_ShowSelectImage(QModelIndex);
public:
	QModelIndex nModelIndex;
	int nListNo;
public:
	QStandardItemModel *nModelExcel; 
	QList<MyModeList> nModeList;
public:
	Ui::widgetMode ui;
};


#endif