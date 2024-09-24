#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>


/*
x= 0 -> 0
x = 5 -> 5
x = 10 -> 10
x = 15 -> 15 
*/

int buscabinaria2 (int x, int n, int v[]) {
  int e, m, d;

  e = -1; d = n;
  
  while (e < d-1) {
    m = (e + d)/2;

    if (v[m] < x) e = m;
      
    else d = m;
  }
    return d;
}


int main() {

    int v[15] = {0};
    
    for(int i = 0; i < 15; i++){
      v[i] = i;
    }

    printf("%d", buscabinaria2(15, 15, v));

    return 0;
}