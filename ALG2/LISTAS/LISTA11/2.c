#include <stdio.h>
#include <stdlib.h>

typedef struct reg *no;

struct reg
{
  int info;
  struct reg *pLink;
};

void criarLista(no *lista)
{
  *lista = NULL;
}

void incluir_f(no *lista, int info)
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
  }
}

void mostrar(no lista)
{

  if (lista == NULL)
  {
    printf("\nNula");
    return;
  }

  no q = lista;

  do
  {
    printf("%d ", q->info);
    q = q->pLink;
  } while (q != lista);
}

int excluir_p(no *lista)
{

  no p, q;

  if (*lista == NULL)
  {
    printf("\nERRO");
    return 0;
  }

  if ((*lista)->pLink == *lista)
  {
    free(*lista);
    *lista = NULL;
  }
  else
  {
    q = *lista;
    p = *lista;

    while (q->pLink != *lista)
    {
      q = q->pLink;
    }

    *lista = (*lista)->pLink;
    free(p);
    q->pLink = *lista;
  }
}
int main()
{

  no lista;

  criarLista(&lista);

  int p = 1;

  while (p)
  {

    int x;

    printf("Digite um valor: ");
    scanf("%d", &x);

    incluir_f(&lista, x);

    printf("CONTINUA: ");
    scanf("%d", &p);

  }

  printf("LISTA: ");
  mostrar(lista);

  printf("\n");

  excluir_p(&lista);
  printf("LISTA EXCLUSAO: ");
  mostrar(lista);
}