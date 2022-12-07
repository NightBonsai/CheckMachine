#ifndef CORRECTRECORDWIN_H
#define CORRECTRECORDWIN_H

#include <vector>
#include "CWindow.h"
#include "CLabel.h"
#include "CEdition.h"
#include "CButton.h"
#include "CTable.h"
#include "CheckRecord.h"


//类名：CorrectRecordWin	盘点冲正界面
class CorrectRecordWin:public Window
{
public:
	CorrectRecordWin(int x=0,int y=0,int w=70,int h=30);
	~CorrectRecordWin();

	static string checkSheetID;		//记录当前冲正的盘点表盘点编号

	void showWin();			//重定义showWin成员函数，输出界面新增内容
	int winRun();			//重定义winRun 实现左右键键盘监听
	int doAction();			//实现CheckRecordWin界面各功能
private:
	Label *title;
	Label *welcome;
	Label *date;
	Label *checkID;
	Table *correctTable;
	Button *button1;
	Button *button2;
	Button *button3;
	Button *finish;
	Button *esc;
};


//类名：CorrectingWin	冲正界面
class CorrectingWin:public Window
{
public:
	CorrectingWin(int x=15,int y=5,int w=40,int h=20);
	~CorrectingWin();

	static vector<CheckRecord*>::iterator it;	//记录当前选中的盘点记录

	void correcting();	//实现冲正功能
	int doAction();		//实现CorrectingWin界面各功能
private:
	Label *title;
	Label *correctCount;
	Label *correctInstructions;
	Edition *edition1;
	Edition *edition2;
	Button *enter;
	Button *esc;
};

#endif