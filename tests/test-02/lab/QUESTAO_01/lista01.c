#include <stdlib.h>
#include "lista.h"

p_no maximo(p_no L) {
  /* PREENCHA O CORPO DESTA FUNÇÃO PARA
     RESPONDER À QUESTÃO 1 DA PROVA */
  if (L == NULL)
    return NULL;
  if (L->prox == NULL)
    return L;

  p_no x = maximo(L->prox);

  if (x->item > L->item)
    return x;
  
  return L;
}