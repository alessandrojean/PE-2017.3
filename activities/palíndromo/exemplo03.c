/* Neste exemplo a leitura da frase é feita da entrada padrão. */

#include <stdio.h>
#include <string.h>

int main() {
  char *frase = NULL;
  size_t espaco = 0;
  int n = getline(&frase, &espaco, stdin);

  if (frase[n - 1] == '\n') { 
    frase[n - 1] = '\0';
    n --;
  }
   
  printf("A frase \"%s\" tem comprimento %d.\n", frase, n);

  /* seu código vem aqui */
  
  return 0;
}

