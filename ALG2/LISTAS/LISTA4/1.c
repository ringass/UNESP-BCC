#include <stdio.h>
#include <stdlib.h>

int main()
{
  char p[15], ch;

  scanf("%s", &p);

  FILE *arq = fopen(strcat(p, ".txt"), "r");

  if (arq == NULL)
  {
    printf("Erro\n");
    return 1;
  }

  while ((ch = fgetc(arq)) != EOF)
  {
    putchar(ch);
  }
  fclose(arq);
}