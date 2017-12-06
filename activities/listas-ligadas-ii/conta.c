#include <stdio.h>
#include <stdlib.h>

typedef struct s_no * no;

struct s_no {
  int item;
  no  prox;
};

no livres = NULL;
int q1024 = 0, qifs = 0;

void insere_inicio(no *ini, no x) {
  x->prox = *ini;
  *ini = x;
}

void deleta(no x) {
  x->prox = livres;
  livres = x;
  //insere_inicio(&livres, x);
  //free(x);
}

no novo(int item) {
  if (livres != NULL) {
    no x = livres;
    livres = livres->prox;
    x->item = item;
    x->prox = NULL;
    qifs++;
    return x;
  }

  no v = (no) malloc(1024 * sizeof(struct s_no));
  if (v == NULL) {
    fprintf(stderr, "Erro de alocação.\nq1024 = %d, qifs = %d\n", q1024, qifs);
    exit(1);
  }
  
  for (int i = 0; i < 1024; i++) {
    insere_inicio(&livres, v + i);
  }
  q1024++;
  //fprintf(stderr, "Alocando mais 1024.\nqlivres = %d\n", qlivres);

  return novo(item);
}

void imprime(no x) {
  for (; x != NULL; x = x->prox)
    printf("%d", x->item);
  printf("\n");
}

void inverte(no *ini) {
  no x = *ini;
  *ini = NULL;
  
  while (x != NULL) {
    no y = x->prox;
    x->prox = *ini;
    *ini = x;
    x = y;    
  }
}

void limpar(no *inicio) {
  no x = *inicio;
  while (x != NULL) {
    *inicio = x->prox;
    deleta(x);
    //insere_inicio(&livres, x);
    x = *inicio;
  }

  *inicio = NULL;
}

no somar(no *n1, no *n2) {
  //fprintf(stderr, "Executando soma\n");

  no resultado = NULL;
  no x = *n1, y = *n2;

  int vai = 0;

  while (x != NULL || y != NULL || vai != 0) {
    int v = 0;

    if (x == NULL && y == NULL && vai != 0) {
      v = vai;
    }
    else if (x == NULL) {
      v = y->item + vai;
      y = y->prox;
    }
    else if (y == NULL) {
      v = x->item + vai;
      x = x->prox;
    }
    else {
      v = x->item + y->item + vai;
      
      x = x->prox;
      y = y->prox;
    }

    no t = novo(v % 10);
    vai = v / 10;

    insere_inicio(&resultado, t);
  }

  // Remover zeros iniciais
  x = resultado;
  while (x->item == 0) {
    resultado = x->prox;
    deleta(x);
    //insere_inicio(&livres, x);
    x = resultado;
  }

  return resultado;
}

no multiplicar(no *n1, no *n2) {
  //fprintf(stderr, "Executando multiplicação\n");
  no x = *n1, y = *n2;

  if (x == NULL || y == NULL)
    return novo(0);
  if (x->item == 0 && x->prox == NULL)
    return novo(0);
  if (y->item == 0 && y->prox == NULL)
    return novo(0);

  no resultado = NULL, atu = NULL;
  int vai = 0, deslocar = 0;

  while (y != NULL) {
    no r = x;

    if (y->item == 0) {
      deslocar++;
      y = y->prox;
      vai = 0;
      continue;
    }

    for (int i = 0; i < deslocar; i++)
      insere_inicio(&atu, novo(0));

    while (r != NULL) {
      int v = r->item * y->item + vai;
      no t = novo(v % 10);
      vai = v / 10;

      insere_inicio(&atu, t);

      if (r->prox == NULL && vai != 0)
        insere_inicio(&atu, novo(vai));

      r = r->prox;
    }

    deslocar++;
    vai = 0;
    y = y->prox;

    inverte(&atu);
    inverte(&resultado);

    no stemp = somar(&atu, &resultado);
    limpar(&resultado);
    limpar(&atu);

    resultado = stemp;
  } 

  return resultado;
}

int main(int argc, char **argv) {
    char n;
    no n1 = NULL, n2 = NULL, r = NULL;
    int op = 0;

    while (scanf("%c", &n) != EOF) {
        if (n == '+' || n == '*') {
            op = n;
            continue;
        }

        if (n != '\n') {
            no nt = novo(n - '0');

            if (op == 0) insere_inicio(&n1, nt);
            else insere_inicio(&n2, nt);
        }
        else {
            r = (op == '+') ? somar(&n1, &n2) : multiplicar(&n1, &n2);

            imprime(r);

            op = 0;
            limpar(&n1);
            limpar(&n2);
            limpar(&r);
        }
    }

    return EXIT_SUCCESS;
}