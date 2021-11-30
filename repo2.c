#include <stdio.h>
#include <stdlib.h>    /* exit(  ) で必要 */

#define BYTE 256
int alpha[BYTE];       /* 関数の外で宣言 */

void CountLett(FILE *fp);
void PrintResult(void) ;
void main(void);

  /* ファイル中の英文字の出現頻度を調べる */
void CountLett(FILE *fp)
{
    int c;
    int C;
      /* ファイルの終わりに達するまで１文字読み込む */
    while ((c = getc(fp)) != EOF){
          /* c がアルファベットの小文字なら */
        if (c >= 'a' && c <= 'z')
        { 
          alpha[c]++;  
                      }      
     /*大文字なら小文字に変換*/
        else if (c >= 'A' && c <= 'Z'){
         c = c + ('a'-'A');
         alpha[c]++;
        }
              } 
}
void PrintResult(void)
{
    int c;

    for (c = 'a'; c <= 'z'; c++)       /* 小文字の出現頻度を */
        printf("%c:%d\t",  c, alpha[c]);    /* 表示 */
    printf("\n\n");
 }

void main(void)
{
    FILE *fp;

    if ((fp = fopen("Filex.txt", "r")) == NULL) {   /* ファイルを開けなければ */
                                                    /* メッセージを表示して */
        fprintf ( stderr, "Can't Open C Source File!\n" );
        exit (2);                                   /* 終了 */
    }
    printf("filex.txt ファイルにおけるアルファベットの出現頻度\n");
    CountLett(fp) ;        /* 文字の出現頻度を調べて */
    PrintResult(  );       /* 表示する */
	 
    fclose(fp);            /* ファイルを閉じる */
 }

