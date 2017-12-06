#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

#define SEED 2017

void verifica01(int n, int max) {
  p_no L = malloc(n * sizeof(struct s_no));
  
  for (int i = 0; i < n; i ++) {
    L[i].item = rand() % max;
    L[i].prox = L + i + 1;
  }

  L[n - 1].prox = NULL;

  printf("max: %ld\n", maximo(L)->item);
  
  free(L);
}

int main() {
  srand(SEED);

  for (int i = 10; i < 1000; i += i / 5)
    verifica01(i, 2000 + 10 * i);

  return 0;
}
  

  
