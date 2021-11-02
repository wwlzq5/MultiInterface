#ifndef WIDGET_SEVER_H
#define WIDGET_SEVER_H

#include <QWidget>
#include <windows.h>
#include "Stool.h"
#include <QCloseEvent>
#include <QTimer>


class VNC_widget : public QWidget
{
	Q_OBJECT
public:
	VNC_widget(QWidget *parent=0);
	~VNC_widget();

	bool Connect(int index);
	bool disConnect();

	void ShowWidget(int index);
	void CloseWidget();

private slots:
	void Show();

private:
	void *m_plmp;
	int CurrentCntIndex;

};

#endif // WIDGET_PLC_H
