#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int n, int *v) {
    if (n == 1) return v[n - 1];

    int a = v[n - 1], b = min(n - 1, v);
    return (a < b) ? a : b;
}

int main(int argc, char** argv) {
    int n = 0;
    
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    int vet[n];
    printf("Digite os elementos do vetor:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &vet[i]);
    }

    printf("O valor do menor elemento do vetor é: %d\n", min(n, vet));

    return EXIT_SUCCESS;
}