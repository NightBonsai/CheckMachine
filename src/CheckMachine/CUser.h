#ifndef CUSER_H
#define CUSER_H

#define ADMIN 0
#define CHECKMAN 1

	
//用户信息类	保存用户信息的基本信息（id,名字、密码，权限）
class User
{
public:
	User(char n[]="admin",char password[]="123456",int auth=ADMIN);
	~User();

	static int defaultID;	//默认id：实现id自增

	int getID();			//获取ID
	char *getName();		//获取用户名
	char *getPassword();	//获取密码
	int getAuthority();		//获取权限

	void printUserInfo();	//输出用户信息
private:
	int id;
	char name[15];
	char passWord[15];
	int authority;			//用户权限：管理员-0	盘点员-1
};

#endif