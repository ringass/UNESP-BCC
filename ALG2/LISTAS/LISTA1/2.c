#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
  int i;
  char frase[100];

  gets(frase);

  for(i = 0; i < strlen(frase); i++){
    if(frase[i] >= 'a' && frase[i] <= 'z'){
      frase[i] = frase[i] - 32;
    }
  }
  i++;

puts(frase);
}

