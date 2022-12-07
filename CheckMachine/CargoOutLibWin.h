#ifndef	CARGOOUTLIBWIN_H 
#define CARGOOUTLIBWIN_H

#include "CWindow.h"
#include "CLabel.h"
#include "CEdition.h"
#include "CButton.h"


//������CargoOutLib		��Ʒ�������
class CargoOutLib:public Window
{
public:
	CargoOutLib(int x=0,int y=0,int w=70,int h=30);
	~CargoOutLib();
	
	static int searchCargoID;	//�洢��ǰ����������ƷID

	void showWin();			//�ض���showWin��Ա����	����û���Ϣ&����
	int searchCargo();		//������Ʒ��ż���&�����Ʒ��Ϣ		�����ɹ�����1�����򷵻�0
	void cargoOutLib();		//ʵ����Ʒ���⹦��
	int doAction();			//ʵ��CargoOutLib���������
private:
	Label *title;
	Label *welcome;
	Label *date;
	Label *CargoID;
	Edition *edition1;
	Button *search;
	Label *count;
	Edition *edition2;
	Button *enter;
	Button *esc;
};


//������OutTip    δ�ҵ���Ʒ��ʾ����
class OutTip:public Window
{
public:
	OutTip(int x=18,int y=8,int w=35,int h=15);
	~OutTip();
	
	void showWin();		//�ض���showWin��Ա����	���һЩ��Ҫ��Ϣ
	int doAction();		//ʵ��OutTip���������
private:
	Button *reInput;
};

#endif