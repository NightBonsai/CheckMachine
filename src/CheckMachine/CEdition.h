#ifndef CEDITION_H
#define CEDITION_H

#include "CtrlBase.h"


//类名：Edition	编辑框类
class Edition:public CtrlBase
{
public:
	Edition(int x=0,int y=0,int w=20,int h=3,int type=EDITION,int it=2,int l=20,int i=0,char s[]="");
	~Edition();

	void show();				//重定义，绘制编辑框控件
	
	void editKeyListen(char x);	//实现编辑框输入键盘监听
	void clearEdit();			//清除编辑框内容

private:
	int inputType;				//数据输入类型：数字-0 字母-1 数字+字母-2 中文-3 数字+字母+中文-4
	int maxLen;					//允许最大数值
	int ips;					//显示类型：密文-0 明文-1
};

#endif