#ifndef CREGISTWIN_H
#define CREGISTWIN_H

#include "CWindow.h"
#include "CLabel.h"
#include "CEdition.h"
#include "CButton.h"


//类名：RegistWin	注册界面类
class RegistWin:public Window
{
public:
	RegistWin(int x=0,int y=0,int w=70,int h=30);
	~RegistWin();

	static int presentAuthority;	//存储当前注册用户选择的权限

	void showWin();		//重定义showWin成员函数	输出默认用户id
	int doAction();		//实现RegistWin界面各功能
	int regJudge();		//注册判断，注册是否成功
private:
	Label *title;
	Label *userid;
	Label *username;
	Label *password;
	Label *confirmPassword;
	Edition *edition1;		//用户名编辑框
	Edition *edition2;		//密码编辑框
	Edition *edition3;		//确认密码编辑框
	Button *select;
	Button *regist;
	Button *exit;
};

#endif