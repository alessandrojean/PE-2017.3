#include <stdio.h>

int main(int argc, char** argv) {
    int a;
    char c;
    int *p = &a;
    char d[4];
    int **q = &p;

    printf("&a = %p\n", &a);
    printf("&c = %p\n", &c);
    printf("&p = %p\n", &p);
    printf("&d = %p\n", &d);
    printf("&q = %p\n", &q);

    return 0;
}