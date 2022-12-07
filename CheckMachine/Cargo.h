#ifndef CARGO_H
#define CARGO_H

#include <string>
using namespace std;


//类名：Cargo类（存储商品信息）
class Cargo
{
public:
	Cargo(char name[]="",char type[]="智能手机",double price=10,int count=0);
	~Cargo();
	
	static int defaultCargoID;		//默认商品编号	实现商品编号自增
	static string defaultLibID;		//默认仓库编号	实现仓库编号自增
	static string getNewLibID();	//获取自增后的仓库编号

	int getID();				//公有接口
	char* getName(); 
	char* getType();
	double getPrice();
	int getCount();
	string getLibID();

	void add(int num);			//新增商品个数
	void minus(int num);		//减少商品个数
	void editCount(int num);	//修改商品个数
	
	void printCargoInfo();		//输出商品信息
private:
	int id;						//商品编号
	char name[20];
	char type[20];				//商品类型	0-智能手机 1-电脑办公 2-智能穿戴 3-电视盒子		
	double price;				//商品价格
	int count;					//商品数量
	string libID;				//仓库编号
};

#endif