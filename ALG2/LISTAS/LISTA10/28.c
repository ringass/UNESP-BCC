#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct reg *no;

struct reg
{
    int info;
    struct reg *pLink;
};

void inclui_ordenadamente(no *lista, int num)
{
    no p = (no)malloc(sizeof(struct reg));

    p->info = num;

    if (*lista == NULL || num <= (*lista)->info)
    {
        p->pLink = *lista;
        *lista = p;
    }
    else
    {
        no q = *lista, r;

        while (q != NULL && q->info < num)
        {
            r = q;
            q = q->pLink;
        }

        p->pLink = q;
        r->pLink = p;
    }
}

int compara(no lista1, no lista2){
    no p = lista1;
    no q = lista2;

    while(p != NULL && q != NULL){

        if(p->info != q->info){

            return 0;
        }

        p = p->pLink;
        q = q->pLink;
    }

    if (p != NULL || q != NULL) {
        return 0;
    }

    return 1;
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

    no lista1 = NULL;
    no lista2 = NULL;

    while (continua)
    {

        scanf("%d", &x);

        inclui_ordenadamente(&lista1, x);

        printf("Deseja continuar inserindo a lista? ");
        scanf("%d", &continua);
    }

    continua = 1;

    printf("\nLISTA 2\n");

    while (continua)
    {

        scanf("%d", &x);

        inclui_ordenadamente(&lista2, x);

        printf("Deseja continuar inserindo a lista? ");
        scanf("%d", &continua);
    }

    mostra_lista(lista1);

    printf("\n");

    mostra_lista(lista2);

    printf("\n");

    if(compara(lista1, lista2)){
        printf("sao iguais");
    }else{
        printf("nao sao iguais");
    }
}