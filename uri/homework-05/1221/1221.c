#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int eh_primo(int n) {
    if (n <= 3) return 1;
    if (n % 2 == 0) return 0;

    int fim = sqrt(n), i;
    for (i = 3; i <= fim; i++) {
        if (n % i == 0) return 0;
    }

    return 1;
}

int main(int argc, char** argv) {
    int n = 0, i, a = 0;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a);
        printf(eh_primo(a) ? "Prime\n" : "Not Prime\n");
    }

    return EXIT_SUCCESS;
}
