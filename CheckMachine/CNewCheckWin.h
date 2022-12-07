#ifndef CNEWCHECKWIN_H
#define CNEWCHECKWIN_H

#include <string>
#include "CWindow.h"
#include "CLabel.h"
#include "CEdition.h"
#include "CButton.h"
#include "CTable.h"
using namespace std;


//类名：NewCheckWin	新建盘点界面
class NewCheckWin:public Window
{
public:
	NewCheckWin(int x=0,int y=0,int w=70,int h=30);
	~NewCheckWin();

	static int searchCargoID;
	
	void showWin();				//重定义showWin成员函数	输出用户信息&日期
	int searchCargo();			//根据商品编号检索&输出商品信息		检索成功返回1，否则返回0
	void cargoCheck();			//实现商品盘点功能
	int doAction();				//实现NewCheckWin界面各功能
private:
	Label *title;
	Label *welcome;
	Label *date;
	Label *checkID;
	Label *cargoID;
	Edition *edition1;
	Button *search;
	Label *count1;
	Label *count2;
	Edition *edition2;
	Button *enter;
	Button *esc;
	Button *newCheck;
};


//类名：Tip    未找到商品提示界面
class Tip:public Window
{
public:
	Tip(int x=18,int y=8,int w=35,int h=15);
	~Tip();
	
	void showWin();		//重定义showWin成员函数	输出一些必要信息
	int doAction();		//实现OutTip界面各功能
private:
	Button *reInput;
};


//类名：
class NewSheetWin:public Window
{
public:
	NewSheetWin(int x=0,int y=0,int w=70,int h=30);
	~NewSheetWin();

	void showWin();		//重定义showWin成员函数	输出一些必要信息
	int winRun();		//重定义winRun 实现左右键键盘监听
	void newSheet();	//实现新增盘点表功能
	int doAction();		//实现NewSheetWin界面各功能
private:
	Label *title;
	Label *welcome;
	Label *date;
	Label *checkID;
	Label *checkState;
	Table *cargoTable;
	Button *button1;
	Button *button2;
	Button *button3;
	Button *endCheck;
	Button *esc;
};

#endif