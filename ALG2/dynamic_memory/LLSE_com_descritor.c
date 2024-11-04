#include <stdio.h>
#include <stdlib.h>

typedef struct reg *no;

struct reg{
    int info;
    struct reg *prox; 
};

typedef struct{
    no prim, ult;
    int qt;
}descritor;

//acessar primeiro nó: lista.prim
//acessar ultimo nó: lista.ult;

void criaLista(descritor *lista){

    lista->prim = lista->ult = NULL;
    lista->qt = 0;
}

void insere(descritor *lista, int info){

    no p = (no)malloc(sizeof(struct reg));

    p->info = info;
    p->prox = NULL;

    if(lista->prim == NULL){
        lista->prim = p;

        lista->ult = p;

        lista->qt++;
    
    }else{
        p->prox = lista->prim;
        lista->prim = p;
        lista->qt++;
    }

}

void insere_final(descritor *lista, int info){

    no p = (no)malloc(sizeof(struct reg));

    p->info = info;
    p->prox = NULL;

    if(lista->prim == NULL && lista->ult ==NULL){

        lista->prim = p;
        lista->ult = p;
        lista->qt++;
        
    }else{

        lista->ult->prox = p;
        
        lista->ult = p;

        lista->qt++;
    }

}

void insere_ordenado(descritor *lista, int info) {
    no p = (no)malloc(sizeof(struct reg));

    p->info = info;
    p->prox = NULL;

    if (lista->prim == NULL) {
        lista->prim = p;
        lista->ult = p;
        lista->qt++;
        return;
    }

    if (lista->prim->info >= info) {
        p->prox = lista->prim;
        lista->prim = p;
    } else {
        no q = lista->prim;
        no r = NULL;

        while (q != NULL && q->info < info) {
            r = q;
            q = q->prox;
        }

        p->prox = q;
        if (r != NULL) {
            r->prox = p;
        }

        if (q == NULL) {  
            lista->ult = p;
        }
    }

    lista->qt++;
}

void excluir_final(descritor *lista){

    no q = lista->ult;
    if(lista->ult != NULL){
        no p = lista->prim;

        while(p->prox != lista->ult){
            p = p->prox;
        }

        p->prox = NULL;
        lista->ult = p;

    }else if(lista->ult == lista->prim){
        lista->prim = NULL;
        lista->ult = NULL;  
    }

    free(q);
    lista->qt--;

}

void excluir_inicio(descritor *lista){
    no q = lista->prim;

    if(lista->prim == NULL){
        return;
    }

    if(lista->prim == lista->ult){

        lista->prim = NULL;
        lista->ult = NULL;
    
    }else{
        no p = lista->prim->prox;

        lista->prim = p;
    }

    free(q);

    lista->qt--;
}

void mostraLista(descritor lista){

    if(lista.prim == NULL){
        printf("erro");
        return;
    }

    no p = lista.prim;

    while(p != NULL){
        printf("%d ", p->info);
        p = p->prox;
    }
}

int main(){
    descritor lista;

    criaLista(&lista);

    insere(&lista, 10);
    insere(&lista, 15);
    insere(&lista, 5);
    insere_final(&lista, 100);
    insere_final(&lista, 7);
    insere_ordenado(&lista, 8);
    insere_ordenado(&lista, 4);

    mostraLista(lista);

    excluir_final(&lista);
    excluir_inicio(&lista);

    printf("\n");

    mostraLista(lista);

    printf("\n\nquantidade de elementos: %d", lista.qt);

}