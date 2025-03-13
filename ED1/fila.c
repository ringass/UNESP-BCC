#include <stdio.h>
#include <stdlib.h>
typedef struct reg *no;

struct reg{
    int info;
    struct reg *link;
};

typedef struct{
    no ini;
    no fim;
}queue;

void cria(queue *fila){
    fila->ini = NULL;
    fila->fim = NULL;
}

void Enqueue(queue *fila, int p){
    no q;

    q = (no)malloc(sizeof(struct reg));

    q->info = p;
    q->link = NULL;

    if(fila->ini == NULL){
        fila->ini = q;
    }else{
        fila->fim->link = q;
    }
    
    fila->fim = p;
}

void Dequeue


int main(){

    queue fila;
    cria(&fila);





    
    int x;


}