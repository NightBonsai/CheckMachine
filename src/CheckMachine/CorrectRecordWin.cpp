#pragma warning (disable : 4786)	//命名过长 容器
#include "CorrectRecordWin.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <conio.h>
#include <map>
#include "CWindow.h"
#include "CLabel.h"
#include "CEdition.h"
#include "CButton.h"
#include "CTable.h"
#include "CTool.h"
#include "CData.h"
#include "CheckRecord.h"
#include "Cargo.h"
using namespace std;


vector<CheckRecord*>::iterator CorrectingWin::it=NULL;	


CorrectRecordWin::CorrectRecordWin(int x,int y,int w,int h):Window(x,y,w,h)
{
	this->title=new Label(25,3,LABEL,"欢迎使用HHS盘点机系统");
	this->welcome=new Label(5,5,LABEL,"欢迎：管理员");
	this->date=new Label(50,5,LABEL,"日期：");
	this->checkID=new Label(5,8,LABEL,"盘点编号：");

	this->correctTable=new Table(0,12,7,4,TABLE,4,2,4);
	
	this->button1=new Button(0,14,11,3,BUTTON,"");
	this->button2=new Button(0,16,11,3,BUTTON,"");
	this->button3=new Button(0,18,11,3,BUTTON,"");

	this->finish=new Button(15,24,15,3,BUTTON,"完成冲正");
	this->esc=new Button(35,24,15,3,BUTTON,"返回");

	this->addCtrl(title);
	this->addCtrl(welcome);
	this->addCtrl(date);
	this->addCtrl(checkID);
	this->addCtrl(correctTable);
	this->addCtrl(button1);			//5
	this->addCtrl(button2);			//6
	this->addCtrl(button3);			//7
	this->addCtrl(finish);			//8
	this->addCtrl(esc);				//9
}
CorrectRecordWin::~CorrectRecordWin()
{
}


void CorrectRecordWin::showWin()
{
	//更新盘点冲正表格总页数
	this->correctTable->editPageCount();

	Window::showWin();

	//输出当下登录用户信息&日期
	Ctools::gotoxy(20,5);
	cout<<Ctools::presentUser->getName();
	Ctools::gotoxy(58,5);
	char timedate[64]={0};
	Ctools::getTime(timedate);
	cout<<timedate;

	//输出盘点表盘点编号
	Ctools::gotoxy(20,8);
	cout<<CorrectRecordWin::checkSheetID;

	//输出表格内数据
	this->correctTable->showData();
}


