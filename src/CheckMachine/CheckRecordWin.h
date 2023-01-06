#ifndef CHECKRECORDWIN_H
#define CHECKRECORDWIN_H

#include "CWindow.h"
#include "CLabel.h"
#include "CButton.h"
#include "CTable.h"


//������CheckRecordWin	�̵��¼����
class CheckRecordWin:public Window
{
public:
	CheckRecordWin(int x=0,int y=0,int w=70,int h=30);
	~CheckRecordWin();

	void showWin();		//�ض���showWin��Ա����	����û���Ϣ&����
	int winRun();		//�ض���winRun ʵ�����Ҽ����̼���
	int doAction();		//ʵ��CheckRecordWin���������
private:
	Label *title;
	Label *welcome;
	Label *date;
	Table *sheetTable;
	Button *button1;
	Button *button2;
	Button *button3;
	Button *esc;
};

#endif