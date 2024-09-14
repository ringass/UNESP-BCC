#include <stdio.h>
#include <time.h>
#include <stdlib.h> 
#include <string.h>


int buscabinaria(int p[], int a, int x, int z){
  
  if (x > z) {
      return -1; 
  }

  int meio = (z+x)/2;

  if(p[meio] == a){
    return meio;
  }else if(p[meio] > a){
    return buscabinaria(p, a, x, meio-1);
  }else{
    return buscabinaria(p, a, meio+1, z);
  }
}

int main(){

srand(time(NULL));

int a, p[100];

scanf("%d", &a);

for(int i = 0; i < 100; i++){
  
  if(i == 27){
    p[i] = 18;
  }else{

  p[i] = rand() % 100 + 1;
  }
}

qsort(p, 100, sizeof(int), (int (*)(const void *, const void *))strcmp);


printf("%d\n\n", buscabinaria(p, a, 0, 99));


for(int i = 0; i < 100; i++){
  printf("%d ", p[i]);
}


}