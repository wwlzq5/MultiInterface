#include "widgetSever.h"
#ifdef VNCTEST
#define __GCHANDLE_TO_VOIDPTR(x) ((GCHandle::operator System::IntPtr(x)).ToPointer())
#define __VOIDPTR_TO_GCHANDLE(x) (GCHandle::operator GCHandle(System::IntPtr(x)))
inline BadControl^ GetImpObj(void *pHandle)
{
	BadControl^ person = nullptr;
	if(pHandle != NULL)
	{
		person = static_cast<BadControl^>(__VOIDPTR_TO_GCHANDLE(pHandle).Target);
	}
	return person;
}

Widget_Sever::Widget_Sever(QWidget *parent,int id)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	setWindowIcon(QIcon("./Resources/LOGO.png"));
	setWindowFlags(Qt::FramelessWindowHint);
	setWindowState(Qt::WindowMaximized);
	BadControl^ nTest = gcnew BadControl();
	GCHandle handle= GCHandle::Alloc(nTest);
#ifdef TESTREMOTE
	if(id == 1)
	{
		setWindowTitle(tr("Anterior wall display"));
		nTest->Name = "123";
		nTest->HostAddress = "192.168.20.124";
	}else if(id == 2)
	{
		setWindowTitle(tr("Clamping display"));
		nTest->Name = "1234";
		nTest->HostAddress = "192.168.20.143";
	}else if(id == 3){
		setWindowTitle(tr("Posterior wall display"));
		nTest->Name = "12345";
		nTest->HostAddress = "192.168.20.116";
	}
#else
	if(id == 1)
	{
		setWindowTitle(tr("Anterior wall display"));
		nTest->Name = "123";
		nTest->HostAddress = "192.168.250.201";
	}else if(id == 2)
	{
		setWindowTitle(tr("Clamping display"));
		nTest->Name = "1234";
		nTest->HostAddress = "192.168.250.202";
	}else if(id == 3){
		setWindowTitle(tr("Posterior wall display"));
		nTest->Name = "12345";
		nTest->HostAddress = "192.168.250.203";
	}
#endif
	
	nTest->Password = "123456";
	m_plmp = __GCHANDLE_TO_VOIDPTR(handle);
	int test = nTest->Handle.ToInt32();
	SetParent((HWND)(test),ui.Sever->winId());
}
Widget_Sever::~Widget_Sever()
{
	BadControl^ nTest = GetImpObj(m_plmp);
	if(nTest->IsControlConnected)
	{
		nTest->CloseConnection();
	}
	close();
}

void Widget_Sever::closeEvent(QCloseEvent *e)
{
	BadControl^ nTest = GetImpObj(m_plmp);
	if(nTest->IsControlConnected)
	{
		nTest->CloseConnection();
	}
	hide();
	e->accept();
}
void Widget_Sever::closeScreen()
{
	BadControl^ nTest = GetImpObj(m_plmp);
	if(nTest->IsControlConnected)
	{
		nTest->CloseConnection();
	}
}
void Widget_Sever::SetParam(int width,int height)
{
	setWindowState(Qt::WindowMaximized);
	BadControl^ nTests = GetImpObj(m_plmp);
	if(!nTests->IsControlConnected)
	{
		nTests->SetScreenSize(width,height);
		nTests->Connect();
	}
}
#else
Widget_Sever::Widget_Sever(QWidget *parent,int id)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	setWindowIcon(QIcon("./Resources/LOGO.png"));
	setWindowFlags(Qt::FramelessWindowHint);
	setWindowState(Qt::WindowMaximized);
}
Widget_Sever::~Widget_Sever()
{

}
void Widget_Sever::closeEvent(QCloseEvent *event)
{
}
void Widget_Sever::SetParam(int width,int height)
{
}
#endif // !1


