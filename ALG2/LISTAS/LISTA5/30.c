#include <stdio.h>
#include <string.h>


void PermutarCaracteres(char *str ,int p1, int p2){
    char temp;

    temp = str[p1];
    str[p1] = str[p2];
    str[p2] = temp;
}


void Permutacao(char *str, int k){

  int i, len;

  len = strlen(str);

  if(k == len){
    printf("%s\n", str);
  } else {
    for(i = k; i < len; i++){
      PermutarCaracteres(str, k, i);
      Permutacao(str, k+1);
      PermutarCaracteres(str, i, k);
    }
  }
}


int main(){
    char str[] = "ANA";
    Permutacao(str, 0);
}