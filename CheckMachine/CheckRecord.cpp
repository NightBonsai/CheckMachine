#include "CheckRecord.h"
#include <string>
using namespace std;


CheckRecord::CheckRecord(int id,char name[],int count,int checkCount,string libID,int state)
{
	this->id=id;
	strcpy(this->name,name);
	this->count=count;
	this->checkCount=checkCount;
	this->libID=libID;
	this->state=state;

	//计算差异数量
	if(count>checkCount)
	{
		this->difCount=count-checkCount;
	}
	else if(count<checkCount)
	{
		this->difCount=checkCount-count;
	}
	else
	{
		this->difCount=0;
	}
}
CheckRecord::~CheckRecord()
{}


int CheckRecord::getID()
{
	return this->id;
}
char* CheckRecord::getName()
{
	return this->name;
}
int CheckRecord::getCount()
{
	return this->count;
}
int CheckRecord::getCheckCount()
{
	return this->checkCount;
}
int CheckRecord::getDifCount()
{
	return this->difCount;
}
string CheckRecord::getLibID()
{
	return this->libID;
}
int CheckRecord::getState()
{
	return this->state;
}


void CheckRecord::addCheckCount(int num)
{
	//累加盘点数量
	this->checkCount=this->checkCount+num;

	//重新计算差异数量
	if(count>checkCount)
	{
		this->difCount=count-checkCount;
	}
	else if(count<checkCount)
	{
		this->difCount=checkCount-count;
	}
	else
	{
		this->difCount=0;
	}
}


void CheckRecord::editCount(int correctNum)
{
	if(this->count > this->checkCount)
	{
		this->count=this->count-correctNum;
	}
	else if(this->count < this->checkCount)
	{
		this->count=this->count+correctNum;
	}
}


void CheckRecord::editDifCount()
{
	if(this->count > this->checkCount)
	{
		this->difCount=this->count-this->checkCount;
	}
	else if(this->count < this->checkCount)
	{
		this->difCount=this->checkCount-this->count;
	}
	else
	{
		this->difCount=0;
	}
}


void CheckRecord::editState()
{
	this->state=1;
}