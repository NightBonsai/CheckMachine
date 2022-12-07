#ifndef CTRLBASE_H
#define CTRLBASE_H

#define LABEL 0			
#define EDITION 1
#define BUTTON 2
#define TABLE 3


//类名：CtrlBase	控件父类
class CtrlBase
{
public:
	CtrlBase(int x=0,int y=0,int w=8,int h=3,int type=LABEL,char s[]="");
	virtual ~CtrlBase();
	
	virtual void show();						//基类重定义show函数
	virtual void editKeyListen(char x);			//编辑框类重定义editKeyListen函数
	virtual void editContent(char *s);			//修改控件内容
	
	int getCtrlType();		//公有接口
	int getStartx();
	int getStarty();
	int getWidth();
	int getHeight();
	char *getContent();
protected:
	int startx;			//xy起始位置坐标	
	int starty;
	int width;			//控件宽高
	int height;
	int ctrlType;		//控件类型	0-标签 1-编辑框 2-按钮
	char content[20];	//显示内容
};

#endif