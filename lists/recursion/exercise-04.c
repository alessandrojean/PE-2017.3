#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int eh_palindroma(int n, char *p) {
    if (n <= 1) return 1;
    if (p[0] != p[n - 1]) return 0;

    return eh_palindroma(n - 2, p + 1);
}

int main(int argc, char** argv){
    char palavra[20];

    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    int res = eh_palindroma(strlen(palavra), palavra);
    printf((res) ? "É palíndroma.\n" : "Não é palíndroma.\n");

    return EXIT_SUCCESS;
}