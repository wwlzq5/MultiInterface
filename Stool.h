#ifndef STOOL_H
#define STOOL_H


#define HORIZONTAL24 sizeof(int)*24
#define HORIZONTAL4 sizeof(int)*4



//#define IP1 "192.168.250.201"
//#define IP2 "192.168.20.101"
//#define IP3 "192.168.250.203"

#define IP1 "192.168.250.201"
#define IP2 "192.168.250.202"
#define IP3 "192.168.250.203"

#define PASSWORD "123456"

enum StateEnum
{
	SENDDATA,//发送数据模式
	GETSUCCESS,//接受数据成功
	CLEAR,//接受数据失败
	CONNECT,//心跳包，连接机制
	LOCKSCREEN,
	ALERT,//单个类型报错
	SEVERS,//服务器
	IMAGE,//显示图像界面
	NLEADING,
	NCLAMPING,
	NBACKING,
	MAININTERFACE,
	SYSTEMMODEADD,
	SYSTEMMODESELECT,
	SYSTEMMODEDELTE,
	ONLYSHOWSEVER,
	FRONTSTATE
};
enum UnitEnum
{
	LEADING, //前端
	CLAMPING,//夹持
	BACKING//后端
};

enum SaveReportType
{
	ByTime,		//按整点时间
	ByShift		//按班次
};

struct IpStruct
{
	QString ipAddress; //ip地址
	int startTime; //时间，用于判断是否网络连接中断
	bool nstate; //目前连接状态
};
struct MyErrorType
{
	int id;
	int nType;
	int nErrorArea;
};
struct MyStruct
{
	StateEnum nState;//发送状态标志位
	UnitEnum nUnit;//发送的设备标志位
	int nCount;//数据大小
	int nCheckNum;//前端通过in0得到的过检总数
	int nFail;//前端通过out3得到的踢废总数
	char nTemp[256];//前端的多余变量
};

typedef struct _ErrorInfo
{
	int	iErrorTypeCount;					
	QList<QString> iErrorType;
}s_ErrorInfo;

#endif