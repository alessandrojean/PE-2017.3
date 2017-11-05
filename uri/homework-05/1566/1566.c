#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubble_sort(int n, int h[n]);

int main(int argc, char** argv){
    int nc, n;
    scanf("%d", &nc);

    for(int i = 0; i < nc; i++){
        scanf("%d", &n);

        int h[n];

        for(int j = 0; j < n; j++)
            scanf("%d", &h[j]);

        bubble_sort(n, h);

        for(int j = 0; j < n; j++)
            printf("%d ", h[j]);
        printf("\n");
    }


    return EXIT_SUCCESS;
}

void bubble_sort(int n, int h[n]){
    int t;

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(h[i] > h[j]){
                t = h[i];
                h[i] = h[j];
                h[j] = t;
            }
        }
    }
}