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

void exclui_x(no *lista, int x){

    no p = *lista;

    if(*lista == NULL || x < (*lista)->info){
        printf("nao há o numero %d na linked list", x);
        return;
    }

    if((*lista)->info == x){
        *lista = (*lista)->pLink;
        
        free(p);

        return;
    }

    no r = NULL;

    while(p != NULL && p->info != x){
        r = p;
        p = p->pLink;
    }

    if(p == NULL){
        printf("nao há esse numero na lista");
        return;
    }

    if(p->pLink == NULL){
        r->pLink = NULL;
    }else{
        r->pLink = p->pLink;   
    }

    free(p);

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

    int n;

    printf("quero excluir: ");
    scanf("%d", &n);
    exclui_x(&lista, n);

    printf("\n");
    mostra_lista(lista);



}