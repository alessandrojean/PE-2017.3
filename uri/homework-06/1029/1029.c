#include <stdio.h>
#include <stdlib.h>


int fibonnaci(int n, int *c) {
    *c = *c + 1;

    if (n == 0 || n == 1) return n;

    return fibonnaci(n - 1, c) + fibonnaci(n - 2, c);
}

int main(int argc, char** argv) {
    int n, i;
    scanf("%d", &n);
    
    for(i = 0; i < n; i++) {
        int t, c = -1;
        scanf("%d", &t);
        int fibt = fibonnaci(t, &c);
        printf("fib(%d) = %d calls = %d\n", t, c, fibt);
    }

    return EXIT_SUCCESS;
}