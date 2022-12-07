#include "CData.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <conio.h>
#include "CTool.h"
#include "CUser.h"
#include "Cargo.h"
#include "CWindow.h"
#include "CStartWin.h"
#include "CLogWin.h"
#include "CRegistWin.h"
#include "CAdminWin.h"
#include "CheckWin.h"
#include "CargoInLibMenu.h"
#include "CargoOutLibMenu.h"
#include "CargoInLibWin.h"
#include "CargoOutLibWin.h"
#include "CargoSearch.h"
#include "CargoCheckMenu.h"
#include "CNewCheckWin.h"
#include "CheckRecordWin.h"
#include "CorrectRecordWin.h"
using namespace std;

int userCount=2;
map<int,Cargo*> Data::cargoMap;			
map<int,User*> Data::userMap;
vector<Window*> Data::CheckMashine;
vector<CheckRecord*> Data::checkRecords;
map<string,vector<CheckRecord*> > Data::checkSheet;

int Data::checkID2=101;


void Data::initCargoMap()
{
	//���ļ��������ļ�������
	fstream fs;
	//�򿪷�ʽ����д+�ļ�ĩβ��ӣ�
	fs.open("./data/cargo.txt",ios::in | ios::out | ios::app);
	//��궨λ�ļ�ĩβ
	fs.seekg(0,ios::end);
	//�����ļ���С
	int fileSize=fs.tellg();
	
	//���ļ���������
	if(fileSize<=0)
	{
		int cargoID=Cargo::defaultCargoID+cargoMap.size();
		cargoMap[cargoID]=new Cargo("С��Civi_1S","�����ֻ�",2699,20);
		cargoID=Cargo::defaultCargoID+cargoMap.size();
		cargoMap[cargoID]=new Cargo("Redmi_Book","���԰칫",5799,20);
		cargoID=Cargo::defaultCargoID+cargoMap.size();
		cargoMap[cargoID]=new Cargo("С��Air_2_Pro","���ܴ���",399,20);
		cargoID=Cargo::defaultCargoID+cargoMap.size();
		cargoMap[cargoID]=new Cargo("С��Redmi_X","���Ӻ���",3999,20);	

		map<int,Cargo*>::iterator it;
	
		for(it=cargoMap.begin();it!=cargoMap.end();it++)
		{
			fs<<it->first<<" "<<it->second->getName()<<" "<<it->second->getType()<<" "<<it->second->getPrice()<<" "<<it->second->getCount()<<" "<<it->second->getLibID()<<endl;
			cout<<it->first<<" "<<it->second->getName()<<" "<<it->second->getType()<<" "<<it->second->getPrice()<<" "<<it->second->getCount()<<" "<<it->second->getLibID()<<endl;
		}
	}
	//���ļ���������
	else 
	{
		int cargoID=0;
		char type[20]="�����ֻ�";
		char name[20]={0};
		double price=0;
		int count=0;
		string LibID;
		int state=0;
		char buf[256]={0};	//�洢���ļ��ڶ������ַ���
		
		fs.seekg(0,ios::beg);
		while(fs.peek()!=EOF)
		{
			fs.getline(buf,256);
			sscanf(buf,"%d %s %s %lf %d %s",&cargoID,&name,&type,&price,&count,&LibID);
			cargoMap[cargoID]=new Cargo(name,type,price,count);
		}

		map<int,Cargo*>::iterator it;
		for(it=cargoMap.begin();it!=cargoMap.end();it++)
		{
			cout<<it->first<<" "<<it->second->getName()<<" "<<it->second->getType()<<" "<<it->second->getPrice()<<" "<<it->second->getCount()<<" "<<it->second->getLibID()<<endl;
		}
	}
	
	fs.close();
}


void Data::initUserMap()
{
	fstream fs;
	
	fs.open("./data/user.txt",ios::in | ios::out | ios::app);
	fs.seekg(0,ios::end);
	int fileSize=fs.tellg();

	if(fileSize<=0)
	{
		//��ֵ��
		int id=User::defaultID+userMap.size();
		userMap[id]=new User("admin","123456",ADMIN);
		id=User::defaultID+userMap.size();
		userMap[id]=new User("hhs","170221",CHECKMAN);

		map<int,User*>::iterator it;
	
		for(it=userMap.begin();it!=userMap.end();it++)
		{
			fs<<it->first<<" "<<it->second->getName()<<" "<<it->second->getPassword()<<" "<<it->second->getAuthority()<<endl;
			cout<<it->first<<" "<<it->second->getName()<<" "<<it->second->getPassword()<<" "<<it->second->getAuthority()<<endl;
		}
	}
	else
	{
		int id=0;
		char name[20]={0};
		char password[20]={0};
		int authority=ADMIN;
		char buf[256]={0};	//�洢���ļ��ڶ������ַ���
		
		fs.seekg(0,ios::beg);
		while(fs.peek()!=EOF)
		{
			fs.getline(buf,256);
			sscanf(buf,"%d %s %s %d",&id,&name,&password,&authority);
			userMap[id]=new User(name,password,authority);
		}

		map<int,User*>::iterator it;
		for(it=userMap.begin();it!=userMap.end();it++)
		{
			cout<<it->first<<" "<<it->second->getName()<<" "<<it->second->getPassword()<<" "<<it->second->getAuthority()<<endl;
		}
	}
	
	fs.close();
}


