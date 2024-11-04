#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct reg *no;

struct reg {
    int info;
    struct reg *pLink;
};

void inclui_ordenadamente(no *lista, int num){
    no p = (no)malloc(sizeof(struct reg));

    p->info = num;

    if(*lista == NULL || num <= (*lista)->info){
        p->pLink = *lista;
        *lista = p;
    }else{
        no q = *lista, r;

        while(q != NULL && q->info < num){
            r = q;
            q = q->pLink;
        }

        p->pLink = q;
        r->pLink = p;
    }
}

void inverte(no *lista){
    no p, q, r;

    if(*lista == NULL || (*lista)->pLink == NULL){
        return;
    }

    p = *lista;
    q = (*lista)->pLink;

    p->pLink = NULL;

    while(q != NULL){
        r = q;
        q = q->pLink;
        r->pLink = p;
        p = r;
    }

    *lista = r;
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

int main()
{

    int continua = 1, x;

    no lista = NULL;

    while (continua)
    {

        scanf("%d", &x);

        inclui_ordenadamente(&lista, x);

        printf("Deseja continuar inserindo a lista? ");
        scanf("%d", &continua);
    }

    
    mostra_lista(lista);

    printf("\n");

    inverte(&lista);

    printf("\n");
    mostra_lista(lista);



}