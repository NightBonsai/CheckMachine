#include "CWindow.h"
#include <iostream>
#include <string.h>
#include <conio.h>
#include "CTool.h"
#include "CtrlBase.h"
#include "CLabel.h"
#include "CEdition.h"
#include "CButton.h"
using namespace std;


int Window::getCtrlCount()
{
	return this->ctrlCount;
}
int Window::getCtrlIndex()
{
	return this->ctrlIndex;
}


Window::Window(int x,int y,int w,int h,int count,int index)
{
	this->startx=x;
	this->starty=y;
	this->width=w;
	this->height=h;
	this->ctrlCount=count;
	this->ctrlIndex=index;
	for(int i=0;i<20;i++)
	{
		this->CtrlArr[i]=NULL;
	}
}
Window::~Window()
{
	for(int i;i<this->ctrlCount;i++)
	{
		delete this->CtrlArr[i];
	}
}


void Window::showWin()
{
	Ctools::printWindow(this->startx,this->starty,this->width,this->height);

	for(int i=0;i<this->ctrlCount;i++)
	{
		this->CtrlArr[i]->show();
	}
}


void Window::addCtrl(CtrlBase *ctrl)
{
	this->CtrlArr[this->ctrlCount]=ctrl;
	this->ctrlCount++;
}


int Window::winRun()
{
	int i;

	//找到第一个运行光标定位（编辑框or按钮）
	for(i=0;i<this->ctrlCount;i++)
	{
		if(this->CtrlArr[i]->getCtrlType()==EDITION || this->CtrlArr[i]->getCtrlType()==BUTTON)
		{
			Ctools::gotoxy(this->CtrlArr[i]->getStartx()+2,this->CtrlArr[i]->getStarty()+this->CtrlArr[i]->getHeight()/3);
			break;
		}
	}

	char c1,c2,x;
	
	//实现键盘监听
	while(true)
	{
		c1=getch();

		//若输入方向键
		if(c1==-32)
		{
			c2=getch();		
			//若按键盘"↑"键
			if(c2==KEY_UP)
			{
				while(1)
				{
					i--;
					if(i==-1){i=this->ctrlCount-1;}
					//找到上一个编辑框or按钮才停止
					if(this->CtrlArr[i]->getCtrlType()==EDITION)
					{
						Ctools::gotoxy(this->CtrlArr[i]->getStartx()+2+strlen(this->CtrlArr[i]->getContent()),
							this->CtrlArr[i]->getStarty()+this->CtrlArr[i]->getHeight()/3);
						break;
					}
					else if( this->CtrlArr[i]->getCtrlType()==BUTTON)
					{
						Ctools::gotoxy(this->CtrlArr[i]->getStartx()+2,
							this->CtrlArr[i]->getStarty()+this->CtrlArr[i]->getHeight()/3);
						break;
					}
				}	
			}
			//若按键盘"↓"键
			else if(c2==KEY_DOWN)
			{
				while(1)
				{
					i++;
					if(i==this->ctrlCount){i=0;}
					//找到下一个编辑框or按钮才停止
					if(this->CtrlArr[i]->getCtrlType()==EDITION)
					{
						Ctools::gotoxy(this->CtrlArr[i]->getStartx()+2+strlen(this->CtrlArr[i]->getContent()),
							this->CtrlArr[i]->getStarty()+this->CtrlArr[i]->getHeight()/3);
						break;
					}
					else if( this->CtrlArr[i]->getCtrlType()==BUTTON)
					{
						Ctools::gotoxy(this->CtrlArr[i]->getStartx()+2,
							this->CtrlArr[i]->getStarty()+this->CtrlArr[i]->getHeight()/3);
						break;
					}
				}
			}
		}
		//若输入回车键且当前控件为按钮
		else if(c1=='\r' && this->CtrlArr[i]->getCtrlType()==BUTTON)
		{
			//需要记录当前选择的控件下标，代表具体的button
			this->ctrlIndex=i;
			return this->doAction();
		}
		//若输入其他字符且为编辑框
		else
		{
			x=c1;

			if(this->CtrlArr[i]->getCtrlType()==EDITION)
			{
				this->CtrlArr[i]->editKeyListen(x);
			}			
		}
	}
}
