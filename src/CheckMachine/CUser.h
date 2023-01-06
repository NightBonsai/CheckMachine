#ifndef CUSER_H
#define CUSER_H

#define ADMIN 0
#define CHECKMAN 1

	
//�û���Ϣ��	�����û���Ϣ�Ļ�����Ϣ��id,���֡����룬Ȩ�ޣ�
class User
{
public:
	User(char n[]="admin",char password[]="123456",int auth=ADMIN);
	~User();

	static int defaultID;	//Ĭ��id��ʵ��id����

	int getID();			//��ȡID
	char *getName();		//��ȡ�û���
	char *getPassword();	//��ȡ����
	int getAuthority();		//��ȡȨ��

	void printUserInfo();	//����û���Ϣ
private:
	int id;
	char name[15];
	char passWord[15];
	int authority;			//�û�Ȩ�ޣ�����Ա-0	�̵�Ա-1
};

#endif