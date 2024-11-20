#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

typedef struct reg *no;

struct reg
{
  int info;
  struct reg *pLink;
};

void inserir_i(no *lista, int info)
{
  no p = (no)malloc(sizeof(struct reg));
  p->info = info;
  if (*lista == NULL)
  {
    p->pLink = p;
    *lista = p;
  }
  else
  {
    no q = *lista;
    while (q->pLink != *lista)
    {
      q = q->pLink;
    }
    q->pLink = p;
    p->pLink = *lista;
    *lista = p;
  }
}

void mostrar(no lista)
{
  no p = lista;
  if (lista == NULL)
  {
    printf("NULA\n");
    return;
  }
  do
  {
    printf("%d ", p->info);
    p = p->pLink;
  } while (p != lista);
}

void mais_menos_vezes(no lista)
{
    if (lista == NULL)
    {
        printf("Lista vazia.\n");
        return;
    }

    no p = lista;
    int maiorInfo = lista->info;

    
    do
    {
        if (p->info > maiorInfo)
        {
            maiorInfo = p->info;
        }
        p = p->pLink;
    } while (p != lista);

    
    int x[maiorInfo + 1];
    
    for (int i = 0; i <= maiorInfo; i++)
    {
        x[i] = 0;
    }

    
    p = lista;
    do
    {
        x[p->info]++;
        p = p->pLink;
    } while (p != lista);

    
    int menor = -1, maior = -1;
    for (int i = 0; i <= maiorInfo; i++)
    {
        if (x[i] > 0)
        {
            if (menor == -1 || x[i] < x[menor])
            {
                menor = i;
            }
            if (maior == -1 || x[i] > x[maior])
            {
                maior = i;
            }
        }
    }

    printf("\nMaior: %d apareceu %d vezes\n", maior, x[maior]);
    printf("Menor: %d apareceu %d vezes\n", menor, x[menor]);
}
int main()
{

  no lista = NULL;

  inserir_i(&lista, 10);
  inserir_i(&lista, 10);
  inserir_i(&lista, 12);
  inserir_i(&lista, 1);
  inserir_i(&lista, 1);
  inserir_i(&lista, 1);
  inserir_i(&lista, 1);
  inserir_i(&lista, 1);

  mostrar(lista);

  printf("\n");
  mostrar(lista);

  mais_menos_vezes(lista);

  return 0;
}