void Data::initCheckID()
{
	fstream fs;
	fs.open("./data/curCheckID.txt",ios::in | ios::out | ios::app);

	//��궨λ�ļ�ĩβ
	//�����ļ���С
	fs.seekg(0,ios::end);
	int fileSize=fs.tellg();

	//���ļ���������
	if(fileSize<=0)
	{
		fs<<Data::checkID2;
	}
	//���ļ���������
	else
	{
		int checkID;
		char buf[256];

		fs.seekg(0,ios::beg);
		fs.getline(buf,256);
		sscanf(buf,"%d",&checkID);

		Data::checkID2=checkID;
	}
	
	fs.close();
}


void Data::initCheckSheetMap()
{
	//�����ļ����ݱ���
	int checkID=101;
	int id;
	char name[20];
	int count;
	int checkCount;
	string libID;
	int state;
	char buf[256];
	
	//�������̵���ļ����̵���ļ����ݶ���
	for(;checkID<Data::checkID2;checkID++)
	{
		//��ȡ�̵���ļ���
		string fileName1="./data/";
		char fileName2[20];
		Ctools::getCheckName(fileName2);
		int fileName3=checkID;
		string fileName4=".txt";
		
		//�ļ����·��
		//�̵����
		stringstream fileName;
		stringstream sheetID;
		fileName<<fileName1<<fileName2<<fileName3<<fileName4;
		sheetID<<fileName2<<fileName3;

		//�򿪶�Ӧ�ļ�����ȡ����
		fstream fs;
		fs.open(fileName.str().c_str(),ios::in | ios::out);
		fs.seekg(0,ios::beg);
		while(fs.peek()!=EOF)
		{
			fs.getline(buf,256);
			sscanf(buf,"%d %s %d %d %s %d",&id,&name,&count,&checkCount,&libID,&state);
			Data::checkSheet[sheetID.str().c_str()].push_back
				(
					new CheckRecord
					(
						id,name,count,checkCount,libID,state					
					) 
				);
			
		}
	}
}


void Data::initCheckMashine()
{
	CheckMashine.push_back(new StartWin(0,0,71,30));		//0
	CheckMashine.push_back(new LogWin(0,0,71,30));			//1
	CheckMashine.push_back(new RegistWin(0,0,71,30));		//2

	CheckMashine.push_back(new AdminWin(0,0,71,30));		//3
	CheckMashine.push_back(new CheckWin(0,0,71,30));		//4

	CheckMashine.push_back(new CargoInLibMenu(0,0,71,30));	//5
	CheckMashine.push_back(new CargoInLib(0,0,71,30));		//6
	CheckMashine.push_back(new CargoOutLibMenu(0,0,71,30));	//7
	CheckMashine.push_back(new CargoOutLib(0,0,71,30));		//8

	CheckMashine.push_back(new CargoSearch(0,0,71,30));		//9
	
	CheckMashine.push_back(new CargoCheckMenu(0,0,71,30));	//10
	CheckMashine.push_back(new NewCheckWin(0,0,71,30));		//11
	CheckMashine.push_back(new CheckRecordWin(0,0,71,30));	//12
	CheckMashine.push_back(new CorrectRecordWin(0,0,71,30));//13
}


void Data::userRegist(char*name,char*password,int authority)
{
	fstream fs;
	fs.open("./data/user.txt",ios::in | ios::out | ios::app);
	fs.seekg(0,ios::end);

	//���û�д���û�map��������
	int id=User::defaultID+Data::userMap.size();
	Data::userMap[id]=new User(name,password,authority);

	//���û�д��user.txt
	map<int,User*>::iterator it;
	it=Data::userMap.find(id);
	fs<<it->first<<" "<<it->second->getName()<<" "<<it->second->getPassword()<<" "<<it->second->getAuthority()<<endl;

	fs.close();
}


string Data::getCheckID()
{
	char checkID1[20];
	Ctools::getCheckName(checkID1);

	stringstream checkID;
	checkID<<checkID1<<Data::checkID2;

	return checkID.str();
}


string Data::getCheckSheetFileName()
{
	string fileName1="./data/";
	string fileName2=Data::getCheckID();
	string fileName3=".txt";
	
	stringstream fileName;
	fileName<<fileName1<<fileName2<<fileName3;

	return fileName.str();
}