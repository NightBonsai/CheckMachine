#ifndef CSELECTBUTTON_H
#define CSELECTBUTTON_H

#include "CWindow.h"
#include "CButton.h"


//������SelectButton	��������
class SelectButton:public Window
{
public:
	SelectButton(int x,int y,int width=8,int height=6);
	~SelectButton();

	int doAction();				//�ض���doAction����	ʵ��ѡ���û�Ȩ��
	void clearSelectButton();	//���������
private:
	Button *admin;
	Button *checkMan;
};

#endif