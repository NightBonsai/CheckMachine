#ifndef CEDITION_H
#define CEDITION_H

#include "CtrlBase.h"


//������Edition	�༭����
class Edition:public CtrlBase
{
public:
	Edition(int x=0,int y=0,int w=20,int h=3,int type=EDITION,int it=2,int l=20,int i=0,char s[]="");
	~Edition();

	void show();				//�ض��壬���Ʊ༭��ؼ�
	
	void editKeyListen(char x);	//ʵ�ֱ༭��������̼���
	void clearEdit();			//����༭������

private:
	int inputType;				//�����������ͣ�����-0 ��ĸ-1 ����+��ĸ-2 ����-3 ����+��ĸ+����-4
	int maxLen;					//���������ֵ
	int ips;					//��ʾ���ͣ�����-0 ����-1
};

#endif