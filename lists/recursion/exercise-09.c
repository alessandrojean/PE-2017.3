#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long soma_digitos(int n) {
    if (n < 10) return n;

    return n % 10 + soma_digitos(n / 10);
}

int main(int argc, char** argv) {
    int n = 0;
    
    printf("Digite um inteiro positivo: ");
    scanf("%d", &n);

    printf("A soma dos dígitos de %d é: %ld\n", n, soma_digitos(n));

    return EXIT_SUCCESS;
}