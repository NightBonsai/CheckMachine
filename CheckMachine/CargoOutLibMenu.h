#ifndef CARGOOUTLIBMENU_H
#define CARGOOUTLIBMENU_H

#include "CWindow.h"
#include "CLabel.h"
#include "CButton.h"


//������CargoOutLibMenu	��Ʒ���˵�������
class CargoOutLibMenu:public Window
{
public:
	CargoOutLibMenu(int x=0,int y=0,int w=70,int h=30);
	~CargoOutLibMenu();

	void showWin();		//�ض���showWin��Ա����	����û���Ϣ&����
	int doAction();		//ʵ��CargoOutLibMenu���������
private:
	Label *title;
	Label *welcome;
	Label *date;
	Button *outLib;
	Button *outLibRecord;
	Button *back;
};

#endif