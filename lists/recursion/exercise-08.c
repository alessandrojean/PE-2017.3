#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char g_digito[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

long imprimir_em_base(int n, int b) {
    if (n == 0) return 0;

    imprimir_em_base(n / b, b);
    printf("%c", g_digito[n % b]);
}

int main(int argc, char** argv) {
    int n = 0, b = 0;
    printf("Digite o número e a base: ");
    scanf("%d %d", &n, &b);

    imprimir_em_base(n, b);
    printf("\n");

    return EXIT_SUCCESS;
}