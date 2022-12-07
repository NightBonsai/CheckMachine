#ifndef	CARGOINLIBWIN_H 
#define CARGOINLIBWIN_H

#include "CWindow.h"
#include "CLabel.h"
#include "CEdition.h"
#include "CButton.h"


//������CargoInLib	��Ʒ������
class CargoInLib:public Window
{
public:
	CargoInLib(int x=0,int y=0,int w=70,int h=30);
	~CargoInLib();
	
	static int searchCargoID;	//�洢��ǰ����������ƷID

	void showWin();			//�ض���showWin��Ա����	����û���Ϣ&����
	int searchCargo();		//������Ʒ��ż���&�����Ʒ��Ϣ		�����ɹ�����1�����򷵻�0
	void cargoInLib();		//ʵ����Ʒ��⹦��
	int doAction();			//ʵ��CargoInLib���������
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


//������InTip    δ�ҵ���Ʒ��ʾ����
class InTip:public Window
{
public:
	InTip(int x=18,int y=8,int w=35,int h=15);
	~InTip();
	
	void showWin();		//�ض���showWin��Ա����	���һЩ��Ҫ��Ϣ
	int doAction();		//ʵ��Tip���������
private:
	Button *reInput;
	Button *newCargo;
};


//������AddNewCargo	������Ʒ����
class AddNewCargo:public Window
{
public:
	AddNewCargo(int x=0,int y=0,int w=70,int h=30);
	~AddNewCargo();

	void showWin();		//�ض���showWin��Ա���� ����û���Ϣ&����
	int doAction();		//ʵ��������Ʒ���������
	void addNewCargo();	//ʵ��������Ʒ����	
private:
	Label *title;
	Label *welcome;
	Label *date;
	Label *cargoid;
	Label *cargoname;
	Label *cargotype;
	Label *cargoprice;
	Label *libid;
	Edition *edition1;	//��Ʒ���༭��
	Edition *edition2;	//��Ʒ���ͱ༭��
	Edition *edition3;	//��Ʒ�۸�༭��
	Button *enter;
	Button *esc;
};

#endif