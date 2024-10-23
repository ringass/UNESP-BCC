#include <stdio.h>
#include <stdlib.h>

typedef struct reg *no;

struct reg
{
    int info;
    struct reg *pLink;
};

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
    no p = lista;
    printf("\nElementos da lista: ");
    while (p)
    {
        printf("%d ", p->info);
        p = p->pLink;
    }
}

void inclui_ordenadamente(no *lista, int num){
    no p = (no)malloc(sizeof(struct reg));

    p->info = num;

    if(*lista == NULL || num <= (*lista)->info){
        p->pLink = *lista;
        *lista = p;
    }else{
        no q = *lista, r;

        while(q!= NULL && q->info < num){
            r = q;
            q = q->pLink;
        }

        p->pLink = q;
        r->pLink = p;
    }
}


void concatenar(no *lista, no lista2){

    no p = *lista;

    if(lista2 == NULL){
        *lista = lista2;
        return;
    }

    if(lista != NULL){
    while(p->pLink != NULL){
        p = p->pLink;
    }
    }

    p->pLink = lista2;

}

void concatena_newlista (no l1, no l2, no *l3) {
  no p = l1, r;
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
  p = l2;
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

        inclui_ordenadamente(&lista, x);

        printf("Deseja continuar inserindo a lista? ");
        scanf("%d", &continua);
    }

    continua = 1;
    printf("Insira na lista2: ");

    while (continua)
    {

        scanf("%d", &x);

        inclui_ordenadamente(&lista2, x);

        printf("Deseja continuar inserindo a lista? ");
        scanf("%d", &continua);
    }

    printf("lista1: ");
    mostra_lista(lista);

    
    printf("\nlista2: ");
    mostra_lista(lista2);

    printf("\nlista 1 com a 2" );
    concatena_newlista(lista, lista2, &lista3);
    mostra_lista(lista3);

    concatenar(&lista, lista2);

    printf("\nlista 1" );
    mostra_lista(lista);

}