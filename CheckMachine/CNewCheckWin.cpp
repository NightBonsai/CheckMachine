#pragma warning (disable : 4786)	//命名过长 容器
#include "CNewCheckWin.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <conio.h>
#include "CWindow.h"
#include "CLabel.h"
#include "CEdition.h"
#include "CButton.h"
#include "CTable.h"
#include "CTool.h"
#include "CData.h"
#include "CheckRecord.h"
using namespace std;


int NewCheckWin::searchCargoID=0;


NewCheckWin::NewCheckWin(int x,int y,int w,int h):Window(x,y,w,h)
{
	//w=70,h=30
	this->title=new Label(25,3,LABEL,"欢迎使用HHS盘点机系统");
	this->welcome=new Label(5,5,LABEL,"欢迎：盘点员，");
	this->date=new Label(50,5,LABEL,"日期：");
	this->checkID=new Label(5,8,LABEL,"盘点编号：");

	this->cargoID=new Label(5,11,LABEL,"请输入商品编号：");
	this->edition1=new Edition(20,10,40,3,EDITION,2,20,1,"");
	this->search=new Button(55,10,8,3,BUTTON,"查询");

	this->count1=new Label(41,15,LABEL,"请输入盘点库存数量");
	this->count2=new Label(41,17,LABEL,"[1-10000]");
	this->edition2=new Edition(40,18,25,3,EDITION,2,20,1,"");
	this->enter=new Button(40,21,12,3,BUTTON,"确定Enter");
	this->esc=new Button(53,21,12,3,BUTTON,"取消Esc");
	this->newCheck=new Button(40,24,20,3,BUTTON,"生成盘点表[1]");

	this->addCtrl(title);
	this->addCtrl(welcome);
	this->addCtrl(date);
	this->addCtrl(checkID);
	this->addCtrl(cargoID);
	this->addCtrl(edition1);		//5			
	this->addCtrl(search);			//6
	this->addCtrl(count1);			
	this->addCtrl(count2);
	this->addCtrl(edition2);		//9
	this->addCtrl(enter);			//10
	this->addCtrl(esc);				//11
	this->addCtrl(newCheck);		//12
}
NewCheckWin::~NewCheckWin()
{}


void NewCheckWin::showWin()
{
	Window::showWin();

	//输出当下登录用户信息&日期
	Ctools::gotoxy(20,5);
	cout<<Ctools::presentUser->getName();
	Ctools::gotoxy(58,5);
	char timedate[64]={0};
	Ctools::getTime(timedate);
	cout<<timedate;

	//输出当前盘点编号
	Ctools::gotoxy(20,8);
	cout<<Data::getCheckID();

	//输出商品信息标签
	Ctools::gotoxy(7,15);
	cout<<"商品名称：";
	Ctools::gotoxy(7,18);
	cout<<"商品类型：";
	Ctools::gotoxy(7,21);
	cout<<"商品价格：";
	Ctools::gotoxy(7,24);
	cout<<"仓位编号：";
}


int NewCheckWin::searchCargo()
{
	//根据输入的商品编号在商品map关联容器中检索对应键值对
	map<int,Cargo*>::iterator it;

	int cargoID=atoi(this->edition1->getContent());			//将商品编号编辑框内字符串转化为整型
	it=Data::cargoMap.find(cargoID);							//迭代器获取find返回的键值对

	//若未找到对应键值对
	if(it==Data::cargoMap.end())
	{
		Ctools::gotoxy(18,15);
		cout<<"             ";
		Ctools::gotoxy(18,15);
		cout<<"未找到对应商品";

		Ctools::gotoxy(18,18);
		cout<<"             ";

		Ctools::gotoxy(18,21);
		cout<<"             ";

		Ctools::gotoxy(18,24);
		cout<<"             ";

		//重置当前检索的商品编号
		NewCheckWin::searchCargoID=0;

		return 0;
	}
	//若找到对应键值对
	else
	{
		//商品名称
		Ctools::gotoxy(18,15);
		cout<<"             ";
		Ctools::gotoxy(18,15);
		cout<<it->second->getName();
		//商品类型
		Ctools::gotoxy(18,18);
		cout<<"             ";
		Ctools::gotoxy(18,18);
		cout<<it->second->getType();
		//商品价格
		Ctools::gotoxy(18,21);
		cout<<"             ";
		Ctools::gotoxy(18,21);
		cout<<it->second->getPrice();
		//商品个数
		Ctools::gotoxy(18,24);
		cout<<"             ";
		Ctools::gotoxy(18,24);
		cout<<it->second->getLibID().c_str();

		//存储当前检索的商品编号
		NewCheckWin::searchCargoID=it->first;

		return 1;
	}
}


