#pragma warning (disable : 4786)	//�������� ����
#include "CTable.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include "CtrlBase.h"
#include "CData.h"
#include "CTool.h"
#include "Cargo.h"
#include "CheckRecordWin.h"
#include "CorrectRecordWin.h"
using namespace std;


Table::Table(int x,int y,int w,int h,int type,int cw,int ch,int tabletype):CtrlBase(x,y,w,h,type)
{
	this->cellWidth=cw;				//���ӿ��
	this->cellHeight=ch;
	this->tableType=tabletype;
	
	//��Ϊ��Ʒ��ѯ���
	if(tabletype==1)
	{
		//������ҳ��
		if(Data::cargoMap.size()%(h-1)==0)
		{
			this->pageCount=Data::cargoMap.size()/(h-1);
		}
		else
		{
			this->pageCount=Data::cargoMap.size()/(h-1)+1;
		}
		//��ǰҳ��
		this->curPage=1;
		
		//��ͷ
		this->tableHead.push_back("��Ʒ���");
		this->tableHead.push_back("��Ʒ����");
		this->tableHead.push_back("��Ʒ����");
		this->tableHead.push_back("��Ʒ�۸�");
		this->tableHead.push_back("�������");
		this->tableHead.push_back("��λ���");
	}
	//��Ϊ�̵��¼���
	else if(tabletype==2)
	{
		//������ҳ��
		if(Data::checkRecords.size()%(h-1)==0)
		{
			this->pageCount=Data::checkRecords.size()/(h-1);
		}
		else
		{
			this->pageCount=Data::checkRecords.size()/(h-1)+1;
		}
		//��ǰҳ��
		this->curPage=1;

		//��ͷ
		this->tableHead.push_back("��Ʒ���");
		this->tableHead.push_back("��Ʒ����");
		this->tableHead.push_back("�������");
		this->tableHead.push_back("�̵�����");
		this->tableHead.push_back("��������");
		this->tableHead.push_back("���̱�־");
	}
	//��Ϊ�̵����
	else if(tabletype==3)
	{
		//������ҳ��
		if(Data::checkSheet.size()%(h-1)==0)
		{
			this->pageCount=Data::checkSheet.size()/(h-1);
		}
		else
		{
			this->pageCount=Data::checkSheet.size()/(h-1)+1;
		}
		//��ǰҳ��
		this->curPage=1;

		//��ͷ
		this->tableHead.push_back("�̵���");
		this->tableHead.push_back("�̵�״̬");
	}
	//��Ϊ�̵�������
	else if(tabletype==4)
	{
		//��ȡ��Ӧ�̵��
		map<string,vector<CheckRecord*> >::iterator it_map;
		it_map=Data::checkSheet.find(CorrectRecordWin::checkSheetID);

		//������ҳ��
		if(it_map->second.size()%(h-1)==0)
		{
			this->pageCount=it_map->second.size()/(h-1);
		}
		else
		{
			this->pageCount=it_map->second.size()/(h-1)+1;
		}
		//��ǰҳ��
		this->curPage=1;

		//��ͷ
		this->tableHead.push_back("��Ʒ���");
		this->tableHead.push_back("��Ʒ����");
		this->tableHead.push_back("�������");
		this->tableHead.push_back("�̵�����");
		this->tableHead.push_back("��������");
		this->tableHead.push_back("��������");
		this->tableHead.push_back("����˵��");
	}
}
Table::~Table()
{}


int Table::getCellWidth()
{
	return this->cellWidth;
}
int Table::getCellHeight()
{
	return this->cellHeight;
}
void Table::editPageCount()
{
	if(this->tableType==3)
	{
		//������ҳ��
		if(Data::checkSheet.size()%(this->height-1)==0)
		{
			this->pageCount=Data::checkSheet.size()/(this->height-1);
		}
		else
		{
			this->pageCount=Data::checkSheet.size()/(this->height-1)+1;
		}
	}
	else if(this->tableType==4)
	{
		//��ȡ��Ӧ�̵��
		map<string,vector<CheckRecord*> >::iterator it_map;
		it_map=Data::checkSheet.find(CorrectRecordWin::checkSheetID);

		//������ҳ��
		if(it_map->second.size()%(this->height-1)==0)
		{
			this->pageCount=it_map->second.size()/(this->height-1);
		}
		else
		{
			this->pageCount=it_map->second.size()/(this->height-1)+1;
		}
	}
}


