#pragma warning (disable : 4786)	//命名过长 容器
#include "CUser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include "CData.h"
using namespace std;

//静态id初始化
int User::defaultID=1001;


User::User(char n[],char password[],int auth)
{
	this->id=User::defaultID+Data::userMap.size();
	this->authority=auth;

	memset(this->name,0,15);			//memset数组初始化
	memset(this->passWord,0,15);

	strcpy(this->name,n);
	strcpy(this->passWord,password);
}
User::~User()
{
}


int User::getID()
{
	return this->id;
}
char *User::getName()
{
	return this->name;
}
char *User::getPassword()
{
	return this->passWord;
}
int User::getAuthority()
{
	return this->authority;
}


void User::printUserInfo()
{
	printf("id:%d\n",this->id);
	printf("用户名:%s\n",this->name);
	printf("密码:%s\n",this->passWord);
	if(this->authority==0)
	{
		printf("权限:管理员\n\n");
	}
	else if(this->authority==1)
	{	
		printf("权限:盘点员\n\n");
	}
}
