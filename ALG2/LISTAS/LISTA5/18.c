#include <stdio.h>
#define MAX 10

int soma(int v[], int n)
{
  if(n < 0){
    return 0;
  }

  return v[n] + soma(v, n-1); 
}

int main()
{

  int aa = 1;

  while (aa)
  {
    int p, v[MAX];

    scanf("%d", &p);

    for(int i = 0; i < p; i++){
      scanf("%d", &v[i]);
    }

    printf("%d\n", soma(v, p-1));

    printf("1 para continuar/ 0 para encerrar\n");
    scanf("%d", &aa);
  }

  return 0;
}