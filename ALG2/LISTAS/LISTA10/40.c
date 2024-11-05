#include <stdio.h>
#include <stdlib.h>

typedef struct reg *no;

struct reg {
    int info;
    struct reg *pLink;
};

void mostra_lista(no lista) {
    if (lista == NULL) {
        printf("vazia");
        return;
    }

    no p = lista;
    printf("\nElementos da lista: ");
    while (p) {
        printf("%d ", p->info);
        p = p->pLink;
    }
    printf("\n");
}

void inclui_inicio(no *lista, int info) {
    no p = (no) malloc(sizeof(struct reg));
    p->info = info;
    p->pLink = *lista;
    *lista = p;
}

void exclui_tudo(no *lista) {
    while (*lista != NULL) {
        no p = *lista;
        *lista = (*lista)->pLink;
        free(p);
    }
}

void maior_menor(no lista){
    int maior, menor;

    maior = menor = lista->info;

    no p = lista;

    while(p->pLink != NULL){

        if(p->info <= menor){
            menor = p->info;
        }

        if(p->info >= maior){
            maior = p->info;
        }

        p = p->pLink;
    }


    printf("\nmaior: %d || menor: %d", maior, menor);

}

int main() {
    no lista = NULL;

    inclui_inicio(&lista, 1);
    inclui_inicio(&lista, 2);
    inclui_inicio(&lista, 3);
    inclui_inicio(&lista, 2);
    inclui_inicio(&lista, 1);

    printf("Lista: ");
    mostra_lista(lista);

    maior_menor(lista);
    
    return 0;
}
