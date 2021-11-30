#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
 int i, n, s;
 char txt[5000];
 FILE *fp;
 int ransu;
 int k[30];
 fp = fopen("File.txt","r");
 if(fp == NULL)
 {
  printf("ファイルを開くことができませんでした\n");
  return;
 }
 
 for(i=0; i<30; i++){
     txt[i] = fgetc(fp);
     if(txt[i]==EOF)
     {
     break;
     }
    }
   fclose(fp);
//乱数生成 
 srand((unsigned) time(NULL));
 for(s=0;s<30;s++)
  {
   ransu=rand()%30 + 1;
   k[s] = ransu;
  }

 for(i=0;i<20;i++)
  {
   for(s = 0;s<30;s++)
   {
   i = k[s];
   printf("%c",txt[i]);
   }
   }
  printf("\n");
}
