#include "CSelectButton.h"
#include <iostream>
#include "CButton.h"
#include "CTool.h"
using namespace std;


SelectButton::SelectButton(int x,int y,int width,int height):Window(x,y,width,height)
{
	this->admin=new Button(x,y,width,height/2,BUTTON,"管理员");
	this->checkMan=new Button(x,y+height/2,width,height/2,BUTTON,"盘点员");

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

	//循环遍历下拉框每一层
	for(i=0;i<this->height;i++)
	{
		Ctools::gotoxy(this->startx,this->starty+i);
		//循环遍历下拉框每层的每个字符
		for(j=0;j<this->width;j++)
		{
			cout<<" ";
		}
	}
}