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
    novo->pLink = NULL;
    return novo;
}

void inserir(no *lista, float coef, int exp) {
    no novo = criar_no(coef, exp);

    if (*lista == NULL || (*lista)->exp < exp) {
        novo->pLink = *lista;
        *lista = novo;
    } else {
        no p = *lista;
        while (p->pLink != NULL && p->pLink->exp > exp) {
            p = p->pLink;
        }
        if (p->pLink != NULL && p->pLink->exp == exp) {
            p->pLink->coef += coef;
            free(novo);
        } else {
            novo->pLink = p->pLink;
            p->pLink = novo;
        }
    }
}

void exibir(no lista) {
    while (lista != NULL) {
        printf("%.1fx^%d ", lista->coef, lista->exp);
        if (lista->pLink != NULL && lista->pLink->coef >= 0)
            printf("+ ");
        lista = lista->pLink;
    }
    printf("\n");
}

no somar(no lista1, no lista2) {
    no resultado = NULL;
    while (lista1 != NULL) {
        inserir(&resultado, lista1->coef, lista1->exp);
        lista1 = lista1->pLink;
    }
    while (lista2 != NULL) {
        inserir(&resultado, lista2->coef, lista2->exp);
        lista2 = lista2->pLink;
    }
    return resultado;
}

no multiplicar(no lista1, no lista2) {
    no resultado = NULL;
    for (no p1 = lista1; p1 != NULL; p1 = p1->pLink) {
        for (no p2 = lista2; p2 != NULL; p2 = p2->pLink) {
            float novo_coef = p1->coef * p2->coef;
            int novo_exp = p1->exp + p2->exp;
            inserir(&resultado, novo_coef, novo_exp);
        }
    }
    return resultado;
}

no derivar(no lista) {
    no resultado = NULL;
    for (no p = lista; p != NULL; p = p->pLink) {
        if (p->exp != 0) {
            inserir(&resultado, p->coef * p->exp, p->exp - 1);
        }
    }
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
