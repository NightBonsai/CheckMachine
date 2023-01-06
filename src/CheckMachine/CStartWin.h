#ifndef CSTARTWIN_H
#define CSTARTWIN_H

#include "CWindow.h"
#include "CLabel.h"
#include "CButton.h"


//������StartWin	ϵͳ��ʼ������
class StartWin:public Window 
{
public:
	StartWin(int x=0,int y=0,int w=70,int h=30);
	~StartWin();

	int doAction();		//ʵ��StartWin���������
private:
	Label *title;
	Button *log;
	Button *regist;
	Button *exit;
	Label *copyRightID;
};


//������ConfirmWin	ȷ���˳�����
class ConfirmWin:public Window
{
public:
	ConfirmWin(int x=20,int y=10,int w=30,int h=10);
	~ConfirmWin();

	int doAction();		//ʵ��ConfirmWin���������
private:
	Label *title;
	Button *yes;
	Button *no;
};


#endif