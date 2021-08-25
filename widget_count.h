#ifndef WIDGET_COUNT_H
#define WIDGET_COUNT_H

#include <QWidget>
#include "ui_widget_count.h"

#include <QPushButton>
#include <QStandardItemModel>

#include "pieview.h"
#include "qcustomplot.h"

#define  MAX_CAMERA_COUNT 30

//������Ϣ��-��һȱ��
class cErrorTypeCountInfo;
//������Ϣ��-ÿ��Сʱ����
class cErrorCountbyTime;
//�Զ���QCustomPlotֱ��ͼbar
class CustomBars;

class widget_count : public QWidget
{
	Q_OBJECT

public:
	widget_count(int CameraNum = 0,QWidget *parent = 0);
	~widget_count();

	enum table2UpdateType
	{
		APPEND =0,
		UPDATE
	};
private:
	void init();

private slots:
	void slots_turnPage();

public slots:
	/**********************************************************
		ֻˢ���������߷������߷��ʣ� modelRate������-1
		ֻˢ�¶�ģ�ʣ� total �� failNum ��Ϊ -1
	***********************************************************/
	void slots_updateCountInfo(int total,int failNum,float modelRate);
	/**********************************************************
		������ʾÿ���������ȱ����
	***********************************************************/
	void slots_UpdateTable1(QList<cErrorTypeCountInfo> pCountdates);
	/**********************************************************
		��ʾÿ���С����һ��Сʱ����
		ɾ��������������У����������������
		��ListΪ�գ�ֻ����������
	***********************************************************/
	void slots_UpdateTable2(QList<cErrorCountbyTime> pCountdates);
	/**********************************************************
		��ʾÿ���С����һ��Сʱ����
		���أ�ֻ���һ�����ݣ����뵽��β����ɾ�����б������
	***********************************************************/
	void slots_UpdateTable2(cErrorCountbyTime pCountdate);
	/**********************************************************
		����ÿСʱȱ��ռ�ȱ�ͼ
	***********************************************************/
	void slots_ShowPieImage1(QList<cErrorTypeCountInfo> pCountdates);
	/**********************************************************
		����ÿ�����ȱ��ռ�ȱ�ͼ
	***********************************************************/
	void slots_ShowPieImage2(QList<cErrorTypeCountInfo> pCountdates);
	/**********************************************************
		����ÿСʱ����������߷�����
	***********************************************************/
	void slots_ShowShiftIamge();


private:
	Ui::widget_count ui;
	QPushButton *buttonTurn;
	QStandardItemModel *table1Model;
	QStandardItemModel *table2Model;
	int nCamNum;
	PieView *pieImage1;
	QStandardItemModel *PieModel_1;

	PieView *pieImage2;
	QStandardItemModel *PieModel_2;

	QList<QColor> PieItemcolors;
	
};

//�Զ���QCustomPlotֱ��ͼbar
class CustomBars :public QCPBars
{
public:
	explicit CustomBars(QCPAxis *keyAxis , QCPAxis *valueAxis);

	enum CustomBarsFlags{
		CustomBars_NULL = 0,
		CustomBars_Rate
	};

	Qt::Alignment textAlignment() const { return mTextAlignment;}
	double spacing() const {return mSpacing;}
	QFont font() const {return mFont;}

	void setTextAlignment(Qt::Alignment alignment);
	void setSpacing(double spacing);
	void setFont(const QFont &font);

	void setTextSuffix(QString Suffix);

protected:
	Qt::Alignment mTextAlignment;
	double mSpacing;
	QFont mFont;
	CustomBarsFlags m_Flags;
	QString m_TextSuffix;

	virtual void draw(QCPPainter *painter) Q_DECL_OVERRIDE;
};

//������Ϣ��-��һȱ��
class cErrorTypeCountInfo
{
public:
	cErrorTypeCountInfo()
	{
		iErrorType =0;
		iErrorTxt = "";
		iErrorFailCount = 0;
		iFailCount = 0;
		iCheckCount = 0;
		for (int i=0;i<MAX_CAMERA_COUNT;i++)
		{
			iCamErrorNum[i]=0;
		}
	}
	//��������
	int sum()
	{
		int total=0;
		for (int i=0;i<MAX_CAMERA_COUNT;i++)
		{
			total += iCamErrorNum[i];
		}
		return total;
	}

