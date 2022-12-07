#ifndef CTABLE_H
#define CTABLE_H

#include "CtrlBase.h"
#include <vector>
using namespace std;


//类名：Table	表格类
class Table:public CtrlBase
{
public:
	Table(int x=5,int y=10,int w=6,int h=4,int type=TABLE,int cw=3,int ch=2,int tabletype=1);
	~Table();

	int pageCount;				//总页数
	int curPage;				//当前页数

	int getCellWidth();					//公有接口
	int getCellHeight();	

	void editPageCount();				//重新获取表格总页数
	
	void show();						//重定义，绘制表格
	void showPageInform();				//输出当前页数/总页数信息
	void showData();					//重定义,输出所有商品数据
	void clearTable();					//清空表格内数据
private:
	int cellWidth;				//格子宽高
	int cellHeight;
	vector<string>tableHead;	//表头
	int tableType;				//表格类型	1-商品查询表格	2-盘点记录表格	3-盘点表表格  4-盘点冲正表格
};

#endif