#ifndef	CARGOOUTLIBWIN_H 
#define CARGOOUTLIBWIN_H

#include "CWindow.h"
#include "CLabel.h"
#include "CEdition.h"
#include "CButton.h"


//类名：CargoOutLib		商品出库界面
class CargoOutLib:public Window
{
public:
	CargoOutLib(int x=0,int y=0,int w=70,int h=30);
	~CargoOutLib();
	
	static int searchCargoID;	//存储当前检索到的商品ID

	void showWin();			//重定义showWin成员函数	输出用户信息&日期
	int searchCargo();		//根据商品编号检索&输出商品信息		检索成功返回1，否则返回0
	void cargoOutLib();		//实现商品出库功能
	int doAction();			//实现CargoOutLib界面各功能
private:
	Label *title;
	Label *welcome;
	Label *date;
	Label *CargoID;
	Edition *edition1;
	Button *search;
	Label *count;
	Edition *edition2;
	Button *enter;
	Button *esc;
};


//类名：OutTip    未找到商品提示界面
class OutTip:public Window
{
public:
	OutTip(int x=18,int y=8,int w=35,int h=15);
	~OutTip();
	
	void showWin();		//重定义showWin成员函数	输出一些必要信息
	int doAction();		//实现OutTip界面各功能
private:
	Button *reInput;
};

#endif