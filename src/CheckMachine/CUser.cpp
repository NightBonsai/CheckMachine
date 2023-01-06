#pragma warning (disable : 4786)	//�������� ����
#include "CUser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include "CData.h"
using namespace std;

//��̬id��ʼ��
int User::defaultID=1001;


User::User(char n[],char password[],int auth)
{
	this->id=User::defaultID+Data::userMap.size();
	this->authority=auth;

	memset(this->name,0,15);			//memset�����ʼ��
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
	printf("�û���:%s\n",this->name);
	printf("����:%s\n",this->passWord);
	if(this->authority==0)
	{
		printf("Ȩ��:����Ա\n\n");
	}
	else if(this->authority==1)
	{	
		printf("Ȩ��:�̵�Ա\n\n");
	}
}
