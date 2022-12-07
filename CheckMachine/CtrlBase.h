#ifndef CTRLBASE_H
#define CTRLBASE_H

#define LABEL 0			
#define EDITION 1
#define BUTTON 2
#define TABLE 3


//������CtrlBase	�ؼ�����
class CtrlBase
{
public:
	CtrlBase(int x=0,int y=0,int w=8,int h=3,int type=LABEL,char s[]="");
	virtual ~CtrlBase();
	
	virtual void show();						//�����ض���show����
	virtual void editKeyListen(char x);			//�༭�����ض���editKeyListen����
	virtual void editContent(char *s);			//�޸Ŀؼ�����
	
	int getCtrlType();		//���нӿ�
	int getStartx();
	int getStarty();
	int getWidth();
	int getHeight();
	char *getContent();
protected:
	int startx;			//xy��ʼλ������	
	int starty;
	int width;			//�ؼ����
	int height;
	int ctrlType;		//�ؼ�����	0-��ǩ 1-�༭�� 2-��ť
	char content[20];	//��ʾ����
};

#endif