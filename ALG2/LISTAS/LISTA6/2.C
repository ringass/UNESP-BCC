#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>


// é uma função que busca encontrar a posição do vetor que seja maior ou igual a X;

int busca (int x, int n, int v[]) {
  int j = 0;

  while (v[j] < x && j < n) ++j;
  
  return j;
}


int main() {
    
    int x[10] = {10, 9, 10, 8, 7, 5, 4, 2, 1, 2};

    printf("%d", busca(11, 10, x));


    return 0;
}