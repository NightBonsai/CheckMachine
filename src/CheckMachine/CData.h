#pragma warning (disable : 4786)	//命名过长 容器
#ifndef CDATA_H
#define CDATA_H


#include <string>
#include <vector>
#include <list>
#include <map>
#include "CUser.h"
#include "Cargo.h"
#include "CWindow.h"
#include "CheckRecord.h"
using namespace std;


//类名：Data(输出界面前加载必要数据内容)
class Data
{
public:
	static void initCargoMap();				//初始化静态商品关联容器
	static void initUserMap();				//初始化静态用户关联容器
	static void initCheckID();				//初始化盘点编号
	static void initCheckSheetMap();		//初始化静态盘点表关联容器
	static void initCheckMashine();			//初始化静态盘点机系统界面向量
	
	static void userRegist(char*name,char*password,int authority);		//加入新用户，实现用户注册
	static string getCheckID();											//获取当前盘点编号
	static string getCheckSheetFileName();								//获取盘点表文件相对地址
	
	static int checkID2;			//记录盘点编号

	static map<int,Cargo*> cargoMap;						//商品关联容器	键：商品编号id
	static map<int,User*> userMap;							//用户关联容器	键：用户id
	static vector<CheckRecord*> checkRecords;				//盘点记录容器，存储一个盘点表内的多条盘点记录
	static map<string,vector<CheckRecord*> > checkSheet;	//盘点表关联容器，存储多个盘点表
	static vector<Window*> CheckMashine;					//盘点机系统界面向量容器
};
extern int userCount;

#endif