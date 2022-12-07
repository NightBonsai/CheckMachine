#ifndef CARGOINLIBMENU_H
#define CARGOINLIBMENU_H

#include "CWindow.h"
#include "CLabel.h"
#include "CButton.h"


//类名：CargoInLibMenu	商品入库菜单界面类
class CargoInLibMenu:public Window
{
public:
	CargoInLibMenu(int x=0,int y=0,int w=70,int h=30);
	~CargoInLibMenu();

	void showWin();		//重定义showWin成员函数	输出用户信息&日期
	int doAction();		//实现CargoInLibMenu界面各功能
private:
	Label *title;
	Label *welcome;
	Label *date;
	Button *inLib;
	Button *inLibRecord;
	Button *back;
};

#endif