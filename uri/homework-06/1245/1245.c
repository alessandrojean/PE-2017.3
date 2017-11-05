#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    int n;
    while (scanf("%d", &n) != EOF) {
        int d[31], e[31], i;
        for (i = 0; i < 31; i++) {
            d[i] = 0;
            e[i] = 0;
        }

        for (i = 0; i < n; i++) {
            int t;
            char p;
            scanf("%d %c", &t, &p);

            if (p == 'D') d[t - 30]++;
            else e[t - 30]++;
        }

        /*int c = 0, j = 0;
        while()*/

        /*for (int i = 0; i < 31; i++) {
            printf("e[%d] = %d, d[%d] = %d\n", i + 30, e[i], i + 30, d[i]);
        }
        printf("\n");*/

        int c = 0;
        for (i = 0; i < 31; i++) {
            if (d[i] == 0 && e[i] == 0) continue;

            while (d[i] > 0 && e[i] > 0) {
                c++;
                d[i]--;
                e[i]--;
            }
        }

        printf("%d\n", c);
    }    

    return EXIT_SUCCESS;
}