#pragma warning (disable : 4786)	//命名过长 容器
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
	this->title=new Label(30,3,LABEL,"用户注册");
	this->userid=new Label(20,6,LABEL,"用户id");
	this->username=new Label(20,9,LABEL,"姓名");
	this->password=new Label(20,12,LABEL,"密码");
	this->confirmPassword=new Label(20,15,LABEL,"确认密码");
	this->edition1=new Edition(30,8,25,3,EDITION,3,20,1,"");	//用户名编辑框
	this->edition2=new Edition(30,11,25,3,EDITION,0,20,0,"");	//密码编辑框
	this->edition3=new Edition(30,14,25,3,EDITION,0,20,0,"");	//确认密码编辑框
	this->select=new Button(32,17,20,3,BUTTON,"用户权限 |▽");
	this->regist=new Button(20,25,18,3,BUTTON,"注册[Regist]");
	this->exit=new Button(40,25,18,3,BUTTON,"退出[Esc]");

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
	//重置下拉框内容
	this->select->editContent("用户权限 |▽");

	Window::showWin();

	//输出默认账号id(系统内定)
	Ctools::gotoxy(32,6);
	cout<<User::defaultID+Data::userMap.size();
}


int RegistWin::doAction()		//1
{
	switch(this->ctrlIndex)
	{
	case 8:
		{
			//下拉框实现
			//输出下拉框
			//根据下拉框返回数值进行具体操作 0-管理员	1-盘点员
			SelectButton *registSelect=new SelectButton(52,17,8,6);
			registSelect->showWin();
			RegistWin::presentAuthority=registSelect->winRun();
			
			if(RegistWin::presentAuthority==ADMIN)
			{
				this->CtrlArr[8]->editContent("管理员 |▽");
				this->CtrlArr[8]->show();
				registSelect->clearSelectButton();
				return this->winRun();		
			}
			else if(RegistWin::presentAuthority==CHECKMAN)
			{
				this->CtrlArr[8]->editContent("盘点员 |▽");
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

	//表单为空判断
	if(strcmp(this->edition1->getContent(),"")==0 || strcmp(this->edition2->getContent(),"")==0 || strcmp(this->edition3->getContent(),"")==0)
	{
		//提示表单不能为空
		Ctools::gotoxy(30,22);
		cout<<"               ";
		Ctools::gotoxy(30,22);
		cout<<"表单不能为空";
		system("pause");
		return 2;
	}
	for(it=Data::userMap.begin();it!=Data::userMap.end();it++)
	{
		//若用户名存在
		if(strcmp(this->edition1->getContent(),it->second->getName())==0)
		{
			//提示用户名已存在
			Ctools::gotoxy(30,22);
			cout<<"               ";
			Ctools::gotoxy(30,22);
			cout<<"用户名已存在";
			system("pause");
			return 2;
		}		
	}
	//若用户名不存在
	//若用户名长度符合要求
	if(strlen(this->edition1->getContent())>=2 && strlen(this->edition1->getContent())<=10)
	{
		//若密码长度符合要求
		if(strlen(this->edition2->getContent())>=6 && strlen(this->edition2->getContent())<=10)
		{
			//若两次密码相同
			if(strcmp(this->edition2->getContent(),this->edition3->getContent())==0)
			{
				//若当前已选择用户权限
				if(strcmp(this->select->getContent(),"用户权限 |▽")!=0 )
				{
					//进行注册
					Data::userRegist(this->CtrlArr[5]->getContent(),this->CtrlArr[6]->getContent(),RegistWin::presentAuthority);
					//提示注册成功
					Ctools::gotoxy(30,22);
					cout<<"               ";
					Ctools::gotoxy(30,22);
					cout<<"注册成功";
					system("pause");
					
					return 1;
				}
				else
				{
					//提示表单不能为空
					Ctools::gotoxy(30,22);
					cout<<"                ";
					Ctools::gotoxy(30,22);
					cout<<"尚未选择用户权限";
					system("pause");
					return 2;
				}
			}
			//若两次密码不同
			else
			{
				//提示两次输入密码不一致
				Ctools::gotoxy(30,22);
				cout<<"               ";
				Ctools::gotoxy(30,22);
				cout<<"输入密码不一致";
				system("pause");
				return 2;
			}	
		}
		//若密码长度不符合要求
		else
		{
			//提示密码长度不符合要求
			Ctools::gotoxy(30,22);
			cout<<"                ";
			Ctools::gotoxy(30,22);
			cout<<"密码长度不合要求";
			system("pause");
			return 2;
		}
	}
	//若用户名长度不符合要求
	else
	{
		//提示用户名长度不符合要求
		Ctools::gotoxy(30,22);
		cout<<"                  ";
		Ctools::gotoxy(30,22);
		cout<<"用户名长度不合要求";
		system("pause");
		return 2;
	}
}
