#ifndef WIDGET_SEVER_H
#define WIDGET_SEVER_H
#include <QWidget>
#include <QMainWindow>
#include "ui_Sever.h"
#include <windows.h>
#include "Stool.h"
#include <QCloseEvent>
//#define VNCTEST
#ifdef VNCTEST
#using "E:\MultiInterface\x64\123\BADControl.dll"
#using "E:\MultiInterface\x64\123\System.Windows.Forms.dll"
#using "E:\MultiInterface\x64\123\System.dll"
using namespace BAD;
using namespace System::Runtime::InteropServices;
#else

#endif // !1
class Widget_Sever : public QMainWindow
{
	Q_OBJECT

public:
	Widget_Sever(QWidget *parent = 0,int temp =0);
	~Widget_Sever();
public:
	void closeScreen();
	void SetParam(int,int);
protected:
	void closeEvent(QCloseEvent *event);
public:
	void* m_plmp;
public:
	Ui::MainWindow ui;
};

#endif // WIDGET_PLC_H
