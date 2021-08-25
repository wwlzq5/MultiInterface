#include "widget_count.h"
#if 0
#include "glasswaredetectsystem.h"
extern GlasswareDetectSystem *pMainFrm;
#endif

widget_count::widget_count(int CameraNum,QWidget *parent)
	:QWidget(parent)
{
	ui.setupUi(this);
	nCamNum = CameraNum;
	init();
}

widget_count::~widget_count()
{

}

void widget_count::init()
{
	//注册Qt元对象
	qRegisterMetaType<QList<cErrorTypeCountInfo>>("QList<cErrorTypeCountInfo>"); 
	qRegisterMetaType<QList<cErrorCountbyTime>>("QList<cErrorCountbyTime>");
	qRegisterMetaType<cErrorCountbyTime>("cErrorCountbyTime");

	ui.stackedWidget->setCurrentIndex(0);
	//小标题设置
	ui.widget->setWidgetName(tr("Count Table"));
	ui.widget_countInfo->setWidgetName(tr("Count Info"));
	ui.widget_saveRecord->setWidgetName(tr("Save Set"));
	ui.widget_ShiftSet->setWidgetName(tr("Shift Set"));
	ui.widget_HistotySearch->setWidgetName(tr("History Search"));
	ui.widget_TimePie->setWidgetName(tr("Defect Count - Every hour or half an hour"));
	ui.widget_HistoryShift->setWidgetName(tr("History Search Shift Set"));
	ui.widget_shiftSearch->setWidgetName(tr("Shift Selete"));
	ui.widget_table->setWidgetName(tr("Search Table Type"));
	ui.widget_ShiftPie->setWidgetName(tr("Detect Count - Shift"));
	//添加切换页按钮
	buttonTurn = new QPushButton; 
	QPixmap iconTurn(":/MultiInterface/turnImage");
	buttonTurn->setIcon(iconTurn);
	buttonTurn->setFixedSize(iconTurn.size());
	QHBoxLayout *nameLayout = new QHBoxLayout(ui.widget);
	nameLayout->addWidget(ui.widget->widgetName);
	nameLayout->addStretch();
	nameLayout->addWidget(buttonTurn);
	nameLayout->setSpacing(5);
	nameLayout->setContentsMargins(5,0,5,0);

	//初始化实时显示的缺陷统计表
	ui.tableView_1->setEditTriggers(QAbstractItemView::NoEditTriggers);		//禁止编辑
	ui.tableView_1->setSelectionBehavior(QAbstractItemView::SelectRows);	//整行选中
	ui.tableView_1->setSelectionMode(QAbstractItemView::SingleSelection);	//单个选中目标
	ui.tableView_1->verticalHeader()->setVisible(false);					//隐藏行头
	table1Model=new QStandardItemModel;
	QStringList headerList;
	headerList<<QObject::tr("Type");
	headerList<<QObject::tr("Count");
	for (int i=0;i<nCamNum;i++)
	{
		headerList <<QObject::tr("Camera%1").arg(i+1);
	}
	table1Model->setHorizontalHeaderLabels(headerList);
	ui.tableView_1->setModel(table1Model);
	ui.tableView_1->setColumnWidth(0,120);									//设置第一列列宽

	ui.tableView_2->setEditTriggers(QAbstractItemView::NoEditTriggers);		//禁止编辑
	ui.tableView_2->setSelectionBehavior(QAbstractItemView::SelectRows);	//整行选中
	ui.tableView_2->setSelectionMode(QAbstractItemView::SingleSelection);	//单个选中目标
	ui.tableView_2->verticalHeader()->setVisible(false);					//隐藏行头
	table2Model=new QStandardItemModel;
	headerList.clear();
	headerList<<tr("DateTime");
	headerList<<tr("AllCheck");
	headerList<<tr("AllReject");
	headerList<<tr("Reject Rate");
	for (int i = 1;i <= nCamNum;i++)
	{
		headerList <<QObject::tr("Camera%1").arg(i);
	}
	table2Model->setHorizontalHeaderLabels(headerList);
	ui.tableView_2->setModel(table2Model);
	ui.tableView_2->setColumnWidth(0,120);									//设置第一列列宽

	//绘制饼图
	PieItemcolors<<QColor(153,230,0)
				 <<QColor(174,77,102)
				 <<QColor(128,255,128)
				 <<QColor(128,255,255)
				 <<QColor(0,128,255)
				 <<QColor(255,255,128)
				 <<QColor(0,248,128)
				 <<QColor(255,0,213)
				 <<QColor(35,0,255)
				 <<QColor(255,129,0);
	pieImage1=new PieView();
	PieModel_1 = new QStandardItemModel(10, 2, this);
	PieModel_1->setHeaderData(0, Qt::Horizontal, tr("Error1"));
	PieModel_1->setHeaderData(1, Qt::Horizontal, tr("Error2"));
	PieModel_1->setHeaderData(2, Qt::Horizontal, tr("Error3"));
	PieModel_1->setHeaderData(3, Qt::Horizontal, tr("Error4"));
	PieModel_1->setHeaderData(4, Qt::Horizontal, tr("Error5"));
	PieModel_1->setHeaderData(5, Qt::Horizontal, tr("Error6"));
	PieModel_1->setHeaderData(6, Qt::Horizontal, tr("Error7"));
	PieModel_1->setHeaderData(7, Qt::Horizontal, tr("Error8"));
	PieModel_1->setHeaderData(8, Qt::Horizontal, tr("Error9"));
	PieModel_1->setHeaderData(9, Qt::Horizontal, tr("Error10"));
	pieImage1->setModel(PieModel_1);
	QVBoxLayout *m_pielayout = new QVBoxLayout(ui.widget_pie1);
	m_pielayout->addWidget(pieImage1);
	m_pielayout->setMargin(4);

	pieImage2=new PieView();
	PieModel_2 = new QStandardItemModel(10, 2, this);
	PieModel_2->setHeaderData(0, Qt::Horizontal, tr("Error1"));
	PieModel_2->setHeaderData(1, Qt::Horizontal, tr("Error2"));
	PieModel_2->setHeaderData(2, Qt::Horizontal, tr("Error3"));
	PieModel_2->setHeaderData(3, Qt::Horizontal, tr("Error4"));
	PieModel_2->setHeaderData(4, Qt::Horizontal, tr("Error5"));
	PieModel_2->setHeaderData(5, Qt::Horizontal, tr("Error6"));
	PieModel_2->setHeaderData(6, Qt::Horizontal, tr("Error7"));
	PieModel_2->setHeaderData(7, Qt::Horizontal, tr("Error8"));
	PieModel_2->setHeaderData(8, Qt::Horizontal, tr("Error9"));
	PieModel_2->setHeaderData(9, Qt::Horizontal, tr("Error10"));
	pieImage2->setModel(PieModel_2);
	QVBoxLayout *m_pielayout_2 = new QVBoxLayout(ui.widget_pie2);
	m_pielayout_2->addWidget(pieImage2);
	m_pielayout_2->setMargin(4);

	//初始化直方图
	QLinearGradient gradient(0, 0, 0, 400);
	gradient.setColorAt(0, QColor(90, 90, 90));
	gradient.setColorAt(0.38, QColor(105, 105, 105));
	gradient.setColorAt(1, QColor(70, 70, 70));
	ui.CustomPlot->setBackground(QBrush(gradient));

	//设置countInfo默认值
	slots_updateCountInfo(0,0,1);

	connect(buttonTurn,SIGNAL(clicked()),this,SLOT(slots_turnPage()));


	QList<cErrorTypeCountInfo > pInfos;
	for (int i=0;i<10;i++)
	{
		cErrorTypeCountInfo info;
		info.iErrorTxt = QString::number(i);
		info.iCamErrorNum[0]=i;
		info.iCamErrorNum[1]=i;
		info.iCheckCount=100;
		info.iErrorFailCount=i+1;
		info.iFailCount=55;
		pInfos<<info;
	}
	slots_UpdateTable1(pInfos);
	slots_ShowPieImage1(pInfos);

	QList<cErrorCountbyTime> pCountdates;
	for (int i=0;i<10;i++)
	{
		cErrorCountbyTime info;
		info.iTime = 202107271600;
		pCountdates<<info;
	}
	slots_UpdateTable2(pCountdates);
	slots_ShowShiftIamge();
}

