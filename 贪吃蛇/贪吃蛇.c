#include<stdio.h> 
#include<stdlib.h>              //有清屏函数	system("CLS");
#include<windows.h>             //睡眠函数Sleep
#include<conio.h>               //不用回车就能输入getch

void BackGrandInit(void);       //背景初始化化
void SetPosition(int x,int y);  //定位
void SetColor(int x);            //设置颜色
void Move(char direction);                      //移动
void SnakeMap(COORD sh,COORD st,COORD old1,COORD old2);
//void Food();

int score;
int SnakeLong=3;

struct BorderSize                  //边框大小
			{
				char x;
				char y;
			}BorderSize={45,25};
struct{
		 char *ch;
		int color;
		}Border = {"■", 4},  //边框
		Bg = {"□",16},  //背景
		SnakeHead= {"★", 14},  //贪吃蛇
		SnakeBody={"■",14},
		Food = {"●", 13};  //食物
		struct{ 
		COORD sh;   //蛇头坐标
		COORD st;   //蛇尾坐标
		}position;
struct{
		COORD sh;        //蛇头蛇尾上一次的位置
		COORD st;
		} old; 
/*SetConsoleCursorPosition//光标控制函数
HANDLE colour;	colour=GetStdHandle(STD_OUTPUT_HANDLE);	SetConsoleTextAttribute(colour,FOREGROUND_RED|BACKGROUND_GREEN);是API设置控制台窗口字体颜色和背景色的函数
GetConsoleCursorInfo 函数检索有关指定的控制台屏幕缓冲区的光标的可见性和大小信息
GetStdHandle
b****************************************************************
	HANDLE SetPosition;
	COORD coord;
	SetPosition=GetStdHandle(STD_OUTPUT_HANDLE);//设置光标位置
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
			}charBorder = {"□", 4, 1},  //边框
			charBg = {"■", 2, 2},  //背景
			charSnake = {"★", 0xe, 3},  //贪吃蛇节点
			charFood = {"●", 0xc, 4};  //食物
	colour=GetStdHandle(STD_OUTPUT_HANDLE);	
	SetConsoleTextAttribute(colour,FOREGROUND_RED);
	printf("%s",charBg.ch);
**********************************************************
wAttributes 颜色 对应的值 
FOREGROUND_BLUE 字体颜色：蓝 1 
FOREGROUND_GREEN 字体颜色：绿 2 
FOREGROUND_RED 字体颜色：红 4 黄14
FOREGROUND_INTENSITY 前景色高亮显示 8 
BACKGROUND_BLUE 背景颜色：蓝 16 
BACKGROUND_GREEN 背景颜色：绿 32 
BACKGROUND_RED 
背景颜色：红
 64 
BACKGROUND_INTENSITY 背景色高亮显示 128 
****************************************************************
kbhit是一个函数，可以用来检查当前是否有键盘输入。
*******************************************************
思路：利用二维数组记录每次拐弯的方向*/
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
	SetPosition(sh.X,sh.Y);                   //新蛇头
	SetColor(SnakeHead.color);
	printf("%s",SnakeHead.ch);

	SetPosition(old2.X,old2.Y);
	SetColor(Bg.color);                      //消除jiu蛇尾
	printf("%s",Bg.ch);

	SetPosition(old1.X,old1.Y);
	SetColor(SnakeBody.color);                   //旧蛇头
	printf("%s",SnakeBody.ch);


}


void BackGrandInit()
{
	int i,j;
	//************************************************************
	SetColor(Bg.color);
	SetColor(16);//背景为蓝色
	for(i=2;i<=BorderSize.x-1;i++)
	{
		for(j=2;j<=BorderSize.y-1;j++)      //中心为蓝色块，背景也也为蓝
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
	}	                                   //边框颜色为红色
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
	printf("%s",SnakeHead.ch);    //蛇身蛇尾
	SetPosition(23,12);
	printf("%s",SnakeBody.ch);
	SetPosition(24,12);
	printf("%s",SnakeBody.ch);
	position.sh.X=22;
	position.sh.Y=12;
	position.st.X=24;
	position.st.Y=12;
	//*********************************************************************
	SetColor(2);//字体颜色绿色
	SetPosition(50,12);
	printf("分数： %d",score);
	SetPosition(50,13);
	printf("The company:");
	SetPosition(55,14);
	printf("XingYeGongSi");               //分数，公司，制作者，
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
	SetPosition=GetStdHandle(STD_OUTPUT_HANDLE);//设置光标位置
	coord.X=2*(x-1);
	coord.Y=y-1;
	SetConsoleCursorPosition(SetPosition,coord);
}

void SetColor(int x)
{
	HANDLE colour;
	colour=GetStdHandle(STD_OUTPUT_HANDLE);	//设置颜色
	SetConsoleTextAttribute(colour,x);
}