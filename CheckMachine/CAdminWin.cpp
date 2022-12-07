#include "CAdminWin.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include "CTool.h"
#include "CLabel.h"
#include "CEdition.h"
#include "CButton.h"
#include "CWindow.h"
#include <time.h>
using namespace std;

AdminWin::AdminWin(int x,int y,int w,int h):Window(x,y,w,h) 
{
	this->title=new Label(25,3,LABEL,"��ӭʹ��HHS�̵��ϵͳ");
	this->welcome=new Label(5,5,LABEL,"��ӭ������Ա��");
	this->date=new Label(50,5,LABEL,"���ڣ�");
	this->cargoSearch=new Button(10,8,20,3,BUTTON,"��Ʒ��ѯ[1]");
	this->cargoLoad=new Button(40,8,20,3,BUTTON,"������Ʒ[2]");
	this->cargoInLib=new Button(10,13,20,3,BUTTON,"��Ʒ���[3]");
	this->cargoOutLib=new Button(40,13,20,3,BUTTON,"��Ʒ����[4]");
	this->cargoEdit=new Button(10,18,20,3,BUTTON,"�̵����[5]");
	this->exit=new Button(40,18,20,3,BUTTON,"�˳�����[Esc]");

	this->addCtrl(title);
	this->addCtrl(cargoSearch);		//1
	this->addCtrl(cargoLoad);		//2
	this->addCtrl(cargoInLib);		//3
	this->addCtrl(cargoOutLib);		//4
	this->addCtrl(cargoEdit);		//5
	this->addCtrl(exit);			//6
	this->addCtrl(welcome);			
	this->addCtrl(date);			
}
AdminWin::~AdminWin()
{}


void AdminWin::showWin()
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


int AdminWin::doAction()
{
	switch(this->ctrlIndex)
	{
	case 1:
		return 9; 
		break;
	case 3:
		return 5;
		break;
	case 4:
		return 7;
		break;
	case 5:
		return 12;
		break;
	case 6:
		return 0;
		break;
	}
}