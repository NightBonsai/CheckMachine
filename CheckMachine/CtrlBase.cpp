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
�������ƣ�get*
�������ã����нӿڻ�ȡ�ؼ����ݳ�Ա
������������
�������أ����ݳ�Ա����*/
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