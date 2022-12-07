#include "CEdition.h"
#include <iostream.h>
#include <string>
#include <conio.h>
#include <stdio.h>
#include "CtrlBase.h"
#include "CTool.h"
using namespace std;


Edition::Edition(int x,int y,int w,int h,int type,int it,int l,int i,char s[]):CtrlBase(x,y,w,h,type)
{
	this->inputType=it;
	this->maxLen=l;
	this->ips=i;
	memset(this->content,0,this->maxLen);	//memset初始化编辑框字符内容
	strcpy(this->content,s);
}
Edition::~Edition()
{}


void Edition::show()
{
	Ctools::printWindow(this->startx,this->starty,
		this->width,this->height);
	this->clearEdit();						//清除上次留下的编辑框字符内容
}


void Edition::clearEdit()
{
	memset(this->content,0,this->maxLen);
	strcpy(this->content,"");
}


void Edition::editKeyListen(char x)
{
	int j=strlen(this->content);

	//回删操作
	if(x=='\b' && j>0)
	{
		//若为中文删除
		if(this->inputType==3)
		{
			printf("\b \b");
			printf("\b \b");
			this->content[--j]='\0';
			this->content[--j]='\0';
		}
		else
		{
			printf("\b \b");
			this->content[--j]='\0';
			return;
		}
	}

	//判断输入类型
	switch(this->inputType)
	{
		//若输入类型为数字
		case 0:
			if(j<this->maxLen 
				&& x>='0' 
				&& x<='9')
			{
				//若ips==0 密文
				if(this->ips==0)
				{
					putch('*');
				}
				else if(this->ips==1)
				{
					putch(x);
				}
				this->content[j]=x;
			}
			break;
		//若输入类型为字母
		case 1:
			if(((x>='a' && x<='z') || (x>='A' && x<='Z')) 
				&& j<this->maxLen)
			{
				//若ips==0 密文
				if(this->ips==0)
				{
					putch('*');
				}
				else if(this->ips==1)
				{
					putch(x);
				}
				this->content[j]=x;
			}
			break;
		//若输入类型为字母+数字
		case 2:
			if(((x>='a' && x<='z') || (x>='A' && x<='Z')|| (x>='0' && x<='9')) 
				&& j<this->maxLen)
			{
				//若ips==0 密文
				if(this->ips==0)
				{
					putch('*');
				}
				else if(this->ips==1)
				{
					putch(x);
				}
				this->content[j]=x;
			}	
			break;
		//若输入类型为中文
		case 3:
			if((unsigned char)x >= 0xA1 && (unsigned char)x <=0xFE
				&& j<this->maxLen)
			{
				char x2=getch();
				if((unsigned char)x2 >= 0xA1 && (unsigned char)x2 <= 0xFE)
				{
					this->content[j++]=x;
					this->content[j]=x2;

					if(this->ips==1)
					{
						printf("%c%c",x,x2);
					}
					else if(this->ips==0)
					{
						printf("**");
					}
				}
			}
			break;
		//若输入类型为数字+字母+中文
		case 4:
			if(	
				( 
					((unsigned char)x >= 0xA1 && (unsigned char)x <=0xFE) || 
					(x>='a' && x<='z') || (x>='A' && x<='Z') || 
					(x>='0' && x<='9') || x=='_'
				) 
				&& j<this->maxLen
			  )
			{
				if((unsigned char)x >= 0xA1 && (unsigned char)x <=0xFE)
				{
					char x2=getch();
					if((unsigned char)x2 >= 0xA1 && (unsigned char)x2 <= 0xFE)
					{
						this->content[j++]=x;
						this->content[j]=x2;

						if(this->ips==1)
						{
							printf("%c%c",x,x2);
						}
						else if(this->ips==0)
						{
							printf("**");
						}
					}
				}
				else if(((x>='a' && x<='z') || (x>='A' && x<='Z') || (x>='0' && x<='9') || x=='_'))
				{
					//若ips==0 密文
					if(this->ips==0)
					{
						putch('*');
					}
					else if(this->ips==1)
					{
						putch(x);
					}
					this->content[j]=x;
				}
			}
			break;
	}
}