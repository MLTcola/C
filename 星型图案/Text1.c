#include<stdio.h>
int main()
{
	int i,k,m=0,j;
	unsigned char table[]={3,2,1,0,1,2,3};
	for(i=7;i>0;i--)
	{
		for(k=0;k<table[m];k++)
		{
			printf(" ");
		}
		
		j=7-2*table[m];
		m++;
		for(k=0;k<j;k++)
		{
			printf("*");
		}
		printf("\n");	
	}
}
