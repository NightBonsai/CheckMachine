#include "CargoCheckMenu.h"
#include <iostream>
#include <string>
#include "CTool.h"
#include "CLabel.h"
#include "CEdition.h"
#include "CButton.h"
#include "CWindow.h"
using namespace std;


CargoCheckMenu::CargoCheckMenu(int x,int y,int w,int h):Window(x,y,w,h) 
{
	this->title=new Label(25,3,LABEL,"��ӭʹ��HHS�̵��ϵͳ");
	this->welcome=new Label(5,5,LABEL,"��ӭ���̵�Ա��");
	this->date=new Label(50,5,LABEL,"���ڣ�");
	this->newCheck=new Button(10,8,20,3,BUTTON,"�½��̵�[1]");
	this->checkRecord=new Button(40,8,20,3,BUTTON,"�̵��¼[2]");
	this->back=new Button(10,13,20,3,BUTTON,"����[Esc]");

	this->addCtrl(title);
	this->addCtrl(newCheck);		//1
	this->addCtrl(checkRecord);		//2
	this->addCtrl(back);			//3
	this->addCtrl(welcome);			
	this->addCtrl(date);			
}
CargoCheckMenu::~CargoCheckMenu()
{}


void CargoCheckMenu::showWin()
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


int CargoCheckMenu::doAction()
{
	switch(this->ctrlIndex)
	{
	case 1:
		return 11;
		break;
	case 2:
		return 12;
		break;
	case 3:
		return 4;
		break;
	}
}


