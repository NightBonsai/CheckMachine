#pragma warning (disable : 4786)	//�������� ����
#include "CLogWin.h"
#include <string>
#include <iostream>
#include <map>
#include "CTool.h"
#include "CLabel.h"
#include "CEdition.h"
#include "CButton.h"
#include "CWindow.h"
#include "CUser.h"
#include "CData.h"
using namespace std;


LogWin::LogWin(int x,int y,int w,int h):Window(x,y,w,h)
{
	//int w=70,int h=30
	this->title=new Label(30,3,LABEL,"�û���¼");
	this->username=new Label(20,10,LABEL,"�û�id");
	this->password=new Label(20,15,LABEL,"����");
	this->edition1=new Edition(30,9,25,3,EDITION,2,20,1,"");
	this->edition2=new Edition(30,14,25,3,EDITION,2,20,0,"");
	this->log=new Button(20,20,18,3,BUTTON,"��¼[Enter]");
	this->exit=new Button(40,20,18,3,BUTTON,"�˳�[Esc]");

	this->addCtrl(title);
	this->addCtrl(username);
	this->addCtrl(password);
	this->addCtrl(edition1);	//3
	this->addCtrl(edition2);	//4
	this->addCtrl(log);			//5
	this->addCtrl(exit);		//6
}
LogWin::~LogWin()
{
	for(int i;i<this->ctrlCount;i++)
	{
		delete this->CtrlArr[i];
	}
}


int LogWin::logJudge()
{
	int z=0;
	
	map<int,User*>::iterator it;

	int id=atoi(this->edition1->getContent());		//���û����༭�����ַ���ת��Ϊ����
	it=Data::userMap.find(id);						//��������ȡfind���صļ�ֵ��
	
	//���˺�or����༭��Ϊ��(��Ϊ���ж�)
	if(strcmp(this->edition1->getContent(),"")==0 || strcmp(this->edition2->getContent(),"")==0)
	{
		Ctools::gotoxy(15,26);
		printf("�û���or���벻��Ϊ��\n");
		system("pause");
		return 1;
	}
	//���û���������
	else if(it==Data::userMap.end())
	{
		Ctools::gotoxy(15,26);
		cout<<"�û���������"<<endl;
		system("pause");
		return 1;
	}
	else
	{
		//������ƥ��
		if( strcmp(this->edition2->getContent(),it->second->getPassword())==0 )
		{
			Ctools::gotoxy(15,26);
			printf("��¼�ɹ�\n");
			system("pause");

			//���û���ƥ���Ҹ��û�Ȩ��Ϊ���̵�Ա������Ա
			if(it->second->getAuthority()==ADMIN)
			{
				Ctools::presentUser=it->second;
				return 3;	
			}
			else if(it->second->getAuthority()==CHECKMAN)
			{
				Ctools::presentUser=it->second;
				return 4;
			}
		}
		else
		{
			Ctools::gotoxy(15,26);
			printf("�û���or�������\n");
			system("pause");
			return 1;
		}
	}
}



int LogWin::doAction()
{
	int i;

	if(this->ctrlIndex==5)
	{
		i=this->logJudge();
		return i;
	}
	else if(this->ctrlIndex==6)
	{
		return 0;
	}
}