	void operator= (const cErrorTypeCountInfo pErrorInfo)
	{
		iErrorType = pErrorInfo.iErrorType;
		iErrorTxt = pErrorInfo.iErrorTxt;
		iErrorFailCount = pErrorInfo.iErrorFailCount;
		iFailCount = pErrorInfo.iFailCount;
		iCheckCount = pErrorInfo.iCheckCount;
		for (int i=0;i<MAX_CAMERA_COUNT;i++)
		{
			iCamErrorNum[i] += pErrorInfo.iCamErrorNum[i];
		}
	}

	void clear()
	{
		iErrorType =0;
		iErrorTxt = "";
		iErrorFailCount =0;
		iFailCount = 0;
		iCheckCount = 0;
		for (int i=0;i<MAX_CAMERA_COUNT;i++)
		{
			iCamErrorNum[i]=0;
		}
	}

	//ȱ������
	int iErrorType;
	//ȱ�����ƣ��� �� Ӣ��
	QString iErrorTxt;
	//��������ȱ����
	int iCamErrorNum[MAX_CAMERA_COUNT];
	//ĳ��ȱ���߷�����
	int iErrorFailCount;
	//�߷�����
	int iFailCount;
	//�������
	int iCheckCount;
};

//������Ϣ��-ÿ��Сʱ����
class cErrorCountbyTime
{
public:
	cErrorCountbyTime()
	{
		iTime = 0;
		iAllcount = 0;
		iErrorCount = 0;
		for (int i=0;i<MAX_CAMERA_COUNT;i++)
		{
			iCamErrorNum[i] = 0;
		}
	}

	//ͬһʱ���µ��������ͬȱ���������
	void operator+= (const cErrorCountbyTime pCountInfo)
	{
		for (int i=0;i<MAX_CAMERA_COUNT;i++)
		{
			iCamErrorNum[i] += pCountInfo.iCamErrorNum[i];
		}
	}

	void operator= (const cErrorCountbyTime pCountInfo)
	{
		iTime = pCountInfo.iTime;
		iAllcount = pCountInfo.iAllcount;
		iErrorCount = pCountInfo.iErrorCount;
		for (int i=0;i<MAX_CAMERA_COUNT;i++)
		{
			iCamErrorNum[i] = pCountInfo.iCamErrorNum[i];
		}
	}

	void clear()
	{
		iTime = 0;
		iAllcount = 0;
		iErrorCount = 0;
		for (int i=0;i<MAX_CAMERA_COUNT;i++)
		{
			iCamErrorNum[i] = 0;
		}
	}
	//ת��ʱ���ַ�����ʽ ����2021-07-27 16:00
	QString GetTimeStr()
	{
		QDateTime pTime = QDateTime::fromString(QString::number(iTime),"yyyyMMddhhmm");
		return pTime.toString("yyyy-MM-dd hh:mm");
	}
	//��ȡȱ����
	QString GetFailRate()
	{
		double pRate=0.0;
		if (iAllcount != 0)
			pRate =(double)iErrorCount / iAllcount;
		return QString::number(pRate,'f',2)+"%";
	}

	//ʱ��
	long long iTime;
	//�������
	int iAllcount;
	//ȱ������
	int iErrorCount;
	//���������ͬȱ���ۼ���
	int iCamErrorNum[MAX_CAMERA_COUNT];
};
/*
class cErrorInfo
{
public:
	cErrorInfo()
	{
		iTime =0;
		iAllcount=0;
		iErrorCount = 0;

	}

	//��ȡͬһʱ�� �ж����ֲ�ͬ��ȱ��
	int GetErrorTypeCount()
	{
		if (iErrorNames.count() != 0)
			return iErrorNames.count();
		else
			return iErrorTypes.count();
	}

	void clear()
	{
		iTime =0;
		iAllcount=0;
		iErrorCount = 0;
		iErrorTypes.clear();
		iErrorNames.clear();
		for (int i=0;i<MAX_CAMERA_COUNT;i++)
		{
			iCamErrorNum[i].clear();
		}
	}

	//ʱ��
	long long iTime;
	//�������
	int iAllcount;	
	//ȱ������
	int iErrorCount;
	//ȱ������
	QList<int> iErrorTypes;
	//ȱ������
	QList<QString> iErrorNames;
	//���������ͬȱ���ۼ���
	QList<int> iCamErrorNum[MAX_CAMERA_COUNT];
};
*/
#endif // WIDGET_COUNT_H
