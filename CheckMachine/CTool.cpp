#include "CTool.h"
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <time.h>
#include "CUser.h"
using namespace std;

User* Ctools::presentUser=NULL;


void Ctools::gotoxy(int x, int y)//形参
{
    HANDLE hOut;
    COORD pos = {x, y};
	// 光标的起始位（第1列，第3行） 0是第1列 2是第3行
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, pos);
	//printf("定位光标位置搜索(%d,%d)\n",pos.X,pos.Y);
}


void Ctools::printWindow(int startx,int starty,int width, int height)
{
	int i,j;	
	//画边框
	gotoxy(startx,starty);
	for(i=0;i<height;i++)
	{
		if(i==0)
		{
			printf("┌");
			for(j=0;j<width-2;j++)
				printf("─");
			printf("┐");
		}
		else if(i==height-1)
		{
			gotoxy(startx,starty+height-1);
			printf("└");
			for(j=0;j<width-2;j++)
				printf("─");
			printf("┘");

		}
		else
		{
			gotoxy(startx,starty+i);
			printf("│");
			for(j=0;j<width-2;j++)
				printf(" ");
			printf("│");
		}
	}
}


void Ctools::getTime(char date[])
{
	time_t t= time(0);	//基于当前系统的当前日期/时间

	strftime(date,64,"%Y.%m.%d",localtime(&t));
}
void Ctools::getRecordName(char date[])
{
	time_t t= time(0);	//基于当前系统的当前日期/时间

	strftime(date,64,"%Y%m%d",localtime(&t));
}
void Ctools::getCheckName(char date[])
{
	time_t t= time(0);	//基于当前系统的当前日期/时间

	strftime(date,64,"%Y%m%d-",localtime(&t));
}