void widget_count::slots_turnPage()
{
	if (0 == ui.stackedWidget->currentIndex())
		ui.stackedWidget->setCurrentIndex(1);
	else
		ui.stackedWidget->setCurrentIndex(0);
}

void widget_count::slots_updateCountInfo(int total,int failNum,float modelRate)
{
	if (total >= 0 && failNum >= 0)
	{
		ui.label_total->setText(tr("Product Number")+"\n"+QString::number(total));
		ui.label_failur->setText(tr("Reject Number")+"\n"+QString::number(failNum));
		double failRate=0.0;
		if (0 != total)
		{
			failRate = (double)failNum *100 / total;
		}
		ui.label_failurRate->setText(tr("Reject Rate")+"\n"+QString::number(failRate,'f',2)+"%");
	}
	if (modelRate >= 0)
	{
		ui.label_modelRate->setText(tr("Model Rate") + "\n" + QString::number(modelRate *100 ,'f',2)+"%");
	}	
}

void widget_count::slots_UpdateTable1(QList<cErrorTypeCountInfo> pCountdates)
{
	while(table1Model->rowCount()>0 )
	{
		QList<QStandardItem*> listItem = table1Model->takeRow(0);
		qDeleteAll(listItem);
		listItem.clear();
	}
	QList<QStandardItem*> items;
	for (int i=0;i<pCountdates.count();i++)
	{
		cErrorTypeCountInfo pInfo = pCountdates.at(i);
		items.clear();
		QStandardItem *item1 = new 
#if 1
			QStandardItem(pInfo.iErrorTxt);
#else
			QStandardItem(pMainFrm->m_sErrorInfo.m_vstrErrorType.at(pInfo.iErrorType));
#endif
		items<<item1;
		QStandardItem *item2 = new QStandardItem(QString::number(pInfo.sum()));
		items<<item2;
		for (int j=0;j<nCamNum;j++)
		{
			QStandardItem *item3 = new QStandardItem(QString::number(pInfo.iCamErrorNum[j]));
			items<<item3;
		}
		table1Model->insertRow(table1Model->rowCount(),items);
	}
}

