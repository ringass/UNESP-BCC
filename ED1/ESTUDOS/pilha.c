#include <stdio.h>
#include <stdlib.h>

typedef struct reg *No;

struct reg {
    int info;        
    struct reg *pLink; 
};


typedef struct {
    No topo;   
} Pilha;


void inicializaPilha(Pilha *p) {
    p->topo = NULL;
}


void push(Pilha *p, int valor) {
    No novo = (No)malloc(sizeof(struct reg));
    novo->info = valor;
    novo->pLink = p->topo; 
    p->topo = novo;        
}

int pop(Pilha *p) {
    if (p->topo == NULL) {
        printf("Pilha vazia!\n");
        return -1; 
    }
    No temp = p->topo;
    int valor = temp->info;
    p->topo = temp->pLink; 
    free(temp);            
    return valor;
}


int top(Pilha *p) {
    if (p->topo == NULL) {
        printf("Pilha vazia!\n");
        return -1;
    }
    return p->topo->info;
}



int main()
{
    Pilha p;
    inicializaPilha(&p);

    push(&p, 10);
    push(&p, 20);
    push(&p, 30);

    printf("Topo: %d\n", top(&p)); 
    printf("Pop: %d\n", pop(&p));  
    printf("Topo: %d\n", top(&p)); 
}