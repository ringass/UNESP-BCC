#include <stdio.h>
#include <string.h>

void dectobin(int n, FILE *arq3)
{
  int bin[32];

  int i = 0;

  while(n > 0){
    bin[i] = n % 2;
    n = n / 2;
    i++;
  }

   while (i < 8)
  {
    bin[i] = 0;
    i++;
  }
  
  for (int j = 7; j >= 0; j--)
  {
    fputc(bin[j] + '0', arq3);
  }
}

int main()
{
  int x[10];

  FILE *arq = fopen("8.txt", "w");

  for(int i = 0; i < 10; i++){
    scanf("%d", &x[i]);
    
    dectobin(x[i], arq);
    fputs("\n", arq);
  }

  fclose(arq);
  return 0;
}