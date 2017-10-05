#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int remover_espacos(char *frase, int n);
int verificar_palindromo(char *frase, int n);

int main(int argc, char** argv){

    char *frase = NULL;
    int n = 0;
    size_t comp;

    n = getline(&frase, &comp, stdin) - 1;
    frase[n] = '\0';

    printf("A frase \"%s\" tem comprimento %d.\n", frase, n);

    free(frase);
    return 0;
}