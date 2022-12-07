#ifndef CHECKRECORD_H
#define CHECKRECORD_H

#include <string>
using namespace std;


//类名：CheckRecord    盘点记录类
class CheckRecord
{
public:
	CheckRecord(int id,char name[],int count,int checkCount,string libID,int state);
	~CheckRecord();

	int getID();				//公有接口
	char* getName();
	int getCount();
	int getCheckCount();
	int getDifCount();
	string getLibID();
	int getState();

	void addCheckCount(int num);		//累加盘点数量
	void editCount(int correctNum);		//修改库存数量
	void editDifCount();				//修改差异数量
	void editState();					//修改商品状态
private:
	int id;						//商品编号
	char name[20];				//商品名称	
	int count;					//商品数量
	int checkCount;				//盘点商品数量
	int difCount;				//差异数量
	string libID;				//仓库编号
	int state;					//商品状态(是否冲正)	0-否	1-是
};


#endif