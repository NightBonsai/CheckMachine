#ifndef CTABLE_H
#define CTABLE_H

#include "CtrlBase.h"
#include <vector>
using namespace std;


//������Table	�����
class Table:public CtrlBase
{
public:
	Table(int x=5,int y=10,int w=6,int h=4,int type=TABLE,int cw=3,int ch=2,int tabletype=1);
	~Table();

	int pageCount;				//��ҳ��
	int curPage;				//��ǰҳ��

	int getCellWidth();					//���нӿ�
	int getCellHeight();	

	void editPageCount();				//���»�ȡ�����ҳ��
	
	void show();						//�ض��壬���Ʊ��
	void showPageInform();				//�����ǰҳ��/��ҳ����Ϣ
	void showData();					//�ض���,���������Ʒ����
	void clearTable();					//��ձ��������
private:
	int cellWidth;				//���ӿ��
	int cellHeight;
	vector<string>tableHead;	//��ͷ
	int tableType;				//�������	1-��Ʒ��ѯ���	2-�̵��¼���	3-�̵����  4-�̵�������
};

#endif