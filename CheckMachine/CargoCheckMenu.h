#ifndef CARGOCHECKMENU_H
#define CARGOCHECKMENU_H

#include "CWindow.h"
#include "CLabel.h"
#include "CButton.h"


//类名：CargoCheckMenu	商品盘点菜单界面
class CargoCheckMenu:public Window
{
public:
	CargoCheckMenu(int x=0,int y=0,int w=70,int h=30);
	~CargoCheckMenu();

	void showWin();		//重定义showWin成员函数	输出用户信息&日期
	int doAction();		//实现CargoCheckMenu界面各功能
private:
	Label *title;
	Label *welcome;
	Label *date;
	Button *newCheck;
	Button *checkRecord;
	Button *back;
};

#endif