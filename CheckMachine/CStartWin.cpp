#pragma warning (disable : 4786)	//命名过长 容器
#include "CStartWin.h"
#include "CTool.h"
#include "CLabel.h"
#include "CEdition.h"
#include "CButton.h"
#include "CWindow.h"


StartWin::StartWin(int x,int y,int w,int h):Window(x,y,w,h)
{
	//int w=70,int h=30
	this->title=new Label(25,3,LABEL,"HyperHorizonS盘点机项目");
	this->log=new Button(18,8,30,3,BUTTON,"登录[1]");
	this->regist=new Button(18,13,30,3,BUTTON,"注册[2]");
	this->exit=new Button(18,18,30,3,BUTTON,"退出[3]");
	this->copyRightID=new Label(60,28,LABEL,"OMO220715");

	this->addCtrl(title);		
	this->addCtrl(log);			//1
	this->addCtrl(regist);		//2
	this->addCtrl(exit);		//3
	this->addCtrl(copyRightID);
}
StartWin::~StartWin()
{}


int StartWin::doAction()
{
	int i;
	char x;

	while(true)
	{
		//若控件下标为1
		if(this->ctrlIndex==1)
		{
			return 1;			//登录界面
		}
		//若控件下标为2
		else if(this->ctrlIndex==2)
		{
			return 2;			//注册界面
		}
		//若控件下标为3
		else if(this->ctrlIndex==3)
		{
			ConfirmWin *b=new ConfirmWin;
			b->showWin();
			return b->winRun();
		}
		else 
		{
			break;
		}
	}
}


 
ConfirmWin::ConfirmWin(int x,int y,int w,int h):Window(x,y,w,h)
{
	//int x=20,int y=10,int w=30,int h=10
	this->title=new Label(30,12,LABEL,"是否退出系统");
	this->yes=new Button(25,16,8,3,BUTTON,"是");
	this->no=new Button(35,16,8,3,BUTTON,"否");

	this->addCtrl(title);
	this->addCtrl(yes);
	this->addCtrl(no);
}
ConfirmWin::~ConfirmWin()
{}


int ConfirmWin::doAction()
{
	switch(this->ctrlIndex)
	{
	case 1:
		exit(0);
		break;
	case 2:
		return 0;
	}
}