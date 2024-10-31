#include <stdio.h>
#include <stdlib.h>


typedef struct reg *no;

struct reg {
    int info;
    struct reg *pLink;
};



void incluir_i(no *lista, int n){

no p = (no)malloc(sizeof(struct reg));
p->info = n;


if(*lista == NULL){

  p->pLink = p;
  *lista = p;

}else{

  no q = *lista;

  while(q->pLink != *lista){
    q = q->pLink;
  }

  q->pLink = p;
  p->pLink = *lista;
  *lista = p;

}
}

void mostrar(no lista){

  if(lista == NULL){
    printf("\nNula");
    return;
  }

  no q = lista;

  do{

    printf("%d ", q->info);
    q = q->pLink;

  }while(q != lista);

}

int excluir_p(no *lista){

  no p, q;

  if(*lista == NULL){
    printf("\nERRO");
    return  0;
  }
  
  if((*lista)->pLink == *lista){
    free(*lista);
    *lista = NULL;
  }
  else {
    q = *lista;
    p = *lista;

    while(q->pLink != *lista){
      q = q->pLink;
    }
    

    *lista = (*lista)->pLink;
    free(p);
    q->pLink = *lista;

  }


}

void incluir_ord(no *lista, int n){

  no p = (no)malloc(sizeof(struct reg));

  p->info = n;

  if(*lista == NULL){

    p->pLink = p;
    *lista = p;
    
  }else{

  if(n <= (*lista)->info){
      no q = *lista;

      while(q->pLink != *lista){
      q = q->pLink;
    }

  q->pLink = p;
  p->pLink = *lista;
  *lista = p;
  
  }else{

  no q = *lista, r;

  while(q->pLink != *lista && q->info < n){
    r = q;
    q = q->pLink;
  }

  p->pLink = q;
  r->pLink = p;

  }
  }

}

void incluir_f(no *lista, int n){
  no p = (no)malloc(sizeof(struct reg));

  p->info = n;

  if(*lista == NULL){
    p->pLink = p;
    *lista = p;
  }else{

  no q = *lista;

  while(q->pLink != *lista){
    q = q->pLink;
  }

  q->pLink = p;
  p->pLink = *lista;
  }

}

int main(){

no lista = NULL;


int x, p;

scanf("%d", &x);

while(x){

printf("Digite o numero que deseja inserir no inicio: ");
scanf("%d", &p);

incluir_ord(&lista, p);


printf("Continua? ");
scanf("%d", &x);

};

scanf("%d", &p);
incluir_ord(&lista, p);

system("cls");
mostrar(lista);

excluir_p(&lista);
printf("\n");
mostrar(lista);

}