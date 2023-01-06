#pragma warning (disable : 4786)	//�������� ����
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
	this->title=new Label(25,3,LABEL,"��ӭʹ��HHS�̵��ϵͳ");
	this->welcome=new Label(5,5,LABEL,"��ӭ���̵�Ա��");
	this->date=new Label(50,5,LABEL,"���ڣ�");
	this->checkID=new Label(5,8,LABEL,"�̵��ţ�");

	this->cargoID=new Label(5,11,LABEL,"��������Ʒ��ţ�");
	this->edition1=new Edition(20,10,40,3,EDITION,2,20,1,"");
	this->search=new Button(55,10,8,3,BUTTON,"��ѯ");

	this->count1=new Label(41,15,LABEL,"�������̵�������");
	this->count2=new Label(41,17,LABEL,"[1-10000]");
	this->edition2=new Edition(40,18,25,3,EDITION,2,20,1,"");
	this->enter=new Button(40,21,12,3,BUTTON,"ȷ��Enter");
	this->esc=new Button(53,21,12,3,BUTTON,"ȡ��Esc");
	this->newCheck=new Button(40,24,20,3,BUTTON,"�����̵��[1]");

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

	//������µ�¼�û���Ϣ&����
	Ctools::gotoxy(20,5);
	cout<<Ctools::presentUser->getName();
	Ctools::gotoxy(58,5);
	char timedate[64]={0};
	Ctools::getTime(timedate);
	cout<<timedate;

	//�����ǰ�̵���
	Ctools::gotoxy(20,8);
	cout<<Data::getCheckID();

	//�����Ʒ��Ϣ��ǩ
	Ctools::gotoxy(7,15);
	cout<<"��Ʒ���ƣ�";
	Ctools::gotoxy(7,18);
	cout<<"��Ʒ���ͣ�";
	Ctools::gotoxy(7,21);
	cout<<"��Ʒ�۸�";
	Ctools::gotoxy(7,24);
	cout<<"��λ��ţ�";
}


int NewCheckWin::searchCargo()
{
	//�����������Ʒ�������Ʒmap���������м�����Ӧ��ֵ��
	map<int,Cargo*>::iterator it;

	int cargoID=atoi(this->edition1->getContent());			//����Ʒ��ű༭�����ַ���ת��Ϊ����
	it=Data::cargoMap.find(cargoID);							//��������ȡfind���صļ�ֵ��

	//��δ�ҵ���Ӧ��ֵ��
	if(it==Data::cargoMap.end())
	{
		Ctools::gotoxy(18,15);
		cout<<"             ";
		Ctools::gotoxy(18,15);
		cout<<"δ�ҵ���Ӧ��Ʒ";

		Ctools::gotoxy(18,18);
		cout<<"             ";

		Ctools::gotoxy(18,21);
		cout<<"             ";

		Ctools::gotoxy(18,24);
		cout<<"             ";

		//���õ�ǰ��������Ʒ���
		NewCheckWin::searchCargoID=0;

		return 0;
	}
	//���ҵ���Ӧ��ֵ��
	else
	{
		//��Ʒ����
		Ctools::gotoxy(18,15);
		cout<<"             ";
		Ctools::gotoxy(18,15);
		cout<<it->second->getName();
		//��Ʒ����
		Ctools::gotoxy(18,18);
		cout<<"             ";
		Ctools::gotoxy(18,18);
		cout<<it->second->getType();
		//��Ʒ�۸�
		Ctools::gotoxy(18,21);
		cout<<"             ";
		Ctools::gotoxy(18,21);
		cout<<it->second->getPrice();
		//��Ʒ����
		Ctools::gotoxy(18,24);
		cout<<"             ";
		Ctools::gotoxy(18,24);
		cout<<it->second->getLibID().c_str();

		//�洢��ǰ��������Ʒ���
		NewCheckWin::searchCargoID=it->first;

		return 1;
	}
}


