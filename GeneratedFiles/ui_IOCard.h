/********************************************************************************
** Form generated from reading UI file 'IOCard.ui'
**
** Created: Tue Nov 2 15:06:11 2021
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IOCARD_H
#define UI_IOCARD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IOCard
{
public:
    QTableView *tableView;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QLabel *label_4;
    QLineEdit *lineEdit_4;
    QLabel *label_5;
    QLineEdit *lineEdit_5;
    QLabel *label_6;
    QLineEdit *lineEdit_6;
    QLabel *label_7;
    QLineEdit *lineEdit_7;
    QLabel *label_8;
    QLineEdit *lineEdit_8;
    QLabel *label_9;
    QLineEdit *lineEdit_9;
    QLabel *label_10;
    QLineEdit *lineEdit_10;
    QLabel *label_11;
    QLineEdit *lineEdit_11;
    QLabel *label_12;
    QLineEdit *lineEdit_12;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_17;
    QCheckBox *checkBox;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_Camera;
    QLabel *label_nFailType;
    QWidget *layoutWidget3;
    QGridLayout *gridLayout_2;
    QLabel *label_13;
    QLineEdit *lineEdit_13;
    QLabel *label_14;
    QLineEdit *lineEdit_14;
    QLabel *label_15;
    QLineEdit *lineEdit_15;
    QLabel *label_16;
    QLineEdit *lineEdit_16;

    void setupUi(QWidget *IOCard)
    {
        if (IOCard->objectName().isEmpty())
            IOCard->setObjectName(QString::fromUtf8("IOCard"));
        IOCard->resize(648, 299);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(IOCard->sizePolicy().hasHeightForWidth());
        IOCard->setSizePolicy(sizePolicy);
        tableView = new QTableView(IOCard);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(480, 10, 160, 278));
        sizePolicy.setHeightForWidth(tableView->sizePolicy().hasHeightForWidth());
        tableView->setSizePolicy(sizePolicy);
        tableView->setMinimumSize(QSize(160, 0));
        layoutWidget = new QWidget(IOCard);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 464, 74));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEnabled(false);
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy1);
        lineEdit->setMinimumSize(QSize(75, 20));
        lineEdit->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        lineEdit_2 = new QLineEdit(layoutWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setEnabled(false);
        sizePolicy1.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy1);
        lineEdit_2->setMinimumSize(QSize(75, 20));
        lineEdit_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_2, 0, 3, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 4, 1, 1);

        lineEdit_3 = new QLineEdit(layoutWidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setEnabled(false);
        sizePolicy1.setHeightForWidth(lineEdit_3->sizePolicy().hasHeightForWidth());
        lineEdit_3->setSizePolicy(sizePolicy1);
        lineEdit_3->setMinimumSize(QSize(75, 20));
        lineEdit_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_3, 0, 5, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 6, 1, 1);

        lineEdit_4 = new QLineEdit(layoutWidget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setEnabled(false);
        sizePolicy1.setHeightForWidth(lineEdit_4->sizePolicy().hasHeightForWidth());
        lineEdit_4->setSizePolicy(sizePolicy1);
        lineEdit_4->setMinimumSize(QSize(75, 20));
        lineEdit_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_4, 0, 7, 1, 1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 1, 0, 1, 1);

        lineEdit_5 = new QLineEdit(layoutWidget);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setEnabled(false);
        sizePolicy1.setHeightForWidth(lineEdit_5->sizePolicy().hasHeightForWidth());
        lineEdit_5->setSizePolicy(sizePolicy1);
        lineEdit_5->setMinimumSize(QSize(75, 20));
        lineEdit_5->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_5, 1, 1, 1, 1);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 1, 2, 1, 1);

        lineEdit_6 = new QLineEdit(layoutWidget);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setEnabled(false);
        sizePolicy1.setHeightForWidth(lineEdit_6->sizePolicy().hasHeightForWidth());
        lineEdit_6->setSizePolicy(sizePolicy1);
        lineEdit_6->setMinimumSize(QSize(75, 20));
        lineEdit_6->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_6, 1, 3, 1, 1);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 1, 4, 1, 1);

        lineEdit_7 = new QLineEdit(layoutWidget);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));
        lineEdit_7->setEnabled(false);
        sizePolicy1.setHeightForWidth(lineEdit_7->sizePolicy().hasHeightForWidth());
        lineEdit_7->setSizePolicy(sizePolicy1);
        lineEdit_7->setMinimumSize(QSize(75, 20));
        lineEdit_7->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_7, 1, 5, 1, 1);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 1, 6, 1, 1);

        lineEdit_8 = new QLineEdit(layoutWidget);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));
        lineEdit_8->setEnabled(false);
        sizePolicy1.setHeightForWidth(lineEdit_8->sizePolicy().hasHeightForWidth());
        lineEdit_8->setSizePolicy(sizePolicy1);
        lineEdit_8->setMinimumSize(QSize(75, 20));
        lineEdit_8->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_8, 1, 7, 1, 1);

        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 2, 0, 1, 1);

        lineEdit_9 = new QLineEdit(layoutWidget);
        lineEdit_9->setObjectName(QString::fromUtf8("lineEdit_9"));
        lineEdit_9->setEnabled(false);
        sizePolicy1.setHeightForWidth(lineEdit_9->sizePolicy().hasHeightForWidth());
        lineEdit_9->setSizePolicy(sizePolicy1);
        lineEdit_9->setMinimumSize(QSize(75, 20));
        lineEdit_9->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_9, 2, 1, 1, 1);

        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 2, 2, 1, 1);

        lineEdit_10 = new QLineEdit(layoutWidget);
        lineEdit_10->setObjectName(QString::fromUtf8("lineEdit_10"));
        lineEdit_10->setEnabled(false);
        sizePolicy1.setHeightForWidth(lineEdit_10->sizePolicy().hasHeightForWidth());
        lineEdit_10->setSizePolicy(sizePolicy1);
        lineEdit_10->setMinimumSize(QSize(75, 20));
        lineEdit_10->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_10, 2, 3, 1, 1);

        label_11 = new QLabel(layoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout->addWidget(label_11, 2, 4, 1, 1);

        lineEdit_11 = new QLineEdit(layoutWidget);
        lineEdit_11->setObjectName(QString::fromUtf8("lineEdit_11"));
        lineEdit_11->setEnabled(false);
        sizePolicy1.setHeightForWidth(lineEdit_11->sizePolicy().hasHeightForWidth());
        lineEdit_11->setSizePolicy(sizePolicy1);
        lineEdit_11->setMinimumSize(QSize(75, 20));
        lineEdit_11->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_11, 2, 5, 1, 1);

        label_12 = new QLabel(layoutWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout->addWidget(label_12, 2, 6, 1, 1);

        lineEdit_12 = new QLineEdit(layoutWidget);
        lineEdit_12->setObjectName(QString::fromUtf8("lineEdit_12"));
        lineEdit_12->setEnabled(false);
        sizePolicy1.setHeightForWidth(lineEdit_12->sizePolicy().hasHeightForWidth());
        lineEdit_12->setSizePolicy(sizePolicy1);
        lineEdit_12->setMinimumSize(QSize(75, 20));
        lineEdit_12->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_12, 2, 7, 1, 1);

        layoutWidget1 = new QWidget(IOCard);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 140, 461, 25));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setSpacing(20);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(20, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_17 = new QLabel(layoutWidget1);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        horizontalLayout->addWidget(label_17);

        checkBox = new QCheckBox(layoutWidget1);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        horizontalLayout->addWidget(checkBox);


        horizontalLayout_2->addLayout(horizontalLayout);

        pushButton = new QPushButton(layoutWidget1);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_2->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        layoutWidget2 = new QWidget(IOCard);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 170, 461, 113));
        horizontalLayout_17 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        horizontalLayout_17->setContentsMargins(0, 0, 0, 0);
        label_Camera = new QLabel(layoutWidget2);
        label_Camera->setObjectName(QString::fromUtf8("label_Camera"));
        sizePolicy.setHeightForWidth(label_Camera->sizePolicy().hasHeightForWidth());
        label_Camera->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("Aharoni"));
        font.setPointSize(72);
        font.setBold(true);
        font.setWeight(75);
        label_Camera->setFont(font);
        label_Camera->setLayoutDirection(Qt::LeftToRight);
        label_Camera->setAlignment(Qt::AlignCenter);

        horizontalLayout_17->addWidget(label_Camera);

        label_nFailType = new QLabel(layoutWidget2);
        label_nFailType->setObjectName(QString::fromUtf8("label_nFailType"));
        sizePolicy.setHeightForWidth(label_nFailType->sizePolicy().hasHeightForWidth());
        label_nFailType->setSizePolicy(sizePolicy);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush1(QColor(120, 120, 120, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        label_nFailType->setPalette(palette);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Aharoni"));
        font1.setPointSize(48);
        font1.setBold(true);
        font1.setWeight(75);
        label_nFailType->setFont(font1);
        label_nFailType->setCursor(QCursor(Qt::ArrowCursor));
        label_nFailType->setAlignment(Qt::AlignCenter);

        horizontalLayout_17->addWidget(label_nFailType);

        horizontalLayout_17->setStretch(0, 3);
        horizontalLayout_17->setStretch(1, 7);
        layoutWidget3 = new QWidget(IOCard);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 90, 461, 48));
        gridLayout_2 = new QGridLayout(layoutWidget3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_13 = new QLabel(layoutWidget3);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_2->addWidget(label_13, 0, 0, 1, 1);

        lineEdit_13 = new QLineEdit(layoutWidget3);
        lineEdit_13->setObjectName(QString::fromUtf8("lineEdit_13"));
        lineEdit_13->setEnabled(false);
        sizePolicy1.setHeightForWidth(lineEdit_13->sizePolicy().hasHeightForWidth());
        lineEdit_13->setSizePolicy(sizePolicy1);
        lineEdit_13->setMinimumSize(QSize(100, 20));
        lineEdit_13->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lineEdit_13, 0, 1, 1, 1);

        label_14 = new QLabel(layoutWidget3);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_2->addWidget(label_14, 0, 2, 1, 1);

        lineEdit_14 = new QLineEdit(layoutWidget3);
        lineEdit_14->setObjectName(QString::fromUtf8("lineEdit_14"));
        lineEdit_14->setEnabled(false);
        sizePolicy1.setHeightForWidth(lineEdit_14->sizePolicy().hasHeightForWidth());
        lineEdit_14->setSizePolicy(sizePolicy1);
        lineEdit_14->setMinimumSize(QSize(100, 20));
        lineEdit_14->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lineEdit_14, 0, 3, 1, 1);

        label_15 = new QLabel(layoutWidget3);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_2->addWidget(label_15, 1, 0, 1, 1);

        lineEdit_15 = new QLineEdit(layoutWidget3);
        lineEdit_15->setObjectName(QString::fromUtf8("lineEdit_15"));
        lineEdit_15->setEnabled(false);
        sizePolicy1.setHeightForWidth(lineEdit_15->sizePolicy().hasHeightForWidth());
        lineEdit_15->setSizePolicy(sizePolicy1);
        lineEdit_15->setMinimumSize(QSize(100, 20));
        lineEdit_15->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lineEdit_15, 1, 1, 1, 1);

        label_16 = new QLabel(layoutWidget3);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout_2->addWidget(label_16, 1, 2, 1, 1);

        lineEdit_16 = new QLineEdit(layoutWidget3);
        lineEdit_16->setObjectName(QString::fromUtf8("lineEdit_16"));
        lineEdit_16->setEnabled(false);
        sizePolicy1.setHeightForWidth(lineEdit_16->sizePolicy().hasHeightForWidth());
        lineEdit_16->setSizePolicy(sizePolicy1);
        lineEdit_16->setMinimumSize(QSize(100, 20));
        lineEdit_16->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lineEdit_16, 1, 3, 1, 1);


        retranslateUi(IOCard);

        QMetaObject::connectSlotsByName(IOCard);
    } // setupUi

    void retranslateUi(QWidget *IOCard)
    {
        IOCard->setWindowTitle(QApplication::translate("IOCard", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("IOCard", "IN0:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("IOCard", "IN1:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("IOCard", "IN2:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("IOCard", "IN3:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("IOCard", "OUT0:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("IOCard", "OUT1:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("IOCard", "OUT2:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("IOCard", "OUT3:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("IOCard", "OUT3:", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("IOCard", "OUT5:", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("IOCard", "OUT6:", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("IOCard", "OUT7:", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("IOCard", "IfShowError", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QString());
        pushButton->setText(QApplication::translate("IOCard", "clear table", 0, QApplication::UnicodeUTF8));
        label_Camera->setText(QString());
        label_nFailType->setText(QString());
        label_13->setText(QApplication::translate("IOCard", "nALL:", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("IOCard", "nKick:", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("IOCard", "nCBAll:", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("IOCard", "nCBFail:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class IOCard: public Ui_IOCard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IOCARD_H
