#ifndef CSTARTWIN_H
#define CSTARTWIN_H

#include "CWindow.h"
#include "CLabel.h"
#include "CButton.h"


//类名：StartWin	系统开始界面类
class StartWin:public Window 
{
public:
	StartWin(int x=0,int y=0,int w=70,int h=30);
	~StartWin();

	int doAction();		//实现StartWin界面各功能
private:
	Label *title;
	Button *log;
	Button *regist;
	Button *exit;
	Label *copyRightID;
};


//类名：ConfirmWin	确认退出界面
class ConfirmWin:public Window
{
public:
	ConfirmWin(int x=20,int y=10,int w=30,int h=10);
	~ConfirmWin();

	int doAction();		//实现ConfirmWin界面各功能
private:
	Label *title;
	Button *yes;
	Button *no;
};


#endif