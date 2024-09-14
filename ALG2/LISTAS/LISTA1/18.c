#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
  int i;
  char frase[100];

  gets(frase);
  strupr(frase);
  for(i = 0; i < strlen(frase); i++){
    if(isalpha(frase[i])){
    frase[i] = frase[i] + 3;
    if(frase[i] == 'Z'){
      frase[i] = 'A';
    }
    }
  }
  i++;

puts(frase);
}

