/*数値解析学　問題１
　　　　　　　　　　　　20C1050 佐藤涼耶*/

#include <stdio.h>
#include <stdlib.h>    

#define BYTE 3000
int alpha[BYTE];

void main(void);

void main(void)
{
    FILE *fp;
    int c;

    if ((fp = fopen( "Filex.txt", "r")) == NULL) {
        fprintf(stderr, "Can't Open File\n");
        exit(2);	
    }			
    
    while ((c = fgetc(fp)) != EOF){    /* 一文字読み込み */
      if (c >= 'A' && c <= 'Z'){
      c = c + ('a'-'A');

      }else if(c >= 0 && c <= 64){
      c = 32;
      
      }else if(c >= 91 && c <= 96){
      c = 32;
      
      }else if(c >= 123 && c <= 126){
      c = 32;
      
      }
      printf("%c",c);
       
                  /* 画面に表示 */
}
printf("\n\n");
    fclose(fp);                       /* ファイルを閉じる */
}
