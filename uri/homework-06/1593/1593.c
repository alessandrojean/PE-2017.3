#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int resto(int n, char *p) {
    int c = 0, resto = 0;

    //printf("%d: %d\n", c, resto);

    while (c < n) {
        //printf("%d: %d\n", c, resto);

        int a = p[c];
        resto = resto * 10 + a;

        //printf("%d / 2 = %d r %d\n", resto, resto / 2, resto % 2);
        
        p[c] = resto / 2;
        resto = resto % 2;
        

        c++;
    }

   // for (int i = 0; i < n; i++) {
   //     printf("%d", p[i]);
   // }
   // printf("\n");

    return resto;
}

int eh_valido(int n, char *p) {
    int i;
    for (i = 0; i < n; i++) {
        if (p[i] > 0) return 0;
    }

    return 1;
}

int contar_soma_bits(int n, char *p) {
    int c = 0;

    while (!eh_valido(n, p)) {
        int r = resto(n, p);
       // printf("%d\n",r);
        if (r == 1) c++;
    }

   // printf("\n");

    return c;
}

int main(int argc, char** argv) {
    int t, i;
    scanf("%d", &t);
    
    for(i = 0; i < t; i++) {
        char p[1050];
        scanf("%s", p);
        int n = strlen(p);

        //printf("lido\n");

        int j;
        for (j = 0; j < n; j++) {
            p[j] = p[j] - '0';
        }

        printf("%d\n", contar_soma_bits(n, p));

        //int r = resto(n, p);
        //printf("%d\n", r);
    }

    return EXIT_SUCCESS;
}