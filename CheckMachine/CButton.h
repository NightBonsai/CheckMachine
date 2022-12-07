#ifndef CBUTTON_H
#define CBUTTON_H

#include "CtrlBase.h"


//类名：按钮
class Button:public CtrlBase
{
public:
	Button(int x=0,int y=0,int w=8,int h=3,int type=BUTTON,char s[]="按钮");
	~Button();

	void show();						//重定义，绘制按钮控件
	void editContent(char *s);			//修改按钮内容
};

#endif