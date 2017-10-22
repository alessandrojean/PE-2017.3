#include <stdio.h>
#include <stdlib.h>

int a, b, n, M[200][200];

void imprime_caminho(int i, int j);

int main(int argc, char** argv){
    scanf("%d %d %d", &n, &a, &b);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &M[i][j]);

    if(a == b){
        printf("%d\n", a);
        return EXIT_SUCCESS;
    }
    if(M[a][b] == n){
        printf("impossivel\n");
        return EXIT_SUCCESS;
    }
    
    imprime_caminho(a, b);

    return EXIT_SUCCESS;
}

void imprime_caminho(int i, int j){
    if(M[i][j] == -1){
        if(j == b)
            printf("%d %d\n", i, j);
        else
            printf("%d ", i);
        return;
    }

    int k = M[i][j];
    imprime_caminho(i, k);
    imprime_caminho(k, j);
}