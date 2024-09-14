#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
  char p[100], L1, L2;
  int i = 0, count = 0;
  gets(p);
  scanf("%c %c", &L1, &L2);

  while(p[i] != '\0'){
    if(p[i] == L1){
      p[i] = L2;
    }
    i++;
  }

  puts(p);
  
}