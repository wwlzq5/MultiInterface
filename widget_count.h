#ifndef WIDGET_COUNT_H
#define WIDGET_COUNT_H


#include <QWidget>
#include "ui_widget_count.h"

#include <QPushButton>
#include <QStandardItemModel>

#include "pieview.h"
#include "qcustomplot.h"

#define  MAX_CAMERA_COUNT 30

//错误信息类-单一缺陷
class cErrorTypeCountInfo;
//错误信息类-每个小时错误
class cErrorCountbyTime;
//自定义QCustomPlot直方图bar
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
		只刷新总数、踢废数、踢废率， modelRate可以设-1
		只刷新读模率， total 或 failNum 设为 -1
	***********************************************************/
	void slots_updateCountInfo(int total,int failNum,float modelRate);
	/**********************************************************
		更新显示每个相机检测的缺陷数
	***********************************************************/
	void slots_UpdateTable1(QList<cErrorTypeCountInfo> pCountdates);
	/**********************************************************
		显示每半个小数或一个小时数据
		删除表格已有数据行，重新添加所有数据
		若List为空，只清除表格数据
	***********************************************************/
	void slots_UpdateTable2(QList<cErrorCountbyTime> pCountdates);
	/**********************************************************
		显示每半个小数或一个小时数据
		重载，只添加一个数据，插入到行尾，不删除已有表格数据
	***********************************************************/
	void slots_UpdateTable2(cErrorCountbyTime pCountdate);
	/**********************************************************
		绘制每小时缺陷占比饼图
	***********************************************************/
	void slots_ShowPieImage1(QList<cErrorTypeCountInfo> pCountdates);
	/**********************************************************
		绘制每个班次缺陷占比饼图
	***********************************************************/
	void slots_ShowPieImage2(QList<cErrorTypeCountInfo> pCountdates);
	/**********************************************************
		绘制每小时检测总数与踢废总数
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

//自定义QCustomPlot直方图bar
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

//错误信息类-单一缺陷
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
	//各相机求和
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

	//缺陷类型
	int iErrorType;
	//缺陷名称（中 或 英）
	QString iErrorTxt;
	//各相机检测缺陷数
	int iCamErrorNum[MAX_CAMERA_COUNT];
	//某种缺陷踢废总数
	int iErrorFailCount;
	//踢废总数
	int iFailCount;
	//检测总数
	int iCheckCount;
};

//错误信息类-每个小时错误
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

	//同一时间下单个相机不同缺陷相加总数
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
	//转换时间字符串格式 例：2021-07-27 16:00
	QString GetTimeStr()
	{
		QDateTime pTime = QDateTime::fromString(QString::number(iTime),"yyyyMMddhhmm");
		return pTime.toString("yyyy-MM-dd hh:mm");
	}
	//获取缺陷率
	QString GetFailRate()
	{
		double pRate=0.0;
		if (iAllcount != 0)
			pRate =(double)iErrorCount / iAllcount;
		return QString::number(pRate,'f',2)+"%";
	}

	//时间
	long long iTime;
	//检测总数
	int iAllcount;
	//缺陷总数
	int iErrorCount;
	//单个相机不同缺陷累加数
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

	//获取同一时间 有多少种不同的缺陷
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

	//时间
	long long iTime;
	//检测总数
	int iAllcount;	
	//缺陷总数
	int iErrorCount;
	//缺陷类型
	QList<int> iErrorTypes;
	//缺陷名称
	QList<QString> iErrorNames;
	//单个相机不同缺陷累加数
	QList<int> iCamErrorNum[MAX_CAMERA_COUNT];
};
*/
#endif // WIDGET_COUNT_H
