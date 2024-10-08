#include <stdio.h>


int F (int i){
if (i > 1)
return i + F(i-1);
return 1;
}


int main() {

    int n = 5, s = 0;

    for(int i = 0; i <= n; i++){
      s+= i;
    }  

    printf("%d\n",F(5));
    printf("%d", s);  


    return 0;
}