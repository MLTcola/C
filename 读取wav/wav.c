#include <stdio.h>       
 #include <stdlib.h>         
 #include <math.h>     

 #define  W  128   //每次读写文件的数据量  

 int    FileSet=0;      //定义一个整型变量， 用于保存fseek函数的返回值
 int     FileEnd=0;    //整个文件的字节数 
 int     FileLength=0;  //文件的数据长度。（注：每2个字节作为一个数据 ）
 int i;
 short InputData[W];   //文件读写数据缓冲区  

 main()
 {
  FILE *Ifp,*Ofp,*ttt; //定义文件读写指针 
  Ifp = fopen("1.wav","rb");    /*以只读方式打开1a.wav文件*/
  Ofp = fopen(" ProcessedFile.wav","wb");/*以只写方式使用ProcessedFile.wav文件.(注：这个文件本身并不存在，但通过这条语句可以创建这个文件）*/
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
