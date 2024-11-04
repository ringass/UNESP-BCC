#include <stdio.h>
#include <stdlib.h>

typedef struct reg *no;

struct reg
{
    int info;
    struct reg *pLink;
};

void exclui_tudo(no *lista){
    while(*lista != NULL){
        no p = *lista;
        *lista = (*lista)->pLink;
        free(p);
    }
}

void inclui_final(no *lista, int info)
{
    no p = (no)malloc(sizeof(struct reg));

    no q;

    p->info = info;
    p->pLink = NULL;

    if (*lista == NULL)
    {
        *lista = p;
    }
    else
    {
        q = *lista;

        while (q->pLink)
        {
            q = q->pLink;
        }

        q->pLink = p;
    }
}

void mostra_lista(no lista)
{   

    if(lista == NULL){
        printf("vazia");
        return;
    }

    no p = lista;
    printf("\nElementos da lista: ");
    while (p)
    {
        printf("%d ", p->info);
        p = p->pLink;
    }
}

void concatena_newlista (no *l1, no *l2, no *l3) {
  no p = *l1, r;
  *l3 = NULL;
  while (p != NULL){
  	no q = (no) malloc(sizeof(struct reg));
  	q->info = p->info;
  	q->pLink = NULL;
    if (*l3 == NULL) 
	    *l3 = q;
	  else
	    r->pLink = q;
	  r = q;  
	  p = p->pLink;    	
  }
  p = *l2;
  while (p != NULL){
  	no q = (no) malloc(sizeof(struct reg));
  	q->info = p->info;
  	q->pLink = NULL;
    if (*l3 == NULL) 
	    *l3 = q;
	  else
	    r->pLink = q;
	  r = q;  
	  p = p->pLink;    	
  }

  exclui_tudo(l1);
  exclui_tudo(l2);
}


int main()
{
    int continua = 1, x;

    no lista = NULL;
    no lista2 = NULL;
    no lista3 = NULL;

    while (continua)
    {

        scanf("%d", &x);

        inclui_final(&lista, x);

        printf("Deseja continuar inserindo a lista? ");
        scanf("%d", &continua);
    }

    continua = 1;
    printf("Insira na lista2: ");

    while (continua)
    {

        scanf("%d", &x);

        inclui_final(&lista2, x);

        printf("Deseja continuar inserindo a lista? ");
        scanf("%d", &continua);
    }

    printf("lista1: ");
    mostra_lista(lista);

    
    printf("\nlista2: ");
    mostra_lista(lista2);

    concatena_newlista(&lista, &lista2, &lista3);

    printf("\nlista3: ");
    mostra_lista(lista3);

    printf("\n\nlista1 dps: ");
    mostra_lista(lista);

    printf("\n\nlista2 dps: ");
    mostra_lista(lista2);

}