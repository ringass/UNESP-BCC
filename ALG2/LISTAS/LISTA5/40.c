#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int soma(int x, int z){

  if(z == 0){
    return x;
  }

  return soma(x+1, z-1);

}


int main() {


    printf("%d", soma(4, 3));
    
    return 0;
}