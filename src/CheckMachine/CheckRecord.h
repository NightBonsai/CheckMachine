#ifndef CHECKRECORD_H
#define CHECKRECORD_H

#include <string>
using namespace std;


//������CheckRecord    �̵��¼��
class CheckRecord
{
public:
	CheckRecord(int id,char name[],int count,int checkCount,string libID,int state);
	~CheckRecord();

	int getID();				//���нӿ�
	char* getName();
	int getCount();
	int getCheckCount();
	int getDifCount();
	string getLibID();
	int getState();

	void addCheckCount(int num);		//�ۼ��̵�����
	void editCount(int correctNum);		//�޸Ŀ������
	void editDifCount();				//�޸Ĳ�������
	void editState();					//�޸���Ʒ״̬
private:
	int id;						//��Ʒ���
	char name[20];				//��Ʒ����	
	int count;					//��Ʒ����
	int checkCount;				//�̵���Ʒ����
	int difCount;				//��������
	string libID;				//�ֿ���
	int state;					//��Ʒ״̬(�Ƿ����)	0-��	1-��
};


#endif