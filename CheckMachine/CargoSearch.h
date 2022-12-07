#ifndef CARGOSEARCH_H
#define CARGOSEARCH_H

#include <vector>
#include "CWindow.h"
#include "CLabel.h"
#include "CEdition.h"
#include "CButton.h"
#include "CTable.h"
#include "Cargo.h"
using namespace std;


//������CargoSearch	��Ʒ��ѯ����
class CargoSearch:public Window
{
public:
	CargoSearch(int x=0,int y=0,int w=70,int h=30);
	~CargoSearch();

	static int searchType;	//��¼��ǰ��������	0-�������κ����ݼ��� 1-���������ݼ���

	void showWin();			//�ض���showWin��Ա����	����û���Ϣ&����
	int winRun();			//�ض���winRun ʵ�����Ҽ����̼���
	void cargoSearch();		//ʵ����Ʒ��ѯ����
	bool recordOut();		//ʵ�ֵ�����Ʒ��Ϣ			false-����ʧ��	true-�����ɹ�
	int doAction();			//ʵ��CargoSearch���������
private:
	Label *title;
	Label *welcome;
	Label *date;
	Label *cargoID;
	Edition *edition1;
	Button *search;
	Table *cargoTable;
	Button *enter;
	Button *esc;
	
	vector<Cargo*> tmpCargoVector;		//��ʱ��Ʒ����
};

#endif