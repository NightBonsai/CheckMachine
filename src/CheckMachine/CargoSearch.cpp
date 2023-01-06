#pragma warning (disable : 4786)	//�������� ����
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
	this->title=new Label(25,3,LABEL,"��ӭʹ��HHS�̵��ϵͳ");
	this->welcome=new Label(5,5,LABEL,"��ӭ��");
	this->date=new Label(50,5,LABEL,"���ڣ�");
	
	this->cargoID=new Label(5,8,LABEL,"��������Ʒ��ţ�");
	this->edition1=new Edition(20,7,40,3,EDITION,2,20,1,"");
	this->search=new Button(55,7,8,3,BUTTON,"��ѯ");

	this->cargoTable=new Table (4,12,6,4,TABLE,4,2,1);

	this->enter=new Button(5,25,20,3,BUTTON,"������Ʒ��Ϣ[3]");
	this->esc=new Button(50,25,15,3,BUTTON,"����[Esc]");

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

	//������µ�¼�û���Ϣ&����
	Ctools::gotoxy(20,5);
	cout<<Ctools::presentUser->getName();
	Ctools::gotoxy(58,5);
	char timedate[64]={0};
	Ctools::getTime(timedate);
	cout<<timedate;

	//�����û�Ȩ�������ǰ�û���Ϣ
	Ctools::gotoxy(11,5);
	if(Ctools::presentUser->getAuthority()==ADMIN)
	{
		cout<<"����Ա��";
	}
	else if(Ctools::presentUser->getAuthority()==CHECKMAN)
	{
		cout<<"�̵�Ա��";
	}
}


int CargoSearch::winRun()
{
	int i;

	//�ҵ���һ�����й�궨λ���༭��or��ť��
	for(i=0;i<this->ctrlCount;i++)
	{
		if(this->CtrlArr[i]->getCtrlType()==EDITION || this->CtrlArr[i]->getCtrlType()==BUTTON)
		{
			Ctools::gotoxy(this->CtrlArr[i]->getStartx()+2,this->CtrlArr[i]->getStarty()+this->CtrlArr[i]->getHeight()/3);
			break;
		}
	}

	char c1,c2,x;
	
	//ʵ�ּ��̼���
	while(true)
	{
		c1=getch();

		//�����뷽���
		if(c1==-32)
		{
			c2=getch();		
			//��������"��"��
			if(c2==KEY_UP)
			{
				while(1)
				{
					i--;
					if(i==-1){i=this->ctrlCount-1;}
					//�ҵ���һ���༭��or��ť��ֹͣ
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
			//��������"��"��
			else if(c2==KEY_DOWN)
			{
				while(1)
				{
					i++;
					if(i==this->ctrlCount){i=0;}
					//�ҵ���һ���༭��or��ť��ֹͣ
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
			//��������"��"��
			else if(c2==KEY_LEFT)
			{
				//���ҳ���߽��ж�
				if(this->cargoTable->curPage<=1)
				{
					Ctools::gotoxy(30,23);
					cout<<"              ";
					Ctools::gotoxy(30,23);
					cout<<"��ǰΪ��һҳ";
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
			//��������"��"��
			else if(c2==KEY_RIGHT)
			{
				//���ҳ���߽��ж�
				if(this->cargoTable->curPage+1>this->cargoTable->pageCount)
				{
					Ctools::gotoxy(30,23);
					cout<<"              ";
					Ctools::gotoxy(30,23);
					cout<<"��ǰΪ���һҳ";
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
		//������س����ҵ�ǰ�ؼ�Ϊ��ť
		else if(c1=='\r' && this->CtrlArr[i]->getCtrlType()==BUTTON)
		{
			//��Ҫ��¼��ǰѡ��Ŀؼ��±꣬��������button
			this->ctrlIndex=i;
			return this->doAction();
		}
		//�����������ַ���Ϊ�༭��
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
	
	//���༭����ɶ��û��(�����������)
	if(strlen(this->edition1->getContent())==0)
	{
		CargoSearch::searchType=0;
		this->cargoTable->showData();
	}
	//��Ϊģ����ѯor��ȷ��ѯ
	else
	{	
		CargoSearch::searchType=1;

		//�����ʱ����
		//��ձ��
		this->tmpCargoVector.clear();
		this->cargoTable->clearTable();

		map<int,Cargo*>::iterator it1;
		char tmp[20];						//��ʱ�ַ�����

		//������Ʒ��������
		for(it1=Data::cargoMap.begin();it1!=Data::cargoMap.end();it1++)
		{
			itoa(it1->first,tmp,10);
			//�������ַ���Ϊ��Ʒ��ŵ��Ӵ�
			if(strstr(tmp,this->edition1->getContent())!=NULL)
			{
				//����Ʒ����vector��Ʒ��ʱ������
				this->tmpCargoVector.push_back(it1->second);
			}
		}
		

		//��ǰҳ��Ҫ�����������
		int nowPageLine;		
		//���ݵ�ǰҳ��Ʒ�������������������
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
		
		//�������
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
	//��ȡ�ļ���������+GI
	char fileName1[20];
	string fileName2="GI.txt";
	Ctools::getRecordName(fileName1);

	stringstream fileName;
	fileName<<fileName1<<fileName2;

	fstream fs;
	fs.open(fileName.str().c_str(),ios::in | ios::out | ios::app);

	//����ǰ��������Ϊ�������κ�����
	if(CargoSearch::searchType==0)
	{
		//����Ʒ���������ڵ���������д���µ������ļ���
		map<int,Cargo*>::iterator it1;
		for(it1=Data::cargoMap.begin();it1!=Data::cargoMap.end();it1++)
		{
			fs<<it1->first<<" "<<it1->second->getName()<<" "<<it1->second->getType()<<" "<<it1->second->getPrice()<<" "<<it1->second->getCount()<<" "<<it1->second->getLibID()<<endl;
		}
		
		fs.close();

		return true;
	}
	//����ǰ��������Ϊ��������
	else if(CargoSearch::searchType==1)
	{
		//����ʱ�����ڵ���������д���µ������ļ���
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
			cout<<"������Ʒ��Ϣ�ɹ�";
			system("pause");
			Ctools::gotoxy(30,24);
			cout<<"                                   ";
			this->winRun();
		}
		else
		{
			Ctools::gotoxy(30,25);
			cout<<"������Ʒ��Ϣʧ��";
			system("pause");
			Ctools::gotoxy(30,24);
			cout<<"                                   ";
			this->winRun();
		}
		break;
	case 8:
		//��Ϊ����Ա�򿪵Ľ���
		if(Ctools::presentUser->getAuthority()==ADMIN)
		{
			return 3;
		}
		//��Ϊ�̵�Ա�򿪵Ľ���
		else if(Ctools::presentUser->getAuthority()==CHECKMAN)
		{
			return 4;
		}
		break;
	}
}