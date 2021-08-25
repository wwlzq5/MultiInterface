#ifndef CLOGFILE_H
#define CLOGFILE_H

#include <QString>
#include <QApplication>
#include <QMutex>
#include <QThread>
#include <QDir>
#include <windows.h>
//#include "common.h"

enum e_SaveLogType
{
	OperationLog,
	CheckLog,
	MendParamLog,
	AbnormityLog,
	StatInfo,
	AlgorithmDLL
};
struct s_LogInfo
{
	QString strInfo;
	e_SaveLogType logtype;
};
class WriteLogThread : public QThread
{
	Q_OBJECT

public:
	WriteLogThread(QObject *parent);
	WriteLogThread();
	~WriteLogThread();

	QList<s_LogInfo> listLog;
	QString strLastFilePath;
 	QMutex mutexLog;
private:
	bool m_bStopThread;
	QString m_strlogfilepath;
	QString m_strLogInfo;
public:
	void run();
	void StartThread();
	void StopThread();
	void WaitThreadStop();
	void Initpath(e_SaveLogType logtype);
	void write(QString strInfo,e_SaveLogType logtype, int showInterface = 1);
};

class CLogFile
{
public:
	CLogFile();
	~CLogFile();
	void write(QString strInfo,e_SaveLogType logtype, int showInterface = 1);
private:
	QMutex mutexWriteLogFile;
	QString strLastFilePath;
	WriteLogThread *pThreadWriteLog;
};

#endif // CLOGFILE_H
