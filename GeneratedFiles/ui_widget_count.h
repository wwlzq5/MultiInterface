/********************************************************************************
** Form generated from reading UI file 'widget_count.ui'
**
** Created: Sat Sep 18 14:47:59 2021
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_COUNT_H
#define UI_WIDGET_COUNT_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCalendarWidget>
#include <QtGui/QCheckBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStackedWidget>
#include <QtGui/QTableView>
#include <QtGui/QTimeEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <dhbasewidget.h>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_widget_count
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    DHBaseWidget *widget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_4;
    QWidget *widget_page1;
    QVBoxLayout *verticalLayout_7;
    QTableView *tableView_1;
    QTableView *tableView_2;
    QHBoxLayout *horizontalLayout_9;
    DHBaseWidget *widget_HistotySearch;
    QVBoxLayout *verticalLayout_5;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_2;
    QCalendarWidget *calendarWidget_1;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *Btn_OpenExcel;
    QSpacerItem *horizontalSpacer;
    QPushButton *Btn_HistorySearch;
    QSpacerItem *verticalSpacer_2;
    DHBaseWidget *widget_TimePie;
    QVBoxLayout *verticalLayout_6;
    QWidget *widget_pie1;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_12;
    QCustomPlot *CustomPlot;
    QHBoxLayout *horizontalLayout_10;
    DHBaseWidget *widget_HistoryShift;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_Cancel;
    QLabel *label_4;
    QTimeEdit *timeEdit_2;
    QTimeEdit *timeEdit_3;
    QLabel *label_5;
    QPushButton *pushButton_Save;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_11;
    QRadioButton *radioBtn_Half;
    QRadioButton *radioBtn_anHour;
    QLabel *label_1;
    QTimeEdit *timeEdit_1;
    QCalendarWidget *calendarWidget_2;
    QVBoxLayout *verticalLayout_8;
    DHBaseWidget *widget_shiftSearch;
    QVBoxLayout *verticalLayout_9;
    QRadioButton *radioButton_Shift1;
    QRadioButton *radioButton_Shift2;
    QRadioButton *radioButton_Shift3;
    QRadioButton *radioButton_ShiftAll;
    DHBaseWidget *widget_table;
    QVBoxLayout *verticalLayout_10;
    QRadioButton *radioButton_table1;
    QRadioButton *radioButton_table2;
    QRadioButton *radioButton_table3;
    QPushButton *pushButton_Search;
    DHBaseWidget *widget_ShiftPie;
    QVBoxLayout *verticalLayout_11;
    QWidget *widget_pie2;
    QWidget *widget_countset;
    QVBoxLayout *verticalLayout_3;
    DHBaseWidget *widget_countInfo;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QLabel *label_total;
    QLabel *label_failur;
    QFrame *line;
    QLabel *label_failurRate;
    QFrame *line_3;
    QLabel *label_modelRate;
    QFrame *line_4;
    QFrame *line_2;
    DHBaseWidget *widget_saveRecord;
    QGridLayout *gridLayout_saveRecord;
    QCheckBox *checkBox_saveRecord;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_saveRecordOK;
    QPushButton *pushButton_saveRecordCancel;
    QRadioButton *radioButton_30minite;
    QRadioButton *radioButton_60minite;
    DHBaseWidget *widget_ShiftSet;
    QVBoxLayout *verticalLayout_shitf;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QTimeEdit *timeEdit_shift1;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    QTimeEdit *timeEdit_shift2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_3;
    QTimeEdit *timeEdit_shift3;
    QCheckBox *checkBox_AutoSetZero;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *pushButton_shiftOK;
    QPushButton *pushButton_shiftCancel;

    void setupUi(QWidget *widget_count)
    {
        if (widget_count->objectName().isEmpty())
            widget_count->setObjectName(QString::fromUtf8("widget_count"));
        widget_count->resize(1500, 881);
        horizontalLayout = new QHBoxLayout(widget_count);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, -1, 0, -1);
        widget = new DHBaseWidget(widget_count);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(0, 25));
        widget->setMaximumSize(QSize(16777215, 25));

        verticalLayout->addWidget(widget);

        stackedWidget = new QStackedWidget(widget_count);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        verticalLayout_4 = new QVBoxLayout(page);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 5, 0, 0);
        widget_page1 = new QWidget(page);
        widget_page1->setObjectName(QString::fromUtf8("widget_page1"));
        verticalLayout_7 = new QVBoxLayout(widget_page1);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 5, 0, 0);
        tableView_1 = new QTableView(widget_page1);
        tableView_1->setObjectName(QString::fromUtf8("tableView_1"));

        verticalLayout_7->addWidget(tableView_1);

        tableView_2 = new QTableView(widget_page1);
        tableView_2->setObjectName(QString::fromUtf8("tableView_2"));

        verticalLayout_7->addWidget(tableView_2);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        widget_HistotySearch = new DHBaseWidget(widget_page1);
        widget_HistotySearch->setObjectName(QString::fromUtf8("widget_HistotySearch"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_HistotySearch->sizePolicy().hasHeightForWidth());
        widget_HistotySearch->setSizePolicy(sizePolicy);
        widget_HistotySearch->setMinimumSize(QSize(400, 0));
        widget_HistotySearch->setMaximumSize(QSize(400, 16777215));
        verticalLayout_5 = new QVBoxLayout(widget_HistotySearch);
        verticalLayout_5->setSpacing(10);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 30, 0, 0);
        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_3);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_2);

        calendarWidget_1 = new QCalendarWidget(widget_HistotySearch);
        calendarWidget_1->setObjectName(QString::fromUtf8("calendarWidget_1"));
        calendarWidget_1->setMaximumSize(QSize(330, 300));
        calendarWidget_1->setStyleSheet(QString::fromUtf8("\n"
"QToolButton#qt_calendar_monthbutton,#qt_calendar_yearbutton{\n"
"\n"
"color: #9ea5a9; \n"
"\n"
"font: 13pt simHei; \n"
"}\n"
"\n"
"QCalendarWidget QWidget#qt_calendar_navigationbar\n"
"{\n"
"\n"
"background-color: #2F2F3E;\n"
"}\n"
"QCalendarWidget QToolButton {\n"
"    height: 30px;\n"
"    width: 80px;\n"
"    color: white;\n"
"    font-size: 24px;\n"
"    icon-size: 48px, 48px;\n"
"}\n"
"QCalendarWidget QMenu {\n"
"    width: 100px;\n"
"    left: 20px;\n"
"    color: white;\n"
"    font-size: 18px;\n"
"}\n"
"\n"
""));
        calendarWidget_1->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        horizontalLayout_7->addWidget(calendarWidget_1);

        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_3);


        verticalLayout_5->addLayout(horizontalLayout_7);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(15, -1, 15, -1);
        Btn_OpenExcel = new QPushButton(widget_HistotySearch);
        Btn_OpenExcel->setObjectName(QString::fromUtf8("Btn_OpenExcel"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Btn_OpenExcel->sizePolicy().hasHeightForWidth());
        Btn_OpenExcel->setSizePolicy(sizePolicy1);
        Btn_OpenExcel->setMinimumSize(QSize(120, 0));

        horizontalLayout_3->addWidget(Btn_OpenExcel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        Btn_HistorySearch = new QPushButton(widget_HistotySearch);
        Btn_HistorySearch->setObjectName(QString::fromUtf8("Btn_HistorySearch"));
        sizePolicy1.setHeightForWidth(Btn_HistorySearch->sizePolicy().hasHeightForWidth());
        Btn_HistorySearch->setSizePolicy(sizePolicy1);
        Btn_HistorySearch->setMinimumSize(QSize(120, 0));

        horizontalLayout_3->addWidget(Btn_HistorySearch);


        verticalLayout_5->addLayout(horizontalLayout_3);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_2);

        verticalLayout_5->setStretch(1, 6);
        verticalLayout_5->setStretch(2, 1);

        horizontalLayout_9->addWidget(widget_HistotySearch);

        widget_TimePie = new DHBaseWidget(widget_page1);
        widget_TimePie->setObjectName(QString::fromUtf8("widget_TimePie"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(widget_TimePie->sizePolicy().hasHeightForWidth());
        widget_TimePie->setSizePolicy(sizePolicy2);
        verticalLayout_6 = new QVBoxLayout(widget_TimePie);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 30, 0, 0);
        widget_pie1 = new QWidget(widget_TimePie);
        widget_pie1->setObjectName(QString::fromUtf8("widget_pie1"));
        widget_pie1->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_6->addWidget(widget_pie1);


        horizontalLayout_9->addWidget(widget_TimePie);


        verticalLayout_7->addLayout(horizontalLayout_9);

        verticalLayout_7->setStretch(0, 2);
        verticalLayout_7->setStretch(1, 2);
        verticalLayout_7->setStretch(2, 3);

        verticalLayout_4->addWidget(widget_page1);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        verticalLayout_12 = new QVBoxLayout(page_2);
        verticalLayout_12->setSpacing(5);
        verticalLayout_12->setContentsMargins(11, 11, 11, 11);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        verticalLayout_12->setContentsMargins(0, 5, 0, 0);
        CustomPlot = new QCustomPlot(page_2);
        CustomPlot->setObjectName(QString::fromUtf8("CustomPlot"));
        CustomPlot->setContextMenuPolicy(Qt::CustomContextMenu);
        CustomPlot->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_12->addWidget(CustomPlot);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, -1, -1, -1);
        widget_HistoryShift = new DHBaseWidget(page_2);
        widget_HistoryShift->setObjectName(QString::fromUtf8("widget_HistoryShift"));
        widget_HistoryShift->setContextMenuPolicy(Qt::NoContextMenu);
        gridLayout_2 = new QGridLayout(widget_HistoryShift);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setVerticalSpacing(12);
        gridLayout_2->setContentsMargins(-1, 25, -1, -1);
        pushButton_Cancel = new QPushButton(widget_HistoryShift);
        pushButton_Cancel->setObjectName(QString::fromUtf8("pushButton_Cancel"));
        pushButton_Cancel->setMinimumSize(QSize(0, 40));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        pushButton_Cancel->setFont(font);

        gridLayout_2->addWidget(pushButton_Cancel, 5, 1, 1, 1);

        label_4 = new QLabel(widget_HistoryShift);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(0, 30));

        gridLayout_2->addWidget(label_4, 3, 0, 1, 1);

        timeEdit_2 = new QTimeEdit(widget_HistoryShift);
        timeEdit_2->setObjectName(QString::fromUtf8("timeEdit_2"));
        timeEdit_2->setMinimumSize(QSize(0, 25));
        timeEdit_2->setMaximumTime(QTime(23, 59, 59));
        timeEdit_2->setMinimumTime(QTime(0, 0, 0));

        gridLayout_2->addWidget(timeEdit_2, 2, 1, 1, 1);

        timeEdit_3 = new QTimeEdit(widget_HistoryShift);
        timeEdit_3->setObjectName(QString::fromUtf8("timeEdit_3"));
        timeEdit_3->setMinimumSize(QSize(0, 25));
        timeEdit_3->setMaximumTime(QTime(23, 59, 59));
        timeEdit_3->setMinimumTime(QTime(0, 0, 0));

        gridLayout_2->addWidget(timeEdit_3, 3, 1, 1, 1);

        label_5 = new QLabel(widget_HistoryShift);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(0, 30));

        gridLayout_2->addWidget(label_5, 2, 0, 1, 1);

        pushButton_Save = new QPushButton(widget_HistoryShift);
        pushButton_Save->setObjectName(QString::fromUtf8("pushButton_Save"));
        pushButton_Save->setMinimumSize(QSize(0, 40));
        pushButton_Save->setFont(font);

        gridLayout_2->addWidget(pushButton_Save, 5, 0, 1, 1);

        groupBox = new QGroupBox(widget_HistoryShift);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(0, 50));
        groupBox->setContextMenuPolicy(Qt::NoContextMenu);
        groupBox->setStyleSheet(QString::fromUtf8("border-color: rgb(190, 190, 190);"));
        horizontalLayout_11 = new QHBoxLayout(groupBox);
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        radioBtn_Half = new QRadioButton(groupBox);
        radioBtn_Half->setObjectName(QString::fromUtf8("radioBtn_Half"));

        horizontalLayout_11->addWidget(radioBtn_Half);

        radioBtn_anHour = new QRadioButton(groupBox);
        radioBtn_anHour->setObjectName(QString::fromUtf8("radioBtn_anHour"));

        horizontalLayout_11->addWidget(radioBtn_anHour);


        gridLayout_2->addWidget(groupBox, 4, 0, 1, 2);

        label_1 = new QLabel(widget_HistoryShift);
        label_1->setObjectName(QString::fromUtf8("label_1"));
        label_1->setMinimumSize(QSize(0, 30));

        gridLayout_2->addWidget(label_1, 0, 0, 1, 1);

        timeEdit_1 = new QTimeEdit(widget_HistoryShift);
        timeEdit_1->setObjectName(QString::fromUtf8("timeEdit_1"));
        timeEdit_1->setMinimumSize(QSize(0, 25));
        timeEdit_1->setTime(QTime(8, 0, 0));
        timeEdit_1->setMaximumTime(QTime(23, 59, 59));

        gridLayout_2->addWidget(timeEdit_1, 0, 1, 1, 1);

        gridLayout_2->setRowStretch(0, 1);

        horizontalLayout_10->addWidget(widget_HistoryShift);

        calendarWidget_2 = new QCalendarWidget(page_2);
        calendarWidget_2->setObjectName(QString::fromUtf8("calendarWidget_2"));
        calendarWidget_2->setMinimumSize(QSize(350, 0));
        calendarWidget_2->setMaximumSize(QSize(350, 16777215));
        calendarWidget_2->setContextMenuPolicy(Qt::NoContextMenu);
        calendarWidget_2->setStyleSheet(QString::fromUtf8("\n"
"QToolButton#qt_calendar_monthbutton,#qt_calendar_yearbutton{\n"
"\n"
"color: #9ea5a9; \n"
"\n"
"font: 13pt simHei; \n"
"}\n"
"\n"
"QCalendarWidget QWidget#qt_calendar_navigationbar\n"
"{\n"
"\n"
"background-color: #2F2F3E;\n"
"}\n"
"QCalendarWidget QToolButton {\n"
"    height: 30px;\n"
"    width: 100px;\n"
"    color: white;\n"
"    font-size: 24px;\n"
"    icon-size: 48px, 48px;\n"
"}\n"
"QCalendarWidget QMenu {\n"
"    width: 100px;\n"
"    left: 20px;\n"
"    color: white;\n"
"    font-size: 18px;\n"
"}\n"
"\n"
""));
        calendarWidget_2->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        horizontalLayout_10->addWidget(calendarWidget_2);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(-1, 0, -1, 0);
        widget_shiftSearch = new DHBaseWidget(page_2);
        widget_shiftSearch->setObjectName(QString::fromUtf8("widget_shiftSearch"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(widget_shiftSearch->sizePolicy().hasHeightForWidth());
        widget_shiftSearch->setSizePolicy(sizePolicy3);
        widget_shiftSearch->setContextMenuPolicy(Qt::NoContextMenu);
        verticalLayout_9 = new QVBoxLayout(widget_shiftSearch);
        verticalLayout_9->setSpacing(5);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(-1, 25, -1, 5);
        radioButton_Shift1 = new QRadioButton(widget_shiftSearch);
        radioButton_Shift1->setObjectName(QString::fromUtf8("radioButton_Shift1"));
        radioButton_Shift1->setChecked(true);

        verticalLayout_9->addWidget(radioButton_Shift1);

        radioButton_Shift2 = new QRadioButton(widget_shiftSearch);
        radioButton_Shift2->setObjectName(QString::fromUtf8("radioButton_Shift2"));

        verticalLayout_9->addWidget(radioButton_Shift2);

        radioButton_Shift3 = new QRadioButton(widget_shiftSearch);
        radioButton_Shift3->setObjectName(QString::fromUtf8("radioButton_Shift3"));

        verticalLayout_9->addWidget(radioButton_Shift3);

        radioButton_ShiftAll = new QRadioButton(widget_shiftSearch);
        radioButton_ShiftAll->setObjectName(QString::fromUtf8("radioButton_ShiftAll"));

        verticalLayout_9->addWidget(radioButton_ShiftAll);


        verticalLayout_8->addWidget(widget_shiftSearch);

        widget_table = new DHBaseWidget(page_2);
        widget_table->setObjectName(QString::fromUtf8("widget_table"));
        widget_table->setContextMenuPolicy(Qt::NoContextMenu);
        verticalLayout_10 = new QVBoxLayout(widget_table);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(-1, 15, -1, -1);
        radioButton_table1 = new QRadioButton(widget_table);
        radioButton_table1->setObjectName(QString::fromUtf8("radioButton_table1"));
        radioButton_table1->setChecked(true);

        verticalLayout_10->addWidget(radioButton_table1);

        radioButton_table2 = new QRadioButton(widget_table);
        radioButton_table2->setObjectName(QString::fromUtf8("radioButton_table2"));

        verticalLayout_10->addWidget(radioButton_table2);

        radioButton_table3 = new QRadioButton(widget_table);
        radioButton_table3->setObjectName(QString::fromUtf8("radioButton_table3"));

        verticalLayout_10->addWidget(radioButton_table3);


        verticalLayout_8->addWidget(widget_table);

        pushButton_Search = new QPushButton(page_2);
        pushButton_Search->setObjectName(QString::fromUtf8("pushButton_Search"));
        pushButton_Search->setMinimumSize(QSize(150, 50));
        pushButton_Search->setFont(font);

        verticalLayout_8->addWidget(pushButton_Search);


        horizontalLayout_10->addLayout(verticalLayout_8);

        widget_ShiftPie = new DHBaseWidget(page_2);
        widget_ShiftPie->setObjectName(QString::fromUtf8("widget_ShiftPie"));
        verticalLayout_11 = new QVBoxLayout(widget_ShiftPie);
        verticalLayout_11->setSpacing(0);
        verticalLayout_11->setContentsMargins(11, 11, 11, 11);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        verticalLayout_11->setContentsMargins(0, 30, 0, 0);
        widget_pie2 = new QWidget(widget_ShiftPie);
        widget_pie2->setObjectName(QString::fromUtf8("widget_pie2"));

        verticalLayout_11->addWidget(widget_pie2);


        horizontalLayout_10->addWidget(widget_ShiftPie);

        horizontalLayout_10->setStretch(0, 2);
        horizontalLayout_10->setStretch(1, 4);
        horizontalLayout_10->setStretch(2, 2);
        horizontalLayout_10->setStretch(3, 7);

        verticalLayout_12->addLayout(horizontalLayout_10);

        verticalLayout_12->setStretch(0, 4);
        verticalLayout_12->setStretch(1, 3);
        stackedWidget->addWidget(page_2);

        verticalLayout->addWidget(stackedWidget);


        horizontalLayout->addLayout(verticalLayout);

        widget_countset = new QWidget(widget_count);
        widget_countset->setObjectName(QString::fromUtf8("widget_countset"));
        widget_countset->setMinimumSize(QSize(330, 0));
        widget_countset->setMaximumSize(QSize(330, 16777215));
        verticalLayout_3 = new QVBoxLayout(widget_countset);
        verticalLayout_3->setSpacing(5);
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        widget_countInfo = new DHBaseWidget(widget_countset);
        widget_countInfo->setObjectName(QString::fromUtf8("widget_countInfo"));
        widget_countInfo->setMinimumSize(QSize(0, 0));
        QFont font1;
        font1.setPointSize(12);
        widget_countInfo->setFont(font1);
        verticalLayout_2 = new QVBoxLayout(widget_countInfo);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, 30, -1, -1);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_total = new QLabel(widget_countInfo);
        label_total->setObjectName(QString::fromUtf8("label_total"));
        QFont font2;
        font2.setPointSize(9);
        font2.setBold(true);
        font2.setWeight(75);
        label_total->setFont(font2);
        label_total->setFrameShape(QFrame::NoFrame);
        label_total->setFrameShadow(QFrame::Plain);
        label_total->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_total, 0, 0, 1, 1);

        label_failur = new QLabel(widget_countInfo);
        label_failur->setObjectName(QString::fromUtf8("label_failur"));
        label_failur->setFont(font2);
        label_failur->setFrameShape(QFrame::NoFrame);
        label_failur->setFrameShadow(QFrame::Plain);
        label_failur->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_failur, 0, 2, 1, 1);

        line = new QFrame(widget_countInfo);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 0, 1, 1, 1);

        label_failurRate = new QLabel(widget_countInfo);
        label_failurRate->setObjectName(QString::fromUtf8("label_failurRate"));
        label_failurRate->setFont(font2);
        label_failurRate->setFrameShape(QFrame::NoFrame);
        label_failurRate->setFrameShadow(QFrame::Plain);
        label_failurRate->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_failurRate, 2, 0, 1, 1);

        line_3 = new QFrame(widget_countInfo);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_3, 2, 1, 1, 1);

        label_modelRate = new QLabel(widget_countInfo);
        label_modelRate->setObjectName(QString::fromUtf8("label_modelRate"));
        label_modelRate->setFont(font2);
        label_modelRate->setFrameShape(QFrame::NoFrame);
        label_modelRate->setFrameShadow(QFrame::Plain);
        label_modelRate->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_modelRate, 2, 2, 1, 1);

        line_4 = new QFrame(widget_countInfo);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_4, 1, 2, 1, 1);

        line_2 = new QFrame(widget_countInfo);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 1, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout);


        verticalLayout_3->addWidget(widget_countInfo);

        widget_saveRecord = new DHBaseWidget(widget_countset);
        widget_saveRecord->setObjectName(QString::fromUtf8("widget_saveRecord"));
        widget_saveRecord->setFont(font1);
        gridLayout_saveRecord = new QGridLayout(widget_saveRecord);
        gridLayout_saveRecord->setSpacing(6);
        gridLayout_saveRecord->setContentsMargins(11, 11, 11, 11);
        gridLayout_saveRecord->setObjectName(QString::fromUtf8("gridLayout_saveRecord"));
        gridLayout_saveRecord->setContentsMargins(-1, 30, -1, -1);
        checkBox_saveRecord = new QCheckBox(widget_saveRecord);
        checkBox_saveRecord->setObjectName(QString::fromUtf8("checkBox_saveRecord"));
        checkBox_saveRecord->setFont(font1);

        gridLayout_saveRecord->addWidget(checkBox_saveRecord, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_saveRecordOK = new QPushButton(widget_saveRecord);
        pushButton_saveRecordOK->setObjectName(QString::fromUtf8("pushButton_saveRecordOK"));
        pushButton_saveRecordOK->setMinimumSize(QSize(120, 40));
        pushButton_saveRecordOK->setMaximumSize(QSize(120, 40));
        pushButton_saveRecordOK->setFont(font1);

        horizontalLayout_2->addWidget(pushButton_saveRecordOK);

        pushButton_saveRecordCancel = new QPushButton(widget_saveRecord);
        pushButton_saveRecordCancel->setObjectName(QString::fromUtf8("pushButton_saveRecordCancel"));
        pushButton_saveRecordCancel->setMinimumSize(QSize(120, 40));
        pushButton_saveRecordCancel->setMaximumSize(QSize(120, 40));
        pushButton_saveRecordCancel->setFont(font1);

        horizontalLayout_2->addWidget(pushButton_saveRecordCancel);


        gridLayout_saveRecord->addLayout(horizontalLayout_2, 3, 0, 1, 1);

        radioButton_30minite = new QRadioButton(widget_saveRecord);
        radioButton_30minite->setObjectName(QString::fromUtf8("radioButton_30minite"));
        radioButton_30minite->setFont(font1);

        gridLayout_saveRecord->addWidget(radioButton_30minite, 1, 0, 1, 1);

        radioButton_60minite = new QRadioButton(widget_saveRecord);
        radioButton_60minite->setObjectName(QString::fromUtf8("radioButton_60minite"));
        radioButton_60minite->setFont(font1);

        gridLayout_saveRecord->addWidget(radioButton_60minite, 2, 0, 1, 1);


        verticalLayout_3->addWidget(widget_saveRecord);

        widget_ShiftSet = new DHBaseWidget(widget_countset);
        widget_ShiftSet->setObjectName(QString::fromUtf8("widget_ShiftSet"));
        widget_ShiftSet->setFont(font1);
        verticalLayout_shitf = new QVBoxLayout(widget_ShiftSet);
        verticalLayout_shitf->setSpacing(6);
        verticalLayout_shitf->setContentsMargins(11, 11, 11, 11);
        verticalLayout_shitf->setObjectName(QString::fromUtf8("verticalLayout_shitf"));
        verticalLayout_shitf->setContentsMargins(-1, 30, -1, -1);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label = new QLabel(widget_ShiftSet);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font1);

        horizontalLayout_4->addWidget(label, 0, Qt::AlignHCenter);

        timeEdit_shift1 = new QTimeEdit(widget_ShiftSet);
        timeEdit_shift1->setObjectName(QString::fromUtf8("timeEdit_shift1"));
        timeEdit_shift1->setFont(font1);

        horizontalLayout_4->addWidget(timeEdit_shift1);


        verticalLayout_shitf->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_2 = new QLabel(widget_ShiftSet);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);

        horizontalLayout_5->addWidget(label_2, 0, Qt::AlignHCenter);

        timeEdit_shift2 = new QTimeEdit(widget_ShiftSet);
        timeEdit_shift2->setObjectName(QString::fromUtf8("timeEdit_shift2"));
        timeEdit_shift2->setFont(font1);

        horizontalLayout_5->addWidget(timeEdit_shift2);


        verticalLayout_shitf->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_3 = new QLabel(widget_ShiftSet);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);

        horizontalLayout_6->addWidget(label_3, 0, Qt::AlignHCenter);

        timeEdit_shift3 = new QTimeEdit(widget_ShiftSet);
        timeEdit_shift3->setObjectName(QString::fromUtf8("timeEdit_shift3"));
        timeEdit_shift3->setFont(font1);

        horizontalLayout_6->addWidget(timeEdit_shift3);


        verticalLayout_shitf->addLayout(horizontalLayout_6);

        checkBox_AutoSetZero = new QCheckBox(widget_ShiftSet);
        checkBox_AutoSetZero->setObjectName(QString::fromUtf8("checkBox_AutoSetZero"));
        checkBox_AutoSetZero->setFont(font1);

        verticalLayout_shitf->addWidget(checkBox_AutoSetZero);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        pushButton_shiftOK = new QPushButton(widget_ShiftSet);
        pushButton_shiftOK->setObjectName(QString::fromUtf8("pushButton_shiftOK"));
        pushButton_shiftOK->setMinimumSize(QSize(120, 40));
        pushButton_shiftOK->setMaximumSize(QSize(120, 40));
        pushButton_shiftOK->setFont(font1);

        horizontalLayout_8->addWidget(pushButton_shiftOK);

        pushButton_shiftCancel = new QPushButton(widget_ShiftSet);
        pushButton_shiftCancel->setObjectName(QString::fromUtf8("pushButton_shiftCancel"));
        pushButton_shiftCancel->setMinimumSize(QSize(120, 40));
        pushButton_shiftCancel->setMaximumSize(QSize(120, 40));
        pushButton_shiftCancel->setFont(font1);

        horizontalLayout_8->addWidget(pushButton_shiftCancel);


        verticalLayout_shitf->addLayout(horizontalLayout_8);


        verticalLayout_3->addWidget(widget_ShiftSet);


        horizontalLayout->addWidget(widget_countset);


        retranslateUi(widget_count);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(widget_count);
    } // setupUi

    void retranslateUi(QWidget *widget_count)
    {
        widget_count->setWindowTitle(QApplication::translate("widget_count", "widget_count", 0, QApplication::UnicodeUTF8));
        Btn_OpenExcel->setText(QApplication::translate("widget_count", "Open Excel Table", 0, QApplication::UnicodeUTF8));
        Btn_HistorySearch->setText(QApplication::translate("widget_count", "History Search", 0, QApplication::UnicodeUTF8));
        pushButton_Cancel->setText(QApplication::translate("widget_count", "Cancel", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("widget_count", "Shift3 StartTime:", 0, QApplication::UnicodeUTF8));
        timeEdit_2->setDisplayFormat(QApplication::translate("widget_count", "HH:mm:ss", 0, QApplication::UnicodeUTF8));
        timeEdit_3->setDisplayFormat(QApplication::translate("widget_count", "HH:mm:ss", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("widget_count", "Shift2 StartTime:", 0, QApplication::UnicodeUTF8));
        pushButton_Save->setText(QApplication::translate("widget_count", "Save", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        radioBtn_Half->setText(QApplication::translate("widget_count", "Half an Hour", 0, QApplication::UnicodeUTF8));
        radioBtn_anHour->setText(QApplication::translate("widget_count", "an Hour", 0, QApplication::UnicodeUTF8));
        label_1->setText(QApplication::translate("widget_count", "Shift1 StartTime:", 0, QApplication::UnicodeUTF8));
        timeEdit_1->setDisplayFormat(QApplication::translate("widget_count", "HH:mm:ss", 0, QApplication::UnicodeUTF8));
        radioButton_Shift1->setText(QApplication::translate("widget_count", "Shift 1", 0, QApplication::UnicodeUTF8));
        radioButton_Shift2->setText(QApplication::translate("widget_count", "shift 2", 0, QApplication::UnicodeUTF8));
        radioButton_Shift3->setText(QApplication::translate("widget_count", "shift 3", 0, QApplication::UnicodeUTF8));
        radioButton_ShiftAll->setText(QApplication::translate("widget_count", "All shift", 0, QApplication::UnicodeUTF8));
        radioButton_table1->setText(QApplication::translate("widget_count", "Failure Number table", 0, QApplication::UnicodeUTF8));
        radioButton_table2->setText(QApplication::translate("widget_count", "Failure Rate table", 0, QApplication::UnicodeUTF8));
        radioButton_table3->setText(QApplication::translate("widget_count", "Shift Defect Count Plot", 0, QApplication::UnicodeUTF8));
        pushButton_Search->setText(QApplication::translate("widget_count", "Search", 0, QApplication::UnicodeUTF8));
        label_total->setText(QApplication::translate("widget_count", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_failur->setText(QApplication::translate("widget_count", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_failurRate->setText(QApplication::translate("widget_count", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_modelRate->setText(QApplication::translate("widget_count", "TextLabel", 0, QApplication::UnicodeUTF8));
        checkBox_saveRecord->setText(QApplication::translate("widget_count", "Save Record", 0, QApplication::UnicodeUTF8));
        pushButton_saveRecordOK->setText(QApplication::translate("widget_count", "OK", 0, QApplication::UnicodeUTF8));
        pushButton_saveRecordCancel->setText(QApplication::translate("widget_count", "Cancel", 0, QApplication::UnicodeUTF8));
        radioButton_30minite->setText(QApplication::translate("widget_count", "Save record every 30minite", 0, QApplication::UnicodeUTF8));
        radioButton_60minite->setText(QApplication::translate("widget_count", "Save record every 60minite", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("widget_count", "Shift1:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("widget_count", "Shift2:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("widget_count", "Shift3:", 0, QApplication::UnicodeUTF8));
        checkBox_AutoSetZero->setText(QApplication::translate("widget_count", "AutoSetZero", 0, QApplication::UnicodeUTF8));
        pushButton_shiftOK->setText(QApplication::translate("widget_count", "OK", 0, QApplication::UnicodeUTF8));
        pushButton_shiftCancel->setText(QApplication::translate("widget_count", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class widget_count: public Ui_widget_count {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_COUNT_H
