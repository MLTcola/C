#include<stdio.h> 
#include<stdlib.h>              //����������	system("CLS");
#include<windows.h>             //˯�ߺ���Sleep
#include<conio.h>               //���ûس���������getch

void BackGrandInit(void);       //������ʼ����
void SetPosition(int x,int y);  //��λ
void SetColor(int x);            //������ɫ
void Move(char direction);                      //�ƶ�
void SnakeMap(COORD sh,COORD st,COORD old1,COORD old2);
//void Food();

int score;
int SnakeLong=3;

struct BorderSize                  //�߿��С
			{
				char x;
				char y;
			}BorderSize={45,25};
struct{
		 char *ch;
		int color;
		}Border = {"��", 4},  //�߿�
		Bg = {"��",16},  //����
		SnakeHead= {"��", 14},  //̰����
		SnakeBody={"��",14},
		Food = {"��", 13};  //ʳ��
		struct{ 
		COORD sh;   //��ͷ����
		COORD st;   //��β����
		}position;
struct{
		COORD sh;        //��ͷ��β��һ�ε�λ��
		COORD st;
		} old; 
/*SetConsoleCursorPosition//�����ƺ���
HANDLE colour;	colour=GetStdHandle(STD_OUTPUT_HANDLE);	SetConsoleTextAttribute(colour,FOREGROUND_RED|BACKGROUND_GREEN);��API���ÿ���̨����������ɫ�ͱ���ɫ�ĺ���
GetConsoleCursorInfo ���������й�ָ���Ŀ���̨��Ļ�������Ĺ��Ŀɼ��Ժʹ�С��Ϣ
GetStdHandle
b****************************************************************
	HANDLE SetPosition;
	COORD coord;
	SetPosition=GetStdHandle(STD_OUTPUT_HANDLE);//���ù��λ��
	coord.X=67;
	coord.Y=45;
	SetConsoleCursorPosition(SetPosition,coord);
	printf("akjh");
***************************************************************8
	HANDLE colour;	

	struct{
			 char *ch;
			int color;
			char type;
			}charBorder = {"��", 4, 1},  //�߿�
			charBg = {"��", 2, 2},  //����
			charSnake = {"��", 0xe, 3},  //̰���߽ڵ�
			charFood = {"��", 0xc, 4};  //ʳ��
	colour=GetStdHandle(STD_OUTPUT_HANDLE);	
	SetConsoleTextAttribute(colour,FOREGROUND_RED);
	printf("%s",charBg.ch);
**********************************************************
wAttributes ��ɫ ��Ӧ��ֵ 
FOREGROUND_BLUE ������ɫ���� 1 
FOREGROUND_GREEN ������ɫ���� 2 
FOREGROUND_RED ������ɫ���� 4 ��14
FOREGROUND_INTENSITY ǰ��ɫ������ʾ 8 
BACKGROUND_BLUE ������ɫ���� 16 
BACKGROUND_GREEN ������ɫ���� 32 
BACKGROUND_RED 
������ɫ����
 64 
BACKGROUND_INTENSITY ����ɫ������ʾ 128 
****************************************************************
kbhit��һ������������������鵱ǰ�Ƿ��м������롣
*******************************************************
˼·�����ö�ά�����¼ÿ�ι���ķ���*/
void main()
{
	int m=3;
	char direction='w';
	BackGrandInit(); 
	while(1)
	{	
		if(_kbhit())
		direction=getch();
		Move(direction);
		Sleep(500);	
	}
	

}

