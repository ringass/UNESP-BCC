// Escreva uma função que gere uma lista linear simplesmente encadeada L2 onde cada regis-
// tro contém dois campos de informação: dado contém um elemento de L1, e qte contém

// quantas vezes este elemento apareceu em L1.

#include <stdlib.h>
#include <stdio.h>

typedef struct reg *no;

struct reg
{
    int info;
    struct reg *pLink;
};

void inclui_inicio(no *lista, int info)
{
    no p = (no)malloc(sizeof(struct reg));

    p->info = info;

    p->pLink = *lista;

    *lista = p;
}


void verifica(no *lista){
    no p = *lista;

    if(*lista == NULL || (*lista)->pLink == NULL){
        printf("nao ha repetidos");
        return;
    }

    while(p != NULL){

        int x = p->info;

        no q = p;

        while(q->pLink != NULL){
            if(q->pLink->info == x){
                no r = q->pLink;
                q->pLink = q->pLink->pLink;
                free(r);
            }else{
                q = q->pLink;
            }
        }

        p = p->pLink;
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

int main()
{

    no lista = NULL;

    inclui_inicio(&lista, 100);
    inclui_inicio(&lista, 15);
    inclui_inicio(&lista, 100);
    inclui_inicio(&lista, 15);
    inclui_inicio(&lista, 100);
    inclui_inicio(&lista, 15);
    inclui_inicio(&lista, 1);
    inclui_inicio(&lista, 3);


    mostra_lista(lista);

    printf("\n");

    verifica(&lista);
    mostra_lista(lista);

}