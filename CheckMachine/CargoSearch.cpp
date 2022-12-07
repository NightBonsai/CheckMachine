#pragma warning (disable : 4786)	//命名过长 容器
#include "CargoSearch.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <conio.h>
#include <map>
#include <vector>
#include "CWindow.h"
#include "CLabel.h"
#include "CEdition.h"
#include "CButton.h"
#include "CTool.h"
#include "CData.h"
#include "CTable.h"
using namespace std;


int CargoSearch::searchType=0;


CargoSearch::CargoSearch(int x,int y,int w,int h):Window(x,y,w,h)
{
	//w=70,h=30
	this->title=new Label(25,3,LABEL,"欢迎使用HHS盘点机系统");
	this->welcome=new Label(5,5,LABEL,"欢迎：");
	this->date=new Label(50,5,LABEL,"日期：");
	
	this->cargoID=new Label(5,8,LABEL,"请输入商品编号：");
	this->edition1=new Edition(20,7,40,3,EDITION,2,20,1,"");
	this->search=new Button(55,7,8,3,BUTTON,"查询");

	this->cargoTable=new Table (4,12,6,4,TABLE,4,2,1);

	this->enter=new Button(5,25,20,3,BUTTON,"导出商品信息[3]");
	this->esc=new Button(50,25,15,3,BUTTON,"返回[Esc]");

	this->addCtrl(title);
	this->addCtrl(welcome);
	this->addCtrl(date);
	this->addCtrl(cargoID);
	this->addCtrl(edition1);
	this->addCtrl(search);		//5
	this->addCtrl(cargoTable);	//6
	this->addCtrl(enter);		//7
	this->addCtrl(esc);			//8
}
CargoSearch::~CargoSearch()
{}


void CargoSearch::showWin()
{
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
}


