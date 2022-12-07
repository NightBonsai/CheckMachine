#include "CargoInLibMenu.h"
#include <iostream>
#include <string>
#include "CTool.h"
#include "CLabel.h"
#include "CEdition.h"
#include "CButton.h"
#include "CWindow.h"
using namespace std;


CargoInLibMenu::CargoInLibMenu(int x,int y,int w,int h):Window(x,y,w,h) 
{
	this->title=new Label(25,3,LABEL,"欢迎使用HHS盘点机系统");
	this->welcome=new Label(5,5,LABEL,"欢迎：管理员，");
	this->date=new Label(50,5,LABEL,"日期：");
	this->inLib=new Button(10,8,20,3,BUTTON,"入库[1]");
	this->inLibRecord=new Button(40,8,20,3,BUTTON,"入库记录[2]");
	this->back=new Button(10,13,20,3,BUTTON,"返回[Esc]");

	this->addCtrl(title);
	this->addCtrl(inLib);			//1
	this->addCtrl(inLibRecord);		//2
	this->addCtrl(back);			//3
	this->addCtrl(welcome);			
	this->addCtrl(date);			
}
CargoInLibMenu::~CargoInLibMenu()
{}


void CargoInLibMenu::showWin()
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


int CargoInLibMenu::doAction()
{
	switch(this->ctrlIndex)
	{
	case 1:
		return 6;
		break;
	case 2:
		return 5;
		break;
	case 3:
		return 3;
		break;
	}
}
