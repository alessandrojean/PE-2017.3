#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int p_c = 0;

int fatorial(int n) {
    if (n == 0) return 1;

    return n * fatorial(n - 1);
}

void trocar_elementos(int i, int j, int *v) {
    int t = v[i];
    v[i] = v[j];
    v[j] = t;
}

int verificar(int *v, int t, int ft, int p[][t]) {
    for (int i = 0; i < ft; i++) {
        int c = 0;

        for (int j = 0; j < t; j++) {
            if (p[i][j] == v[j]) c++;

            //printf("%d: %d == %d\n", c, p[i][j], v[j]);
        }

        //printf("\n");

        if (c == t) return 1;
    }

    return 0;
}

void permutar(int n, int t, int *v, int ft, int p[][n]) {
    if (n == t){
        if (!verificar(v, t, ft, p)) {
            for (int i = 0; i < t; i++) {
                printf("%d ", v[i]);
                p[p_c][i] = v[i];
            }
            printf("\n");

            p_c++;

        }

        return;
    }

    for (int i = n; i < t; i++) {
        trocar_elementos(n, i, v);
        permutar(n + 1, t, v, ft, p);
        trocar_elementos(i, n, v);
    }
}

long enum_permut(int n, int *v) {
    int fat = fatorial(n);
    int p[fat][n];

    permutar(0, n, v, fat, p);    
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

    printf("Permutações distintas dos elementos do vetor:\n");
    enum_permut(n, vet);

    return EXIT_SUCCESS;
}