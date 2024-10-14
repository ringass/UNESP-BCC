#include <stdio.h>
#include <stdlib.h>

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

void mostra_lista(no lista){
    no p = lista;

    while(p){
        printf("%d", lista->info);
        p = p->pLink;
    }
}

int main(){
    
    no lista = NULL;

    inclui_inicio(&lista, 100);
    mostra_lista(lista);

}
