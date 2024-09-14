#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
  int i;
  char frase[100];

  gets(frase);

  for(i = 0; i < strlen(frase); i++){
    frase[i] = frase[i] + 1;
  }
  i++;

puts(frase);
}

