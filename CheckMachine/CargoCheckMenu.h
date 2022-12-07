#ifndef CARGOCHECKMENU_H
#define CARGOCHECKMENU_H

#include "CWindow.h"
#include "CLabel.h"
#include "CButton.h"


//������CargoCheckMenu	��Ʒ�̵�˵�����
class CargoCheckMenu:public Window
{
public:
	CargoCheckMenu(int x=0,int y=0,int w=70,int h=30);
	~CargoCheckMenu();

	void showWin();		//�ض���showWin��Ա����	����û���Ϣ&����
	int doAction();		//ʵ��CargoCheckMenu���������
private:
	Label *title;
	Label *welcome;
	Label *date;
	Button *newCheck;
	Button *checkRecord;
	Button *back;
};

#endif