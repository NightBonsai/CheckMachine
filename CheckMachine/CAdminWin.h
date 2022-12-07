#ifndef CADMINWIN_H
#define CADMINWIN_H

#include "CWindow.h"
#include "CLabel.h"
#include "CButton.h"


//������AdminWin	����Ա������
class AdminWin:public Window
{
public:
	AdminWin(int x=0,int y=0,int w=70,int h=30);
	~AdminWin();

	void showWin();		//�ض���showWin��Ա����	����û���Ϣ&����
	int doAction();		//ʵ��AdminWin���������
private:
	Label *title;
	Label *welcome;
	Label *date;
	Button *cargoSearch;
	Button *cargoLoad;
	Button *cargoInLib;
	Button *cargoOutLib;
	Button *cargoEdit;
	Button *exit;
};

#endif