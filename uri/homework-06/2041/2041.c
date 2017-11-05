#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void godelito(int n, char g[][100000]) {
    g[0][0] = '3';
    g[0][1] = '\0';
    
    int i;
    for (i = 1; i < n; i++) {
        //printf("%s\n", g[i - 1]);
        int t = strlen(g[i - 1]), j = 0, k = 0, l = 0, e = g[i - 1][0];

        while (j < t) {
            k = 0;
            while (g[i - 1][j] == e) {
                //printf("%d: %c == %c\n", j, g[i - 1][j], e);
                k++;
                j++;
            }

            g[i][l] = k + '0';
            g[i][l + 1] = e;

            e = g[i - 1][j];
            //printf("e: %c\n", e);

            l += 2;
            //j++;
        }

        //printf("j: %d\n", j);

        g[i][l] = '\0';
    }

}

int main(int argc, char** argv) {
    char g[40][100000];
    godelito(40, g);

    int n;
    while (scanf("%d", &n) != EOF) {
        printf("%s\n", g[n - 1]);
    }

    return EXIT_SUCCESS;
}