#pragma warning (disable : 4786)	//命名过长 容器
#include "Cargo.h"
#include "CData.h"
#include <list>
#include <string>
#include <iostream>
#include <sstream>					//sstream库主要用来进行数据类型转换
using namespace std;


//静态数据成员初始化
int Cargo::defaultCargoID=2001;
string Cargo::defaultLibID="X101";


string Cargo::getNewLibID()
{
	string a=Cargo::defaultLibID.substr(0,1);		//substr()：获取子字符串(求从指定位置开始，并具有指定的长度)
	string b=Cargo::defaultLibID.substr(1,3);
	int c=atoi(b.c_str())+Data::cargoMap.size();	//c_str()：把string对象转换为字符数组指针char*
	stringstream final;
	final<<a<<c;

	return final.str();								//str()：将stringstream类型转换为string类型
}


Cargo::Cargo(char name[],char type[],double price,int count)
{
	//实现商品编号id自增
	this->id=Cargo::defaultCargoID+Data::cargoMap.size();
	//实现仓库编号自增
	this->libID=this->getNewLibID();

	strcpy(this->name,name);
	strcpy(this->type,type);
	this->price=price;
	this->count=count;
}
Cargo::~Cargo()
{
}


int Cargo::getID()
{
	return this->id;
}
double Cargo::getPrice()
{
	return this->price;
}
char* Cargo::getName()
{
	return this->name;
}
char* Cargo::getType()
{
	return this->type;
}
int Cargo::getCount()
{
	return this->count;
}
string Cargo::getLibID()
{
	return this->libID;
}


void Cargo::add(int num)
{
	this->count=this->count+num;
}


void Cargo::minus(int num)
{
	this->count=this->count-num;
}


void Cargo::editCount(int num)
{
	this->count=num;
}


void Cargo::printCargoInfo()
{
	cout<<"id:"<<this->id<<endl;
	cout<<"name:"<<this->name<<endl;
	cout<<"type:"<<this->type<<endl;
	cout<<"price:"<<this->price<<endl;
	cout<<"libID:"<<this->libID<<endl;
	cout<<"count:"<<this->count<<endl;
}