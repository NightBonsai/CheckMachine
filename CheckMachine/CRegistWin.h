#ifndef CREGISTWIN_H
#define CREGISTWIN_H

#include "CWindow.h"
#include "CLabel.h"
#include "CEdition.h"
#include "CButton.h"


//������RegistWin	ע�������
class RegistWin:public Window
{
public:
	RegistWin(int x=0,int y=0,int w=70,int h=30);
	~RegistWin();

	static int presentAuthority;	//�洢��ǰע���û�ѡ���Ȩ��

	void showWin();		//�ض���showWin��Ա����	���Ĭ���û�id
	int doAction();		//ʵ��RegistWin���������
	int regJudge();		//ע���жϣ�ע���Ƿ�ɹ�
private:
	Label *title;
	Label *userid;
	Label *username;
	Label *password;
	Label *confirmPassword;
	Edition *edition1;		//�û����༭��
	Edition *edition2;		//����༭��
	Edition *edition3;		//ȷ������༭��
	Button *select;
	Button *regist;
	Button *exit;
};

#endif