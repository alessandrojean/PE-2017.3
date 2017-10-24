#include <stdio.h>
#include <stdlib.h>

void counting_sort(int n, int k, int *v);

int main(int argc, char** argv) {
    int v[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(v) / sizeof(v[0]);

    int k = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] > k) k = v[i];
    }

    counting_sort(n, k, v);

    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }

    return EXIT_SUCCESS;
}

void counting_sort(int n, int k, int *v) {
    int aux[k + 1], ordenado[n];

    printf("Zerando o aux\n");

    for (int i = 0; i < k + 1; i++) {
        aux[i] = 0;
    }

    printf("Contando no aux\n");
    
    for (int i = 0; i < n; i++) {
        aux[v[i]]++;
    }

    printf("Atribuindo o anterior ao i no aux\n");

    for (int i = 1; i < k + 1; i++) {
        aux[i] += aux[i - 1];
        //printf("%d: %d\n", i, aux[i]);
    }

    printf("Preenchendo o ordenado\n");

    /*printf("aux: ");
    for (int i = 0; i < k + 1; i++) {
        printf("%d ", aux[i]);
    }
    printf("\n");*/

    for (int i = 0; i < n; i++) {
        printf("ordenado[%d] = %d\n", aux[v[i] - 1], v[i]);
        ordenado[aux[v[i]] - 1] = v[i];
        aux[v[i]]--;
    }

    printf("Atribuindo o ordenado ao v\n");

    for (int i = 0; i < n; i++) {
        v[i] = ordenado[i];
    }
}
