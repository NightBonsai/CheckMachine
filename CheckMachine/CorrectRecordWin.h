#ifndef CORRECTRECORDWIN_H
#define CORRECTRECORDWIN_H

#include <vector>
#include "CWindow.h"
#include "CLabel.h"
#include "CEdition.h"
#include "CButton.h"
#include "CTable.h"
#include "CheckRecord.h"


//������CorrectRecordWin	�̵��������
class CorrectRecordWin:public Window
{
public:
	CorrectRecordWin(int x=0,int y=0,int w=70,int h=30);
	~CorrectRecordWin();

	static string checkSheetID;		//��¼��ǰ�������̵���̵���

	void showWin();			//�ض���showWin��Ա���������������������
	int winRun();			//�ض���winRun ʵ�����Ҽ����̼���
	int doAction();			//ʵ��CheckRecordWin���������
private:
	Label *title;
	Label *welcome;
	Label *date;
	Label *checkID;
	Table *correctTable;
	Button *button1;
	Button *button2;
	Button *button3;
	Button *finish;
	Button *esc;
};


//������CorrectingWin	��������
class CorrectingWin:public Window
{
public:
	CorrectingWin(int x=15,int y=5,int w=40,int h=20);
	~CorrectingWin();

	static vector<CheckRecord*>::iterator it;	//��¼��ǰѡ�е��̵��¼

	void correcting();	//ʵ�ֳ�������
	int doAction();		//ʵ��CorrectingWin���������
private:
	Label *title;
	Label *correctCount;
	Label *correctInstructions;
	Edition *edition1;
	Edition *edition2;
	Button *enter;
	Button *esc;
};

#endif