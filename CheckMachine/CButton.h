#ifndef CBUTTON_H
#define CBUTTON_H

#include "CtrlBase.h"


//��������ť
class Button:public CtrlBase
{
public:
	Button(int x=0,int y=0,int w=8,int h=3,int type=BUTTON,char s[]="��ť");
	~Button();

	void show();						//�ض��壬���ư�ť�ؼ�
	void editContent(char *s);			//�޸İ�ť����
};

#endif