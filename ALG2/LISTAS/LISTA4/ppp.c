#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define MAX 20

int main() {

    FILE *arq = fopen("p.txt", "r");

    if(arq == NULL){
      printf("erro");
      exit(1);
    }
    
    int x, y;

    fscanf(arq, "%d %d", &x, &y);

    int m[MAX][MAX], count = 0;

    for(int i = 0; i < x; i++){
      for(int j = 0; j < y; j++){
        fscanf(arq, "%d", &m[i][j]);
        count+= m[i][j];
      }
    }

    for(int i = 0; i < x; i++){
      for(int j = 0; j < y; j++){
        printf("%d ", m[i][j]);
      }
      printf("\n");
    }

    printf("soma dos termos: %d", count);

    fclose(arq);

    return 0;
}