int CorrectRecordWin::winRun()
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
				if(this->correctTable->curPage<=1)
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
					this->correctTable->curPage--;
					this->correctTable->showData();
					this->correctTable->showPageInform();
				}
			}
			//若按键盘"→"键
			else if(c2==KEY_RIGHT)
			{
				//表格页数边界判断
				if(this->correctTable->curPage+1>this->correctTable->pageCount)
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
					this->correctTable->curPage++;
					this->correctTable->showData();
					this->correctTable->showPageInform();
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


int CorrectRecordWin::doAction()
{
	map<string,vector<CheckRecord*> >::iterator it_map;
	it_map=Data::checkSheet.find(CorrectRecordWin::checkSheetID);
	CorrectingWin::it=it_map->second.begin();

	switch(this->ctrlIndex)
	{
	case 5:
		{
			//记录当前选中的盘点记录
			CorrectingWin::it=CorrectingWin::it+(this->correctTable->curPage-1)*(this->correctTable->getHeight()-1);
			
			//运行冲正界面
			CorrectingWin *correctingWin;
			correctingWin=new CorrectingWin(15,5,40,20);
			correctingWin->showWin();
			return correctingWin->winRun();
		}
		break;
	case 6:
		{
			//记录当前选中的盘点记录
			CorrectingWin::it=CorrectingWin::it+(this->correctTable->curPage-1)*(this->correctTable->getHeight()-1)+1;
			
			//运行冲正界面
			CorrectingWin *correctingWin;
			correctingWin=new CorrectingWin(15,5,40,20);
			correctingWin->showWin();
			return correctingWin->winRun();
		}
		break;
	case 7:
		{
			//记录当前选中的盘点记录
			CorrectingWin::it=CorrectingWin::it+(this->correctTable->curPage-1)*(this->correctTable->getHeight()-1)+2;
			
			//运行冲正界面
			CorrectingWin *correctingWin;
			correctingWin=new CorrectingWin(15,5,40,20);
			correctingWin->showWin();
			return correctingWin->winRun();
		}
		break;
	case 8:
		return 12;
	case 9:
		return 12;
		break;
	}
}


CorrectingWin::CorrectingWin(int x,int y,int w,int h):Window(x,y,w,h)
{
	//int x=15,int y=5,int w=40,int h=20
	this->title=new Label(20,7,LABEL,"冲正记录");
	this->correctCount=new Label(20,10,LABEL,"冲正数量：");
	this->correctInstructions=new Label(20,13,LABEL,"冲正说明：");
	this->edition1=new Edition(30,9,20,3,EDITION,0,6,1);
	this->edition2=new Edition(30,12,20,6,EDITION,4,20,1);
	this->enter=new Button(20,20,8,3,BUTTON,"确定");
	this->esc=new Button(30,20,8,3,BUTTON,"取消");

	this->addCtrl(title);
	this->addCtrl(correctCount);
	this->addCtrl(correctInstructions);
	this->addCtrl(edition1);			//3
	this->addCtrl(edition2);			//4
	this->addCtrl(enter);				//5
	this->addCtrl(esc);					//6
}
CorrectingWin::~CorrectingWin()
{
}


void CorrectingWin::correcting()
{
	map<int,Cargo*>::iterator cargoIt;

	//判断冲正数量是否符合要求	<=差异数量
	if(atoi(this->edition1->getContent()) <= (*CorrectingWin::it)->getDifCount() 
		&&
		atoi(this->edition1->getContent()) >= 0)
	{
		//进行冲正
		//修改冲正记录
		(*CorrectingWin::it)->editCount(atoi(this->edition1->getContent()));
		(*CorrectingWin::it)->editDifCount();
		(*CorrectingWin::it)->editState();
		//修改商品个数
		cargoIt=Data::cargoMap.find((*CorrectingWin::it)->getID());
		cargoIt->second->editCount((*CorrectingWin::it)->getCount());

		//将冲正记录写入文件
		fstream fs;

		//获取文件名
		string fileName1="./data/";
		string fileName2=CorrectRecordWin::checkSheetID;
		string fileName3=".txt";
		stringstream fileName;
		fileName<<fileName1<<fileName2<<fileName3;

		//获取当前修改的盘点记录从属于的盘点表
		map<string,vector<CheckRecord*> >::iterator it_map;
		it_map=Data::checkSheet.find(CorrectRecordWin::checkSheetID);

		fs.open(fileName.str().c_str(),ios::in | ios::out);
		for(CorrectingWin::it=it_map->second.begin();CorrectingWin::it!=it_map->second.end();it++)
		{
			fs<<" "<<(*it)->getID()<<" "<<(*it)->getName()<<" "<<(*it)->getCount()<<" "<<(*it)->getCheckCount()<<" "<<(*it)->getLibID()<<" "<<(*it)->getState()<<endl;
		}
		fs.close();

		//将商品记录写入文件
		fs.open("./data/cargo.txt",ios::in | ios::out);
		fs.seekg(0,ios::beg);
		map<int,Cargo*>::iterator it_cargo;

		for(it_cargo=Data::cargoMap.begin();it_cargo!=Data::cargoMap.end();it_cargo++)
		{
			fs<<it_cargo->first<<" "<<it_cargo->second->getName()<<" "<<it_cargo->second->getType()<<" "<<it_cargo->second->getPrice()<<" "<<it_cargo->second->getCount()<<" "<<it_cargo->second->getLibID()<<endl;
		}
		fs.close();

		Ctools::gotoxy(20,18);
		cout<<"冲正成功";
		system("pause");
	}
	else
	{
		Ctools::gotoxy(20,18);
		cout<<"冲正数量不合法";
		system("pause");
	}
}


int CorrectingWin::doAction()
{
	switch(this->ctrlIndex)
	{
	case 5:
		this->correcting();
		return 13;
		break;
	case 6:
		return 13;
	}
}