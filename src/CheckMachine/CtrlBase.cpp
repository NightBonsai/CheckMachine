#include "CtrlBase.h"
#include "CTool.h"
#include <string>


CtrlBase::CtrlBase(int x,int y,int w,int h,int type,char s[])
{
	int str=strlen(s);

	this->startx=x;
	this->starty=y;
	this->width=w;
	this->height=h;
	this->ctrlType=type;
	strcpy(this->content,s);
}
CtrlBase::~CtrlBase()
{
}



void CtrlBase::show()
{}
void CtrlBase::editKeyListen(char x)
{}
void CtrlBase::editContent(char *s)
{}


/*
函数名称：get*
函数作用：公有接口获取控件数据成员
函数参数：无
函数返回：数据成员数据*/
int CtrlBase::getCtrlType()
{
	return this->ctrlType;
}
int CtrlBase::getStartx()
{
	return this->startx;	
}
int CtrlBase::getStarty()
{
	return this->starty;
}
int CtrlBase::getWidth()
{
	return this->width;
}
int CtrlBase::getHeight()
{
	return this->height;
}
char *CtrlBase::getContent()
{
	return this->content;
}