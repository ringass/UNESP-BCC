#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

double F(int n){
  
  if(n == 1){
    return 2.0; 
  }

  return (1+pow(n,2))/ n + F(n-1);

}


int main() {

    printf("%.2f", F(1));

    return 0;
}