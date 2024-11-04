#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct reg *no;

struct reg {
    int info;
    struct reg *pLink;
};

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
    printf("\n");
}

void inclui_inicio(no *lista, int info){
    no p = (no) malloc(sizeof(struct reg));

    p->info = info;

    p->pLink = *lista;

    *lista = p;
}

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

void divide(no *lista, no *m1, no *m2){
    no p = *lista;

    if(*lista == NULL || (*lista)->pLink == NULL){
        return;
    }

    int qt = 0;
    int i = 0;

    while( p != NULL){
        p = p->pLink;
        qt++;
    }

    p = *lista;

    while(p != NULL){
        
        if(i < qt/2){
            inclui_final(m1, p->info);
        }else{
            inclui_final(m2, p->info);
        }

        p = p->pLink;
        i++;
    }

    exclui_tudo(lista);
}


int main()
{

    no lista = NULL;
    no m1 = NULL;
    no m2 = NULL;

    inclui_inicio(&lista, 100);
    inclui_inicio(&lista, 15);
    inclui_inicio(&lista, 10);
    inclui_inicio(&lista, 5);
    inclui_inicio(&lista, 0);
    inclui_inicio(&lista, 8);
    inclui_inicio(&lista, 9);
    inclui_inicio(&lista, 14);
    inclui_inicio(&lista, 2);
    inclui_inicio(&lista, 1);

    printf("lista 1: ");
    mostra_lista(lista);

    printf("\n");

    divide(&lista, &m1, &m2);

    printf("metade 1: ");
    mostra_lista(m1);

    printf("metade 2: ");
    mostra_lista(m2);

    printf("lista 1 pos: ");
    mostra_lista(lista);

}