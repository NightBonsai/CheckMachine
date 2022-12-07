#include "CLabel.h"
#include "CtrlBase.h"
#include "CTool.h"
#include <string>


Label::Label(int x,int y,int type,char s[]):CtrlBase(x,y,8,3,type,s)
{
}
Label::~Label()
{}


void Label::show()
{
	Ctools::gotoxy(this->startx,this->starty);
	puts(this->content);
}