void NewCheckWin::cargoCheck()
{
	map<int,Cargo*>::iterator it1;
	
	it1=Data::cargoMap.find(NewCheckWin::searchCargoID);

	//����ǰδ�м�����Ʒ
	if(it1==Data::cargoMap.end())
	{
		//�����ʾ
		Ctools::gotoxy(7,26);
		cout<<"���ȼ�����Ʒ";
		system("pause");
		Ctools::gotoxy(7,26);
		cout<<"                              ";
		
		//ˢ�±༭������
		NewCheckWin::searchCargoID=0;
		this->edition1->editContent("");
		this->edition2->editContent("");
		this->showWin();
	}
	//����ǰ�Ѿ�������Ʒ
	else
	{
		//��ȡ�̵������༭���ڸ���
		int checkNum=atoi(this->edition2->getContent());
		//���п�
		if(strcmp(this->edition2->getContent(),"")==0)
		{
			//�����ʾ
			Ctools::gotoxy(7,26);
			cout<<"�̵���������Ϊ��";
			system("pause");
			Ctools::gotoxy(7,26);
			cout<<"                                 ";
			
			//���õ�ǰ��������Ʒ���
			NewCheckWin::searchCargoID=0;
			//ˢ�±༭������
			NewCheckWin::searchCargoID=0;
			this->edition1->editContent("");
			this->edition2->editContent("");
			this->showWin();
			
			return;
		}
		//���̵���������Ҫ��
		else if(checkNum>=1 && checkNum<=10000)
		{
			vector<CheckRecord*>::iterator it_vector;
			
			//�����̵��¼
			//�����Ƿ������ͬ�̵��¼
			for(it_vector=Data::checkRecords.begin();it_vector!=Data::checkRecords.end();it_vector++)
			{
				
				//����¼�Ѵ��ڣ������
				if((*it_vector)->getID()==NewCheckWin::searchCargoID)
				{
					(*it_vector)->addCheckCount(checkNum);
					
					//�����ʾ
					Ctools::gotoxy(7,26);
					cout<<"��Ʒ�̵�ɹ�";
					system("pause");
					Ctools::gotoxy(7,26);
					cout<<"                              ";
					
					//���õ�ǰ��������Ʒ���
					NewCheckWin::searchCargoID=0;
					//ˢ�±༭������
					NewCheckWin::searchCargoID=0;
					this->edition1->editContent("");
					this->edition2->editContent("");
					this->showWin();
					
					return;
				}
			}
			//����¼δ����
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
			
			//�����ʾ
			Ctools::gotoxy(7,26);
			cout<<"��Ʒ�̵�ɹ�";
			system("pause");
			Ctools::gotoxy(7,26);
			cout<<"                              ";
			
			//���õ�ǰ��������Ʒ���
			NewCheckWin::searchCargoID=0;
			//ˢ�±༭������
			NewCheckWin::searchCargoID=0;
			this->edition1->editContent("");
			this->edition2->editContent("");
			this->showWin();
		}
		//���̵�����������Ҫ��
		else
		{
			Ctools::gotoxy(18,26);
			cout<<"�̵��������Ϸ�";
			system("pause");
			Ctools::gotoxy(18,26);
			cout<<"                                  ";

			//ˢ�±༭������
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
		//�����Ʒ�����ɹ�
		if(this->searchCargo()==1)
		{
			return this->winRun();
		}
		//�����Ʒδ�����ɹ�
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
	this->reInput=new Button(30,15,15,3,BUTTON,"��������[1]");

	this->addCtrl(reInput);
}
Tip::~Tip()
{}


void Tip::showWin()
{
	Window::showWin();

	Ctools::gotoxy(20,10);
	cout<<"��ʾ��";
	Ctools::gotoxy(25,12);
	cout<<"δ�ҵ���Ӧ����Ʒ";
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
	this->title=new Label(25,3,LABEL,"��ӭʹ��HHS�̵��ϵͳ");
	this->welcome=new Label(5,5,LABEL,"��ӭ���̵�Ա��");
	this->date=new Label(50,5,LABEL,"���ڣ�");
	this->checkID=new Label(5,8,LABEL,"�̵��ţ�");
	this->checkState=new Label(50,8,LABEL,"�̵�״̬��");

	this->cargoTable=new Table(5,12,6,4,TABLE,4,2,2);

	this->endCheck=new Button(5,24,15,3,BUTTON,"�����̵�");
	this->esc=new Button(25,24,8,3,BUTTON,"����");

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

	//������µ�¼�û���Ϣ&����
	Ctools::gotoxy(20,5);
	cout<<Ctools::presentUser->getName();
	Ctools::gotoxy(58,5);
	char timedate[64]={0};
	Ctools::getTime(timedate);
	cout<<timedate;

	//�����ǰ�̵���
	Ctools::gotoxy(20,8);
	cout<<Data::getCheckID();

	//�����ǰ�̵�״̬
	Ctools::gotoxy(60,8);
	cout<<"������";

	//����������
	this->cargoTable->showData();
}


int NewSheetWin::winRun()
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


void NewSheetWin::newSheet()
{
	vector<CheckRecord*>::iterator it;
	//�½��̵�����̵��¼д���̵��
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

	//���̵��д���ļ���;
	//��ȡ�ļ���
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

	//�����ʾ
	Ctools::gotoxy(40,26);
	cout<<"�½��̵��ɹ�";
	system("pause");
	Ctools::gotoxy(40,26);
	cout<<"                          ";

	//�����ǰ�̵����̵��¼�����ڴ洢��һ���̵����̵��¼
	Data::checkRecords.clear();
	
	//�̵�������
	//���̵�������д���ļ�
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
