#include "CSelectButton.h"
#include <iostream>
#include "CButton.h"
#include "CTool.h"
using namespace std;


SelectButton::SelectButton(int x,int y,int width,int height):Window(x,y,width,height)
{
	this->admin=new Button(x,y,width,height/2,BUTTON,"����Ա");
	this->checkMan=new Button(x,y+height/2,width,height/2,BUTTON,"�̵�Ա");

	this->addCtrl(admin);
	this->addCtrl(checkMan);
}
SelectButton::~SelectButton()
{}


int SelectButton::doAction()
{
	if(this->ctrlIndex==0)
	{
		return 0;
	}
	else if(this->ctrlIndex==1)
	{
		return 1;
	}
	return 0;
}


void SelectButton::clearSelectButton()
{
	int i,j;

	//ѭ������������ÿһ��
	for(i=0;i<this->height;i++)
	{
		Ctools::gotoxy(this->startx,this->starty+i);
		//ѭ������������ÿ���ÿ���ַ�
		for(j=0;j<this->width;j++)
		{
			cout<<" ";
		}
	}
}