#include <stdio.h>
#include <stdlib.h>

void remover_elemento(int *n, int x, int *v);

int main(int argc, char** argv) {
    int v[] = {1, 2, 3, 2, 4, 2, 5, 2, 6, 2};
    int n = sizeof(v) / sizeof(v[0]);
    
    remover_elemento(&n, 2, v);
    
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    
    printf("\n");

    return EXIT_SUCCESS;
}

void remover_elemento(int *n, int x, int *v) {
    int i = 0, j = 0, temp;
    
    while (j < *n) {
        while (v[j] == x) j++;
        
        temp = v[i];
        v[i] = v[j];
        v[j] = temp;
        
        i++;
        j++;
    }
    
    *n = i - 1;
}
