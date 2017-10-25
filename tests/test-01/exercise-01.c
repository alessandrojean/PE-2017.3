#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    int n;
    scanf("%d", &n);
    int v[n], min = 1000, max = 0, med = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        med += &v[i];
        if (v[i] > max) max = v[i];
        if (v[i] < min) min = v[i];
    }
    med = med / n;
    printf("min = %d, max = %d, med = %d\n", min, max, med);

    int c = 0, medm = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] < med) {
            medm += v[i];
            c++;
        }
    }
    printf("média dos valores menores que a média: %d\n", medm / c);

    return EXIT_SUCCESS;
}