#ifndef CWINDOW_H
#define CWINDOW_H

#include "CtrlBase.h"

#define LABEL 0
#define EDITION 1
#define BUTTON 2
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77


//������Window	���ڻ���
class Window
{
public:
	Window(int x=0,int y=0,int w=50,int h=25,int count=0,int index=0);
	virtual ~Window();
	
	int getCtrlIndex();				//��ȡ���ڿؼ��±�
	int getCtrlCount();				//��ȡ���ڿؼ�����

	virtual void showWin();			//���ƴ��ڽ���
	virtual int doAction()=0;		//���麯��ʵ�ֽ��������
	virtual int winRun();			//��������

	void addCtrl(CtrlBase *ctrl);	//����ؼ�
protected:
	int startx;						//xy��ʼλ������
	int starty;
	int width;						//���ڿ��
	int height;
	CtrlBase *CtrlArr[20];			//�ؼ�����
	int ctrlCount;					//�ؼ�����
	int ctrlIndex;					//��ǰѡ�пؼ��±�
};


#endif