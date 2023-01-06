#ifndef CHECKRECORDWIN_H
#define CHECKRECORDWIN_H

#include "CWindow.h"
#include "CLabel.h"
#include "CButton.h"
#include "CTable.h"


//类名：CheckRecordWin	盘点记录界面
class CheckRecordWin:public Window
{
public:
	CheckRecordWin(int x=0,int y=0,int w=70,int h=30);
	~CheckRecordWin();

	void showWin();		//重定义showWin成员函数	输出用户信息&日期
	int winRun();		//重定义winRun 实现左右键键盘监听
	int doAction();		//实现CheckRecordWin界面各功能
private:
	Label *title;
	Label *welcome;
	Label *date;
	Table *sheetTable;
	Button *button1;
	Button *button2;
	Button *button3;
	Button *esc;
};

#endif