void Table::show()
{
	int i,j,k,z;

	//�����
	//����������
	for(i=0;i<this->height;i++)
	{
		Ctools::gotoxy(this->startx,this->starty+i*(this->cellHeight));
		//�������ÿһ��
		cout<<"�� ";
		for(j=0;j<this->width;j++)
		{
			for(k=0;k<this->cellWidth;k++)
			{
				cout<<"�� ";
			}
			if(j==this->width-1)
			{
				cout<<"��";
			}
			else 
			{
				cout<<"�� ";
			}
		}
		for(z=1;z<this->cellHeight;z++)
		{
			Ctools::gotoxy(this->startx,this->starty+i*(this->cellHeight)+z);
			cout<<"�� ";
			for(j=0;j<this->width;j++)
			{
				for(k=0;k<this->cellWidth;k++)
				{
					cout<<"  ";
				}
				if(j==this->width-1)
				{
					cout<<"��";
				}
				else
				{
					cout<<"�� ";
				}
			}
		}
		Ctools::gotoxy(this->startx,this->starty+i*(this->cellHeight)+this->cellHeight);
		cout<<"�� ";
		for(j=0;j<this->width;j++)
		{
			for(k=0;k<this->cellWidth;k++)
			{
				cout<<"�� ";
			}
			if(j==this->width-1)
			{
				cout<<"��";
			}
			else
			{
				cout<<"�� ";
			}
		}
	}
	
	//�����ͷ
	for(j=0;j<this->width;j++)
	{
		Ctools::gotoxy( this->startx+2+j*(this->cellWidth*2.5), this->starty+this->cellHeight/2 );
		cout<<this->tableHead[j];
	}

	this->showPageInform();
}


void Table::showPageInform()
{
	Ctools::gotoxy(30,22);
	cout<<this->curPage<<'/'<<this->pageCount<<endl;

	Ctools::gotoxy(40,22);
	cout<<"��<-->����ҳ";
}


