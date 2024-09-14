#include <stdio.h>
#include <string.h>
int acha(char frase[], char palavra[]){
  int count = 0;

  char *quebra = strtok(frase, " ");

  while(quebra != NULL){
    if(strcmp(palavra, quebra)){
      count++;
    }
    quebra = strtok(NULL, frase);
  }
  return count;
}

int main() {
    char frase[50];
    char palavra[10];
    printf("Digite sua frase: ");
    gets(frase);
    printf("Digite sua palavra: ");
    gets(palavra);
    
    printf("%d", acha(frase, palavra));

    return 0;
}