void NewCheckWin::cargoCheck()
{
	map<int,Cargo*>::iterator it1;
	
	it1=Data::cargoMap.find(NewCheckWin::searchCargoID);

	//若当前未有检索商品
	if(it1==Data::cargoMap.end())
	{
		//输出提示
		Ctools::gotoxy(7,26);
		cout<<"请先检索商品";
		system("pause");
		Ctools::gotoxy(7,26);
		cout<<"                              ";
		
		//刷新编辑框内容
		NewCheckWin::searchCargoID=0;
		this->edition1->editContent("");
		this->edition2->editContent("");
		this->showWin();
	}
	//若当前已经检索商品
	else
	{
		//读取盘点数量编辑框内个数
		int checkNum=atoi(this->edition2->getContent());
		//表单判空
		if(strcmp(this->edition2->getContent(),"")==0)
		{
			//输出提示
			Ctools::gotoxy(7,26);
			cout<<"盘点数量不能为空";
			system("pause");
			Ctools::gotoxy(7,26);
			cout<<"                                 ";
			
			//重置当前检索的商品编号
			NewCheckWin::searchCargoID=0;
			//刷新编辑框内容
			NewCheckWin::searchCargoID=0;
			this->edition1->editContent("");
			this->edition2->editContent("");
			this->showWin();
			
			return;
		}
		//若盘点数量符合要求
		else if(checkNum>=1 && checkNum<=10000)
		{
			vector<CheckRecord*>::iterator it_vector;
			
			//新增盘点记录
			//检索是否存在相同盘点记录
			for(it_vector=Data::checkRecords.begin();it_vector!=Data::checkRecords.end();it_vector++)
			{
				
				//若记录已存在，做添加
				if((*it_vector)->getID()==NewCheckWin::searchCargoID)
				{
					(*it_vector)->addCheckCount(checkNum);
					
					//输出提示
					Ctools::gotoxy(7,26);
					cout<<"商品盘点成功";
					system("pause");
					Ctools::gotoxy(7,26);
					cout<<"                              ";
					
					//重置当前检索的商品编号
					NewCheckWin::searchCargoID=0;
					//刷新编辑框内容
					NewCheckWin::searchCargoID=0;
					this->edition1->editContent("");
					this->edition2->editContent("");
					this->showWin();
					
					return;
				}
			}
			//若记录未存在
			Data::checkRecords.push_back
				(
					new CheckRecord
					(
						//int id,char name[],int count,int checkCount,string libID,int state
						Data::cargoMap[NewCheckWin::searchCargoID]->getID(),
						Data::cargoMap[NewCheckWin::searchCargoID]->getName(),
						Data::cargoMap[NewCheckWin::searchCargoID]->getCount(),
						checkNum,
						Data::cargoMap[NewCheckWin::searchCargoID]->getLibID(),
						0				
					)
				);
			
			//输出提示
			Ctools::gotoxy(7,26);
			cout<<"商品盘点成功";
			system("pause");
			Ctools::gotoxy(7,26);
			cout<<"                              ";
			
			//重置当前检索的商品编号
			NewCheckWin::searchCargoID=0;
			//刷新编辑框内容
			NewCheckWin::searchCargoID=0;
			this->edition1->editContent("");
			this->edition2->editContent("");
			this->showWin();
		}
		//若盘点数量不符合要求
		else
		{
			Ctools::gotoxy(18,26);
			cout<<"盘点数量不合法";
			system("pause");
			Ctools::gotoxy(18,26);
			cout<<"                                  ";

			//刷新编辑框内容
			NewCheckWin::searchCargoID=0;
			this->edition1->editContent("");
			this->edition2->editContent("");
			this->showWin();
		}
	}
}


int NewCheckWin::doAction()
{
	switch(this->ctrlIndex)
	{
	case 6:
		//如果商品检索成功
		if(this->searchCargo()==1)
		{
			return this->winRun();
		}
		//如果商品未检索成功
		else
		{
			Tip *tip=new Tip;
			tip->showWin();
			return tip->winRun();
		}
		break;
	case 10:
		this->cargoCheck();
		return this->winRun();
		break;
	case 11:
		return 10;
		break;
	case 12:
		{
			NewSheetWin *newSheetWin=new NewSheetWin(0,0,70,30);
			newSheetWin->showWin();
			return newSheetWin->winRun();
		}
		break;
	}
}


