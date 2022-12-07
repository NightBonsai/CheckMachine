#ifndef CARGOSEARCH_H
#define CARGOSEARCH_H

#include <vector>
#include "CWindow.h"
#include "CLabel.h"
#include "CEdition.h"
#include "CButton.h"
#include "CTable.h"
#include "Cargo.h"
using namespace std;


//类名：CargoSearch	商品查询界面
class CargoSearch:public Window
{
public:
	CargoSearch(int x=0,int y=0,int w=70,int h=30);
	~CargoSearch();

	static int searchType;	//记录当前检索类型	0-不输入任何数据检索 1-有输入数据检索

	void showWin();			//重定义showWin成员函数	输出用户信息&日期
	int winRun();			//重定义winRun 实现左右键键盘监听
	void cargoSearch();		//实现商品查询功能
	bool recordOut();		//实现导出商品信息			false-导出失败	true-导出成功
	int doAction();			//实现CargoSearch界面各功能
private:
	Label *title;
	Label *welcome;
	Label *date;
	Label *cargoID;
	Edition *edition1;
	Button *search;
	Table *cargoTable;
	Button *enter;
	Button *esc;
	
	vector<Cargo*> tmpCargoVector;		//临时商品容器
};

#endif