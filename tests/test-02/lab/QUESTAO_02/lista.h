#include <stdlib.h>

#ifndef LISTALAB_H
#define LISTALAB_H

typedef struct s_no * p_no;

struct s_no {
  long item;
  p_no prox;
};

void exclui(p_no x);
p_no remove_menores(p_no L, long k);
p_no maximo(p_no L);

#endif  // LISTALAB_H


