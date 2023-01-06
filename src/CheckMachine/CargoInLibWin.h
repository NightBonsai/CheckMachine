#ifndef	CARGOINLIBWIN_H 
#define CARGOINLIBWIN_H

#include "CWindow.h"
#include "CLabel.h"
#include "CEdition.h"
#include "CButton.h"


//类名：CargoInLib	商品入库界面
class CargoInLib:public Window
{
public:
	CargoInLib(int x=0,int y=0,int w=70,int h=30);
	~CargoInLib();
	
	static int searchCargoID;	//存储当前检索到的商品ID

	void showWin();			//重定义showWin成员函数	输出用户信息&日期
	int searchCargo();		//根据商品编号检索&输出商品信息		检索成功返回1，否则返回0
	void cargoInLib();		//实现商品入库功能
	int doAction();			//实现CargoInLib界面各功能
private:
	Label *title;
	Label *welcome;
	Label *date;
	Label *CargoID;
	Edition *edition1;
	Button *search;
	Label *count;
	Edition *edition2;
	Button *enter;
	Button *esc;
};


//类名：InTip    未找到商品提示界面
class InTip:public Window
{
public:
	InTip(int x=18,int y=8,int w=35,int h=15);
	~InTip();
	
	void showWin();		//重定义showWin成员函数	输出一些必要信息
	int doAction();		//实现Tip界面各功能
private:
	Button *reInput;
	Button *newCargo;
};


//类名：AddNewCargo	新增商品界面
class AddNewCargo:public Window
{
public:
	AddNewCargo(int x=0,int y=0,int w=70,int h=30);
	~AddNewCargo();

	void showWin();		//重定义showWin成员函数 输出用户信息&日期
	int doAction();		//实现新增商品界面各功能
	void addNewCargo();	//实现新增商品功能	
private:
	Label *title;
	Label *welcome;
	Label *date;
	Label *cargoid;
	Label *cargoname;
	Label *cargotype;
	Label *cargoprice;
	Label *libid;
	Edition *edition1;	//商品名编辑框
	Edition *edition2;	//商品类型编辑框
	Edition *edition3;	//商品价格编辑框
	Button *enter;
	Button *esc;
};

#endif