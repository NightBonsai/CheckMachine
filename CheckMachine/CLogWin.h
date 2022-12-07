#ifndef CLOGWIN_H
#define CLOGWIN_H

#include "CWindow.h"
#include "CLabel.h"
#include "CEdition.h"
#include "CButton.h"


//类名：LogWin	登录界面类
class LogWin:public Window 
{
public:
	LogWin(int x=0,int y=0,int w=70,int h=30);
	~LogWin();

	int doAction();		//实现LogWin界面各功能
	int logJudge();		//验证登录是否成功&判断权限显示不同界面
private:
	Label *title;
	Label *username;
	Label *password;
	Edition *edition1;
	Edition *edition2;
	Button *log;
	Button *exit;
};

#endif