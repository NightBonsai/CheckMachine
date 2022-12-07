#ifndef CWINDOW_H
#define CWINDOW_H

#include "CtrlBase.h"

#define LABEL 0
#define EDITION 1
#define BUTTON 2
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77


//类名：Window	窗口基类
class Window
{
public:
	Window(int x=0,int y=0,int w=50,int h=25,int count=0,int index=0);
	virtual ~Window();
	
	int getCtrlIndex();				//获取窗口控件下标
	int getCtrlCount();				//获取窗口控件个数

	virtual void showWin();			//绘制窗口界面
	virtual int doAction()=0;		//纯虚函数实现界面各功能
	virtual int winRun();			//窗口运行

	void addCtrl(CtrlBase *ctrl);	//加入控件
protected:
	int startx;						//xy起始位置坐标
	int starty;
	int width;						//窗口宽高
	int height;
	CtrlBase *CtrlArr[20];			//控件数组
	int ctrlCount;					//控件个数
	int ctrlIndex;					//当前选中控件下标
};


#endif