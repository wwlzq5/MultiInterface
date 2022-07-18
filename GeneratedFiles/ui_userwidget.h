/********************************************************************************
** Form generated from reading UI file 'userwidget.ui'
**
** Created: Fri Mar 4 10:05:46 2022
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERWIDGET_H
#define UI_USERWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserWidget
{
public:
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_LogIn;
    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_image;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_user;
    QComboBox *comboBoxUser;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_password;
    QLineEdit *lineEdit_passWord;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_login;
    QWidget *widget_ChangePassWord;
    QGridLayout *gridLayout_6;
    QGridLayout *gridLayout_3;
    QLabel *label_password_2;
    QLineEdit *lineEdit_passWord2;
    QLabel *label_password_3;
    QLineEdit *lineEdit_newPassWord;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnOK_changePassWrod;
    QPushButton *btnCancel_changePassWrod;

    void setupUi(QWidget *UserWidget)
    {
        if (UserWidget->objectName().isEmpty())
            UserWidget->setObjectName(QString::fromUtf8("UserWidget"));
        UserWidget->resize(342, 427);
        UserWidget->setMaximumSize(QSize(16777215, 16777215));
        gridLayout_2 = new QGridLayout(UserWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox = new QGroupBox(UserWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        widget_LogIn = new QWidget(groupBox);
        widget_LogIn->setObjectName(QString::fromUtf8("widget_LogIn"));
        gridLayout_4 = new QGridLayout(widget_LogIn);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        pushButton_image = new QPushButton(widget_LogIn);
        pushButton_image->setObjectName(QString::fromUtf8("pushButton_image"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_image->sizePolicy().hasHeightForWidth());
        pushButton_image->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(pushButton_image);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_user = new QLabel(widget_LogIn);
        label_user->setObjectName(QString::fromUtf8("label_user"));

        horizontalLayout_2->addWidget(label_user);

        comboBoxUser = new QComboBox(widget_LogIn);
        comboBoxUser->setObjectName(QString::fromUtf8("comboBoxUser"));
        comboBoxUser->setEditable(true);

        horizontalLayout_2->addWidget(comboBoxUser);

        horizontalLayout_2->setStretch(0, 3);
        horizontalLayout_2->setStretch(1, 7);

        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_password = new QLabel(widget_LogIn);
        label_password->setObjectName(QString::fromUtf8("label_password"));

        horizontalLayout_4->addWidget(label_password);

        lineEdit_passWord = new QLineEdit(widget_LogIn);
        lineEdit_passWord->setObjectName(QString::fromUtf8("lineEdit_passWord"));

        horizontalLayout_4->addWidget(lineEdit_passWord);

        horizontalLayout_4->setStretch(0, 3);
        horizontalLayout_4->setStretch(1, 7);

        verticalLayout->addLayout(horizontalLayout_4);


        horizontalLayout_5->addLayout(verticalLayout);

        horizontalLayout_5->setStretch(0, 3);
        horizontalLayout_5->setStretch(1, 7);

        gridLayout_4->addLayout(horizontalLayout_5, 0, 0, 1, 2);

        horizontalSpacer = new QSpacerItem(166, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pushButton_login = new QPushButton(widget_LogIn);
        pushButton_login->setObjectName(QString::fromUtf8("pushButton_login"));

        horizontalLayout_3->addWidget(pushButton_login);


        gridLayout_4->addLayout(horizontalLayout_3, 1, 1, 1, 1);


        verticalLayout_3->addWidget(widget_LogIn);

        widget_ChangePassWord = new QWidget(groupBox);
        widget_ChangePassWord->setObjectName(QString::fromUtf8("widget_ChangePassWord"));
        gridLayout_6 = new QGridLayout(widget_ChangePassWord);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_password_2 = new QLabel(widget_ChangePassWord);
        label_password_2->setObjectName(QString::fromUtf8("label_password_2"));

        gridLayout_3->addWidget(label_password_2, 0, 0, 1, 1);

        lineEdit_passWord2 = new QLineEdit(widget_ChangePassWord);
        lineEdit_passWord2->setObjectName(QString::fromUtf8("lineEdit_passWord2"));

        gridLayout_3->addWidget(lineEdit_passWord2, 0, 1, 1, 1);

        label_password_3 = new QLabel(widget_ChangePassWord);
        label_password_3->setObjectName(QString::fromUtf8("label_password_3"));

        gridLayout_3->addWidget(label_password_3, 1, 0, 1, 1);

        lineEdit_newPassWord = new QLineEdit(widget_ChangePassWord);
        lineEdit_newPassWord->setObjectName(QString::fromUtf8("lineEdit_newPassWord"));

        gridLayout_3->addWidget(lineEdit_newPassWord, 1, 1, 1, 1);


        gridLayout_6->addLayout(gridLayout_3, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        btnOK_changePassWrod = new QPushButton(widget_ChangePassWord);
        btnOK_changePassWrod->setObjectName(QString::fromUtf8("btnOK_changePassWrod"));

        horizontalLayout->addWidget(btnOK_changePassWrod);

        btnCancel_changePassWrod = new QPushButton(widget_ChangePassWord);
        btnCancel_changePassWrod->setObjectName(QString::fromUtf8("btnCancel_changePassWrod"));

        horizontalLayout->addWidget(btnCancel_changePassWrod);


        gridLayout_6->addLayout(horizontalLayout, 1, 0, 1, 1);


        verticalLayout_3->addWidget(widget_ChangePassWord);

        verticalLayout_3->setStretch(0, 1);
        verticalLayout_3->setStretch(1, 1);

        gridLayout->addLayout(verticalLayout_3, 0, 0, 1, 1);


        gridLayout_2->addWidget(groupBox, 0, 0, 1, 1);


        retranslateUi(UserWidget);

        QMetaObject::connectSlotsByName(UserWidget);
    } // setupUi

    void retranslateUi(QWidget *UserWidget)
    {
        UserWidget->setWindowTitle(QApplication::translate("UserWidget", "UserWidget", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        pushButton_image->setText(QString());
        label_user->setText(QApplication::translate("UserWidget", "User:", 0, QApplication::UnicodeUTF8));
        label_password->setText(QApplication::translate("UserWidget", "Password:", 0, QApplication::UnicodeUTF8));
        pushButton_login->setText(QApplication::translate("UserWidget", "Login", 0, QApplication::UnicodeUTF8));
        label_password_2->setText(QApplication::translate("UserWidget", "Password:", 0, QApplication::UnicodeUTF8));
        label_password_3->setText(QApplication::translate("UserWidget", "New Password:", 0, QApplication::UnicodeUTF8));
        btnOK_changePassWrod->setText(QApplication::translate("UserWidget", "OK", 0, QApplication::UnicodeUTF8));
        btnCancel_changePassWrod->setText(QApplication::translate("UserWidget", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class UserWidget: public Ui_UserWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERWIDGET_H
