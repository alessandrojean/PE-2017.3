/* Neste exemplo a leitura da frase é feita da linha de comando. */

#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
    char *frase;
    int n;
    
    if (argc >= 2) {
        frase = argv[1];
        n = strlen(frase);
    
        printf("A frase \"%s\" tem comprimento %d.\n", frase, n);

	/* seu código vem aqui */
    }

    return 0;
}

