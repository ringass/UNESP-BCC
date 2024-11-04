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

typedef struct regg *node;

struct regg
{
    int qt;
    int dado;
    struct regg *pLink;
};

void inclui_inicio(no *lista, int info)
{
    no p = (no)malloc(sizeof(struct reg));

    p->info = info;

    p->pLink = *lista;

    *lista = p;
}

void inclui_inicio_l2(node *lista, int info, int freq)
{
    node p = (node)malloc(sizeof(struct regg));

    p->dado = info;

    p->qt = freq;

    p->pLink = *lista;

    *lista = p;
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

void mostra_lista_l2(node lista)
{
    node p = lista;
    printf("\nElementos da lista: ");
    while (p)
    {
        printf("dado: %d -> freq: %d || ", p->dado, p->qt);
        p = p->pLink;
    }
}

node L2(no lista)
{

    node lista2 = NULL;

    no p = lista;

    while (p != NULL)
    {
        int dado = p->info;
        int freq = 0;

        no q = lista;

        while (q != NULL)
        {
            if (q->info == dado)
            {
                freq++;
            }
            q = q->pLink;
        }

        node r = lista2;

        int achou = 0;

        while (r != NULL)
        {
            if (r->dado == dado)
            {
                achou = 1;
                break;
            }
            r = r->pLink;
        }

        if (achou == 0)
        {
            inclui_inicio_l2(&lista2, dado, freq);
        }

        p = p->pLink;
    }

    return lista2;
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

    node lista2 = L2(lista);

    mostra_lista(lista);

    printf("\n");
    mostra_lista_l2(lista2);

}