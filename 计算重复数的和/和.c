#include<stdio.h>
int main()
{
	int n,a,sum=0,k=1,num=1,j;
	printf("请输入数字n:");
	scanf("%d",&n);
	printf("请输入数字a:");
	scanf("%d",&a);
	j=n-1;
	while(n)
	{
		while(j--)
			k=k*10;
		sum=sum+a*k*num;
		num++;
		n--;
		j=n-1;
		k=1;
	}
	printf("%d",sum);
	return 0;
}