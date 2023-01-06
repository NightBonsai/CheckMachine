#pragma warning (disable : 4786)	//命名过长 容器
#include "CargoOutLibWin.h"
#include <iostream>
#include <fstream>
#include <map>
#include "CWindow.h"
#include "CLabel.h"
#include "CEdition.h"
#include "CButton.h"
#include "CTool.h"
#include "CData.h"
using namespace std;


int CargoOutLib::searchCargoID=0;


CargoOutLib::CargoOutLib(int x,int y,int w,int h):Window(x,y,w,h)
{
	//w=70,h=30
	this->title=new Label(25,3,LABEL,"欢迎使用HHS盘点机系统");
	this->welcome=new Label(5,5,LABEL,"欢迎：管理员，");
	this->date=new Label(50,5,LABEL,"日期：");

	this->CargoID=new Label(5,8,LABEL,"请输入商品编号：");
	this->edition1=new Edition(20,7,40,3,EDITION,2,20,1,"");
	this->search=new Button(55,7,8,3,BUTTON,"查询");

	this->count=new Label(41,13,LABEL,"请输入出库数量[1-10000]");
	this->edition2=new Edition(40,15,25,3,EDITION,2,20,1,"");
	this->enter=new Button(40,20,12,3,BUTTON,"确定Enter");
	this->esc=new Button(53,20,12,3,BUTTON,"取消Esc");

	this->addCtrl(title);
	this->addCtrl(welcome);
	this->addCtrl(date);
	this->addCtrl(CargoID);
	this->addCtrl(edition1);		//4			
	this->addCtrl(search);			//5
	this->addCtrl(count);
	this->addCtrl(edition2);		//7
	this->addCtrl(enter);			//8
	this->addCtrl(esc);				//9
}
CargoOutLib::~CargoOutLib()
{}


void CargoOutLib::showWin()
{
	Window::showWin();

	//输出当下登录用户信息&日期
	Ctools::gotoxy(20,5);
	cout<<Ctools::presentUser->getName();
	Ctools::gotoxy(58,5);
	char timedate[64]={0};
	Ctools::getTime(timedate);
	cout<<timedate;

	//输出商品信息标签
	Ctools::gotoxy(7,13);
	cout<<"商品名称：";
	Ctools::gotoxy(7,15);
	cout<<"商品类型：";
	Ctools::gotoxy(7,17);
	cout<<"商品价格：";
	Ctools::gotoxy(7,19);
	cout<<"库存数量：";
	Ctools::gotoxy(7,21);
	cout<<"仓位编号：";
}


int CargoOutLib::searchCargo()
{
	//根据输入的商品编号在商品map关联容器中检索对应键值对
	map<int,Cargo*>::iterator it;

	int cargoID=atoi(this->edition1->getContent());			//将商品编号编辑框内字符串转化为整型
	it=Data::cargoMap.find(cargoID);							//迭代器获取find返回的键值对

	//若未找到对应键值对
	if(it==Data::cargoMap.end())
	{
		Ctools::gotoxy(18,13);
		cout<<"             ";
		Ctools::gotoxy(18,13);
		cout<<"未找到对应商品";

		Ctools::gotoxy(18,15);
		cout<<"             ";

		Ctools::gotoxy(18,17);
		cout<<"             ";

		Ctools::gotoxy(18,19);
		cout<<"             ";

		Ctools::gotoxy(18,21);
		cout<<"             ";

		//重置当前检索的商品编号
		CargoOutLib::searchCargoID=0;

		return 0;
	}
	//若找到对应键值对
	else
	{
		//商品名称
		Ctools::gotoxy(18,13);
		cout<<"             ";
		Ctools::gotoxy(18,13);
		cout<<it->second->getName();
		//商品类型
		Ctools::gotoxy(18,15);
		cout<<"             ";
		Ctools::gotoxy(18,15);
		cout<<it->second->getType();
		//商品价格
		Ctools::gotoxy(18,17);
		cout<<"             ";
		Ctools::gotoxy(18,17);
		cout<<it->second->getPrice();
		//商品个数
		Ctools::gotoxy(18,19);
		cout<<"             ";
		Ctools::gotoxy(18,19);
		cout<<it->second->getCount();
		//仓库编号
		Ctools::gotoxy(18,21);
		cout<<it->second->getLibID().c_str();

		//存储当前检索的商品编号
		CargoOutLib::searchCargoID=it->first;

		return 1;
	}
}


