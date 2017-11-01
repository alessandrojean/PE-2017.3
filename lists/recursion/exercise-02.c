#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int soma(int n, int *v){
    if (n == 0) return 0;
    
    return v[n - 1] + soma(n - 1, v);
}

int main(int argc, char** argv){
    int n = 0;
    
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    int vet[n];
    printf("Digite os elementos do vetor:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &vet[i]);
    }

    printf("A soma dos elementos do vetor é: %d\n", soma(n, vet));

    return EXIT_SUCCESS;
}