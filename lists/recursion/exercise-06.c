#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long pot2(int k) {
    if (k == 0) return 1;

    return 2 * pot2(k - 1);
}

int main(int argc, char** argv) {
    int k = 0;

    printf("Digite o k: ");
    scanf("%d", &k);

    printf("O valor de 2 ^ %d é: %ld\n", k, pot2(k));

    return EXIT_SUCCESS;
}