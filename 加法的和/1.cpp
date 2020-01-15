#include<stdio.h>

unsigned char table[]={2,4,8,10,16};

int main()
{
	int a,b,c,d,j,q=0,p,n,flag,num=0,num1=0,num2=0,num3=0;
	int pingfang(int n,int m);
	scanf("%d",&a);
	scanf("%d",&b);
	scanf("%d",&c);
	for(p=0;p<5;p++)
	{
	n=table[p];
	num1=0;
	num2=0;
	num3=0;
	d=a;
	j=a;
	flag=a*10;
	while(flag)
	{	
		d=j;
		d=d%10;
		if(d>=n)
		{
			flag=0;
			num1=0;
			break;
		}
		num1=d*pingfang(n,num)+num1;
		num++;
		j=j/10;
		flag=flag/10;	
	}
	num=0;
	d=b;
	j=b;
	flag=b*10;
	while(flag)
	{		
		d=j;
		d=d%10;
		if(d>=n)
		{
			flag=0;
			num2=0;
			break;
		}
		num2=d*pingfang(n,num)+num2;
		num++;
		j=j/10;
		flag=flag/10;
	}
	num=0;
	d=c;
	j=c;
	flag=c*10;
	while(flag)
	{		
		d=j;
		d=d%10;
		if(d>=n)
		{
			flag=0;
			num3=0;
			break;
		}
		num3=d*pingfang(n,num)+num3;
		num++;
		j=j/10;
		flag=flag/10;
	}
	num=0;
	if((num3==num1*num2)&num3!=0) 
	{
		switch(n)
		{
			case 2:printf("Kessel");printf(" ");q=1;break;
			case 4:printf("Hoth");printf(" ");q=1;break;
			case 8:printf("Endor");printf(" ");q=1;break;
			case 10:printf("Earth");printf(" ");q=1;break;			
			case 16:printf("Death2");printf(" ");q=1;break;
		}
	}
	}
	if(q==0)
	{
		printf("Larry");
		printf(" ");
	}
	return 0;
}

int pingfang(int n,int m)
{
	int num=1;
	while(m)
	{
		num=n*num;
		m--;
	}
	return num;
}
