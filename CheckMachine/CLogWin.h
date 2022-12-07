#ifndef CLOGWIN_H
#define CLOGWIN_H

#include "CWindow.h"
#include "CLabel.h"
#include "CEdition.h"
#include "CButton.h"


//������LogWin	��¼������
class LogWin:public Window 
{
public:
	LogWin(int x=0,int y=0,int w=70,int h=30);
	~LogWin();

	int doAction();		//ʵ��LogWin���������
	int logJudge();		//��֤��¼�Ƿ�ɹ�&�ж�Ȩ����ʾ��ͬ����
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