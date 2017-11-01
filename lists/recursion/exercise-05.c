#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int reverter(int n, char *p){
    if (n <= 1) return 1;

    char t = p[0];
    p[0] = p[n - 1];
    p[n - 1] = t;

    return reverter(n - 2, p + 1);
}

int main(int argc, char** argv){
    char palavra[20];

    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    reverter(strlen(palavra), palavra);
    printf("A palavra revertida é: %s\n", palavra);

    return EXIT_SUCCESS;
}