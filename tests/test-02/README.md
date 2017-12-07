# Prova 02

1. **(1.5)** Considere o programa abaixo e escreva no lugar indicado qual seria a saída correspondente à entrada dada.

   ```c
   #include <stdio.h>
   #include <stdlib.h>

   int main() {
       int n;

       scanf("%d", &n);

       int **p = malloc(n * sizeof(int *));
       for (int i = 0; i < n; i++) {
           p[i] = malloc(n * sizeof(int));
           for (int j = 0; j < n; j++)
               scanf("%d", &p[i][j]);
       }

       int *temp = p[1];
       p[1] = p[2];
       p[2] = temp;

       for (int i = 0; i < n; i++) {
           for (int j = 0; j < n; j++)
               printf("%d ", p[i][j]);
           printf("\n");
       }

       return 0;
   }
   ```

   Entrada:

       3
       1 3 5
       7 9 2
       4 6 8

1. **(2.5)** Uma função linear é uma função da forma `f(x) = ax + b` onde `a, b ∈ ℝ`. Sejam `f(x) = ax + b` e `g(x) = a'x + b'` funções lineares e seja `c ∈ ℝ` uma constante. As seguintes afirmações são verdadeiras:

   - o produto `c * f(x)` é uma função linear;
   - `f(x) + g(x)` é uma função linear;
   - `f-1(x)`, a inversa da função `f(x)`, é uma função linear, se `a ≠ 0`;
   - a função composta `(f ∘ g)(x)` é uma função linear.

   Neste execício você deverá criar uma estrutura em C (uma `struct`) para representar/armazenar uma função linear e também criar funções em C que realizam as seguintes tarefas:

   1. recebe uma função linear `f` e uma constante (`double`) `c` e devolve a função linear `c * f`;
   1. recebe duas funções lineares `f` e `g` e devolve a função linear `f + g`;
   1. recebe uma função linear `f` e devolve a função linear inversa (pode supor `a ≠ 0`);
   1. recebe duas funções lineares `f` e `g` e devolve a função linear `f ∘ g`.

1. **(1.0)** Considere o programa abaixo e explique o que ele faz.

   ```c
   #include <stdio.h>
   #include <stdlib.h>

   typedef struct node * link;

   struct node {
       long key;
       link next;
   };

   int main(void) {
       link x, y, t;

       x = malloc(sizeof *x);
       y = malloc(sizeof *y);

       x->next = y; x->key = 1;
       y->next = x; y->key = 1;

       for (t = x; t->key < 100; t = t->next)
           t->key = x->key + y->key;
        
       printf("%ld\n", t->key);

       return 0;
   }
   ```

1. **(1.0)** Considere o trecho de código abaixo e escreva no lugar indicado qual seria a saída correspondente à chamada de função `comp(13, f2)`.

   ```c
   int f1(int n) {
       return 3 * n + 1;
   }

   int f2(int n) {
       return n / 2;
   }

   void comp(int n, int (*f)(int)) {
       printf("%d\n", n);

       if (n > 1) {
           n = f(n);

           if (n % 2 == 0)
               comp(n, f2);
           else
               comp(n, f1);
       }
   }
   ```