int CargoSearch::winRun()
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
				if(this->cargoTable->curPage<=1)
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
					this->cargoTable->curPage--;
					this->cargoTable->showData();
					this->cargoTable->showPageInform();
				}
			}
			//若按键盘"→"键
			else if(c2==KEY_RIGHT)
			{
				//表格页数边界判断
				if(this->cargoTable->curPage+1>this->cargoTable->pageCount)
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
					this->cargoTable->curPage++;
					this->cargoTable->showData();
					this->cargoTable->showPageInform();
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


void CargoSearch::cargoSearch()
{
	int searchCargoID;
	searchCargoID=atoi(this->edition1->getContent());
	
	//若编辑框内啥都没有(输出所有数据)
	if(strlen(this->edition1->getContent())==0)
	{
		CargoSearch::searchType=0;
		this->cargoTable->showData();
	}
	//若为模糊查询or精确查询
	else
	{	
		CargoSearch::searchType=1;

		//清空临时容器
		//清空表格
		this->tmpCargoVector.clear();
		this->cargoTable->clearTable();

		map<int,Cargo*>::iterator it1;
		char tmp[20];						//临时字符数组

		//遍历商品关联容器
		for(it1=Data::cargoMap.begin();it1!=Data::cargoMap.end();it1++)
		{
			itoa(it1->first,tmp,10);
			//若输入字符串为商品编号的子串
			if(strstr(tmp,this->edition1->getContent())!=NULL)
			{
				//将商品加入vector商品临时容器中
				this->tmpCargoVector.push_back(it1->second);
			}
		}
		

		//当前页面要输出几行数据
		int nowPageLine;		
		//根据当前页商品个数决定输出几行数据
		if(this->tmpCargoVector.size()>=this->cargoTable->curPage*(this->cargoTable->getHeight()-1))
		{
			nowPageLine=this->cargoTable->getHeight();
		}
		else if(this->tmpCargoVector.size()<this->cargoTable->curPage*(this->cargoTable->getHeight()-1))
		{
			nowPageLine=this->tmpCargoVector.size()-(this->cargoTable->curPage-1)*(this->cargoTable->getHeight()-1)+1;
		}
		
		vector<Cargo*>::iterator it2;
		it2=this->tmpCargoVector.begin();
		
		//输出数据
		for(int i=1;i<nowPageLine;i++)
		{
			Ctools::gotoxy( this->cargoTable->getStartx()+2+0*(this->cargoTable->getCellWidth()*2.5), this->cargoTable->getStarty()+i*(this->cargoTable->getCellHeight())+1 );
			cout<<(*it2)->getID();
			Ctools::gotoxy( this->cargoTable->getStartx()+2+1*(this->cargoTable->getCellWidth()*2.5), this->cargoTable->getStarty()+i*(this->cargoTable->getCellHeight())+1 );
			cout<<(*it2)->getName();
			Ctools::gotoxy( this->cargoTable->getStartx()+2+2*(this->cargoTable->getCellWidth()*2.5), this->cargoTable->getStarty()+i*(this->cargoTable->getCellHeight())+1 );
			cout<<(*it2)->getType();
			Ctools::gotoxy( this->cargoTable->getStartx()+2+3*(this->cargoTable->getCellWidth()*2.5), this->cargoTable->getStarty()+i*(this->cargoTable->getCellHeight())+1 );
			cout<<(*it2)->getPrice();
			Ctools::gotoxy( this->cargoTable->getStartx()+2+4*(this->cargoTable->getCellWidth()*2.5), this->cargoTable->getStarty()+i*(this->cargoTable->getCellHeight())+1 );
			cout<<(*it2)->getCount();
			Ctools::gotoxy( this->cargoTable->getStartx()+2+5*(this->cargoTable->getCellWidth()*2.5), this->cargoTable->getStarty()+i*(this->cargoTable->getCellHeight())+1 );
			cout<<(*it2)->getLibID();
			it2++;
		}
	}
}


bool CargoSearch::recordOut()
{
	//获取文件名：日期+GI
	char fileName1[20];
	string fileName2="GI.txt";
	Ctools::getRecordName(fileName1);

	stringstream fileName;
	fileName<<fileName1<<fileName2;

	fstream fs;
	fs.open(fileName.str().c_str(),ios::in | ios::out | ios::app);

	//若当前检索类型为不输入任何数据
	if(CargoSearch::searchType==0)
	{
		//将商品关联容器内的所有数据写入新导出的文件中
		map<int,Cargo*>::iterator it1;
		for(it1=Data::cargoMap.begin();it1!=Data::cargoMap.end();it1++)
		{
			fs<<it1->first<<" "<<it1->second->getName()<<" "<<it1->second->getType()<<" "<<it1->second->getPrice()<<" "<<it1->second->getCount()<<" "<<it1->second->getLibID()<<endl;
		}
		
		fs.close();

		return true;
	}
	//若当前检索类型为输入数据
	else if(CargoSearch::searchType==1)
	{
		//将临时容器内的所有数据写入新导出的文件中
		vector<Cargo*>::iterator it2;
		for(it2=this->tmpCargoVector.begin();it2<this->tmpCargoVector.end();it2++)
		{
			fs<<(*it2)->getID()<<" "<<(*it2)->getName()<<" "<<(*it2)->getType()<<" "<<(*it2)->getPrice()<<" "<<(*it2)->getCount()<<" "<<(*it2)->getLibID()<<endl;
		}

		fs.close();

		return true;
	}

	return false;
}


int CargoSearch::doAction()
{
	switch(this->ctrlIndex)
	{
	case 5:
		this->cargoSearch();
		this->winRun();
		break;
	case 7:
		if(this->recordOut())
		{
			Ctools::gotoxy(30,24);
			cout<<"导出商品信息成功";
			system("pause");
			Ctools::gotoxy(30,24);
			cout<<"                                   ";
			this->winRun();
		}
		else
		{
			Ctools::gotoxy(30,25);
			cout<<"导出商品信息失败";
			system("pause");
			Ctools::gotoxy(30,24);
			cout<<"                                   ";
			this->winRun();
		}
		break;
	case 8:
		//若为管理员打开的界面
		if(Ctools::presentUser->getAuthority()==ADMIN)
		{
			return 3;
		}
		//若为盘点员打开的界面
		else if(Ctools::presentUser->getAuthority()==CHECKMAN)
		{
			return 4;
		}
		break;
	}
}