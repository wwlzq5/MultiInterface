#include "widgetUser.h"
#include <QSettings>
UserWidget::UserWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint);
	setWindowIcon(QIcon("./Resources/LOGO.png"));
	ui.lineEdit_passWord->setEchoMode(QLineEdit::Password); 
	ui.lineEdit_passWord2->setEchoMode(QLineEdit::Password); 
	ui.lineEdit_newPassWord->setEchoMode(QLineEdit::Password); 
	ui.pushButton_login->setShortcut( QKeySequence::InsertParagraphSeparator );
	nPermission = 3;
	iUserPerm = true;
	initial();
	QPixmap pixmap = QPixmap(":/MultiInterface/NOLOGIN");
	ui.pushButton_image->setPixmap(pixmap);
	ui.groupBox->setStyleSheet("QGroupBox{background:transparent;border:2px solid blue}");
	setFixedSize(350,250);
	ShowInterfance();
}

UserWidget::~UserWidget()
{
	//close();
}
void UserWidget::ShowInterfance()
{
	if(iUserPerm)
	{
		setWindowModality(Qt::ApplicationModal);
		show();
		iUserPerm = false;
	}
}
void UserWidget::initial()
{
	ui.widget_ChangePassWord->setVisible(false);
	QFont fontStatus;
	fontStatus.setPixelSize(22);
	connect(ui.pushButton_image,SIGNAL(clicked()),this,SLOT(slots_loginChangePassWrod()));
	connect(ui.pushButton_login,SIGNAL(clicked()),this,SLOT(slots_login()));
	connect(ui.btnOK_changePassWrod,SIGNAL(clicked()),this,SLOT(slots_changePassWrod()));
	connect(ui.btnCancel_changePassWrod,SIGNAL(clicked()),this,SLOT(slots_CancelchangePassWrod()));
	initialUserInfo();
}
void UserWidget::initialUserInfo()
{
	QSettings sysSet("daheng","GlasswareDetectSystem");
	QString strUsers = sysSet.value("Users","").toString();
	strUserList = strUsers.split(",");
	QString strPassword = sysSet.value("Password","").toString();
	strPasswordList = strPassword.split(",");
	QString strPermissions = sysSet.value("Permissions","").toString();
	QStringList strPermissionsList = strPermissions.split(",");
	nPermissionsList.clear();
	for (int i=0;i<strPermissionsList.size();i++)
	{
		nPermissionsList.append(strPermissionsList.at(i).toInt());
	}
	strUserList.removeAt(strPermissionsList.size()-1);
	strPasswordList.removeAt(strPermissionsList.size()-1);
	strPermissionsList.removeAt(strPermissionsList.size()-1);
	nPermissionsList.removeAt(nPermissionsList.size()-1);

	int iUserNumber = strUserList.size();
	//用户数为零增加2个用户
	if (0 == iUserNumber)
	{
		strUserList.append("Admin");
		strUserList.append("daheng");
		strUserList.append("kongping");
		strPasswordList.append("daheng");
		strPasswordList.append("");
		strPasswordList.append("");
		nPermissionsList.append(0x01FF);
		nPermissionsList.append(0x00FF);
		nPermissionsList.append(0x00FF);
		//保存到注册表
		QString strUsers;
		QString strPassword;
		QString strPermissions;
		for (int i = 0;i<nPermissionsList.size();i++)
		{
			strUsers = strUsers + strUserList.at(i) + ",";
			strPassword = strPassword + strPasswordList.at(i) + ",";
			strPermissions = strPermissions + QString::number(nPermissionsList.at(i)) + ",";
		}
		QSettings sysSet("daheng","GlasswareDetectSystem");
		sysSet.setValue("Users",strUsers);
		sysSet.setValue("Password",strPassword);
		sysSet.setValue("Permissions",strPermissions);
	}
	iUserNumber =  strUserList.size();

	listUser.clear();
	ui.comboBoxUser->clear();
	for (int i = 0;i<iUserNumber;i++)
	{
		QString strUserName = strUserList.at(i);
		listUser.append(strUserName);
		ui.comboBoxUser->addItem(strUserName);
	}
	ui.comboBoxUser->setCurrentIndex(strUserList.size()-1);
}
void UserWidget::slots_login()
{
	int nUser = ui.comboBoxUser->currentIndex();
	strUserName = strUserList.at(nUser);
	strPassWordUser = strPasswordList.at(nUser);
	PassWord = ui.lineEdit_passWord->text();
	
	if (strPassWordUser != PassWord)
	{
		QMessageBox::information(this,tr("Error"),tr("Wrong password"));
		return;
	}
	ui.lineEdit_passWord->clear();
	hide();
	iUserPerm = true;
	if(strUserName == "Admin")
	{
		nPermission = 1;
	}else if(strUserName == "daheng")
	{
		nPermission = 2;
	}else{
		nPermission = 3;
	}
	emit signal_LoginState(nPermission);
}
void UserWidget::slots_changePassWrod()
{
	bool setSuccess = false;
	PassWord = ui.lineEdit_passWord2->text();
	QString newPassWord = ui.lineEdit_newPassWord->text();
	int nUser = ui.comboBoxUser->currentIndex();
	strUserName = strUserList.at(nUser);
	strPassWordUser = strPasswordList.at(nUser);
	if(strPassWordUser == PassWord && newPassWord!=PassWord)
	{
		QString strUsers;
		QString strPassword;
		QString strPermissions;
		for (int i = 0;i<nPermissionsList.size();i++)
		{
			strUsers = strUsers + strUserList.at(i) + ",";
			if(strUserList.at(i) == strUserName)
			{
				strPassword = strPassword + newPassWord + ",";
			}else{
				strPassword = strPassword + strPasswordList.at(i) + ",";
			}
			strPermissions = strPermissions + QString::number(nPermissionsList.at(i)) + ",";
		}
		QSettings sysSet("daheng","GlasswareDetectSystem");
		sysSet.setValue("Users",strUsers);
		sysSet.setValue("Password",strPassword);
		sysSet.setValue("Permissions",strPermissions);
		initialUserInfo();
		setSuccess = true;
		QMessageBox::information(this,tr("Information"),tr("The new password set successfully"));
	}else
	{
		QMessageBox::information(this,tr("Error"),tr("Wrong password"));
	}
	ui.lineEdit_newPassWord->clear();
	if (setSuccess)
	{
		ui.widget_LogIn->setVisible(true);
		ui.widget_ChangePassWord->setVisible(false);
	}
}
void UserWidget::slots_CancelchangePassWrod()
{
	ui.widget_LogIn->setVisible(true);
	ui.widget_ChangePassWord->setVisible(false);
}
void UserWidget::slots_loginChangePassWrod()
{
	ui.widget_LogIn->setVisible(false);
	ui.widget_ChangePassWord->setVisible(true);
}
