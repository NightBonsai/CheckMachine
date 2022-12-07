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
	memset(this->content,0,this->maxLen);	//memset��ʼ���༭���ַ�����
	strcpy(this->content,s);
}
Edition::~Edition()
{}


void Edition::show()
{
	Ctools::printWindow(this->startx,this->starty,
		this->width,this->height);
	this->clearEdit();						//����ϴ����µı༭���ַ�����
}


void Edition::clearEdit()
{
	memset(this->content,0,this->maxLen);
	strcpy(this->content,"");
}


void Edition::editKeyListen(char x)
{
	int j=strlen(this->content);

	//��ɾ����
	if(x=='\b' && j>0)
	{
		//��Ϊ����ɾ��
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

	//�ж���������
	switch(this->inputType)
	{
		//����������Ϊ����
		case 0:
			if(j<this->maxLen 
				&& x>='0' 
				&& x<='9')
			{
				//��ips==0 ����
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
		//����������Ϊ��ĸ
		case 1:
			if(((x>='a' && x<='z') || (x>='A' && x<='Z')) 
				&& j<this->maxLen)
			{
				//��ips==0 ����
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
		//����������Ϊ��ĸ+����
		case 2:
			if(((x>='a' && x<='z') || (x>='A' && x<='Z')|| (x>='0' && x<='9')) 
				&& j<this->maxLen)
			{
				//��ips==0 ����
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
		//����������Ϊ����
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
		//����������Ϊ����+��ĸ+����
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
					//��ips==0 ����
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