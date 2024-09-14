#include <stdio.h>

int main(){
  char p[100];
  int i = 0, count = 0;
  gets(p);

  while(p[i] != '\0'){
    if(p[i] == '0'){
      count++;
    }
    i++;
  }

  puts(p);
  printf("%d", count);
}