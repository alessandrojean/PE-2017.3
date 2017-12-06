#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

// 1. (EXERCÍCIO) Cria um novo nó da lista.
//    Mudar a implementação da função novo
//    para alocar muitos nós de uma vez e usar a lista
//    livres para guardar os blocos que ainda não estão
//    sendo usados. Como visto em sala...
no novo(int item) {
  if (livres != NULL) {
    no x = livres;
    livres = livres->prox;
    x->item = item;
    x->prox = NULL;
    return x;
  }

  no v = (no) malloc(1024 * sizeof(struct s_no));
  for (int i = 0; i < 1024; i++) {
    insere_inicio(&livres, v + i);
  }

  return novo(item);
}

// 2. (EXERCÍCIO) Deleta um nó.
//    Adaptar a função deleta para trabalhar
//    com a lista de nós livres. Como visto em sala...
void deleta(no x) {
  x->prox = livres;
  livres = x;
}

// 3. Insere um nó no início da lista (como PUSH).
//    (Supõem que x e ini são ambos diferentes de NULL.)
//    (Mas *ini pode ser NULL.)
void insere_inicio(no *ini, no x) {
  x->prox = *ini;
  *ini = x;
}

// 4. Remove o primeiro nó da lista.
//    (Se o valor de retorno fosse o item do nó removido,
//    essa função seria como POP.)
void remove_inicio(no *ini) {
  no x = *ini;
  if (*ini != NULL) {
    *ini = x->prox;
    deleta(x);
  }
}

// 5. Imprime todos os elementos de uma lista
//    (supondo que sejam inteiros).
void imprime(no x) {
  for (; x != NULL; x = x->prox)
    printf("%d", x->item);
  printf("\n");
}

// 6. Busca o primeiro nó contendo item.
//    Retorna NULL se não encontrar o nó.
no busca(no inicio, int item) {
  for (; inicio != NULL && inicio->item != item;
       inicio = inicio->prox);
  return inicio;
}

// 7. Busca o primeiro nó contendo item, recursivamente.
//    Retorna NULL se não encontrar o nó.
no buscaR(no inicio, int item) {
  if (inicio == NULL)
    return NULL;
  if (inicio->item == item)
    return inicio;
  return buscaR(inicio->prox, item);
}

// 8. Devolve o último nó de uma lista.
no final(no x) {
  if (x == NULL)
    return NULL;
  
  while (x->prox != NULL)
    x = x->prox;
  
  return x;
};

// 9. Insere nó no final. 
//    (Supõem que x e ini são ambos diferentes de NULL.)
//    (Mas *ini pode ser NULL.)
void insere_final(no *ini, no x) {
  if (*ini == NULL) {
    *ini = x;
    return;
  }

  no y = final(*ini);
  y->prox = x;
}
    
// 10. Insere nó no final, recursivamente. 
//    (Supõem que x e ini são ambos diferentes de NULL.)
//    (Mas *ini pode ser NULL.)
void insere_finalR(no *ini, no x) {
  if (*ini == NULL) 
    *ini = x;
  else
    insere_finalR(&((*ini)->prox), x);
}

// 11. Remove primeiro nó que contém item.
//    (Supõem que ini é diferente de NULL.
//    (*ini pode ser NULL.)
//    (EXERCÍCIO: entender o que a função faz.)
void remove_um(no *ini, int item) {
  if (*ini == NULL)
    return;
  
  no x, *prev = ini;
  for (x = (*ini); x != NULL && x->item != item;
       prev = &(x->prox), x = x->prox);

  if (x != NULL) {
    *prev = x->prox;
    deleta(x);
  }
}

// 12. (EXERCÍCIO) Remove todos os nós contendo item.
void remove_todos(no *ini, int item) {
  if (*ini == NULL)
    return;

  // Percorrer a primeira parte, se há ocorrencias na primeira posição.
  no x, ant = *ini;
  for (x = *ini; x != NULL && x->item == item; x = *ini) {
    *ini = x->prox;
    deleta(x);
  }

  // Percorrer a segunda parte.
  for (; x != NULL; ant = x, x = x->prox) {
    if (x->item == item) {
      ant->prox = x->prox;
      deleta(x);
      x = ant;
    }
  }
}

// 13. (EXERCÍCIO) Remove todos os nós contendo item, recursivo.
//     Este fica mais simples que o anterior.
void remove_todosR(no *ini, int item) {
  if (*ini == NULL)
    return;

  if ((*ini)->item == item) {
    no x = *ini;
    *ini = x->prox;
    deleta(x);
    remove_todosR(ini, item);
    return;
  }

  remove_todosR(&((*ini)->prox), item);
}

// 14. Cria uma cópia da lista dada
//     (copiar em outras posições de memória, é claro).
no copia(no inicio) {
  if (inicio == NULL)
    return NULL;

  no x = novo(inicio->item);
  x->prox = copia(inicio->prox);
  return x;
}

// 15. Inverte a lista.
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

// 16. (EXERCÍCIO) Função recursiva para inverter uma lista
//     Agora só com o ponteiro para (o ponteiro para) o
//     primeiro nó sendo passado como parâmetro.
void inverteR2(no *ini) {
  if (*ini == NULL || (*ini)->prox == NULL)
    return;

  no x = *ini;
  no y = x->prox;

  inverteR2(&y);
  x->prox->prox = x;
  x->prox = NULL;

  *ini = y;
}

// Troque o corpo da função main para testar outras funções...
int main() {
  no inicio = NULL;

  for (int i = 10; i > 0; i--) {
    insere_inicio(&inicio, novo(i));
  }

  insere_final(&inicio, novo(5));
  insere_final(&inicio, novo(1));

  printf("Lista original: ");
  imprime(inicio);

  inverteR2(&inicio);
  printf("Lista invertida: ");
  imprime(inicio);

  return EXIT_SUCCESS;
}