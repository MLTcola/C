#include<stdio.h>
int main()
{
	int yw=0,kg=0,sz=0,qy=0;
	char k;
	printf("�����룺");
	k=getchar();
	while(k!='\n')
	{
		if((k>='A'&&k<='Z')||(k>='a'&&k<='z'))        yw++;    
		else if(k==' ')          kg++;    
		else if(k>='0'&&k<='9')    sz++;  
		else                     qy++;    
			
		k=getchar();
	}
	printf("a-Z������=%d\n�ո�����=%d\n��������=%d\n�����ַ�����=%d\n",yw,kg,sz,qy);
	return 0;
}