Tip::Tip(int x,int y,int w,int h):Window(x,y,w,h)
{
	//int x=18,int y=8,int w=35,int h=15
	this->reInput=new Button(30,15,15,3,BUTTON,"重新输入[1]");

	this->addCtrl(reInput);
}
Tip::~Tip()
{}


void Tip::showWin()
{
	Window::showWin();

	Ctools::gotoxy(20,10);
	cout<<"提示：";
	Ctools::gotoxy(25,12);
	cout<<"未找到对应的商品";
}


int Tip::doAction()
{
	switch(this->ctrlIndex)
	{
	case 0:
		return 11;
		break;
	}
}


NewSheetWin::NewSheetWin(int x,int y,int w,int h):Window(x,y,w,h)
{
	this->title=new Label(25,3,LABEL,"欢迎使用HHS盘点机系统");
	this->welcome=new Label(5,5,LABEL,"欢迎：盘点员，");
	this->date=new Label(50,5,LABEL,"日期：");
	this->checkID=new Label(5,8,LABEL,"盘点编号：");
	this->checkState=new Label(50,8,LABEL,"盘点状态：");

	this->cargoTable=new Table(5,12,6,4,TABLE,4,2,2);

	this->endCheck=new Button(5,24,15,3,BUTTON,"结束盘点");
	this->esc=new Button(25,24,8,3,BUTTON,"返回");

	this->addCtrl(title);
	this->addCtrl(welcome);
	this->addCtrl(date);
	this->addCtrl(checkID);
	this->addCtrl(checkState);
	this->addCtrl(cargoTable);
	this->addCtrl(endCheck);		//6
	this->addCtrl(esc);				//7
}
NewSheetWin::~NewSheetWin()
{}


void NewSheetWin::showWin()
{
	Window::showWin();

	//输出当下登录用户信息&日期
	Ctools::gotoxy(20,5);
	cout<<Ctools::presentUser->getName();
	Ctools::gotoxy(58,5);
	char timedate[64]={0};
	Ctools::getTime(timedate);
	cout<<timedate;

	//输出当前盘点编号
	Ctools::gotoxy(20,8);
	cout<<Data::getCheckID();

	//输出当前盘点状态
	Ctools::gotoxy(60,8);
	cout<<"进行中";

	//输出表格数据
	this->cargoTable->showData();
}


int NewSheetWin::winRun()
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


void NewSheetWin::newSheet()
{
	vector<CheckRecord*>::iterator it;
	//新建盘点表，将盘点记录写入盘点表
	for(it=Data::checkRecords.begin();it!=Data::checkRecords.end();it++)
	{
		Data::checkSheet[Data::getCheckID()].push_back
		(
			new CheckRecord
			(
				(*it)->getID(),
				(*it)->getName(),
				(*it)->getCount(),
				(*it)->getCheckCount(),
				(*it)->getLibID(),
				(*it)->getState()
			)
		);
	}

	//将盘点表写入文件中;
	//获取文件名
	string fileName1="./data/";
	string fileName2=Data::getCheckID();
	string fileName3=".txt";
	
	stringstream fileName;
	fileName<<fileName1<<fileName2<<fileName3;

	fstream fs1;
	fs1.open(fileName.str().c_str(),ios::in | ios::out | ios::app);

	for(it=Data::checkRecords.begin();it!=Data::checkRecords.end();it++)
	{
		fs1<<" "<<(*it)->getID()<<" "<<(*it)->getName()<<" "<<(*it)->getCount()<<" "<<(*it)->getCheckCount()<<" "<<(*it)->getLibID()<<" "<<(*it)->getState()<<endl;
	}
	fs1.close();

	//输出提示
	Ctools::gotoxy(40,26);
	cout<<"新建盘点表成功";
	system("pause");
	Ctools::gotoxy(40,26);
	cout<<"                          ";

	//清除当前盘点表的盘点记录，用于存储下一个盘点表的盘点记录
	Data::checkRecords.clear();
	
	//盘点编号自增
	//将盘点编号重新写入文件
	Data::checkID2=Data::checkID2+1;

	fstream fs2;
	fs2.open("./data/curCheckID.txt",ios::in | ios::out);
	fs2.seekg(0,ios::beg);

	fs2<<Data::checkID2;
}


int NewSheetWin::doAction()
{
	switch(this->ctrlIndex)
	{
	case 6:
		this->newSheet();
		return 10;
		break;
	case 7:
		return 11;
		break;
	}
}
