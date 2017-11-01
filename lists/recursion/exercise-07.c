#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long enum_pot2(int k) {
    if (k == 0) return 1;

    long n = 2 * enum_pot2(k - 1);
    printf("%ld ", n);

    return n;
}

int main(int argc, char** argv) {
    int k = 0;

    printf("Digite o k: ");
    scanf("%d", &k);

    printf("Potências de 2 até 2 ^ %d:\n", k);
    enum_pot2(k);
    printf("\n");

    return EXIT_SUCCESS;
}