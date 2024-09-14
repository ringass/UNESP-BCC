#include <stdio.h>

int combinatoria(int n, int k){
  if(k == n || k == 0){
    return 1;
  }else{
     return combinatoria(n - 1, k - 1) + combinatoria(n - 1, k);
  }
}


int main() {
    int n, k;

    scanf("%d %d", &n, &k);  

    if(n < k){
      return 1;
    }

    printf("%d",combinatoria(n, k));

    return 0;
}