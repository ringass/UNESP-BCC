#include <stdio.h>

typedef struct {
  float p1, p2;
  char nome[50];
}dados;

int main() {
    
    int qt;
    
    FILE *arq = fopen("alunos.txt", "r");

    fscanf(arq, "%d", &qt);

    dados *alunos = (dados *)malloc(qt * sizeof(dados));

    for(int i = 0; i < qt; i++){
      
      if(fgets(alunos[i].nome, 50, arq) == NULL){
        fclose(arq);
        free(alunos);
        return 1;
      }
      
      if(fscanf(arq, "%f %f", alunos[i].p1, alunos[i].p2) != 2){
        fclose(arq);
        free(alunos);
        return 1;
      }
      

      fgetc(arq);
    }

    fclose(arq);

    
    for(int i = 0; i < qt; i++){

      float media = (alunos[i].p1 + alunos[i].p2)/2;
      if(media >= 5){
        printf("%s\n", alunos[i].nome);
      }
    }

    free(alunos);

    return 0;
}