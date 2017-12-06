#include <stdlib.h>
#include "lista.h"

void exclui(p_no x) {
  /* NÃO MEXER AQUI */
}

p_no remove_menores(p_no L, long k) {
  /* PREENCHA O CORPO DESTA FUNÇÃO PARA
     RESPONDER À QUESTÃO 2 DA PROVA */

     if (L == NULL)
      return NULL;

    p_no ant = L;
    p_no x, y, a;
    // Remove os elementos iniciais.
    for (x = L; x != NULL && x->item < k; x = y) {
      y = x->prox;
      exclui(x);
    }

    // Remove os elementos no meio.
    for (y = x; y != NULL; y = ant->prox) {
      if (y->item < k) {
        ant->prox = y->prox;
        exclui(y);

        continue;
      }

      ant = y;
    }


    return x;
}