void Table::showData()
{
	//��ձ��
	this->clearTable();
	
	//��ǰҳ��Ҫ�����������
	int i,nowPageLine;

	//����ǰΪ��Ʒ��ѯ���
	if(this->tableType==1)
	{
		//��ǰ�����һ�����ݵļ�ֵ
		int key=Cargo::defaultCargoID+(this->curPage-1)*(this->height-1);	

		//���ݵ�ǰҳ��Ʒ�������������������
		if(Data::cargoMap.size()>=this->curPage*(this->height-1))
		{
			nowPageLine=this->height;
		}
		else if(Data::cargoMap.size()<this->curPage*(this->height-1))
		{
			nowPageLine=Data::cargoMap.size()-(this->curPage-1)*(this->height-1)+1;
		}

		//����ÿ��
		for(i=1;i<nowPageLine;i++)
		{
			//���ݵ�ǰҳ�����ݸ���
			//�������ÿһ�е�����
			Ctools::gotoxy( this->startx+2+0*(this->cellWidth*2.5), this->starty+i*(this->cellHeight)+1 );
			cout<<Data::cargoMap[key]->getID();
			Ctools::gotoxy( this->startx+2+1*(this->cellWidth*2.5), this->starty+i*(this->cellHeight)+1 );
			cout<<Data::cargoMap[key]->getName();
			Ctools::gotoxy( this->startx+2+2*(this->cellWidth*2.5), this->starty+i*(this->cellHeight)+1 );
			cout<<Data::cargoMap[key]->getType();
			Ctools::gotoxy( this->startx+2+3*(this->cellWidth*2.5), this->starty+i*(this->cellHeight)+1 );
			cout<<Data::cargoMap[key]->getPrice();
			Ctools::gotoxy( this->startx+2+4*(this->cellWidth*2.5), this->starty+i*(this->cellHeight)+1 );
			cout<<Data::cargoMap[key]->getCount();
			Ctools::gotoxy( this->startx+2+5*(this->cellWidth*2.5), this->starty+i*(this->cellHeight)+1 );
			cout<<Data::cargoMap[key]->getLibID();
			key++;
		}
	}
	//����ǰΪ�̵��¼���
	else if(this->tableType==2)
	{	
		//��ȡ��ǰҳ��ĵ�һ��vector�����ĵ�����
		vector<CheckRecord*>::iterator it=Data::checkRecords.begin();
		it=it+(this->curPage-1)*(this->height-1);

		//���ݵ�ǰҳ��Ʒ�������������������
		if(Data::checkRecords.size()>=this->curPage*(this->height-1))
		{
			nowPageLine=this->height;
		}
		else if(Data::checkRecords.size()<this->curPage*(this->height-1))
		{
			nowPageLine=Data::checkRecords.size()-(this->curPage-1)*(this->height-1)+1;
		}

		//����ÿ��
		for(i=1;i<nowPageLine;i++)
		{
			//���ݵ�ǰҳ�����ݸ���
			//�������ÿһ�е�����
			Ctools::gotoxy( this->startx+2+0*(this->cellWidth*2.5), this->starty+i*(this->cellHeight)+1 );
			cout<<(*it)->getID();
			Ctools::gotoxy( this->startx+2+1*(this->cellWidth*2.5), this->starty+i*(this->cellHeight)+1 );
			cout<<(*it)->getName();
			Ctools::gotoxy( this->startx+2+2*(this->cellWidth*2.5), this->starty+i*(this->cellHeight)+1 );
			cout<<(*it)->getCount();
			Ctools::gotoxy( this->startx+2+3*(this->cellWidth*2.5), this->starty+i*(this->cellHeight)+1 );
			cout<<(*it)->getCheckCount();
			Ctools::gotoxy( this->startx+2+4*(this->cellWidth*2.5), this->starty+i*(this->cellHeight)+1 );
			cout<<(*it)->getDifCount();
			Ctools::gotoxy( this->startx+2+5*(this->cellWidth*2.5), this->starty+i*(this->cellHeight)+1 );
			cout<<"";
			it++;

			//��������������ĩβ
			if(it==Data::checkRecords.end())
			{
				break;
			}
		}
	}
	//����ǰΪ�̵����
	else if(this->tableType==3)
	{
		//��ȡ��ǰҳ��ĵ�һ��map�����ĵ�����
		map<string,vector<CheckRecord*> >::iterator it=Data::checkSheet.begin();
		advance(it,(this->curPage-1)*(this->height-1));

		//���ݵ�ǰҳ��Ʒ�������������������
		if(Data::checkSheet.size()>=this->curPage*(this->height-1))
		{
			nowPageLine=this->height;
		}
		else if(Data::checkSheet.size()<this->curPage*(this->height-1))
		{
			nowPageLine=Data::checkSheet.size()-(this->curPage-1)*(this->height-1)+1;
		}
		
		//��¼�ѳ������̵��¼����
		int correctCount;
		vector<CheckRecord*>::iterator it_vector;
		//����ÿ��
		for(i=1;i<nowPageLine;i++)
		{
			correctCount=0;
			
			//���ݵ�ǰҳ�����ݸ���
			//�������ÿһ�е�����
			Ctools::gotoxy( this->startx+2+0*(this->cellWidth*2.5), this->starty+i*(this->cellHeight)+1 );
			cout<<it->first;
			Ctools::gotoxy( this->startx+2+1*(this->cellWidth*2.5), this->starty+i*(this->cellHeight)+1 );

			//�жϵ�ǰ�̵���Ƿ���ɳ���
			for(it_vector=it->second.begin();it_vector!=it->second.end();it_vector++)
			{
				if((*it_vector)->getState()==1)
				{
					correctCount++;	
				}
			}
			if(correctCount==it->second.size())
			{
				cout<<"�ѳ���";
			}
			else
			{
				cout<<"δ����";
			}

			it++;
			//��������������ĩβ
			if(it==Data::checkSheet.end())
			{
				break;
			}
		}
	}
	//����ǰΪ�̵�������
	else if(this->tableType==4)
	{
		//��ȡ��ǰҳ��ĵ�һ��vector�����ĵ�����
		vector<CheckRecord*>::iterator it=Data::checkRecords.begin();
		map<string,vector<CheckRecord*> >::iterator it_map;
		
		it_map=Data::checkSheet.find(CorrectRecordWin::checkSheetID);
		it=it_map->second.begin();
		advance(it,(this->curPage-1)*(this->height-1));

		//���ݵ�ǰҳ��Ʒ�������������������
		if(it_map->second.size()>=this->curPage*(this->height-1))
		{
			nowPageLine=this->height;
		}
		else if(it_map->second.size()<this->curPage*(this->height-1))
		{
			nowPageLine=it_map->second.size()-(this->curPage-1)*(this->height-1)+1;
		}

		//����ÿ��
		for(i=1;i<nowPageLine;i++)
		{
			//���ݵ�ǰҳ�����ݸ���
			//�������ÿһ�е�����
			Ctools::gotoxy( this->startx+2+0*(this->cellWidth*2.5), this->starty+i*(this->cellHeight)+1 );
			cout<<(*it)->getID();
			Ctools::gotoxy( this->startx+2+1*(this->cellWidth*2.5), this->starty+i*(this->cellHeight)+1 );
			cout<<(*it)->getName();
			Ctools::gotoxy( this->startx+2+2*(this->cellWidth*2.5), this->starty+i*(this->cellHeight)+1 );
			cout<<(*it)->getCount();
			Ctools::gotoxy( this->startx+2+3*(this->cellWidth*2.5), this->starty+i*(this->cellHeight)+1 );
			cout<<(*it)->getCheckCount();
			Ctools::gotoxy( this->startx+2+4*(this->cellWidth*2.5), this->starty+i*(this->cellHeight)+1 );
			cout<<(*it)->getDifCount();
			Ctools::gotoxy( this->startx+2+5*(this->cellWidth*2.5), this->starty+i*(this->cellHeight)+1 );
			cout<<(*it)->getDifCount();
			Ctools::gotoxy( this->startx+2+5*(this->cellWidth*2.5), this->starty+i*(this->cellHeight)+1 );
			cout<<"";
			it++;

			//��������������ĩβ
			if(it==it_map->second.end())
			{
				break;
			}
		}
	}
}


void Table::clearTable()
{
	int i,j=0;

	//����ÿ��
	for(i=1;i<this->height;i++)
	{
		//����ÿһ���ÿո���и���
		for(j=0;j<this->width;j++)
		{
			Ctools::gotoxy( this->startx+2+j*(this->cellWidth*2.5), this->starty+i*(this->cellHeight)+1 );
			cout<<"            ";
		}
	}

	//����������
	this->show();
}