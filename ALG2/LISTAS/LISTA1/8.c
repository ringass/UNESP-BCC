#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
  char p[100];
  int i = 0, count = 0;
  gets(p);
  strupr(p);
  while(p[i] != '\0'){
    if(p[i] == 'A' || p[i] == 'E'  || p[i] == 'I'  || p[i] == 'O'  || p[i] == 'U' ){
      count++;
    }
    i++;
  }

  puts(p);
  printf("%d", count);
}