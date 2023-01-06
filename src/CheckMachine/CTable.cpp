#pragma warning (disable : 4786)	//命名过长 容器
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
	this->cellWidth=cw;				//格子宽高
	this->cellHeight=ch;
	this->tableType=tabletype;
	
	//若为商品查询表格
	if(tabletype==1)
	{
		//求表格总页数
		if(Data::cargoMap.size()%(h-1)==0)
		{
			this->pageCount=Data::cargoMap.size()/(h-1);
		}
		else
		{
			this->pageCount=Data::cargoMap.size()/(h-1)+1;
		}
		//当前页数
		this->curPage=1;
		
		//表头
		this->tableHead.push_back("商品编号");
		this->tableHead.push_back("商品名称");
		this->tableHead.push_back("商品类型");
		this->tableHead.push_back("商品价格");
		this->tableHead.push_back("库存数量");
		this->tableHead.push_back("仓位编号");
	}
	//若为盘点记录表格
	else if(tabletype==2)
	{
		//求表格总页数
		if(Data::checkRecords.size()%(h-1)==0)
		{
			this->pageCount=Data::checkRecords.size()/(h-1);
		}
		else
		{
			this->pageCount=Data::checkRecords.size()/(h-1)+1;
		}
		//当前页数
		this->curPage=1;

		//表头
		this->tableHead.push_back("商品编号");
		this->tableHead.push_back("商品名称");
		this->tableHead.push_back("库存数量");
		this->tableHead.push_back("盘点数量");
		this->tableHead.push_back("差异数量");
		this->tableHead.push_back("复盘标志");
	}
	//若为盘点表表格
	else if(tabletype==3)
	{
		//求表格总页数
		if(Data::checkSheet.size()%(h-1)==0)
		{
			this->pageCount=Data::checkSheet.size()/(h-1);
		}
		else
		{
			this->pageCount=Data::checkSheet.size()/(h-1)+1;
		}
		//当前页数
		this->curPage=1;

		//表头
		this->tableHead.push_back("盘点编号");
		this->tableHead.push_back("盘点状态");
	}
	//若为盘点冲正表格
	else if(tabletype==4)
	{
		//获取对应盘点表
		map<string,vector<CheckRecord*> >::iterator it_map;
		it_map=Data::checkSheet.find(CorrectRecordWin::checkSheetID);

		//求表格总页数
		if(it_map->second.size()%(h-1)==0)
		{
			this->pageCount=it_map->second.size()/(h-1);
		}
		else
		{
			this->pageCount=it_map->second.size()/(h-1)+1;
		}
		//当前页数
		this->curPage=1;

		//表头
		this->tableHead.push_back("商品编号");
		this->tableHead.push_back("商品名称");
		this->tableHead.push_back("库存数量");
		this->tableHead.push_back("盘点数量");
		this->tableHead.push_back("差异数量");
		this->tableHead.push_back("冲正数量");
		this->tableHead.push_back("冲正说明");
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
		//求表格总页数
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
		//获取对应盘点表
		map<string,vector<CheckRecord*> >::iterator it_map;
		it_map=Data::checkSheet.find(CorrectRecordWin::checkSheetID);

		//求表格总页数
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

	//画表格
	//遍历所有行
	for(i=0;i<this->height;i++)
	{
		Ctools::gotoxy(this->startx,this->starty+i*(this->cellHeight));
		//遍历输出每一列
		cout<<"┏ ";
		for(j=0;j<this->width;j++)
		{
			for(k=0;k<this->cellWidth;k++)
			{
				cout<<"━ ";
			}
			if(j==this->width-1)
			{
				cout<<"┓";
			}
			else 
			{
				cout<<"┬ ";
			}
		}
		for(z=1;z<this->cellHeight;z++)
		{
			Ctools::gotoxy(this->startx,this->starty+i*(this->cellHeight)+z);
			cout<<"┃ ";
			for(j=0;j<this->width;j++)
			{
				for(k=0;k<this->cellWidth;k++)
				{
					cout<<"  ";
				}
				if(j==this->width-1)
				{
					cout<<"┃";
				}
				else
				{
					cout<<"┃ ";
				}
			}
		}
		Ctools::gotoxy(this->startx,this->starty+i*(this->cellHeight)+this->cellHeight);
		cout<<"┗ ";
		for(j=0;j<this->width;j++)
		{
			for(k=0;k<this->cellWidth;k++)
			{
				cout<<"━ ";
			}
			if(j==this->width-1)
			{
				cout<<"┛";
			}
			else
			{
				cout<<"┴ ";
			}
		}
	}
	
	//输出表头
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
	cout<<"按<-->键翻页";
}


