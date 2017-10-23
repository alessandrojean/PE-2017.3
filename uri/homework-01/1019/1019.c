#include <stdio.h>

int main(){
    int n, h, m, s;
    scanf("%d", &n);

    h = n / (60 * 60);
    n -= h * 60 * 60;
    m = n / 60;
    n -= m * 60;
    s = n;

    printf("%d:%d:%d\n", h, m, s);
    return 0;
}