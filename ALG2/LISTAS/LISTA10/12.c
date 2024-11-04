#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct reg *no;

struct reg {
    int info;
    struct reg *pLink;
};

void inclui_inicio(no *lista, int info){
    no p = (no) malloc(sizeof(struct reg));

    p->info = info;

    p->pLink = *lista;

    *lista = p;
}


int main()
{

    no lista = NULL;

    inclui_inicio(&lista, 100);
    inclui_inicio(&lista, 15);

}