void Move(char direction)
{
	old.sh.X=position.sh.X;
	old.sh.Y=position.sh.Y;
	old.st.X=position.st.X;
	old.st.Y=position.st.Y;
	switch(direction)
	{
		case 'w':
				{
					position.sh.Y--;
					if(old.sh.X-old.st.X>0)position.st.X++;
					else if(old.sh.X-old.st.X<0)position.st.X--;
					else if(old.sh.X==old.st.X)position.st.Y--;	
				};break;
		case 'a':{
					position.sh.X--;
					if(old.sh.Y-old.st.Y>0)position.st.Y++;
					else if(old.sh.Y-old.st.Y<0)position.st.Y--;
					else if(old.sh.Y==old.st.Y)position.st.X--;			
				 };break;
		case 's':{
					position.sh.Y++;
					if(old.sh.X-old.st.X>0)position.st.X++;
					else if(old.sh.X-old.st.X<0)position.st.X--;
					else if(old.sh.X==old.st.X)position.st.Y++;					
				 };break;
		case 'd':{
					position.sh.X++;
					if(old.sh.Y-old.st.Y>0)position.st.Y++;
					else if(old.sh.Y-old.st.Y<0)position.st.Y--;
					else if(old.sh.Y==old.st.Y)position.st.X++;				
				 };break;

	}	
		SnakeMap(position.sh,position.st,old.sh,old.st);	
}

void SnakeMap( COORD sh,COORD st,COORD old1,COORD old2)
{
	SetPosition(sh.X,sh.Y);                   //����ͷ
	SetColor(SnakeHead.color);
	printf("%s",SnakeHead.ch);

	SetPosition(old2.X,old2.Y);
	SetColor(Bg.color);                      //����jiu��β
	printf("%s",Bg.ch);

	SetPosition(old1.X,old1.Y);
	SetColor(SnakeBody.color);                   //����ͷ
	printf("%s",SnakeBody.ch);


}


void BackGrandInit()
{
	int i,j;
	//************************************************************
	SetColor(Bg.color);
	SetColor(16);//����Ϊ��ɫ
	for(i=2;i<=BorderSize.x-1;i++)
	{
		for(j=2;j<=BorderSize.y-1;j++)      //����Ϊ��ɫ�飬����ҲҲΪ��
		{
			SetPosition(i,j);
			printf("%s",Bg.ch);
		}
	}        
	//*************************************************************
	SetColor(Border.color);
	for(i=1;i<BorderSize.x+1;i++)
	{
		SetPosition(i,1);
		printf("%s",Border.ch);
		SetPosition(i,25);
		printf("%s",Border.ch);
	}	                                   //�߿���ɫΪ��ɫ
	for(i=1;i<BorderSize.y;i++)
	{
		SetPosition(1,i);
		printf("%s",Border.ch);
		SetPosition(45,i);
		printf("%s",Border.ch);
	}
	//*******************************************************************
	SetPosition(22,12);
	SetColor(SnakeHead.color);
	printf("%s",SnakeHead.ch);    //������β
	SetPosition(23,12);
	printf("%s",SnakeBody.ch);
	SetPosition(24,12);
	printf("%s",SnakeBody.ch);
	position.sh.X=22;
	position.sh.Y=12;
	position.st.X=24;
	position.st.Y=12;
	//*********************************************************************
	SetColor(2);//������ɫ��ɫ
	SetPosition(50,12);
	printf("������ %d",score);
	SetPosition(50,13);
	printf("The company:");
	SetPosition(55,14);
	printf("XingYeGongSi");               //��������˾�������ߣ�
	SetPosition(50,15);
	printf("The programmer:");
	SetPosition(55,16);
	printf("zhaozhenjin");
	SetPosition(46,17);
	//*********************************************************************
}

void SetPosition(int x,int y)
{
	HANDLE SetPosition;
	COORD coord;
	SetPosition=GetStdHandle(STD_OUTPUT_HANDLE);//���ù��λ��
	coord.X=2*(x-1);
	coord.Y=y-1;
	SetConsoleCursorPosition(SetPosition,coord);
}

void SetColor(int x)
{
	HANDLE colour;
	colour=GetStdHandle(STD_OUTPUT_HANDLE);	//������ɫ
	SetConsoleTextAttribute(colour,x);
}