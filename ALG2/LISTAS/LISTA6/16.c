#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

//funciona, esse é o codigo de v[0...n];
//iteraçoes infinitas;
//erro no calculo do ponto medio;


int buscabin1(int x, int n, int *v){
  int e, d, m = 0;
  e = 0; d = n;

  while (e <= d) // v[e-1] < x <= v[d]
  {

  m = (e + d)/2;

  if (v[m] < x) e = m+1;

  else d = m;

  } // e == d

  return d;
}


int main() {

    int v[15] = {0};
    
    for(int i = 0; i < 15; i++){
      v[i] = i;
    }

    printf("%d", buscabin1(0, 15, v));


    return 0;
}