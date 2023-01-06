#ifndef CSELECTBUTTON_H
#define CSELECTBUTTON_H

#include "CWindow.h"
#include "CButton.h"


//类名：SelectButton	下拉框类
class SelectButton:public Window
{
public:
	SelectButton(int x,int y,int width=8,int height=6);
	~SelectButton();

	int doAction();				//重定义doAction函数	实现选择用户权限
	void clearSelectButton();	//清除下拉框
private:
	Button *admin;
	Button *checkMan;
};

#endif