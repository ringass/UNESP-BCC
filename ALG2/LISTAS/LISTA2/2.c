#include <stdio.h>

typedef struct {
    int x;
    int y;
} Point;

void insideornot(Point ponto, int v1[], int v2[]) {
    int flag = 1;
    if(ponto.x < v1[0] || ponto.x > v2[0] || ponto.y < v1[1] || ponto.y > v2[1]){
        flag = 0;
    }

    if(flag) {
        printf("dentro\n");
    } else {
        printf("fora\n");
    }
}

int main(int argc, char *argv[]) {
    int v1[2], v2[2];
    Point ok;

    scanf("%d %d", &v1[0], &v1[1]);
    
    scanf("%d %d", &v2[0], &v2[1]);

    scanf("%d %d", &ok.x, &ok.y);
    
    insideornot(ok, v1, v2);
    
    return 0;
}
