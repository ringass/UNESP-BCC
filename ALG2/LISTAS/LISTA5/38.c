#include <stdio.h>

double negpot(double x, int p) {

    if (p == 0) {
        return 1.0;
    }

    if (p < 0) {
        return 1.0 / negpot(x, -p);
    }

    return x * negpot(x, p - 1);
}

int main() {
    printf("6^-2 = %.2f\n", negpot(6, 1));  

    return 0;
}
