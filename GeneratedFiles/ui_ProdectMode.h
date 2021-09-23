/********************************************************************************
** Form generated from reading UI file 'ProdectMode.ui'
**
** Created: Sat Sep 18 14:48:00 2021
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRODECTMODE_H
#define UI_PRODECTMODE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTableView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_widgetMode
{
public:
    QPushButton *pushButton_new;
    QTableView *tableView;
    QPushButton *pushButton_add;
    QPushButton *pushButton_delete;
    QLabel *label;
    QPushButton *pushButton_sure;
    QLineEdit *lineEdit;

    void setupUi(QWidget *widgetMode)
    {
        if (widgetMode->objectName().isEmpty())
            widgetMode->setObjectName(QString::fromUtf8("widgetMode"));
        widgetMode->resize(797, 557);
        pushButton_new = new QPushButton(widgetMode);
        pushButton_new->setObjectName(QString::fromUtf8("pushButton_new"));
        pushButton_new->setGeometry(QRect(11, 498, 261, 23));
        tableView = new QTableView(widgetMode);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(20, 10, 761, 471));
        pushButton_add = new QPushButton(widgetMode);
        pushButton_add->setObjectName(QString::fromUtf8("pushButton_add"));
        pushButton_add->setGeometry(QRect(290, 500, 251, 23));
        pushButton_delete = new QPushButton(widgetMode);
        pushButton_delete->setObjectName(QString::fromUtf8("pushButton_delete"));
        pushButton_delete->setGeometry(QRect(560, 500, 221, 23));
        label = new QLabel(widgetMode);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(11, 527, 261, 23));
        pushButton_sure = new QPushButton(widgetMode);
        pushButton_sure->setObjectName(QString::fromUtf8("pushButton_sure"));
        pushButton_sure->setGeometry(QRect(620, 530, 161, 23));
        lineEdit = new QLineEdit(widgetMode);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(290, 530, 321, 20));

        retranslateUi(widgetMode);

        QMetaObject::connectSlotsByName(widgetMode);
    } // setupUi

    void retranslateUi(QWidget *widgetMode)
    {
        widgetMode->setWindowTitle(QApplication::translate("widgetMode", "Form", 0, QApplication::UnicodeUTF8));
        pushButton_new->setText(QApplication::translate("widgetMode", "new mode", 0, QApplication::UnicodeUTF8));
        pushButton_add->setText(QApplication::translate("widgetMode", " add mode", 0, QApplication::UnicodeUTF8));
        pushButton_delete->setText(QApplication::translate("widgetMode", "delete mode", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        pushButton_sure->setText(QApplication::translate("widgetMode", "sure", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class widgetMode: public Ui_widgetMode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRODECTMODE_H
