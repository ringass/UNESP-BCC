#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

//nao funciona, pois já que estamos indo até n-1 deveriamos considerar o e+1 para inicializar no 0;
//alem disso d = m -1, esta correto esta nos enviando a posicao errada do vetor;
//return d+1 está equivocado tambem



int buscabin2(int x, int n, int *v){
  int e, d, m = 0;
e = -1; d = n - 1;
while (e < d)
{
m = (e + d)/2;
if (v[m] < x) e = m;
else d = m-1;
}
return d+1;
}

int main() {

    int v[15] = {0};
    
    for(int i = 0; i < 15; i++){
      v[i] = i;
    }

    
    printf("%d", buscabin2(5, 15, v));


    return 0;
}