void CargoOutLib::cargoOutLib()
{
	fstream fs;
	fs.open("./data/cargo.txt",ios::in | ios::out);
	fs.seekg(0,ios::beg);
	map<int,Cargo*>::iterator it;

	it=Data::cargoMap.find(CargoOutLib::searchCargoID);
	//若当前未有检索商品
	if(it==Data::cargoMap.end())
	{
		//输出提示
		Ctools::gotoxy(25,25);
		cout<<"请先检索商品";
		system("pause");
		Ctools::gotoxy(25,25);
		cout<<"                              ";
		
		//刷新编辑框内容
		CargoOutLib::searchCargoID=0;
		this->edition1->editContent("");
		this->edition2->editContent("");
		this->showWin();

		fs.close();
	}
	//若当前已经检索商品
	else
	{
		//读取出库数量编辑框内新增个数
		int minusNum=atoi(this->edition2->getContent());
		//若出库数量符合要求
		if(minusNum>=1 && minusNum<=10000)
		{
			//修改商品map关联容器
			it->second->minus(minusNum);
			//将修改后的map关联容器写入文件
			for(it=Data::cargoMap.begin();it!=Data::cargoMap.end();it++)
			{
				fs<<it->first<<" "<<it->second->getName()<<" "<<it->second->getType()<<" "<<it->second->getPrice()<<" "<<it->second->getCount()<<" "<<it->second->getLibID()<<endl;
			}

			Ctools::gotoxy(25,25);
			cout<<"商品出库成功";
			system("pause");
			Ctools::gotoxy(25,25);
			cout<<"                              ";

			CargoOutLib::searchCargoID=0;
			this->edition1->editContent("");
			this->edition2->editContent("");
			this->showWin();

			fs.close();
		}
		//若出库数量不符合要求
		else
		{
			Ctools::gotoxy(25,25);
			cout<<"出库数量不合法";
			system("pause");
			Ctools::gotoxy(25,25);
			cout<<"                              ";
			
			CargoOutLib::searchCargoID=0;
			this->edition1->editContent("");
			this->edition2->editContent("");
			this->showWin();

			fs.close();
		}
	}
}


int CargoOutLib::doAction()
{
	switch(this->ctrlIndex)
	{
	case 5:
		//如果商品检索成功
		if(this->searchCargo()==1)
		{
			return this->winRun();
		}
		//如果商品未检索成功
		else
		{
			OutTip *tip=new OutTip;
			tip->showWin();
			return tip->winRun();
		}
		break;
	case 8:
		this->cargoOutLib();
		return this->winRun();
		break;
	case 9:
		CargoOutLib::searchCargoID=0;
		return 3;
		break;
	}

}


OutTip::OutTip(int x,int y,int w,int h):Window(x,y,w,h)
{
	//int x=18,int y=8,int w=35,int h=15
	this->reInput=new Button(30,15,15,3,BUTTON,"重新输入[1]");

	this->addCtrl(reInput);
}
OutTip::~OutTip()
{}


void OutTip::showWin()
{
	Window::showWin();

	Ctools::gotoxy(20,10);
	cout<<"提示：";
	Ctools::gotoxy(25,12);
	cout<<"未找到对应的商品";
}


int OutTip::doAction()
{
	switch(this->ctrlIndex)
	{
	case 0:
		return 8;
		break;
	}
}
