#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int pal(char *p, int x, int z){

  if(x < z){
    return 1;
  }
  
  while(x>z && !isalpha(p[x])){
    x--;
  }

  while(z < x && !isalpha(p[z])){
    z++;
  }

  if(tolower(p[z]) != tolower(p[x])){
    return 0;
  }

  return pal(p, x-1, z+1);
}

int main() {

    char p[10];

    fgets(p, sizeof(p), stdin);
    
    size_t len = strlen(p) - 1;

    if(p[len] == '\n'){
      p[len] = '\0';
    }

    if(!pal(p, 10, 0)){
      printf("nao eh");
    }else{
      printf("palindromo");
    }

    return 0;
}