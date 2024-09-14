#include <stdio.h>
#include <string.h>

int main()
{
  
  char ch;

  FILE *arq1 = fopen("10.txt", "r");
  FILE *arq2 = fopen("new10.txt", "w");

  while((ch = fgetc(arq1)) != EOF){
    fputc(ch, arq2);
  }

  fclose(arq1);
  fclose(arq2);
  
  return 0;
}