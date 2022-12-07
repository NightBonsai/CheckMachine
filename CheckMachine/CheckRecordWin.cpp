#pragma warning (disable : 4786)	//命名过长 容器
#include "CheckRecordWin.h"
#include <iostream>
#include <conio.h>
#include <string>
#include <vector>
#include <map>
#include "CWindow.h"
#include "CLabel.h"
#include "CButton.h"
#include "CTable.h"
#include "CTool.h"
#include "CData.h"
#include "CheckRecord.h"
#include "CorrectRecordWin.h"
using namespace std;


string CorrectRecordWin::checkSheetID="";


CheckRecordWin::CheckRecordWin(int x,int y,int w,int h):Window(x,y,w,h)
{
	this->title=new Label(25,3,LABEL,"欢迎使用HHS盘点机系统");
	this->welcome=new Label(5,5,LABEL,"欢迎：");
	this->date=new Label(50,5,LABEL,"日期：");

	this->sheetTable=new Table(15,10,2,4,TABLE,8,2,3);
	
	this->button1=new Button(15,12,19,3,BUTTON,"");
	this->button2=new Button(15,14,19,3,BUTTON,"");
	this->button3=new Button(15,16,19,3,BUTTON,"");

	this->esc=new Button(15,24,15,3,BUTTON,"返回");

	this->addCtrl(title);
	this->addCtrl(welcome);
	this->addCtrl(date);
	this->addCtrl(sheetTable);
	this->addCtrl(button1);			//4
	this->addCtrl(button2);			//5
	this->addCtrl(button3);			//6
	this->addCtrl(esc);				//7
}
CheckRecordWin::~CheckRecordWin()
{
}


void CheckRecordWin::showWin()
{
	//更新表格总页数
	this->sheetTable->editPageCount();

	Window::showWin();

	//输出当下登录用户信息&日期
	Ctools::gotoxy(20,5);
	cout<<Ctools::presentUser->getName();
	Ctools::gotoxy(58,5);
	char timedate[64]={0};
	Ctools::getTime(timedate);
	cout<<timedate;

	//根据用户权限输出当前用户信息
	Ctools::gotoxy(11,5);
	if(Ctools::presentUser->getAuthority()==ADMIN)
	{
		cout<<"管理员，";
	}
	else if(Ctools::presentUser->getAuthority()==CHECKMAN)
	{
		cout<<"盘点员，";
	}

	//输出表格内数据
	this->sheetTable->showData();
}


int CheckRecordWin::winRun()
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
			//若按键盘"←"键
			else if(c2==KEY_LEFT)
			{
				//表格页数边界判断
				if(this->sheetTable->curPage<=1)
				{
					Ctools::gotoxy(30,23);
					cout<<"              ";
					Ctools::gotoxy(30,23);
					cout<<"当前为第一页";
				}
				else
				{
					Ctools::gotoxy(30,23);
					cout<<"              ";
					this->sheetTable->curPage--;
					this->sheetTable->showData();
					this->sheetTable->showPageInform();
				}
			}
			//若按键盘"→"键
			else if(c2==KEY_RIGHT)
			{
				//表格页数边界判断
				if(this->sheetTable->curPage+1>this->sheetTable->pageCount)
				{
					Ctools::gotoxy(30,23);
					cout<<"              ";
					Ctools::gotoxy(30,23);
					cout<<"当前为最后一页";
				}
				else
				{
					Ctools::gotoxy(30,23);
					cout<<"              ";
					this->sheetTable->curPage++;
					this->sheetTable->showData();
					this->sheetTable->showPageInform();
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


int CheckRecordWin::doAction()
{
	map<string,vector<CheckRecord*> >::iterator it;
	it=Data::checkSheet.begin();

	switch(this->ctrlIndex)
	{
	//冲正操作只能管理员进行
	case 4:
		if(Ctools::presentUser->getAuthority()==ADMIN)
		{
			//获取当前选择的盘点表
			advance(it,(this->sheetTable->curPage-1)*(this->sheetTable->getHeight()-1));
			CorrectRecordWin::checkSheetID=it->first;

			return 13; 
		}
		else
		{
			return this->winRun();
		}
		break;
	case 5:
		if(Ctools::presentUser->getAuthority()==ADMIN)
		{
			//获取当前选择的盘点表
			advance(it,(this->sheetTable->curPage-1)*(this->sheetTable->getHeight()-1)+1);
			CorrectRecordWin::checkSheetID=it->first;
		
			return 13; 
		}
		else
		{
			return this->winRun();
		}
		break;
	case 6:
		if(Ctools::presentUser->getAuthority()==ADMIN)
		{
			//获取当前选择的盘点表
			advance(it,(this->sheetTable->curPage-1)*(this->sheetTable->getHeight()-1)+2);
			CorrectRecordWin::checkSheetID=it->first;
	
			return 13; 
		}
		else
		{
			return this->winRun();
		}
		break;
	case 7:
		//若为管理员打开的界面
		if(Ctools::presentUser->getAuthority()==ADMIN)
		{
			return 3;
		}
		//若为盘点员打开的界面
		else if(Ctools::presentUser->getAuthority()==CHECKMAN)
		{
			return 10;
		}
		break;
	}
}
