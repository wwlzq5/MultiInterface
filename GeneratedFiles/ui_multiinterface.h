/********************************************************************************
** Form generated from reading UI file 'multiinterface.ui'
**
** Created: Tue Nov 2 15:06:11 2021
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MULTIINTERFACE_H
#define UI_MULTIINTERFACE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStackedWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MultiInterfaceClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_6;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_home;
    QPushButton *pushButton_open1;
    QPushButton *pushButton_open2;
    QPushButton *pushButton_open3;
    QPushButton *pushButton_2;
    QPushButton *pushButton_IO;
    QPushButton *pushButton_Alert;
    QPushButton *pushButton_Mode;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout;
    QLabel *label;
    QCheckBox *checkBox;
    QLabel *label_2;
    QCheckBox *checkBox_2;
    QLabel *label_3;
    QCheckBox *checkBox_3;
    QFrame *line;
    QStackedWidget *stackedWidget;
    QWidget *Page1;

    void setupUi(QMainWindow *MultiInterfaceClass)
    {
        if (MultiInterfaceClass->objectName().isEmpty())
            MultiInterfaceClass->setObjectName(QString::fromUtf8("MultiInterfaceClass"));
        MultiInterfaceClass->resize(1124, 707);
        MultiInterfaceClass->setStyleSheet(QString::fromUtf8("QWidget#widget_Count,#widget{\n"
"	background:rgb(120,240,128,70); \n"
"}\n"
"\n"
"DHBaseWidget{\n"
"	background:rgb(90,90,90,120);\n"
"}\n"
"QTableView{ \n"
"	background:gray; \n"
"}\n"
"QStackedWidget{\n"
"	background:rgb(120,240,128,70); \n"
"} "));
        centralWidget = new QWidget(MultiInterfaceClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout_6 = new QHBoxLayout(centralWidget);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setMinimumSize(QSize(150, 0));
        widget->setMaximumSize(QSize(150, 16777215));
        widget->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border:none;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	background:rgb(120,240,128); \n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	background:rgb(255,255,255); \n"
"}"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, -1, 0, 9);
        pushButton_home = new QPushButton(widget);
        pushButton_home->setObjectName(QString::fromUtf8("pushButton_home"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_home->sizePolicy().hasHeightForWidth());
        pushButton_home->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(pushButton_home);

        pushButton_open1 = new QPushButton(widget);
        pushButton_open1->setObjectName(QString::fromUtf8("pushButton_open1"));
        sizePolicy1.setHeightForWidth(pushButton_open1->sizePolicy().hasHeightForWidth());
        pushButton_open1->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(pushButton_open1);

        pushButton_open2 = new QPushButton(widget);
        pushButton_open2->setObjectName(QString::fromUtf8("pushButton_open2"));
        sizePolicy1.setHeightForWidth(pushButton_open2->sizePolicy().hasHeightForWidth());
        pushButton_open2->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(pushButton_open2);

        pushButton_open3 = new QPushButton(widget);
        pushButton_open3->setObjectName(QString::fromUtf8("pushButton_open3"));
        sizePolicy1.setHeightForWidth(pushButton_open3->sizePolicy().hasHeightForWidth());
        pushButton_open3->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(pushButton_open3);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        sizePolicy1.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(pushButton_2);

        pushButton_IO = new QPushButton(widget);
        pushButton_IO->setObjectName(QString::fromUtf8("pushButton_IO"));
        sizePolicy1.setHeightForWidth(pushButton_IO->sizePolicy().hasHeightForWidth());
        pushButton_IO->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(pushButton_IO);

        pushButton_Alert = new QPushButton(widget);
        pushButton_Alert->setObjectName(QString::fromUtf8("pushButton_Alert"));
        sizePolicy1.setHeightForWidth(pushButton_Alert->sizePolicy().hasHeightForWidth());
        pushButton_Alert->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(pushButton_Alert);

        pushButton_Mode = new QPushButton(widget);
        pushButton_Mode->setObjectName(QString::fromUtf8("pushButton_Mode"));
        sizePolicy1.setHeightForWidth(pushButton_Mode->sizePolicy().hasHeightForWidth());
        pushButton_Mode->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(pushButton_Mode);

        verticalSpacer = new QSpacerItem(20, 406, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        checkBox = new QCheckBox(widget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        gridLayout->addWidget(checkBox, 0, 1, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        checkBox_2 = new QCheckBox(widget);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));

        gridLayout->addWidget(checkBox_2, 1, 1, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        checkBox_3 = new QCheckBox(widget);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));

        gridLayout->addWidget(checkBox_3, 2, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);


        horizontalLayout_6->addWidget(widget);

        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_6->addWidget(line);

        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setStyleSheet(QString::fromUtf8(""));
        Page1 = new QWidget();
        Page1->setObjectName(QString::fromUtf8("Page1"));
        stackedWidget->addWidget(Page1);

        horizontalLayout_6->addWidget(stackedWidget);

        MultiInterfaceClass->setCentralWidget(centralWidget);

        retranslateUi(MultiInterfaceClass);

        QMetaObject::connectSlotsByName(MultiInterfaceClass);
    } // setupUi

    void retranslateUi(QMainWindow *MultiInterfaceClass)
    {
        MultiInterfaceClass->setWindowTitle(QApplication::translate("MultiInterfaceClass", "MultiInterface", 0, QApplication::UnicodeUTF8));
        pushButton_home->setText(QApplication::translate("MultiInterfaceClass", "Home", 0, QApplication::UnicodeUTF8));
        pushButton_open1->setText(QApplication::translate("MultiInterfaceClass", "Open Front", 0, QApplication::UnicodeUTF8));
        pushButton_open2->setText(QApplication::translate("MultiInterfaceClass", "Open Clamp", 0, QApplication::UnicodeUTF8));
        pushButton_open3->setText(QApplication::translate("MultiInterfaceClass", "Open Rear", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("MultiInterfaceClass", "Clear", 0, QApplication::UnicodeUTF8));
        pushButton_IO->setText(QApplication::translate("MultiInterfaceClass", "Open Card", 0, QApplication::UnicodeUTF8));
        pushButton_Alert->setText(QApplication::translate("MultiInterfaceClass", "Alert Setting", 0, QApplication::UnicodeUTF8));
        pushButton_Mode->setText(QApplication::translate("MultiInterfaceClass", "Product Mode", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MultiInterfaceClass", "Front state", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QString());
        label_2->setText(QApplication::translate("MultiInterfaceClass", "Clamp state", 0, QApplication::UnicodeUTF8));
        checkBox_2->setText(QString());
        label_3->setText(QApplication::translate("MultiInterfaceClass", "Rear state", 0, QApplication::UnicodeUTF8));
        checkBox_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MultiInterfaceClass: public Ui_MultiInterfaceClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MULTIINTERFACE_H
