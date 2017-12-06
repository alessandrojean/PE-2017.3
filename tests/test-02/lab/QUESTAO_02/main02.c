#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

#define SEED 2017

void verifica02(int n, int max, int limitante) {
  p_no K, L;

  L = K = malloc(n * sizeof(struct s_no));
  
  for (int i = 0; i < n; i ++) {
    L[i].item = rand() % max;
    L[i].prox = L + i + 1;
  }

  L[n - 1].prox = NULL;

  L = remove_menores(L, limitante);
  
  printf("(%d, %d, %d) lista que sobrou:", n, max, limitante);
  
  for (; L != NULL; L = L->prox)
    printf(" %ld", L->item);
  printf("\n");

  free(K);
}

int main() {
  srand(SEED);

  for (int i = 10; i < 1000; i += i / 2)
    for (int j = 0; j < 13; j ++)
      verifica02(i, 2000 + 10 * i, 500 + j * i);

  return 0;
}
  

  
