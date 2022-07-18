/********************************************************************************
** Form generated from reading UI file 'AlertWidget.ui'
**
** Created: Fri Mar 4 10:05:46 2022
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALERTWIDGET_H
#define UI_ALERTWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>
#include <QtGui/QTableView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AletrWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox_2;
    QComboBox *comboBox;
    QPushButton *pushButton_set;
    QLabel *label_4;
    QTableView *tableView;
    QPushButton *pushButton_delete;
    QPushButton *pushButton_Sure;
    QSpinBox *spinBox;
    QComboBox *comboBox_2;
    QLabel *label_5;
    QLabel *label_7;
    QSpinBox *spinBox_2;
    QLabel *label_6;
    QGroupBox *groupBox;
    QLabel *label;
    QRadioButton *radioButton_2;
    QLabel *label_3;
    QRadioButton *radioButton;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox_2;

    void setupUi(QMainWindow *AletrWindow)
    {
        if (AletrWindow->objectName().isEmpty())
            AletrWindow->setObjectName(QString::fromUtf8("AletrWindow"));
        AletrWindow->resize(671, 681);
        centralwidget = new QWidget(AletrWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(30, 230, 611, 431));
        comboBox = new QComboBox(groupBox_2);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(20, 70, 201, 22));
        pushButton_set = new QPushButton(groupBox_2);
        pushButton_set->setObjectName(QString::fromUtf8("pushButton_set"));
        pushButton_set->setGeometry(QRect(500, 120, 75, 23));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 20, 161, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Aharoni"));
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        label_4->setFont(font);
        tableView = new QTableView(groupBox_2);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(30, 180, 561, 192));
        pushButton_delete = new QPushButton(groupBox_2);
        pushButton_delete->setObjectName(QString::fromUtf8("pushButton_delete"));
        pushButton_delete->setGeometry(QRect(400, 120, 75, 23));
        pushButton_Sure = new QPushButton(groupBox_2);
        pushButton_Sure->setObjectName(QString::fromUtf8("pushButton_Sure"));
        pushButton_Sure->setGeometry(QRect(510, 380, 75, 23));
        spinBox = new QSpinBox(groupBox_2);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(240, 71, 36, 20));
        comboBox_2 = new QComboBox(groupBox_2);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(330, 71, 51, 20));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(290, 71, 41, 16));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(390, 71, 51, 16));
        spinBox_2 = new QSpinBox(groupBox_2);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setGeometry(QRect(440, 71, 36, 20));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(490, 71, 91, 20));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(30, 20, 451, 191));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 181, 41));
        label->setFont(font);
        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(313, 82, 53, 16));
        radioButton_2->setChecked(true);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(92, 80, 71, 16));
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(240, 82, 53, 16));
        doubleSpinBox = new QDoubleSpinBox(groupBox);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(166, 80, 54, 20));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(92, 117, 71, 16));
        doubleSpinBox_2 = new QDoubleSpinBox(groupBox);
        doubleSpinBox_2->setObjectName(QString::fromUtf8("doubleSpinBox_2"));
        doubleSpinBox_2->setGeometry(QRect(166, 117, 54, 20));
        AletrWindow->setCentralWidget(centralwidget);

        retranslateUi(AletrWindow);

        QMetaObject::connectSlotsByName(AletrWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AletrWindow)
    {
        AletrWindow->setWindowTitle(QApplication::translate("AletrWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QString());
        pushButton_set->setText(QApplication::translate("AletrWindow", "add", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("AletrWindow", "Defect Alert:", 0, QApplication::UnicodeUTF8));
        pushButton_delete->setText(QApplication::translate("AletrWindow", "delete", 0, QApplication::UnicodeUTF8));
        pushButton_Sure->setText(QApplication::translate("AletrWindow", "sure", 0, QApplication::UnicodeUTF8));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("AletrWindow", "yes", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AletrWindow", "no", 0, QApplication::UnicodeUTF8)
        );
        label_5->setText(QApplication::translate("AletrWindow", "min", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("AletrWindow", "defect", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("AletrWindow", "so Alert", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("AletrWindow", "kick rate Alert:", 0, QApplication::UnicodeUTF8));
        radioButton_2->setText(QApplication::translate("AletrWindow", "close", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("AletrWindow", "Min kick:", 0, QApplication::UnicodeUTF8));
        radioButton->setText(QApplication::translate("AletrWindow", "start", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("AletrWindow", "Max kick:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AletrWindow: public Ui_AletrWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALERTWIDGET_H
