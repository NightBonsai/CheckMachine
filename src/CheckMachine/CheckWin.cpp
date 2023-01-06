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
	this->title=new Label(25,3,LABEL,"��ӭʹ��HHS�̵��ϵͳ");
	this->welcome=new Label(5,5,LABEL,"��ӭ���̵�Ա");
	this->date=new Label(50,5,LABEL,"���ڣ�");
	this->cargoSearch=new Button(10,8,20,3,BUTTON,"��Ʒ��ѯ[1]");
	this->LibCheck=new Button(40,8,20,3,BUTTON,"�ֿ��̵�[2]");
	this->exit=new Button(10,13,20,3,BUTTON,"�˳�����[3]");

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

	//������µ�¼�û���Ϣ&����
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
