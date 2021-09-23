#ifndef STOOL_H
#define STOOL_H
#define HORIZONTAL24 sizeof(int)*24
#define HORIZONTAL4 sizeof(int)*4
enum StateEnum
{
	SENDDATA,//��������ģʽ
	GETSUCCESS,//�������ݳɹ�
	CLEAR,//��������ʧ��
	CONNECT,//�����������ӻ���
	LOCKSCREEN,
	ALERT,//�������ͱ���
	SEVERS,//������
	IMAGE,//��ʾͼ�����
	NLEADING,
	NCLAMPING,
	NBACKING,
	MAININTERFACE,
	SYSTEMMODEADD,
	SYSTEMMODESELECT,
	SYSTEMMODEDELTE
};
enum UnitEnum
{
	LEADING, //ǰ��
	CLAMPING,//�г�
	BACKING//���
};
struct IpStruct
{
	QString ipAddress; //ip��ַ
	int startTime; //ʱ�䣬�����ж��Ƿ����������ж�
	bool nstate; //Ŀǰ����״̬
};
struct MyErrorType
{
	int id;
	int nType;
	int nErrorArea;
};
struct MyStruct
{
	StateEnum nState;//����״̬��־λ
	UnitEnum nUnit;//���͵��豸��־λ
	int nCount;//ǰ��ͨ��in0�õ��Ĺ�������
	int nFail;//ǰ��ͨ��out3�õ����߷�����
	QString nTemp;//ǰ�˵Ķ������
};
#endif