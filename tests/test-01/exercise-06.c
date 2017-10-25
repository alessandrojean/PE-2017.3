#include <stdio.h>
#include <stdlib.h>

int ordenado(int n, int *v) {
    if (n <= 1) return 1;

    int a = v[n - 1] > v[n - 2] && ordenado(n - 1, v);

    return a;
}

int main(int argc, char** argv) {
    int v[] = {1, 2, 3, 4, 5};
    int n = sizeof(v) / sizeof(v[0]);

    printf(ordenado(n, v) ? "Ordenado.\n" : "Não ordenado.\n");

    return EXIT_SUCCESS;
}