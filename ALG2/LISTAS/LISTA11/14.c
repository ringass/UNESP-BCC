#include <stdio.h>
#include <stdlib.h>

typedef struct reg *no;

struct reg {
    int exp;
    float coef;
    struct reg *pLink;
};


no criar_no(float coef, int exp) {
    no novo = (no)malloc(sizeof(struct reg));
    novo->coef = coef;
    novo->exp = exp;
    novo->pLink = novo;
    return novo;
}


void inserir(no *lista, float coef, int exp) {
    no novo = criar_no(coef, exp);

    
    if (*lista == NULL) {
        *lista = novo;
        return;
    }

    no atual = *lista, anterior = NULL;

 
    do {
        if (atual->exp < exp) break; 
        anterior = atual;
        atual = atual->pLink;
    } while (atual != *lista);

    
    if (atual != NULL && atual->exp == exp) {
        atual->coef += coef;
        free(novo);
        return;
    }

    
    if (anterior == NULL || (*lista)->exp < exp) {
        novo->pLink = *lista;

        
        no temp = *lista;
        while (temp->pLink != *lista) {
            temp = temp->pLink;
        }
        temp->pLink = novo;

        *lista = novo; 
    } else { 
        
        anterior->pLink = novo;
        novo->pLink = atual;
    }
}

void exibir(no lista) {
    if (lista == NULL) {
        printf("Lista vazia\n");
        return;
    }

    no atual = lista;
    do {
        printf("%.1fx^%d ", atual->coef, atual->exp);
        if (atual->pLink != lista && atual->pLink->coef >= 0)
            printf("+ ");
        atual = atual->pLink;
    } while (atual != lista);
    printf("\n");
}


no somar(no lista1, no lista2) {
    no resultado = NULL;

    if (lista1 != NULL) {
        no atual = lista1;
        do {
            inserir(&resultado, atual->coef, atual->exp);
            atual = atual->pLink;
        } while (atual != lista1);
    }

    if (lista2 != NULL) {
        no atual = lista2;
        do {
            inserir(&resultado, atual->coef, atual->exp);
            atual = atual->pLink;
        } while (atual != lista2);
    }

    return resultado;
}

no multiplicar(no lista1, no lista2) {
    no resultado = NULL;

    if (lista1 == NULL || lista2 == NULL) return resultado;

    no p1 = lista1;
    do {
        no p2 = lista2;
        do {
            float novo_coef = p1->coef * p2->coef;
            int novo_exp = p1->exp + p2->exp;
            inserir(&resultado, novo_coef, novo_exp);
            p2 = p2->pLink;
        } while (p2 != lista2);
        p1 = p1->pLink;
    } while (p1 != lista1);

    return resultado;
}


no derivar(no lista) {
    no resultado = NULL;

    if (lista == NULL) return resultado;

    no atual = lista;
    do {
        if (atual->exp != 0) {
            inserir(&resultado, atual->coef * atual->exp, atual->exp - 1);
        }
        atual = atual->pLink;
    } while (atual != lista);

    return resultado;
}


int main() {
    no polinomio1 = NULL;
    no polinomio2 = NULL;

    inserir(&polinomio1, 3.0, 3);
    inserir(&polinomio1, 2.0, 2);
    inserir(&polinomio1, 1.0, 1);
    printf("Polinomio 1: ");
    exibir(polinomio1);

    inserir(&polinomio2, 4.0, 2);
    inserir(&polinomio2, 1.0, 1);
    inserir(&polinomio2, -1.0, 0);
    printf("Polinomio 2: ");
    exibir(polinomio2);

    no soma = somar(polinomio1, polinomio2);
    printf("Soma: ");
    exibir(soma);

    no produto = multiplicar(polinomio1, polinomio2);
    printf("Multiplicacao: ");
    exibir(produto);

    no derivada = derivar(polinomio1);
    printf("Derivada do Polinomio 1: ");
    exibir(derivada);

    return 0;
}
