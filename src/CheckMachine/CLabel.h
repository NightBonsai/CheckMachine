#ifndef CLABEL_H
#define CLABEL_H
 
#include "CtrlBase.h"


//类名：Label
class Label:public CtrlBase
{
public:
	Label(int x=0,int y=0,int type=LABEL,char s[]="标签");
	~Label();

	void show();	//重定义，绘制标签控件
};

#endif