void widget_count::slots_UpdateTable2(QList<cErrorCountbyTime> pCountdates)
{
	while(table2Model->rowCount()>0 )
	{
		QList<QStandardItem*> listItem = table2Model->takeRow(0);
		qDeleteAll(listItem);
		listItem.clear();
	}

	QList<QStandardItem*> items;
	for (int i=0;i<pCountdates.count();i++)
	{
		cErrorCountbyTime pInfo = pCountdates.at(i);
		items.clear();
		QStandardItem *item1 = new QStandardItem(pInfo.GetTimeStr());
		items<<item1;
		QStandardItem *item2 = new QStandardItem(QString::number(pInfo.iAllcount));
		items<<item2;
		QStandardItem *item3 = new QStandardItem(QString::number(pInfo.iErrorCount));
		items<<item3;
		QStandardItem *item4 = new QStandardItem(pInfo.GetFailRate());
		items<<item4;
		for (int j=0;j<nCamNum;j++)
		{
			QStandardItem *item5 = new QStandardItem(QString::number(pInfo.iCamErrorNum[j]));
			items<<item5;
		}
		table2Model->insertRow(table2Model->rowCount(),items);
	}
}

void widget_count::slots_UpdateTable2(cErrorCountbyTime pCountdate)
{
	//cErrorCountbyTime pInfo = pCountdate;
	QList<QStandardItem*> items;
	QStandardItem *item1 = new QStandardItem(pCountdate.GetTimeStr());
	items<<item1;
	QStandardItem *item2 = new QStandardItem(QString::number(pCountdate.iAllcount));
	items<<item2;
	QStandardItem *item3 = new QStandardItem(QString::number(pCountdate.iErrorCount));
	items<<item3;
	QStandardItem *item4 = new QStandardItem(pCountdate.GetFailRate());
	items<<item4;
	for (int j=0;j<nCamNum;j++)
	{
		QStandardItem *item5 = new QStandardItem(QString::number(pCountdate.iCamErrorNum[j]));
		items<<item5;
	}
	table2Model->insertRow(table2Model->rowCount(),items);
}

