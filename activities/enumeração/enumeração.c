#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char v[101];
int t, mt = 0;

void imprimir_pontos(int q){
    for(int j = 0; j < q; j++)
        printf(".");
}

void enumerar(int mt){
    if (t - mt < 0){
        imprimir_pontos(t);
        printf("\n");
        return;
    }
    
    for(int i = 0; i < t - mt; i++){        
        imprimir_pontos(i);
        for(int j = i; j < t; j++)
            printf("%c", v[j]);
            
        printf("\n");
    }
    v[t - 1 - mt] = '.';
    enumerar(mt + 1);
}

int main(int argc, char** argv){
    scanf("%100s", v);
    t = strlen(v);

    enumerar(0);

    return EXIT_SUCCESS;
}