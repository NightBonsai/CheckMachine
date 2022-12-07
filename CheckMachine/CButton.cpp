#include "CButton.h"
#include "CtrlBase.h"
#include "CTool.h"
#include <string>


Button::Button(int x,int y,int w,int h,int type,char s[]):CtrlBase(x,y,w,h,type,s)
{
}
Button::~Button()
{}


void Button::show()
{
	Ctools::printWindow(this->startx,this->starty,
							this->width,this->height);	

	Ctools::gotoxy(this->startx+this->width/4,
						this->starty+this->height/3);
	puts(this->content);
}


void Button::editContent(char *s)
{
	memset(this->content,0,sizeof(this->content));
	strcpy(this->content,s);
}