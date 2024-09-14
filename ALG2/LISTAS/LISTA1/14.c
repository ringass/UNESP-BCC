#include <stdio.h>
#include <string.h>
void acha(char frase[]){

  char *quebra = strtok(frase, " ");
  while(quebra != NULL){
    puts(quebra);
    quebra = strtok(NULL, " ");
  }
}

int main() {
    char frase[50];
    printf("Digite sua frase: ");
    gets(frase);

    acha(frase);

    return 0;
}