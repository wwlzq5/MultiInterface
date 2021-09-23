/********************************************************************************
** Form generated from reading UI file 'multiinterface.ui'
**
** Created: Sat Sep 18 14:47:59 2021
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
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MultiInterfaceClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_6;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QPushButton *pushButton_open3;
    QPushButton *pushButton_IO;
    QPushButton *pushButton_open1;
    QPushButton *pushButton_open2;
    QPushButton *pushButton_Mode;
    QPushButton *pushButton_2;
    QPushButton *pushButton_Alert;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QCheckBox *checkBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QCheckBox *checkBox_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QCheckBox *checkBox_3;
    QWidget *widget_Count;

    void setupUi(QMainWindow *MultiInterfaceClass)
    {
        if (MultiInterfaceClass->objectName().isEmpty())
            MultiInterfaceClass->setObjectName(QString::fromUtf8("MultiInterfaceClass"));
        MultiInterfaceClass->resize(1468, 898);
        centralWidget = new QWidget(MultiInterfaceClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout_6 = new QHBoxLayout(centralWidget);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_5 = new QHBoxLayout(widget);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton_open3 = new QPushButton(widget);
        pushButton_open3->setObjectName(QString::fromUtf8("pushButton_open3"));

        gridLayout->addWidget(pushButton_open3, 1, 0, 1, 1);

        pushButton_IO = new QPushButton(widget);
        pushButton_IO->setObjectName(QString::fromUtf8("pushButton_IO"));

        gridLayout->addWidget(pushButton_IO, 1, 1, 1, 1);

        pushButton_open1 = new QPushButton(widget);
        pushButton_open1->setObjectName(QString::fromUtf8("pushButton_open1"));

        gridLayout->addWidget(pushButton_open1, 0, 0, 1, 1);

        pushButton_open2 = new QPushButton(widget);
        pushButton_open2->setObjectName(QString::fromUtf8("pushButton_open2"));

        gridLayout->addWidget(pushButton_open2, 0, 1, 1, 1);

        pushButton_Mode = new QPushButton(widget);
        pushButton_Mode->setObjectName(QString::fromUtf8("pushButton_Mode"));

        gridLayout->addWidget(pushButton_Mode, 3, 0, 1, 1);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 2, 0, 1, 1);

        pushButton_Alert = new QPushButton(widget);
        pushButton_Alert->setObjectName(QString::fromUtf8("pushButton_Alert"));

        gridLayout->addWidget(pushButton_Alert, 2, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        checkBox = new QCheckBox(widget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        horizontalLayout->addWidget(checkBox);


        horizontalLayout_4->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        checkBox_2 = new QCheckBox(widget);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));

        horizontalLayout_2->addWidget(checkBox_2);


        horizontalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        checkBox_3 = new QCheckBox(widget);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));

        horizontalLayout_3->addWidget(checkBox_3);


        horizontalLayout_4->addLayout(horizontalLayout_3);


        verticalLayout->addLayout(horizontalLayout_4);


        horizontalLayout_5->addLayout(verticalLayout);


        horizontalLayout_6->addWidget(widget);

        widget_Count = new QWidget(centralWidget);
        widget_Count->setObjectName(QString::fromUtf8("widget_Count"));

        horizontalLayout_6->addWidget(widget_Count);

        horizontalLayout_6->setStretch(0, 3);
        horizontalLayout_6->setStretch(1, 7);
        MultiInterfaceClass->setCentralWidget(centralWidget);

        retranslateUi(MultiInterfaceClass);

        QMetaObject::connectSlotsByName(MultiInterfaceClass);
    } // setupUi

    void retranslateUi(QMainWindow *MultiInterfaceClass)
    {
        MultiInterfaceClass->setWindowTitle(QApplication::translate("MultiInterfaceClass", "MultiInterface", 0, QApplication::UnicodeUTF8));
        pushButton_open3->setText(QApplication::translate("MultiInterfaceClass", "Open Rear", 0, QApplication::UnicodeUTF8));
        pushButton_IO->setText(QApplication::translate("MultiInterfaceClass", "Open Card", 0, QApplication::UnicodeUTF8));
        pushButton_open1->setText(QApplication::translate("MultiInterfaceClass", "Open Front", 0, QApplication::UnicodeUTF8));
        pushButton_open2->setText(QApplication::translate("MultiInterfaceClass", "Open Clamp", 0, QApplication::UnicodeUTF8));
        pushButton_Mode->setText(QApplication::translate("MultiInterfaceClass", "Product Mode", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("MultiInterfaceClass", "Clear", 0, QApplication::UnicodeUTF8));
        pushButton_Alert->setText(QApplication::translate("MultiInterfaceClass", "Alert Setting", 0, QApplication::UnicodeUTF8));
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
