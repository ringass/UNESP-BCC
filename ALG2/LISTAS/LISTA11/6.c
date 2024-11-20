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

void inverter_lista(no *lista)
{
  no p = *lista;
  no q = *lista;

  while (q->pLink != *lista)
  {
    q = q->pLink;
  }

  q->pLink = NULL;

  while (p != NULL)
  {
    no aux = p->pLink;
    p->pLink = q;
    q = p;
    p = aux;
  }

  *lista = q;
}

int main()
{

  no lista = NULL;

  inserir_i(&lista, 10);
  inserir_i(&lista, 12);
  inserir_i(&lista, 1);
  inserir_i(&lista, 5);
  inserir_i(&lista, 9);

  mostrar(lista);

  inverter_lista(&lista);

  printf("\n");
  mostrar(lista);

  return 0;
}