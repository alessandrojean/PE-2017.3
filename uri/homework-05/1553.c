#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int contar_perguntas(int n, int p[n], int k);

int main(int argc, char** argv){
    int n = 1, k = 1;

    while(1){
        scanf("%d %d", &n, &k);
        if(n == 0 && k == 0) break;

        int p[n];

        for(int i = 0; i < n; i++)
            scanf("%d", &p[i]);

        printf("%d\n", contar_perguntas(n, p, k));
    }

    return EXIT_SUCCESS;
}

int contar_perguntas(int n, int p[n], int k){
    int c = 0, ac[100] = {0};

    for(int i = 0; i < n; i++)
        ac[p[i] - 1]++;

    for(int i = 0; i < 100; i++)
        if(ac[i] >= k)
            c++;

    return c;
}
