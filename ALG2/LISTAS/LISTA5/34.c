#include <math.h>
#include <stdio.h>

#define max 4
             
void mostraMatriz (int n, float m[][max]) {
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++)
      printf ("%5.2f ",m[i][j]);
    printf ("\n");
  }    
  printf("\n");
}  
              
void montaMatriz (int n, int i, float m[][max], float a[][max]){
  int j, k, cont;
  for (j = 1; j < n; j++){
    cont = 0;
    for (k = 0; k < n; k++)
      if (k != i){
        a[j-1][cont] = m[j][k];
        cont++;
      }
  }
}
              
float det (int n, float m[][max]){ 
  int i;
  float mat[max][max], s = 0, sinal = 1;
  if (n == 1)
    return m[0][0];
  for (i = 0; i < n; i++){
    if (m[0][i] != 0) {
      montaMatriz (n,i,m,mat);
      s += sinal*m[0][i]*det(n-1,mat); 
    }
    sinal = -sinal;
  }
  return s;
}


int main (){
  float m[max][max] = {-2, 3, 1, 7, 0, -1, 2, 1, 3, -4, 5, 1, 1, 0, -2, -1};
  mostraMatriz (max,m);
  printf ("\n%f",det(max,m));
}