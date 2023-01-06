#pragma warning (disable : 4786)	//�������� ����
#include "Cargo.h"
#include "CData.h"
#include <list>
#include <string>
#include <iostream>
#include <sstream>					//sstream����Ҫ����������������ת��
using namespace std;


//��̬���ݳ�Ա��ʼ��
int Cargo::defaultCargoID=2001;
string Cargo::defaultLibID="X101";


string Cargo::getNewLibID()
{
	string a=Cargo::defaultLibID.substr(0,1);		//substr()����ȡ���ַ���(���ָ��λ�ÿ�ʼ��������ָ���ĳ���)
	string b=Cargo::defaultLibID.substr(1,3);
	int c=atoi(b.c_str())+Data::cargoMap.size();	//c_str()����string����ת��Ϊ�ַ�����ָ��char*
	stringstream final;
	final<<a<<c;

	return final.str();								//str()����stringstream����ת��Ϊstring����
}


Cargo::Cargo(char name[],char type[],double price,int count)
{
	//ʵ����Ʒ���id����
	this->id=Cargo::defaultCargoID+Data::cargoMap.size();
	//ʵ�ֲֿ�������
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