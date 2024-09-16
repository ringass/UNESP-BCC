#include <stdio.h>

int F(int num, int inicio, int fim, int *v){
  if(inicio > fim){
    return -1;
  }

  int meio = (inicio+fim)/2;

  if(v[meio] == num){
    return meio;
  }else if(v[meio] > num){
    return F(num, inicio, meio-1, v);
  }else{
    return F(num, meio+1, fim, v);
  }
}

int main(){

int v[] = {1, 2, 3, 5, 7, 7, 8, 9, 10};

printf("%d", F(2, 0, 10, v)+1);

return 0;
}