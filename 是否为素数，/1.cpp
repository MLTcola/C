#include<stdio.h>
#include<math.h>
int main()
{
	int a,b,c=2;
	printf("Please shu ru yi ge >=3 de  shu\n");
	scanf("%d",&a);
	b=sqrt(a);
	while((a%c!=0)&&(c<=b))
	{
		c=c++;
	}
	if(c>b)
		printf("%d is  a prime\n",a);
	else
		printf("%d is not a prime\n",a);
	return 0;
}