void widget_count::slots_ShowPieImage1(QList<cErrorTypeCountInfo> pCountdates)
{
	if (pCountdates.isEmpty())
	{
		return;
	}
	QFont itemFont("微软雅黑",10);
	itemFont.setBold(true);

	PieModel_1->removeRows(0,PieModel_1->rowCount(QModelIndex()),QModelIndex());
	int tempCount=pCountdates.count();
	int ErrorAllfail=0;
	for(int i = 0;i < tempCount;i++)
	{
		ErrorAllfail += pCountdates.at(i).iErrorFailCount;
	}
	int m_failCount = pCountdates.at(0).iFailCount;
	m_failCount = ErrorAllfail < m_failCount ? ErrorAllfail : m_failCount;
	int m_AllCount = pCountdates.at(0).iCheckCount;
	if (tempCount <=10)
	{
		int t_fail = 0;
		for(int i = 0;i < tempCount;i++)
		{
			int t_data = 0 ;
			if (i != (tempCount-1))
			{
				t_data = pCountdates.at(i).iErrorFailCount;
				t_fail += t_data;
			}
			else
			{
				t_data = m_failCount - t_fail ;
			}
			PieModel_1->insertRows(i, 1, QModelIndex());
			PieModel_1->setData(PieModel_1->index(i, 0, QModelIndex()), pCountdates[i].iErrorTxt+":" + QString::number(t_data)+"("+QString::number((double)t_data/m_AllCount*100,'f',2)+"%)");
			PieModel_1->setData(PieModel_1->index(i, 1, QModelIndex()), QString::number(t_data));
			PieModel_1->setData(PieModel_1->index(i, 0, QModelIndex()), PieItemcolors[i], Qt::DecorationRole);
			PieModel_1->item(i,0)->setFont(itemFont);
		}
	}
	else
	{
		int t_fail = 0;
		for(int i = 0;i < 9;i++)
		{
			int t_data = pCountdates.at(i).iErrorFailCount;
			if (ErrorAllfail != 0)
			{
				t_data = m_failCount * t_data  / ErrorAllfail ;
			}
			t_fail += t_data;

			PieModel_1->insertRows(i, 1, QModelIndex());
			PieModel_1->setData(PieModel_1->index(i, 0, QModelIndex()), pCountdates[i].iErrorTxt+":" + QString::number(t_data)+"("+QString::number((double)t_data/m_AllCount*100,'f',2)+"%)");
			PieModel_1->setData(PieModel_1->index(i, 1, QModelIndex()), QString::number(t_data));
			PieModel_1->setData(PieModel_1->index(i, 0, QModelIndex()), PieItemcolors[i], Qt::DecorationRole);
			PieModel_1->item(i,0)->setFont(itemFont);
		}
		t_fail = m_failCount - t_fail ;
		PieModel_1->insertRows(9, 1, QModelIndex());
		PieModel_1->setData(PieModel_1->index(9, 0, QModelIndex()), tr("Other:") + QString::number(t_fail)+"("+QString::number((double)t_fail/m_AllCount*100,'f',2)+"%)");
		PieModel_1->setData(PieModel_1->index(9, 1, QModelIndex()), QString::number(t_fail));
		PieModel_1->setData(PieModel_1->index(9, 0, QModelIndex()), PieItemcolors[9], Qt::DecorationRole);
		PieModel_1->item(9,0)->setFont(itemFont);
	}

}

