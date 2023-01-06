#ifndef CARGOINLIBMENU_H
#define CARGOINLIBMENU_H

#include "CWindow.h"
#include "CLabel.h"
#include "CButton.h"


//������CargoInLibMenu	��Ʒ���˵�������
class CargoInLibMenu:public Window
{
public:
	CargoInLibMenu(int x=0,int y=0,int w=70,int h=30);
	~CargoInLibMenu();

	void showWin();		//�ض���showWin��Ա����	����û���Ϣ&����
	int doAction();		//ʵ��CargoInLibMenu���������
private:
	Label *title;
	Label *welcome;
	Label *date;
	Button *inLib;
	Button *inLibRecord;
	Button *back;
};

#endif