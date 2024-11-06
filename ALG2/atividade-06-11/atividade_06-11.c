#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include<windows.h>


typedef struct reg *no;

struct reg{
  struct reg *pLink;
  int RA;
  char nome[32];
  float MP;
  float MT;
  float freq;
};


typedef struct{
  no prim, ult;
  int qt;
}descritor;

void incluir(descritor *lista, int RA, char *str, float mp, float mt, float freq){
  no p = (no)malloc(sizeof(struct reg));

  p->RA = RA;
  strcpy(p->nome, str);
  p->MP = mp;
  p->MT = mt;
  p->freq = freq;

  if(lista->prim == NULL){
    lista->prim = p;
    lista->ult = p;
    p->pLink = NULL; 
    lista->qt++;
    return;
  }

  if(lista->prim->RA >= RA){
    p->pLink = lista->prim;
    lista->prim = p;
  }else{
    no q = lista->prim;
    no r = NULL;

    while(q != NULL && q->RA < RA){
      r = q;
      q = q->pLink;
    }

    p->pLink = q;

    if(r != NULL){
      r->pLink = p;
    }

    if(q == NULL){
      lista->ult = p;
    }
  }

  lista->qt++;
}


int remover(descritor *lista, int num){

  
  if(lista->prim == NULL){
    return 0;
  }else if(num == lista->prim->RA){

    no q = lista->prim;

    lista->prim = lista->prim->pLink;

    free(q);

    return 1;

  }else{

    
    no q = lista->prim;
    no r = NULL;

    while(q->pLink != NULL && q->RA < num){

       r = q;
       q = q->pLink;

    }

    if(q->pLink == NULL || q->RA != num){
      return 0;
    }

    r->pLink = q->pLink;
    free(q);
    return 1;
  }
}

void alterar(descritor *lista, int RA) {
    no p = lista->prim;
    
    
    while (p != NULL && p->RA != RA) {
        p = p->pLink;
    }

    
    if (p == NULL) {
        printf("Aluno com RA %d nao encontrado.\n", RA);
        return;
    }

    
    printf("Aluno encontrado: RA: %d | Nome: %s | MP: %.2f | MT: %.2f | Frequencia: %.2f\n",
           p->RA, p->nome, p->MP, p->MT, p->freq);

    
    char nome[32];
    float MP, MT, freq;

    
    printf("Digite o novo nome (maximo 31 caracteres): ");
    getchar();  
    gets(nome);

    printf("Digite o novo MP: ");
    scanf("%f", &MP);

    printf("Digite o novo MT: ");
    scanf("%f", &MT);

    printf("Digite a nova frequencia: ");
    scanf("%f", &freq);

    strcpy(p->nome, nome);
    p->MP = MP;
    p->MT = MT;
    p->freq = freq;

    printf("Dados atualizados com sucesso!\n");
}


void consultar_aprovados(descritor lista){
  if(lista.prim == NULL){
    printf("nao ha alunos na lista");
    return;
  }

  no p = lista.prim;

  printf("ALUNOS APROVADOS\n");
  while(p != NULL){
    float media = ((p->MP + p->MT)/2.0);
    if(media >= 5.0){
    printf("RA: %d | NOME: %s | MP: %f | MT: %f | FREQ: %f\n", p->RA, p->nome, p->MP, p->MT, p->freq);
    }
    p = p->pLink;
  }
}

void consultar_todos(descritor lista){

  if(lista.prim == NULL){
    printf("nao ha alunos na lista");
    return;
  }

  no p = lista.prim;

  printf("ALUNOS APROVADOS\n");
  while(p != NULL){
    printf("RA: %d | NOME: %s | MP: %f | MT: %f | FREQ: %f\n", p->RA, p->nome, p->MP, p->MT, p->freq);
    p = p->pLink;
  }

}

void pegar_info_arquivo(descritor *lista, FILE *file){

  int RA;
  char nome[32];
  float MP, MT, freq;

  while(fscanf(file, "%d %s %f %f %f", &RA, nome, &MP, &MT, &freq) == 5){
    incluir(&(*lista), RA, nome, MP, MT, freq);
  }

}

void incluir_no_arquivo(descritor *lista, FILE *file){
  
  no p = lista->prim;

  while(p != NULL){
    fprintf(file, "%d %s %f %f %f\n", p->RA, p->nome, p->MP, p->MT, p->freq);

    p = p->pLink;
  }

}

void criaLista(descritor *lista){

  lista->prim = NULL;
  lista->ult = NULL;
  lista->qt = 0;

}


int main(){

  FILE *file = fopen("alunos.txt", "r");

  descritor lista;

  criaLista(&lista);

  pegar_info_arquivo(&lista, file);

  fclose(file);

  int escolha = 1;


  while(escolha != 0){

    printf("\nMENU\n");
    printf("[1] - Adicionar\n");
    printf("[2] - Remover\n");
    printf("[3] - Alterar\n");
    printf("[4] - Consultar aprovados\n");
    printf("[5] - Consultar todos\n");
    printf("[0] - sair\n");

    printf("Digite: ");
    scanf("%d", &escolha);


    switch(escolha){

      case 1:{
        int RA;
        char nome[32];
        float MP, MT, freq;

        printf("RA: ");
        scanf("%d", &RA);
        getchar();

        printf("Nome: ");
        gets(nome);

        printf("MP: ");
        scanf("%f", &MP);
        
        printf("MT: ");
        scanf("%f", &MT);

        
        printf("frequencia: ");
        scanf("%f", &freq);

        incluir(&lista, RA, nome, MP, MT, freq);
        break;
      };

      case 2:{
        int RA;

        printf("Digite o RA do aluno que deseja remover: ");
        scanf("%d", &RA);

        int x = remover(&lista, RA);

        if(x){
          printf("\nRemovido com sucesso\n");
        }else{
          printf("\nerro\n");
        }

        break;
      } 

      case 3:{
        int RA;

        printf("Digite o RA do aluno que deseja alterar: ");
        scanf("%d", &RA);

        alterar(&lista, RA);
        break;
      }
      case 4:{
        system("cls");
        consultar_aprovados(lista);
        Sleep(2000);
        break;
      }
      case 5:{
        system("cls");
        consultar_todos(lista);
        Sleep(2000);
        break;
      }
      case 0:{
        system("cls");
        printf("obrigado por utilizar o programa");
        break;
      }
    }

  }

  
  file = fopen("alunos.txt", "w");

  incluir_no_arquivo(&lista, file);

  fclose(file);

  return 0;
}