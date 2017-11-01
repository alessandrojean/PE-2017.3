#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void trocar_elementos(int i, int j, int *v) {
    int t = v[i];
    v[i] = v[j];
    v[j] = t;
}

void permutar(int n, int t, int *v) {
    if (n == t){
        for (int i = 0; i < t; i++) {
            printf("%d ", v[i]);
        }
        printf("\n");

        return;
    }

    for (int i = n; i < t; i++) {
        trocar_elementos(n, i, v);
        permutar(n + 1, t, v);
        trocar_elementos(i, n, v);
    }
}

long enum_permut(int n, int *v) {
    permutar(0, n, v);    
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

    printf("Permutação dos elementos do vetor:\n");
    enum_permut(n, vet);

    return EXIT_SUCCESS;
}