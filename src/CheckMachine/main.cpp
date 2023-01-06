#pragma warning (disable : 4786)	//ÃüÃû¹ı³¤ ÈİÆ÷
#include <iostream>
#include "CTool.h"
#include "CUser.h"
#include "CData.h"
using namespace std;

int main()
{
	Data::initUserMap();
	Data::initCargoMap();
	Data::initCheckID();
	Data::initCheckSheetMap();
	Data::initCheckMashine();

	int i=0;
	while(true)
	{
		Data::CheckMashine[i]->showWin();
		i=Data::CheckMashine[i]->winRun();
	}
	
	for(i=0;i<Data::CheckMashine.size();i++)
	{
		delete Data::CheckMashine[i];
	}

	Ctools::gotoxy(0,30);
	return 0;
}