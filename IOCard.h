#ifndef IOCARD_H
#define IOCARD_H
#include "ui_IOCard.h"
#include <QMainWindow>
#include <QStandardItemModel>
#include <QTime>
class IOCardClass: public QMainWindow
{
	Q_OBJECT
public:
	IOCardClass(QWidget *parent = 0);
	~IOCardClass();
public:
	void initInterfance();
	void setEditValue(int*,QString);
	void InsertTableList(int,QString);
	
public slots:
	void slot_ClearTable();
	void slot_checkBoxCheck();
public:
	QStandardItemModel *m_model; 
	bool ifSHOW;
public:
	Ui::IOCard ui;
};

#endif