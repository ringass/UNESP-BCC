#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

double l(int n, int i){
  if(n == 0){
    return 0;
  }

  return ((double)i/n + l(n-1,i+1));  
}

int main() {

    printf("%.2f ", l(2, 1)); 

    return 0;
}