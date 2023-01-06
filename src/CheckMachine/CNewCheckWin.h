#ifndef CNEWCHECKWIN_H
#define CNEWCHECKWIN_H

#include <string>
#include "CWindow.h"
#include "CLabel.h"
#include "CEdition.h"
#include "CButton.h"
#include "CTable.h"
using namespace std;


//������NewCheckWin	�½��̵����
class NewCheckWin:public Window
{
public:
	NewCheckWin(int x=0,int y=0,int w=70,int h=30);
	~NewCheckWin();

	static int searchCargoID;
	
	void showWin();				//�ض���showWin��Ա����	����û���Ϣ&����
	int searchCargo();			//������Ʒ��ż���&�����Ʒ��Ϣ		�����ɹ�����1�����򷵻�0
	void cargoCheck();			//ʵ����Ʒ�̵㹦��
	int doAction();				//ʵ��NewCheckWin���������
private:
	Label *title;
	Label *welcome;
	Label *date;
	Label *checkID;
	Label *cargoID;
	Edition *edition1;
	Button *search;
	Label *count1;
	Label *count2;
	Edition *edition2;
	Button *enter;
	Button *esc;
	Button *newCheck;
};


//������Tip    δ�ҵ���Ʒ��ʾ����
class Tip:public Window
{
public:
	Tip(int x=18,int y=8,int w=35,int h=15);
	~Tip();
	
	void showWin();		//�ض���showWin��Ա����	���һЩ��Ҫ��Ϣ
	int doAction();		//ʵ��OutTip���������
private:
	Button *reInput;
};


//������
class NewSheetWin:public Window
{
public:
	NewSheetWin(int x=0,int y=0,int w=70,int h=30);
	~NewSheetWin();

	void showWin();		//�ض���showWin��Ա����	���һЩ��Ҫ��Ϣ
	int winRun();		//�ض���winRun ʵ�����Ҽ����̼���
	void newSheet();	//ʵ�������̵����
	int doAction();		//ʵ��NewSheetWin���������
private:
	Label *title;
	Label *welcome;
	Label *date;
	Label *checkID;
	Label *checkState;
	Table *cargoTable;
	Button *button1;
	Button *button2;
	Button *button3;
	Button *endCheck;
	Button *esc;
};

#endif