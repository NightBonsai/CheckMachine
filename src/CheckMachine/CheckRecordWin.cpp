#pragma warning (disable : 4786)	//�������� ����
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
	this->title=new Label(25,3,LABEL,"��ӭʹ��HHS�̵��ϵͳ");
	this->welcome=new Label(5,5,LABEL,"��ӭ��");
	this->date=new Label(50,5,LABEL,"���ڣ�");

	this->sheetTable=new Table(15,10,2,4,TABLE,8,2,3);
	
	this->button1=new Button(15,12,19,3,BUTTON,"");
	this->button2=new Button(15,14,19,3,BUTTON,"");
	this->button3=new Button(15,16,19,3,BUTTON,"");

	this->esc=new Button(15,24,15,3,BUTTON,"����");

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
	//���±����ҳ��
	this->sheetTable->editPageCount();

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

	//������������
	this->sheetTable->showData();
}


int CheckRecordWin::winRun()
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
				if(this->sheetTable->curPage<=1)
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
					this->sheetTable->curPage--;
					this->sheetTable->showData();
					this->sheetTable->showPageInform();
				}
			}
			//��������"��"��
			else if(c2==KEY_RIGHT)
			{
				//���ҳ���߽��ж�
				if(this->sheetTable->curPage+1>this->sheetTable->pageCount)
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
					this->sheetTable->curPage++;
					this->sheetTable->showData();
					this->sheetTable->showPageInform();
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


int CheckRecordWin::doAction()
{
	map<string,vector<CheckRecord*> >::iterator it;
	it=Data::checkSheet.begin();

	switch(this->ctrlIndex)
	{
	//��������ֻ�ܹ���Ա����
	case 4:
		if(Ctools::presentUser->getAuthority()==ADMIN)
		{
			//��ȡ��ǰѡ����̵��
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
			//��ȡ��ǰѡ����̵��
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
			//��ȡ��ǰѡ����̵��
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
		//��Ϊ����Ա�򿪵Ľ���
		if(Ctools::presentUser->getAuthority()==ADMIN)
		{
			return 3;
		}
		//��Ϊ�̵�Ա�򿪵Ľ���
		else if(Ctools::presentUser->getAuthority()==CHECKMAN)
		{
			return 10;
		}
		break;
	}
}
