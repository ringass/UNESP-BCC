#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int F(int x){
  if(x <= 1){
    return 1;
  }

  return F(x-1) + 3;
}

int main() {

    printf("%d", F(3));
    
    return 0;
}