#include <stdio.h>

int main(){
    int a, b, c, d, f;
    scanf("%d %d %d %d", &a, &b, &c, &d);

    f = b > c && d > a && c + d > a + b && c > 0 && d > 0 && a % 2 == 0;

    printf(f ? "Valores aceitos\n" : "Valores nao aceitos\n");

    return 0;
}