#ifndef CHECKWIN_H
#define CHECKWIN_H

#include "CWindow.h"
#include "CLabel.h"
#include "CButton.h"


//������CheckWin	����Ա������
class CheckWin:public Window
{
public:
	CheckWin(int x=0,int y=0,int w=70,int h=30);
	~CheckWin();

	void showWin();		//�ض���showWin��Ա����	����û���Ϣ&����
	int doAction();		//ʵ��CheckWin���������
private:
	Label *title;
	Label *welcome;
	Label *date;
	Button *cargoSearch;
	Button *LibCheck;
	Button *exit;
};

#endif