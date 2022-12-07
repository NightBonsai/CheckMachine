#include "CTool.h"
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <time.h>
#include "CUser.h"
using namespace std;

User* Ctools::presentUser=NULL;


void Ctools::gotoxy(int x, int y)//�β�
{
    HANDLE hOut;
    COORD pos = {x, y};
	// ������ʼλ����1�У���3�У� 0�ǵ�1�� 2�ǵ�3��
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, pos);
	//printf("��λ���λ������(%d,%d)\n",pos.X,pos.Y);
}


void Ctools::printWindow(int startx,int starty,int width, int height)
{
	int i,j;	
	//���߿�
	gotoxy(startx,starty);
	for(i=0;i<height;i++)
	{
		if(i==0)
		{
			printf("��");
			for(j=0;j<width-2;j++)
				printf("��");
			printf("��");
		}
		else if(i==height-1)
		{
			gotoxy(startx,starty+height-1);
			printf("��");
			for(j=0;j<width-2;j++)
				printf("��");
			printf("��");

		}
		else
		{
			gotoxy(startx,starty+i);
			printf("��");
			for(j=0;j<width-2;j++)
				printf(" ");
			printf("��");
		}
	}
}


void Ctools::getTime(char date[])
{
	time_t t= time(0);	//���ڵ�ǰϵͳ�ĵ�ǰ����/ʱ��

	strftime(date,64,"%Y.%m.%d",localtime(&t));
}
void Ctools::getRecordName(char date[])
{
	time_t t= time(0);	//���ڵ�ǰϵͳ�ĵ�ǰ����/ʱ��

	strftime(date,64,"%Y%m%d",localtime(&t));
}
void Ctools::getCheckName(char date[])
{
	time_t t= time(0);	//���ڵ�ǰϵͳ�ĵ�ǰ����/ʱ��

	strftime(date,64,"%Y%m%d-",localtime(&t));
}


