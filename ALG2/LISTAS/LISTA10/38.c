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

int verifica_palindromo(no lista) {
    
    int qt = 0;
    no p = lista;
    while (p != NULL) {
        qt++;
        p = p->pLink;
    }

    
    int *x = (int *)malloc(qt * sizeof(int));
    p = lista;
    for (int i = 0; i < qt; i++) {
        x[i] = p->info;
        p = p->pLink;
    }

    
    int inicio = 0, fim = qt - 1;
    while (inicio < fim) {
        if (x[inicio] != x[fim]) {
            free(x); 
            return 0; 
        }
        inicio++;
        fim--;
    }

    free(x); 
    return 1; 
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

    if (verifica_palindromo(lista)) {
        printf("eh palindromo\n");
    } else {
        printf("nao eh palindromo\n");
    }

    exclui_tudo(&lista);
    return 0;
}