void widget_count::slots_ShowPieImage2(QList<cErrorTypeCountInfo> pCountdates)
{
	if (pCountdates.isEmpty())
	{
		return;
	}
	QFont itemFont("微软雅黑",10);
	itemFont.setBold(true);

	PieModel_2->removeRows(0,PieModel_2->rowCount(QModelIndex()),QModelIndex());
	int tempCount=pCountdates.count();
	int ErrorAllfail=0;
	for(int i = 0;i < tempCount;i++)
	{
		ErrorAllfail += pCountdates.at(i).iErrorFailCount;
	}
	int m_failCount = pCountdates.at(0).iFailCount;
	m_failCount = ErrorAllfail < m_failCount ? ErrorAllfail : m_failCount;
	int m_AllCount = pCountdates.at(0).iCheckCount;
	if (tempCount <=10)
	{
		int t_fail = 0;
		for(int i = 0;i < tempCount;i++)
		{
			int t_data = 0 ;
			if (i != (tempCount-1))
			{
				t_data = pCountdates.at(i).iErrorFailCount;
				t_fail += t_data;
			}
			else
			{
				t_data = m_failCount - t_fail ;
			}
			PieModel_2->insertRows(i, 1, QModelIndex());
			PieModel_2->setData(PieModel_2->index(i, 0, QModelIndex()), pCountdates[i].iErrorTxt+":" + QString::number(t_data)+"("+QString::number((double)t_data/m_AllCount*100,'f',2)+"%)");
			PieModel_2->setData(PieModel_2->index(i, 1, QModelIndex()), QString::number(t_data));
			PieModel_2->setData(PieModel_2->index(i, 0, QModelIndex()), PieItemcolors[i], Qt::DecorationRole);
			PieModel_2->item(i,0)->setFont(itemFont);
		}
	}
	else
	{
		int t_fail = 0;
		for(int i = 0;i < 9;i++)
		{
			int t_data = pCountdates.at(i).iErrorFailCount;
			if (ErrorAllfail != 0)
			{
				t_data = m_failCount * t_data  / ErrorAllfail ;
			}
			t_fail += t_data;

			PieModel_2->insertRows(i, 1, QModelIndex());
			PieModel_2->setData(PieModel_2->index(i, 0, QModelIndex()), pCountdates[i].iErrorTxt+":" + QString::number(t_data)+"("+QString::number((double)t_data/m_AllCount*100,'f',2)+"%)");
			PieModel_2->setData(PieModel_2->index(i, 1, QModelIndex()), QString::number(t_data));
			PieModel_2->setData(PieModel_2->index(i, 0, QModelIndex()), PieItemcolors[i], Qt::DecorationRole);
			PieModel_2->item(i,0)->setFont(itemFont);
		}
		t_fail = m_failCount - t_fail ;
		PieModel_2->insertRows(9, 1, QModelIndex());
		PieModel_2->setData(PieModel_2->index(9, 0, QModelIndex()), tr("Other:") + QString::number(t_fail)+"("+QString::number((double)t_fail/m_AllCount*100,'f',2)+"%)");
		PieModel_2->setData(PieModel_2->index(9, 1, QModelIndex()), QString::number(t_fail));
		PieModel_2->setData(PieModel_2->index(9, 0, QModelIndex()), PieItemcolors[9], Qt::DecorationRole);
		PieModel_2->item(9,0)->setFont(itemFont);
	}

}

