#ifndef CHECKWIN_H
#define CHECKWIN_H

#include "CWindow.h"
#include "CLabel.h"
#include "CButton.h"


//类名：CheckWin	管理员界面类
class CheckWin:public Window
{
public:
	CheckWin(int x=0,int y=0,int w=70,int h=30);
	~CheckWin();

	void showWin();		//重定义showWin成员函数	输出用户信息&日期
	int doAction();		//实现CheckWin界面各功能
private:
	Label *title;
	Label *welcome;
	Label *date;
	Button *cargoSearch;
	Button *LibCheck;
	Button *exit;
};

#endif