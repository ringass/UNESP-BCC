#include <stdio.h>

int soma(int n)
{
  if(n == 0){
    return 0;
  }

  return n + soma(n - 1);
}

int main()
{

  int aa = 1;

  while (aa)
  {
    int p;

    scanf("%d", &p);
    printf("%d\n", soma(p));


    printf("1 para continuar/ 0 para encerrar\n");
    scanf("%d", &aa);
  }

  return 0;
}