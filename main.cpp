#include "multiinterface.h"
#include <QApplication>
#include <QTranslator>
#include <DbgHelp.h>
#pragma comment(lib,"Dbghelp.lib")
static long  __stdcall CrashInfocallback(_EXCEPTION_POINTERS *pexcp);
void KillSameDeathProcess(QString exestr)
{
	HANDLE handle;
	HANDLE handle1;
	handle=CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);
	PROCESSENTRY32 *info; 

	info=new PROCESSENTRY32;  
	info->dwSize=sizeof(PROCESSENTRY32); 

	Process32First(handle,info); 

	do
	{
		QString str = QString::fromWCharArray(info->szExeFile);
		if(exestr==str) 		
		{ 
			handle1=OpenProcess(PROCESS_TERMINATE,FALSE,info->th32ProcessID);
			TerminateProcess(handle1,0); 			
		}
	}while (Process32Next(handle,info)!=FALSE); 
	CloseHandle(handle); 
}
//仅运行一次
bool OnlyRunOnce(QString qstr,QString qstrext)
{
	HANDLE hMapping = ::CreateFileMapping((HANDLE)INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, 16, qstr.utf16());
	if (hMapping == NULL)
	{
		return false;
	}
	else
	{
		if(GetLastError()==ERROR_ALREADY_EXISTS)
		{
			HWND hRecv = NULL;
			hRecv = ::FindWindow(NULL,qstr.utf16());
			if (hRecv != NULL)
			{
				::BringWindowToTop(hRecv);
				return false;
			}
			else
			{
				KillSameDeathProcess(qstrext);
			}
		}
	}
	return true;
}
int main(int argc, char *argv[])
{
	QString exepath = argv[0];
	QString exenameext = exepath.right(exepath.length()-exepath.findRev("\\")-1);
	QString apppath = exepath.left(exepath.findRev("\\")+1);
	QString exename = exenameext.left(exenameext.findRev("."));
	//只运行一个实例
	if (!OnlyRunOnce(exename,exenameext))
	{
		return 0;
	}

	QApplication a(argc, argv);

	QApplication::addLibraryPath(".\\QtPlugins");

	QTextCodec *codec = QTextCodec::codecForName("GBK"); 
	QTextCodec::setCodecForLocale(codec); 
	QTextCodec::setCodecForTr(codec);
	QTextCodec::setCodecForCStrings(codec);

	QTranslator *translator=new QTranslator(0);
	translator->load("./multiinterface_zh.qm");
	a.installTranslator(translator);
	
	MultiInterface w;
	w.CheckLicense();
	w.showMaximized();
	w.hide();
	return a.exec();
}
long  __stdcall CrashInfocallback( _EXCEPTION_POINTERS *pexcp)
{
	HANDLE hDumpFile = ::CreateFile(
		L"MEMORY1.DMP",
		GENERIC_WRITE,
		0,
		NULL,
		CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		NULL
		);
	if( hDumpFile != INVALID_HANDLE_VALUE)
	{
		MINIDUMP_EXCEPTION_INFORMATION dumpInfo;
		dumpInfo.ExceptionPointers = pexcp;
		dumpInfo.ThreadId = ::GetCurrentThreadId();
		dumpInfo.ClientPointers = TRUE;
		::MiniDumpWriteDump(
			::GetCurrentProcess(),
			::GetCurrentProcessId(),
			hDumpFile,
			MiniDumpNormal,
			&dumpInfo,
			NULL,
			NULL
			);
	}
	return 0;
}
