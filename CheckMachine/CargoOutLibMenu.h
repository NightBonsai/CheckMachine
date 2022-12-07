#ifndef CARGOOUTLIBMENU_H
#define CARGOOUTLIBMENU_H

#include "CWindow.h"
#include "CLabel.h"
#include "CButton.h"


//类名：CargoOutLibMenu	商品入库菜单界面类
class CargoOutLibMenu:public Window
{
public:
	CargoOutLibMenu(int x=0,int y=0,int w=70,int h=30);
	~CargoOutLibMenu();

	void showWin();		//重定义showWin成员函数	输出用户信息&日期
	int doAction();		//实现CargoOutLibMenu界面各功能
private:
	Label *title;
	Label *welcome;
	Label *date;
	Button *outLib;
	Button *outLibRecord;
	Button *back;
};

#endif