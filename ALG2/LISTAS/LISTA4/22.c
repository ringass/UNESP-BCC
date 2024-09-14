#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 50

typedef struct{
  char nome[50];
  int idade;
  float altura;
  char telefone[10];
}ss;



void preencherStruct(int n, ss *pessoas){
  
  for(int i = 0; i < n; i++){
    printf("Digite as informacoes das pessoas que deseja cadastrar:\n");

    printf("NOME: ");
    fgets(pessoas->nome, sizeof(pessoas[i].nome), stdin);
    pessoas[i].nome[strcspn(pessoas[i].nome, "\n")] = 0;

    printf("Idade: ");
    scanf("%d", &pessoas[i].idade);

    printf("Altura: ");
    scanf("%f", &pessoas[i].altura);

    getchar();

    printf("Telefone: ");
    fgets(pessoas[i].telefone, sizeof(pessoas->telefone), stdin);
    pessoas[i].telefone[strcspn(pessoas[i].telefone, "\n")] = 0;

    getchar();
  }
}

int main(){
  
  int n;
  scanf("%d", &n);

  FILE *arqbin = fopen("binary.bin", "wb");

  if(arqbin == NULL){
    printf("falha ao abrir o arquivo");
    return 1;
  }

  ss blabla[MAX];

  getchar();

  preencherStruct(n, blabla);

  for(int i = 0; i < n; i++){
    fwrite(&blabla[i], sizeof(ss), 1, arqbin);
  }

  fclose(arqbin);

  arqbin = fopen("binary.bin", "rb");
  FILE *arqtxt = fopen("texto.txt", "w");

  if(arqbin == NULL){
    printf("falha ao abrir o arquivo");
    return 1;
  }
  
  if(arqtxt == NULL){
    printf("falha ao abrir o arquivo");
    return 1;
  }

  for(int i = 0; i < n; i++){
    fprintf(arqtxt, "------------------------\n");
    fprintf(arqtxt,"%s tem %d anos e %.2f de altura.\nTel.: %s\n", blabla[i].nome, blabla[i].idade, blabla[i].altura, blabla[i].telefone);
  }

fclose(arqbin);
fclose(arqtxt);

printf("aaaaa");
return 0;
}