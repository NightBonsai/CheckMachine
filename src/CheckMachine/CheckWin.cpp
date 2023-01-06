#include "CheckWin.h"
#include <string>
#include <iostream>
#include "CTool.h"
#include "CLabel.h"
#include "CEdition.h"
#include "CButton.h"
#include "CWindow.h"
using namespace std;


CheckWin::CheckWin(int x,int y,int w,int h):Window(x,y,w,h) 
{
	//int w=70,int h=30
	this->title=new Label(25,3,LABEL,"欢迎使用HHS盘点机系统");
	this->welcome=new Label(5,5,LABEL,"欢迎：盘点员");
	this->date=new Label(50,5,LABEL,"日期：");
	this->cargoSearch=new Button(10,8,20,3,BUTTON,"商品查询[1]");
	this->LibCheck=new Button(40,8,20,3,BUTTON,"仓库盘点[2]");
	this->exit=new Button(10,13,20,3,BUTTON,"退出程序[3]");

	this->addCtrl(title);
	this->addCtrl(cargoSearch);		//1
	this->addCtrl(LibCheck);		//2
	this->addCtrl(exit);			//3
	this->addCtrl(welcome);
	this->addCtrl(date);
}
CheckWin::~CheckWin()
{}


void CheckWin::showWin()
{
	Window::showWin();

	//输出当下登录用户信息&日期
	Ctools::gotoxy(20,5);
	cout<<Ctools::presentUser->getName();
	Ctools::gotoxy(58,5);
	char timedate[64]={0};
	Ctools::getTime(timedate);
	cout<<timedate;
}


int CheckWin::doAction()
{
	switch(this->ctrlIndex)
	{
	case 1:
		return 9;
		break;
	case 2:
		return 10;
		break;
	case 3:
		return 0;
		break;
	}
}
