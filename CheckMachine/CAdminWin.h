#ifndef CADMINWIN_H
#define CADMINWIN_H

#include "CWindow.h"
#include "CLabel.h"
#include "CButton.h"


//类名：AdminWin	管理员界面类
class AdminWin:public Window
{
public:
	AdminWin(int x=0,int y=0,int w=70,int h=30);
	~AdminWin();

	void showWin();		//重定义showWin成员函数	输出用户信息&日期
	int doAction();		//实现AdminWin界面各功能
private:
	Label *title;
	Label *welcome;
	Label *date;
	Button *cargoSearch;
	Button *cargoLoad;
	Button *cargoInLib;
	Button *cargoOutLib;
	Button *cargoEdit;
	Button *exit;
};

#endif