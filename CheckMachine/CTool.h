#ifndef CTOOL_H
#define CTOOL_H

#include <string>
#include "CUser.h"
using namespace std;


//类名：Ctools	工具类	存放常用函数
class Ctools
{
public:
	//定位到对应坐标位置，坐标横纵
	static void gotoxy(int x, int y);
	//画边框，起始坐标xy，边框长宽
	static void printWindow(int startx,int starty,int width, int height);
	
	static void getTime(char date[]);					//获取当下时间
	static void getRecordName(char date[]);				//获取导出商品信息文件名
	static void getCheckName(char date[]);				//获取盘点编号名

	static User *presentUser;				//存储当前登录用户
};

#endif