void widget_count::slots_ShowShiftIamge()
{
	int plottableCount = ui.CustomPlot->plottableCount();
	if (plottableCount != 0)
		ui.CustomPlot->clearPlottables();
	// create empty bar chart objects:
	CustomBars *nBar1 = new CustomBars(ui.CustomPlot->xAxis, ui.CustomPlot->yAxis);
	CustomBars *nBar2 = new CustomBars(ui.CustomPlot->xAxis, ui.CustomPlot->yAxis);
	CustomBars *nBar3 = new CustomBars(ui.CustomPlot->xAxis, ui.CustomPlot->yAxis);
	nBar1->setAntialiased(false);
	nBar2->setAntialiased(false);
	nBar3->setAntialiased(false);
	QList<QColor> colors;
	colors<<QColor(0, 0, 255) << QColor(250, 0, 0)<<QColor(0, 168, 140);
	
	nBar1->setName(tr("Single Shift All Detect Number"));
	nBar1->setPen(QPen(colors[0]));
	colors[0].setAlpha(180);
	nBar1->setBrush(colors[0]);

	nBar2->setName(tr("Single Shift Failure Number"));
	nBar2->setPen(QPen(colors[1]));
	colors[1].setAlpha(180);
	nBar2->setBrush(colors[1]);

	nBar3->setName(tr("Single Shift Failure Rate"));
	nBar3->setPen(QPen(colors[2].lighter(130)));
	nBar3->setBrush(colors[2]);
	nBar3->setTextSuffix("%");

	//设置并排显示
	QCPBarsGroup *group = new QCPBarsGroup(ui.CustomPlot);  
	QList<QCPBars*> bars;
	bars <<nBar1 <<nBar2<<nBar3 ;// << regen;
	foreach (QCPBars *bar, bars) {
		// 设置柱状图的宽度类型为以key坐标轴计算宽度的大小，其实默认就是这种方式
		bar->setWidthType(QCPBars::wtPlotCoords);
		bar->setWidth(bar->width() / bars.size()); // 设置柱状图的宽度大小
		group->append(bar);  // 将柱状图加入柱状图分组中
	}
	group->setSpacingType(QCPBarsGroup::stAbsolute);  // 设置组内柱状图的间距，按像素
	group->setSpacing(2);     // 设置较小的间距值，这样看起来更紧凑

	QVector<double> ticks;
	QVector<QString> labels;
	ticks<<1<<2<<3;
	labels<<tr("Shift1")<<tr("Shift2")<<tr("Shift3");

	QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
	textTicker->addTicks(ticks, labels);
	ui.CustomPlot->xAxis->setTicker(textTicker);
	ui.CustomPlot->xAxis->setTickLabelRotation(0);
	ui.CustomPlot->xAxis->setSubTicks(false);
	ui.CustomPlot->xAxis->setTickLength(0, 4);
	ui.CustomPlot->xAxis->setRange(0, 4);
	ui.CustomPlot->xAxis->setBasePen(QPen(Qt::white));
	ui.CustomPlot->xAxis->setTickPen(QPen(Qt::white));
	ui.CustomPlot->xAxis->grid()->setVisible(true);
	ui.CustomPlot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
	ui.CustomPlot->xAxis->setTickLabelColor(Qt::white);
	ui.CustomPlot->xAxis->setLabelColor(Qt::white);
	ui.CustomPlot->xAxis->setLabel(tr("Shift(1,2,3)"));

	ui.CustomPlot->yAxis->setRange(0, 1000);
	ui.CustomPlot->yAxis->setPadding(5); // a bit more space to the left border
	ui.CustomPlot->yAxis->setLabel(tr("Shift Failure Number Table(Ps)"));
	ui.CustomPlot->yAxis->setBasePen(QPen(Qt::white));
	ui.CustomPlot->yAxis->setTickPen(QPen(Qt::white));
	ui.CustomPlot->yAxis->setSubTickPen(QPen(Qt::white));
	ui.CustomPlot->yAxis->grid()->setSubGridVisible(true);
	ui.CustomPlot->yAxis->setTickLabelColor(Qt::white);
	ui.CustomPlot->yAxis->setLabelColor(Qt::white);
	ui.CustomPlot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
	ui.CustomPlot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

	// Add data:
	QVector<double> nBar1Date, nBar2Date,nBar3Date;
	nBar1Date<<800<<700<<900;
	nBar2Date<<80<<70<<90;
	nBar3Date<<10<<10<<10;

	//setdata
	nBar1->setData(ticks, nBar1Date);
	nBar2->setData(ticks, nBar2Date);
	nBar3->setData(ticks, nBar3Date);

	// setup legend:
	ui.CustomPlot->legend->setVisible(true);
	ui.CustomPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
	ui.CustomPlot->legend->setBrush(QColor(255, 255, 255, 100));
	ui.CustomPlot->legend->setBorderPen(Qt::NoPen);
	QFont legendFont = font();
	legendFont.setPointSize(10);
	ui.CustomPlot->legend->setFont(legendFont);
	ui.CustomPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
	ui.CustomPlot->replot();

}


//自定义QCustomPlot直方图bar
CustomBars::CustomBars(QCPAxis *keyAxis , QCPAxis *valueAxis)
	:QCPBars(keyAxis,valueAxis),
	mTextAlignment(Qt::AlignCenter),
	mSpacing(5),
	mFont(QFont(QLatin1String("san serif"),9)),
	m_TextSuffix("")
{

}

