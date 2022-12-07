#pragma warning (disable : 4786)	//�������� ����
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
CargoOutLib::~CargoOutLib()
{}


void CargoOutLib::showWin()
{
	Window::showWin();

	//������µ�¼�û���Ϣ&����
	Ctools::gotoxy(20,5);
	cout<<Ctools::presentUser->getName();
	Ctools::gotoxy(58,5);
	char timedate[64]={0};
	Ctools::getTime(timedate);
	cout<<timedate;

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


int CargoOutLib::searchCargo()
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
		CargoOutLib::searchCargoID=0;

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
		CargoOutLib::searchCargoID=0;
		this->edition1->editContent("");
		this->edition2->editContent("");
		this->showWin();

		fs.close();
	}
	//����ǰ�Ѿ�������Ʒ
	else
	{
		//��ȡ���������༭������������
		int minusNum=atoi(this->edition2->getContent());
		//��������������Ҫ��
		if(minusNum>=1 && minusNum<=10000)
		{
			//�޸���Ʒmap��������
			it->second->minus(minusNum);
			//���޸ĺ��map��������д���ļ�
			for(it=Data::cargoMap.begin();it!=Data::cargoMap.end();it++)
			{
				fs<<it->first<<" "<<it->second->getName()<<" "<<it->second->getType()<<" "<<it->second->getPrice()<<" "<<it->second->getCount()<<" "<<it->second->getLibID()<<endl;
			}

			Ctools::gotoxy(25,25);
			cout<<"��Ʒ����ɹ�";
			system("pause");
			Ctools::gotoxy(25,25);
			cout<<"                              ";

			CargoOutLib::searchCargoID=0;
			this->edition1->editContent("");
			this->edition2->editContent("");
			this->showWin();

			fs.close();
		}
		//����������������Ҫ��
		else
		{
			Ctools::gotoxy(25,25);
			cout<<"�����������Ϸ�";
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
		//�����Ʒ�����ɹ�
		if(this->searchCargo()==1)
		{
			return this->winRun();
		}
		//�����Ʒδ�����ɹ�
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
	this->reInput=new Button(30,15,15,3,BUTTON,"��������[1]");

	this->addCtrl(reInput);
}
OutTip::~OutTip()
{}


void OutTip::showWin()
{
	Window::showWin();

	Ctools::gotoxy(20,10);
	cout<<"��ʾ��";
	Ctools::gotoxy(25,12);
	cout<<"δ�ҵ���Ӧ����Ʒ";
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
