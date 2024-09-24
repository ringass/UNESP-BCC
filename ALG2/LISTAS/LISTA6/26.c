//FAZENDO O EXERCICIO 24 UTILIZANDO O BSEARCH DA STDLIB

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>


int comp(const void* a, const void* b) {
   return (*(char*)a - *(char*)b);
}

int main() {

    char str[] = "aaat";

    int n = sizeof(str) / sizeof(str[0]);
    
    char key = 't';

    char* item = (char*)bsearch(&key, str, n, sizeof(char), comp); 

    if(item != NULL){
      printf("No index %ld se encontra a chave %c",  item - str, *item);
    }else{
      printf("nao tem");
    }


    return 0;
}