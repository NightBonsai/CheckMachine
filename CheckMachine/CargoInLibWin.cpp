#pragma warning (disable : 4786)	//�������� ����
#include "CargoInLibWin.h"
#include <iostream>
#include <fstream>
#include <map>
#include "CWindow.h"
#include "CLabel.h"
#include "CEdition.h"
#include "CButton.h"
#include "CTool.h"
#include "CData.h"
#include "Cargo.h"
using namespace std;


int CargoInLib::searchCargoID=0;


CargoInLib::CargoInLib(int x,int y,int w,int h):Window(x,y,w,h)
{
	//w=70,h=30
	this->title=new Label(25,3,LABEL,"��ӭʹ��HHS�̵��ϵͳ");
	this->welcome=new Label(5,5,LABEL,"��ӭ������Ա��");
	this->date=new Label(50,5,LABEL,"���ڣ�");

	this->CargoID=new Label(5,8,LABEL,"��������Ʒ��ţ�");
	this->edition1=new Edition(20,7,40,3,EDITION,2,20,1,"");
	this->search=new Button(55,7,8,3,BUTTON,"��ѯ");

	this->count=new Label(41,13,LABEL,"�������������[1-10000]");
	this->edition2=new Edition(40,15,25,3,EDITION,2,20,1,"");
	this->enter=new Button(40,20,12,3,BUTTON,"ȷ��Enter");
	this->esc=new Button(53,20,12,3,BUTTON,"ȡ��Esc");

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
CargoInLib::~CargoInLib()
{}


void CargoInLib::showWin()
{
	Window::showWin();

	//������µ�¼�û���Ϣ&����
	Ctools::gotoxy(20,5);
	cout<<Ctools::presentUser->getName();
	Ctools::gotoxy(55,5);
	//cout<<Ctools::getTime();

	//�����Ʒ��Ϣ��ǩ
	Ctools::gotoxy(7,13);
	cout<<"��Ʒ���ƣ�";
	Ctools::gotoxy(7,15);
	cout<<"��Ʒ���ͣ�";
	Ctools::gotoxy(7,17);
	cout<<"��Ʒ�۸�";
	Ctools::gotoxy(7,19);
	cout<<"���������";
	Ctools::gotoxy(7,21);
	cout<<"��λ��ţ�";
}


int CargoInLib::searchCargo()
{
	//�����������Ʒ�������Ʒmap���������м�����Ӧ��ֵ��
	map<int,Cargo*>::iterator it;

	int cargoID=atoi(this->edition1->getContent());			//����Ʒ��ű༭�����ַ���ת��Ϊ����
	it=Data::cargoMap.find(cargoID);							//��������ȡfind���صļ�ֵ��

	//��δ�ҵ���Ӧ��ֵ��
	if(it==Data::cargoMap.end())
	{
		Ctools::gotoxy(18,13);
		cout<<"             ";
		Ctools::gotoxy(18,13);
		cout<<"δ�ҵ���Ӧ��Ʒ";

		Ctools::gotoxy(18,15);
		cout<<"             ";

		Ctools::gotoxy(18,17);
		cout<<"             ";

		Ctools::gotoxy(18,19);
		cout<<"             ";

		Ctools::gotoxy(18,21);
		cout<<"             ";

		//���õ�ǰ��������Ʒ���
		CargoInLib::searchCargoID=0;

		return 0;
	}
	//���ҵ���Ӧ��ֵ��
	else
	{
		//��Ʒ����
		Ctools::gotoxy(18,13);
		cout<<"             ";
		Ctools::gotoxy(18,13);
		cout<<it->second->getName();
		//��Ʒ����
		Ctools::gotoxy(18,15);
		cout<<"             ";
		Ctools::gotoxy(18,15);
		cout<<it->second->getType();
		//��Ʒ�۸�
		Ctools::gotoxy(18,17);
		cout<<"             ";
		Ctools::gotoxy(18,17);
		cout<<it->second->getPrice();
		//��Ʒ����
		Ctools::gotoxy(18,19);
		cout<<"             ";
		Ctools::gotoxy(18,19);
		cout<<it->second->getCount();
		//�ֿ���
		Ctools::gotoxy(18,21);
		cout<<it->second->getLibID().c_str();

		//�洢��ǰ��������Ʒ���
		CargoInLib::searchCargoID=it->first;

		return 1;
	}
}


void CargoInLib::cargoInLib()
{
	fstream fs;
	fs.open("./data/cargo.txt",ios::in | ios::out);
	fs.seekg(0,ios::beg);
	map<int,Cargo*>::iterator it;

	it=Data::cargoMap.find(CargoInLib::searchCargoID);
	//����ǰδ�м�����Ʒ
	if(it==Data::cargoMap.end())
	{	
		//�����ʾ
		Ctools::gotoxy(25,25);
		cout<<"���ȼ�����Ʒ";
		system("pause");
		Ctools::gotoxy(25,25);
		cout<<"                              ";
		
		//ˢ�±༭������
		CargoInLib::searchCargoID=0;
		this->edition1->editContent("");
		this->edition2->editContent("");
		this->showWin();

		fs.close();
	}
	//����ǰ�Ѿ�������Ʒ
	else
	{
		//��ȡ��������༭������������
		int addNum=atoi(this->CtrlArr[7]->getContent());
		//�����������������Ҫ��
		if(addNum>=1 &&addNum<=10000)
		{
			//�޸���Ʒmap��������
			it->second->add(addNum);
			//���޸ĺ��map��������д���ļ�
			for(it=Data::cargoMap.begin();it!=Data::cargoMap.end();it++)
			{
				fs<<it->first<<" "<<it->second->getName()<<" "<<it->second->getType()<<" "<<it->second->getPrice()<<" "<<it->second->getCount()<<" "<<it->second->getLibID()<<endl;
			}

			Ctools::gotoxy(25,25);
			cout<<"��Ʒ���ɹ�";
			system("pause");
			Ctools::gotoxy(25,25);
			cout<<"                              ";
			
			//���õ�ǰ��������Ʒ���
			CargoInLib::searchCargoID=0;
			//ˢ�±༭������
			CargoInLib::searchCargoID=0;
			this->edition1->editContent("");
			this->edition2->editContent("");
			this->showWin();

			fs.close();
		}
		//�������������������Ҫ��
		else
		{
			Ctools::gotoxy(25,25);
			cout<<"����������Ϸ�";
			system("pause");
			Ctools::gotoxy(25,25);
			cout<<"                                  ";

			//ˢ�±༭������
			CargoInLib::searchCargoID=0;
			this->edition1->editContent("");
			this->edition2->editContent("");
			this->showWin();

			fs.close();
		}
	}
}


int CargoInLib::doAction()
{
	switch(this->ctrlIndex)
	{
	case 5:
		//�����Ʒ�����ɹ�
		if(this->searchCargo()==1)
		{
			return this->winRun();
		}
		//�����Ʒδ�����ɹ�
		else
		{
			InTip *tip=new InTip;
			tip->showWin();
			return tip->winRun();
		}
		break;
	case 8:
		this->cargoInLib();
		return this->winRun();
		break;
	case 9:
		CargoInLib::searchCargoID=0;
		return 5;
		break;
	}
	return 5;
}


InTip::InTip(int x,int y,int w,int h):Window(x,y,w,h)
{
	//int x=18,int y=8,int w=35,int h=15
	this->reInput=new Button(30,15,15,3,BUTTON,"��������[1]");
	this->newCargo=new Button(30,18,15,3,BUTTON,"������Ʒ[2]");

	this->addCtrl(reInput);
	this->addCtrl(newCargo);
}
InTip::~InTip()
{}


void InTip::showWin()
{
	Window::showWin();

	Ctools::gotoxy(20,10);
	cout<<"��ʾ��";
	Ctools::gotoxy(25,12);
	cout<<"δ�ҵ���Ӧ����Ʒ";
}


int InTip::doAction()
{
	switch(this->ctrlIndex)
	{
	case 0:
		return 6;
		break;
	case 1:
		{
			AddNewCargo *addCargo=new AddNewCargo;
			addCargo->showWin();
			return addCargo->winRun();
		}
		break;
	}
	return 6;
}


AddNewCargo::AddNewCargo(int x,int y,int w,int h):Window(x,y,w,h)
{
	//w=70,h=30
	int cargoID=Cargo::defaultCargoID+Data::cargoMap.size();

	this->title=new Label(25,3,LABEL,"��ӭʹ��HHS�̵��ϵͳ");
	this->welcome=new Label(5,5,LABEL,"��ӭ������Ա��");
	this->date=new Label(50,5,LABEL,"���ڣ�");

	this->cargoid=new Label(20,8,LABEL,"��Ʒ��ţ�");
	this->cargoname=new Label(20,11,LABEL,"��Ʒ���ƣ�");
	this->cargotype=new Label(20,14,LABEL,"��Ʒ���ͣ�");
	this->cargoprice=new Label(20,17,LABEL,"��Ʒ�۸�");
	this->libid=new Label(20,20,LABEL,"��λ��ţ�");
	this->edition1=new Edition(30,10,25,3,EDITION,4,20,1,"");	//��Ʒ���༭��
	this->edition2=new Edition(30,13,25,3,EDITION,3,20,1,"");	//��Ʒ���ͱ༭��
	this->edition3=new Edition(30,16,25,3,EDITION,0,20,1,"");	//��Ʒ�۸�༭��
	this->enter=new Button(20,25,18,3,BUTTON,"ȷ��[Enter]");
	this->esc=new Button(40,25,18,3,BUTTON,"ȡ��[Esc]");

	this->addCtrl(title);
	this->addCtrl(welcome);
	this->addCtrl(date);
	this->addCtrl(cargoid);
	this->addCtrl(cargoname);
	this->addCtrl(cargotype);
	this->addCtrl(cargoprice);
	this->addCtrl(libid);
	this->addCtrl(edition1);	//8
	this->addCtrl(edition2);	//9
	this->addCtrl(edition3);	//10
	this->addCtrl(enter);		//11
	this->addCtrl(esc);			//12
}
AddNewCargo::~AddNewCargo()
{}


void AddNewCargo::showWin()
{
	Window::showWin();

	//������µ�¼�û���Ϣ&����
	Ctools::gotoxy(20,5);
	cout<<Ctools::presentUser->getName();
	Ctools::gotoxy(58,5);
	char timedate[64]={0};
	Ctools::getTime(timedate);
	cout<<timedate;

	//���Ĭ����Ʒ���id & �ֿ���(ϵͳ�ڶ�)
	Ctools::gotoxy(32,8);
	cout<<Cargo::defaultCargoID+Data::cargoMap.size();
	Ctools::gotoxy(32,20);
	cout<<Cargo::getNewLibID();
}


void AddNewCargo::addNewCargo()
{
	map<int,Cargo*>::iterator it;

	//��ȡ��Ʒ����
	//������Ʒmap���������鿴��Ʒ�����Ƿ��ظ�
	for(it=Data::cargoMap.begin();it!=Data::cargoMap.end();it++)
	{
		//���ظ�	��ʾ
		if(strcmp(this->edition1->getContent(),it->second->getName())==0)
		{
			Ctools::gotoxy(30,22);
			cout<<"          ";
			Ctools::gotoxy(30,22);
			cout<<"��Ʒ�Ѵ���";
			this->winRun();				//������Ʒʧ��
		}
	}
	//�пղ���
	if(strcmp(this->edition1->getContent(),"")!=0 && strcmp(this->edition2->getContent(),"")!=0 && strcmp(this->edition3->getContent(),"")!=0)
	{
		
		//��Ʒmap������������
		int cargoID=Cargo::defaultCargoID+Data::cargoMap.size();
		Data::cargoMap[cargoID]=new Cargo(this->edition1->getContent(),this->edition2->getContent(),atoi(this->edition3->getContent()),0);

		//д���ļ����ļ�ĩβ���
		fstream fs;

		fs.open("./data/cargo.txt",ios::in | ios::out | ios::app);
		it=Data::cargoMap.find(cargoID);
		fs<<it->first<<" "<<it->second->getName()<<" "<<it->second->getType()<<" "<<it->second->getPrice()<<" "<<it->second->getCount()<<" "<<it->second->getLibID()<<endl;
		
		fs.close();

		Ctools::gotoxy(30,22);
		cout<<"          ";
		Ctools::gotoxy(30,22);
		cout<<"������Ʒ�ɹ���";
		system("pause");
		return ;							//������Ʒ�ɹ�
	}
	else
	{
		Ctools::gotoxy(30,22);
		cout<<"          ";
		Ctools::gotoxy(30,22);
		cout<<"�༭����Ϊ��";
		this->winRun();						//������Ʒʧ��
	}	
}


int AddNewCargo::doAction()
{
	switch(this->ctrlIndex)
	{
	case 11:
		this->addNewCargo();
		return 6;
		break;
	case 12:
		return 6;
		break;
	}
	return 6;
}
