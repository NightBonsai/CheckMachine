#ifndef CARGO_H
#define CARGO_H

#include <string>
using namespace std;


//������Cargo�ࣨ�洢��Ʒ��Ϣ��
class Cargo
{
public:
	Cargo(char name[]="",char type[]="�����ֻ�",double price=10,int count=0);
	~Cargo();
	
	static int defaultCargoID;		//Ĭ����Ʒ���	ʵ����Ʒ�������
	static string defaultLibID;		//Ĭ�ϲֿ���	ʵ�ֲֿ�������
	static string getNewLibID();	//��ȡ������Ĳֿ���

	int getID();				//���нӿ�
	char* getName(); 
	char* getType();
	double getPrice();
	int getCount();
	string getLibID();

	void add(int num);			//������Ʒ����
	void minus(int num);		//������Ʒ����
	void editCount(int num);	//�޸���Ʒ����
	
	void printCargoInfo();		//�����Ʒ��Ϣ
private:
	int id;						//��Ʒ���
	char name[20];
	char type[20];				//��Ʒ����	0-�����ֻ� 1-���԰칫 2-���ܴ��� 3-���Ӻ���		
	double price;				//��Ʒ�۸�
	int count;					//��Ʒ����
	string libID;				//�ֿ���
};

#endif