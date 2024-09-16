#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

void imprime(int i, int j, int k){

  if(i > j){
    return;
  }

    printf("%d ", i);

  return imprime(i+k, j, k);
}

int main() {

    imprime(1, 9, 2);
    return 0;
}