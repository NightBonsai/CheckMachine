#pragma warning (disable : 4786)	//�������� ����
#include "CRegistWin.h"
#include <iostream>
#include <string>
#include "CTool.h"
#include "CLabel.h"
#include "CEdition.h"
#include "CButton.h"
#include "CWindow.h"
#include "CUser.h"
#include "CData.h"
#include "CSelectButton.h"
using namespace std;


int RegistWin::presentAuthority=ADMIN;


RegistWin::RegistWin(int x,int y,int w,int h):Window(x,y,w,h)
{
	int id=User::defaultID+Data::userMap.size();
	this->title=new Label(30,3,LABEL,"�û�ע��");
	this->userid=new Label(20,6,LABEL,"�û�id");
	this->username=new Label(20,9,LABEL,"����");
	this->password=new Label(20,12,LABEL,"����");
	this->confirmPassword=new Label(20,15,LABEL,"ȷ������");
	this->edition1=new Edition(30,8,25,3,EDITION,3,20,1,"");	//�û����༭��
	this->edition2=new Edition(30,11,25,3,EDITION,0,20,0,"");	//����༭��
	this->edition3=new Edition(30,14,25,3,EDITION,0,20,0,"");	//ȷ������༭��
	this->select=new Button(32,17,20,3,BUTTON,"�û�Ȩ�� |��");
	this->regist=new Button(20,25,18,3,BUTTON,"ע��[Regist]");
	this->exit=new Button(40,25,18,3,BUTTON,"�˳�[Esc]");

	this->addCtrl(title);
	this->addCtrl(userid);
	this->addCtrl(username);
	this->addCtrl(password);
	this->addCtrl(confirmPassword);	
	this->addCtrl(edition1);		//5
	this->addCtrl(edition2);		//6
	this->addCtrl(edition3);		//7
	this->addCtrl(select);			//8
	this->addCtrl(regist);			//9
	this->addCtrl(exit);			//10
}
RegistWin::~RegistWin()
{}


void RegistWin::showWin()
{
	//��������������
	this->select->editContent("�û�Ȩ�� |��");

	Window::showWin();

	//���Ĭ���˺�id(ϵͳ�ڶ�)
	Ctools::gotoxy(32,6);
	cout<<User::defaultID+Data::userMap.size();
}


int RegistWin::doAction()		//1
{
	switch(this->ctrlIndex)
	{
	case 8:
		{
			//������ʵ��
			//���������
			//���������򷵻���ֵ���о������ 0-����Ա	1-�̵�Ա
			SelectButton *registSelect=new SelectButton(52,17,8,6);
			registSelect->showWin();
			RegistWin::presentAuthority=registSelect->winRun();
			
			if(RegistWin::presentAuthority==ADMIN)
			{
				this->CtrlArr[8]->editContent("����Ա |��");
				this->CtrlArr[8]->show();
				registSelect->clearSelectButton();
				return this->winRun();		
			}
			else if(RegistWin::presentAuthority==CHECKMAN)
			{
				this->CtrlArr[8]->editContent("�̵�Ա |��");
				this->CtrlArr[8]->show();
				registSelect->clearSelectButton();
				return this->winRun();
			}
		}
		break;
	case 9:
		return this->regJudge();
		break;
	case 10:
		return 0;
		break;
	}
	return 0;
}


int RegistWin::regJudge()
{
	map<int,User*>::iterator it;

	//��Ϊ���ж�
	if(strcmp(this->edition1->getContent(),"")==0 || strcmp(this->edition2->getContent(),"")==0 || strcmp(this->edition3->getContent(),"")==0)
	{
		//��ʾ������Ϊ��
		Ctools::gotoxy(30,22);
		cout<<"               ";
		Ctools::gotoxy(30,22);
		cout<<"������Ϊ��";
		system("pause");
		return 2;
	}
	for(it=Data::userMap.begin();it!=Data::userMap.end();it++)
	{
		//���û�������
		if(strcmp(this->edition1->getContent(),it->second->getName())==0)
		{
			//��ʾ�û����Ѵ���
			Ctools::gotoxy(30,22);
			cout<<"               ";
			Ctools::gotoxy(30,22);
			cout<<"�û����Ѵ���";
			system("pause");
			return 2;
		}		
	}
	//���û���������
	//���û������ȷ���Ҫ��
	if(strlen(this->edition1->getContent())>=2 && strlen(this->edition1->getContent())<=10)
	{
		//�����볤�ȷ���Ҫ��
		if(strlen(this->edition2->getContent())>=6 && strlen(this->edition2->getContent())<=10)
		{
			//������������ͬ
			if(strcmp(this->edition2->getContent(),this->edition3->getContent())==0)
			{
				//����ǰ��ѡ���û�Ȩ��
				if(strcmp(this->select->getContent(),"�û�Ȩ�� |��")!=0 )
				{
					//����ע��
					Data::userRegist(this->CtrlArr[5]->getContent(),this->CtrlArr[6]->getContent(),RegistWin::presentAuthority);
					//��ʾע��ɹ�
					Ctools::gotoxy(30,22);
					cout<<"               ";
					Ctools::gotoxy(30,22);
					cout<<"ע��ɹ�";
					system("pause");
					
					return 1;
				}
				else
				{
					//��ʾ������Ϊ��
					Ctools::gotoxy(30,22);
					cout<<"                ";
					Ctools::gotoxy(30,22);
					cout<<"��δѡ���û�Ȩ��";
					system("pause");
					return 2;
				}
			}
			//���������벻ͬ
			else
			{
				//��ʾ�����������벻һ��
				Ctools::gotoxy(30,22);
				cout<<"               ";
				Ctools::gotoxy(30,22);
				cout<<"�������벻һ��";
				system("pause");
				return 2;
			}	
		}
		//�����볤�Ȳ�����Ҫ��
		else
		{
			//��ʾ���볤�Ȳ�����Ҫ��
			Ctools::gotoxy(30,22);
			cout<<"                ";
			Ctools::gotoxy(30,22);
			cout<<"���볤�Ȳ���Ҫ��";
			system("pause");
			return 2;
		}
	}
	//���û������Ȳ�����Ҫ��
	else
	{
		//��ʾ�û������Ȳ�����Ҫ��
		Ctools::gotoxy(30,22);
		cout<<"                  ";
		Ctools::gotoxy(30,22);
		cout<<"�û������Ȳ���Ҫ��";
		system("pause");
		return 2;
	}
}
