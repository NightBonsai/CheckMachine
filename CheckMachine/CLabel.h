#ifndef CLABEL_H
#define CLABEL_H
 
#include "CtrlBase.h"


//������Label
class Label:public CtrlBase
{
public:
	Label(int x=0,int y=0,int type=LABEL,char s[]="��ǩ");
	~Label();

	void show();	//�ض��壬���Ʊ�ǩ�ؼ�
};

#endif