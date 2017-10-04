#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int remover_espacos(char *frase, int n);
int verificar_palindromo(char *frase, int n);

int main(int argc, char** argv){
    char *palavra;
    int n;

    if (argc >= 2){
        palavra = argv[1];
        n = strlen(palavra);

        printf("A frase \"%s\" tem comprimento %d.\n", palavra, n);
        int i = remover_espacos(palavra, n);
        printf("Frase sem espaços (%d): %s\n", i, palavra);
        printf(verificar_palindromo(palavra, i - 1) ? "É palíndromo.\n" : "Não é palíndromo.\n");
    }

    return (EXIT_SUCCESS);
}

int remover_espacos(char *frase, int n){
    int i = 0, j = 0;
    char temp;
    while(j < n){
        while(frase[j] == ' ')
            j++;
            
        temp = frase[i];
        frase[i] = frase[j];
        frase[j] = temp;
        i++;
        j++;
    }

    return i;
}

int verificar_palindromo(char *frase, int n){
    for(int i = 0; i < n; i++){
        if(frase[i] != frase[n - i])
            return 0;
    }

    return 1;
}