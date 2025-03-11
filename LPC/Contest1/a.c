#include <stdio.h>
#include <math.h>

int main () {
	long long int n, a, b, c;
	char p[20];
	FILE *in, *out;
	in = fopen ("stdin.txt", "r");
	out = fopen ("stdout.txt", "w");
	fscanf (in, "%lld", &n);
	b=0;
	c=0;
	while (c < n) {
        c += 5LL << b;  
        b++;
    }
    
    b--;
    c -= 5LL << b;
    
    a = (n - c + (1LL << b) - 1) / (1LL << b);
    
    switch (a) {
        case 1: printf("Sheldon\n"); break;
        case 2: printf("Leonard\n"); break;
        case 3: printf("Penny\n"); break;
        case 4: printf("Rajesh\n"); break;
        case 5: printf("Howard\n"); break;
    }
	fclose (in);
	fclose (out);
}