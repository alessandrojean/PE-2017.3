#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int soma(int n) {
    if(n == 0) return 0;

    return n + soma(n - 1);
}

int main(int argc, char** argv) {
    int n = 0;

    printf("Digite o n: ");
    scanf("%d", &n);

    printf("A soma dos primeiros %d inteiros positivos é: %d\n", n, soma(n));

    return EXIT_SUCCESS;
}