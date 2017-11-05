#include <stdio.h>
#include <stdlib.h>

int busca_binaria(int x, int n, int *v) {
    int i = 0, m, f = n - 1;

    while (i <= f) {
        m = (i + f) / 2;

        if (v[m] == x) return m;
        if (v[m] < x) i = m + 1;
        else f = m - 1;
    }

    return -1;
}

int main(int argc, char** argv) {
    int n = 0, i;

    while (scanf("%d", &n) != EOF) {
        int v[n];

        scanf("%d", &v[0]);

        for (i = 1; i < n; i++){
            scanf("%d", &v[i]);

            v[i] += v[i - 1];
        }

        int triangulos = 0;
        int intervalo = v[n - 1] / 3;

        for (i = 0; v[i] + 2 * intervalo <= v[n - 1]; i++) {
            int j = 0, k = 0;

            //while (v[j] < v[i] + intervalo) j++;
            //while (v[k] < v[i] + 2 * intervalo) k++;

            //if (v[j] == v[i] + intervalo && v[k] == v[i] + 2 * intervalo) {
            //    triangulos++;
            //}

            int a = busca_binaria(v[i] + intervalo, n, v);
            int b = busca_binaria(v[i] + 2 * intervalo, n, v);

            if (a != -1 && b != -1) triangulos++;
        }

        printf("%d\n", triangulos);
    }

    return EXIT_SUCCESS;
}
