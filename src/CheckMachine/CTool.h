#ifndef CTOOL_H
#define CTOOL_H

#include <string>
#include "CUser.h"
using namespace std;


//������Ctools	������	��ų��ú���
class Ctools
{
public:
	//��λ����Ӧ����λ�ã��������
	static void gotoxy(int x, int y);
	//���߿���ʼ����xy���߿򳤿�
	static void printWindow(int startx,int starty,int width, int height);
	
	static void getTime(char date[]);					//��ȡ����ʱ��
	static void getRecordName(char date[]);				//��ȡ������Ʒ��Ϣ�ļ���
	static void getCheckName(char date[]);				//��ȡ�̵�����

	static User *presentUser;				//�洢��ǰ��¼�û�
};

#endif