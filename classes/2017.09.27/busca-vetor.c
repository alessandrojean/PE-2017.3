#include <stdio.h>

int busca_sequencial(int v[], int n, int chave);

int main(){
    int a[10] = {3, 5, 7, 9, 11, 13, 18, 65, 7, 3};

    int i = busca_sequencial(a, 10, 2);

    if(i == -1)
        printf("Não achei.\n");
    else
        printf("Achei na posição: %d\n", i);

    return 0;
}

int busca_sequencial(int v[], int n, int chave){
    for(int i = 0; i < n; i++)
        if(v[i] == chave)
            return i;
            
    return -1;
}