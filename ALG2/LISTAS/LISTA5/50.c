#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int S(double nA, double nB, double tA, double tB, int qt){

  if(nA > nB){
    return qt; 
  }

  return S(nA * (1 + tA / 100.0), nB * (1 + tB / 100.0), tA, tB, qt+1);
}


int main() {

  printf("%d", S(100.0, 200.0, 10, 0, 0));

  return 0;
}