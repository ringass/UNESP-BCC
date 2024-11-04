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

void end_val(no lista)
{

    no p = lista;

    while (p->pLink != NULL)
    {
        p = p->pLink;
    }

    printf("endereco: %p || valor: %d", p, p->info);
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

    end_val(lista);

}