#include <stdio.h>       
 #include <stdlib.h>         
 #include <math.h>     

 #define  W  128   //ÿ�ζ�д�ļ���������  

 int    FileSet=0;      //����һ�����ͱ����� ���ڱ���fseek�����ķ���ֵ
 int     FileEnd=0;    //�����ļ����ֽ��� 
 int     FileLength=0;  //�ļ������ݳ��ȡ���ע��ÿ2���ֽ���Ϊһ������ ��
 int i;
 short InputData[W];   //�ļ���д���ݻ�����  

 main()
 {
  FILE *Ifp,*Ofp,*ttt; //�����ļ���дָ�� 
  Ifp = fopen("1.wav","rb");    /*��ֻ����ʽ��1a.wav�ļ�*/
  Ofp = fopen(" ProcessedFile.wav","wb");/*��ֻд��ʽʹ��ProcessedFile.wav�ļ�.(ע������ļ����������ڣ���ͨ�����������Դ�������ļ���*/
  ttt=fopen("hao.txt","w");

fseek(Ifp,0L,SEEK_END);
 FileEnd=ftell(Ifp);
 printf("%d/n",FileEnd);
 rewind(Ifp);
 FileLength=FileEnd/2;

 while(FileLength>=W)
 {
 fread(InputData,sizeof(short),W,Ifp);
 for( i=0;i<W;i++)
 {
 fprintf(ttt,"%d   ",InputData[i]);
 }
 FileLength-=W;
 }
 fread(InputData,sizeof(short),FileLength,Ifp); 
 for(i=0;i<FileLength;i++)
 {

 fprintf(ttt,"%d   ",InputData[i]);

 }
 return 0;

}
