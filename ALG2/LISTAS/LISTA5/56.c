#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

// o resultado da funcao f(1,10) é 5.5

double f (double x, double y) {
  if (x >= y)

    return (x + y)/2;

  else return f (f (x+2, y-1), f (x+1, y-2));
}


int main() {

    printf("%f ", f(1,10));

    return 0;
}