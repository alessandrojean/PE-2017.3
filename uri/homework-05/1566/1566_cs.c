#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_counting_sort(int n, int hcs[n]);

int main(int argc, char** argv){
    int nc, n, i, j;
    scanf("%d", &nc);

    for(i = 0; i < nc; i++){

        scanf("%d", &n);

        int h[n], hcs[211] = {0};

        for(j = 0; j < n; j++){
            scanf("%d", &h[j]);
            hcs[h[j] - 20]++;
        }

        print_counting_sort(211, hcs);
    }


    return EXIT_SUCCESS;
}

void print_counting_sort(int n, int hcs[n]){

    int i, j, ai, f = 1;

    for (i = 0; i < n; i++){
        ai = i + 20;
        for (j = 0; j < hcs[i]; j++){
            if(!f) printf(" ");
            printf("%d", ai);
            f = 0;
        }
    }
    printf("\n");
}