void Table::showData()
{
	//清空表格
	this->clearTable();
	
	//当前页面要输出几行数据
	int i,nowPageLine;

	//若当前为商品查询表格
	if(this->tableType==1)
	{
		//当前界面第一个数据的键值
		int key=Cargo::defaultCargoID+(this->curPage-1)*(this->height-1);	

		//根据当前页商品个数决定输出几行数据
		if(Data::cargoMap.size()>=this->curPage*(this->height-1))
		{
			nowPageLine=this->height;
		}
		else if(Data::cargoMap.size()<this->curPage*(this->height-1))
		{
			nowPageLine=Data::cargoMap.size()-(this->curPage-1)*(this->height-1)+1;
		}

		//遍历每行
		for(i=1;i<nowPageLine;i++)
		{
			//根据当前页面数据个数
			//遍历输出每一列的数据
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
	//若当前为盘点记录表格
	else if(this->tableType==2)
	{	
		//获取当前页面的第一个vector容器的迭代器
		vector<CheckRecord*>::iterator it=Data::checkRecords.begin();
		it=it+(this->curPage-1)*(this->height-1);

		//根据当前页商品个数决定输出几行数据
		if(Data::checkRecords.size()>=this->curPage*(this->height-1))
		{
			nowPageLine=this->height;
		}
		else if(Data::checkRecords.size()<this->curPage*(this->height-1))
		{
			nowPageLine=Data::checkRecords.size()-(this->curPage-1)*(this->height-1)+1;
		}

		//遍历每行
		for(i=1;i<nowPageLine;i++)
		{
			//根据当前页面数据个数
			//遍历输出每一列的数据
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

			//若迭代器到容器末尾
			if(it==Data::checkRecords.end())
			{
				break;
			}
		}
	}
	//若当前为盘点表表格
	else if(this->tableType==3)
	{
		//获取当前页面的第一个map容器的迭代器
		map<string,vector<CheckRecord*> >::iterator it=Data::checkSheet.begin();
		advance(it,(this->curPage-1)*(this->height-1));

		//根据当前页商品个数决定输出几行数据
		if(Data::checkSheet.size()>=this->curPage*(this->height-1))
		{
			nowPageLine=this->height;
		}
		else if(Data::checkSheet.size()<this->curPage*(this->height-1))
		{
			nowPageLine=Data::checkSheet.size()-(this->curPage-1)*(this->height-1)+1;
		}
		
		//记录已冲正的盘点记录个数
		int correctCount;
		vector<CheckRecord*>::iterator it_vector;
		//遍历每行
		for(i=1;i<nowPageLine;i++)
		{
			correctCount=0;
			
			//根据当前页面数据个数
			//遍历输出每一列的数据
			Ctools::gotoxy( this->startx+2+0*(this->cellWidth*2.5), this->starty+i*(this->cellHeight)+1 );
			cout<<it->first;
			Ctools::gotoxy( this->startx+2+1*(this->cellWidth*2.5), this->starty+i*(this->cellHeight)+1 );

			//判断当前盘点表是否完成冲正
			for(it_vector=it->second.begin();it_vector!=it->second.end();it_vector++)
			{
				if((*it_vector)->getState()==1)
				{
					correctCount++;	
				}
			}
			if(correctCount==it->second.size())
			{
				cout<<"已冲正";
			}
			else
			{
				cout<<"未冲正";
			}

			it++;
			//若迭代器到容器末尾
			if(it==Data::checkSheet.end())
			{
				break;
			}
		}
	}
	//若当前为盘点冲正表格
	else if(this->tableType==4)
	{
		//获取当前页面的第一个vector容器的迭代器
		vector<CheckRecord*>::iterator it=Data::checkRecords.begin();
		map<string,vector<CheckRecord*> >::iterator it_map;
		
		it_map=Data::checkSheet.find(CorrectRecordWin::checkSheetID);
		it=it_map->second.begin();
		advance(it,(this->curPage-1)*(this->height-1));

		//根据当前页商品个数决定输出几行数据
		if(it_map->second.size()>=this->curPage*(this->height-1))
		{
			nowPageLine=this->height;
		}
		else if(it_map->second.size()<this->curPage*(this->height-1))
		{
			nowPageLine=it_map->second.size()-(this->curPage-1)*(this->height-1)+1;
		}

		//遍历每行
		for(i=1;i<nowPageLine;i++)
		{
			//根据当前页面数据个数
			//遍历输出每一列的数据
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

			//若迭代器到容器末尾
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

	//遍历每行
	for(i=1;i<this->height;i++)
	{
		//遍历每一列用空格进行覆盖
		for(j=0;j<this->width;j++)
		{
			Ctools::gotoxy( this->startx+2+j*(this->cellWidth*2.5), this->starty+i*(this->cellHeight)+1 );
			cout<<"            ";
		}
	}

	//重新输出表格
	this->show();
}