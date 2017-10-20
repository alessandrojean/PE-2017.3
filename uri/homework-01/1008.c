#include <stdio.h>

int main(){
    int n, h;
    double vh;
    scanf("%d %d %lf", &n, &h, &vh);
    printf("NUMBER = %d\nSALARY = U$ %.2lf\n", n, vh * h);

    return 0;
}