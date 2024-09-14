#include <stdio.h>

int Func (int n){
    if (n == 0)
      return 0;


    return n + Func(n-1);
}

int main() {

    int n = 3, soma = 0;


    for(int i = n; i > 0; i--){
        soma += i;
    }  

    printf("recur: %d // inter: %d\n", Func(n), soma);

    return 0;
}