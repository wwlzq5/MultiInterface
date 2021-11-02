#include "widgetSever.h"

#define VNCTEST
#ifdef VNCTEST
#using "E:\MultiInterface\x64\123\BADControl.dll"
#using "E:\MultiInterface\x64\123\System.Windows.Forms.dll"
#using "E:\MultiInterface\x64\123\System.dll"
using namespace BAD;
using namespace System::Runtime::InteropServices;


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

VNC_widget::VNC_widget(QWidget *parent/*=0*/)
	:QWidget(parent)
{
	setWindowFlags(Qt::FramelessWindowHint);
	setWindowState(Qt::WindowMaximized);

	BadControl^ nVNCCtrl1 = gcnew BadControl();

	GCHandle pHandel1= GCHandle::Alloc(nVNCCtrl1);

	m_plmp = __GCHANDLE_TO_VOIDPTR(pHandel1);

	CurrentCntIndex=0;

	int test = nVNCCtrl1->Handle.ToInt32();
	SetParent((HWND)(test),this->winId());
}

VNC_widget::~VNC_widget()
{

}

bool VNC_widget::Connect(int index)
{
	if (index>3 || index < 0)
		return false;
	bool ret=false;
	BadControl^ nVNCControl = GetImpObj(m_plmp);

	if(!nVNCControl->IsControlConnected)
	{
		nVNCControl->SetScreenSize(2500,1500);
		switch(index)
		{
		case 0:
			nVNCControl->HostAddress = IP1;
			nVNCControl->Password = PASSWORD;
			break;
		case 1:
			nVNCControl->HostAddress = IP2;
			nVNCControl->Password = PASSWORD;
			break;
		case 2:
			nVNCControl->HostAddress = IP3;
			nVNCControl->Password = PASSWORD;
			break;
		default:
			break;
		}
		ret=nVNCControl->Connect();
	}
	return ret;
}

bool VNC_widget::disConnect()
{
	bool ret=true;
	BadControl^ nVNCControl = GetImpObj(m_plmp);
	if(nVNCControl->IsControlConnected)
	{
		ret = nVNCControl->CloseConnection();
	}
	return ret;
}

void VNC_widget::ShowWidget(int index)
{
	if (index>3 || index < 0)
		return;
	disConnect();
	CurrentCntIndex = index;
	QTimer::singleShot(100,this,SLOT(Show()));

}

void VNC_widget::CloseWidget()
{
	hide();
	disConnect();
}

void VNC_widget::Show()
{
	bool ret = Connect(CurrentCntIndex);
	if (ret)
	{
		if(this->isHidden())
			this->show();
	}
}

#else

VNC_widget::VNC_widget(QWidget *parent)
	:QWidget(parent)
{

}

VNC_widget::~VNC_widget()
{

}

bool VNC_widget::Connect(int index)
{
	return true;
}
bool VNC_widget::disConnect()
{
	return true;
}
void VNC_widget::ShowWidget(int index)
{

}
void VNC_widget::CloseWidget()
{

}

void VNC_widget::Show()
{

}
#endif // !1


