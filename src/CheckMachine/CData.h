#pragma warning (disable : 4786)	//�������� ����
#ifndef CDATA_H
#define CDATA_H


#include <string>
#include <vector>
#include <list>
#include <map>
#include "CUser.h"
#include "Cargo.h"
#include "CWindow.h"
#include "CheckRecord.h"
using namespace std;


//������Data(�������ǰ���ر�Ҫ��������)
class Data
{
public:
	static void initCargoMap();				//��ʼ����̬��Ʒ��������
	static void initUserMap();				//��ʼ����̬�û���������
	static void initCheckID();				//��ʼ���̵���
	static void initCheckSheetMap();		//��ʼ����̬�̵���������
	static void initCheckMashine();			//��ʼ����̬�̵��ϵͳ��������
	
	static void userRegist(char*name,char*password,int authority);		//�������û���ʵ���û�ע��
	static string getCheckID();											//��ȡ��ǰ�̵���
	static string getCheckSheetFileName();								//��ȡ�̵���ļ���Ե�ַ
	
	static int checkID2;			//��¼�̵���

	static map<int,Cargo*> cargoMap;						//��Ʒ��������	������Ʒ���id
	static map<int,User*> userMap;							//�û���������	�����û�id
	static vector<CheckRecord*> checkRecords;				//�̵��¼�������洢һ���̵���ڵĶ����̵��¼
	static map<string,vector<CheckRecord*> > checkSheet;	//�̵������������洢����̵��
	static vector<Window*> CheckMashine;					//�̵��ϵͳ������������
};
extern int userCount;

#endif