void CustomBars::setTextAlignment(Qt::Alignment alignment)
{
	mTextAlignment = alignment;
}

void CustomBars::setSpacing(double spacing)
{
	mSpacing = spacing;
}

void CustomBars::setFont(const QFont &font)
{
	mFont = font;
}

void CustomBars::setTextSuffix(QString Suffix)
{
	m_TextSuffix = Suffix;
}

void CustomBars::draw(QCPPainter *painter) Q_DECL_OVERRIDE
{
	if (!mKeyAxis || !mValueAxis) { qDebug() << Q_FUNC_INFO << "invalid key or value axis"; return; }
	if (mDataContainer->isEmpty()) return;

	QCPBarsDataContainer::const_iterator visibleBegin, visibleEnd;
	getVisibleDataBounds(visibleBegin, visibleEnd);

	// loop over and draw segments of unselected/selected data:
	QList<QCPDataRange> selectedSegments, unselectedSegments, allSegments;
	getDataSegments(selectedSegments, unselectedSegments);
	allSegments << unselectedSegments << selectedSegments;
	for (int i=0; i<allSegments.size(); ++i)
	{
		bool isSelectedSegment = i >= unselectedSegments.size();
		QCPBarsDataContainer::const_iterator begin = visibleBegin;
		QCPBarsDataContainer::const_iterator end = visibleEnd;
		mDataContainer->limitIteratorsToDataRange(begin, end, allSegments.at(i));
		if (begin == end)
			continue;

		for (QCPBarsDataContainer::const_iterator it=begin; it!=end; ++it)
		{
			// check data validity if flag set:
#ifdef QCUSTOMPLOT_CHECK_DATA
			if (QCP::isInvalidData(it->key, it->value))
				qDebug() << Q_FUNC_INFO << "Data point at" << it->key << "of drawn range invalid." << "Plottable name:" << name();
#endif
			// draw bar:
			if (isSelectedSegment && mSelectionDecorator)
			{
				mSelectionDecorator->applyBrush(painter);
				mSelectionDecorator->applyPen(painter);
			} else
			{
				painter->setBrush(mBrush);
				painter->setPen(mPen);
			}
			applyDefaultAntialiasingHint(painter);
			QRectF barRect=getBarRect(it->key, it->value);
			painter->drawPolygon(getBarRect(it->key, it->value));

			//add text
			// 计算文字的位置
			painter->setFont(mFont);                     // 设置字体
			QString text = QString::number(it->value);   // 取得当前value轴的值，保留两位精度
			text += m_TextSuffix;

			QRectF textRect = painter->fontMetrics().boundingRect(0, 0, 0, 0, Qt::TextDontClip | mTextAlignment, text);  // 计算文字所占用的大小

			if (mKeyAxis.data()->orientation() == Qt::Horizontal) 
			{    // 当key轴为水平轴的时候
				if (mKeyAxis.data()->axisType() == QCPAxis::atTop)     // 上轴，移动文字到柱状图下面
					textRect.moveTopLeft(barRect.bottomLeft() + QPointF(0, mSpacing));
				else                                                   // 下轴，移动文字到柱状图上面
					textRect.moveBottomLeft(barRect.topLeft() - QPointF(0, mSpacing));
				textRect.setWidth(barRect.width());
				painter->drawText(textRect, Qt::TextDontClip | mTextAlignment, text);
			}
			else 
			{                                                  // 当key轴为竖直轴的时候
				if (mKeyAxis.data()->axisType() == QCPAxis::atLeft)   // 左轴，移动文字到柱状图右边
					textRect.moveTopLeft(barRect.topRight() + QPointF(mSpacing, 0));
				else                                                  // 右轴，移动文字到柱状图左边
					textRect.moveTopRight(barRect.topLeft() - QPointF(mSpacing, 0));
				textRect.setHeight(barRect.height());
				painter->drawText(textRect, Qt::TextDontClip | mTextAlignment, text);
			}
		}
	}

	// draw other selection decoration that isn't just line/scatter pens and brushes:
	if (mSelectionDecorator)
		mSelectionDecorator->drawDecoration(painter, selection());
}
