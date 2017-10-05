#include <stdio.h>

int main(){
    printf("O tipo de 123.4 tem %ld bytes.\n", sizeof(typeof(123.4)));
    return 0;
}