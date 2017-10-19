# Lista de exercícios: recursão

Implemente funções recursivas para fazer o que é pedido em cada exercício.

1. Computar a soma dos primeiros `n` inteiros positivos.
    ```c
    int soma(int n);
    ```
1. Computar a soma dos elementos de um vetor `v` com índices de `0` até `n - 1`.
    ```c
    int soma(int n, int *v);
    ```
1. Encontrar o valor do menor elemento de um vetor `v` com índices de `0` até `n - 1`.
    ```c
    int min(int n, int *v);
    ```
1. Decidir se uma palavra `p` é palíndroma.
    ```c
    int eh_palindroma(int n, char *p);
    ```
1. Reverter a ordem das letras de uma palavra `p`.
    ```c
    int reverter(int n, char *p);
    ```
1. Calcular `2 ^ k`.
    ```c
    long pot2(int k);
    ```
1. Dado `k`, enumerar as potências de `2` até `2 ^ k`.
    ```c
    long enum_pot2(int k);
    ```
1. Dados inteiros positivos `n` e `b`, imprimir `n` em base `b`.
    ```c
    long imprimir_em_base(int n, int b);
    ```
1. Dado um inteiro positivo `n`, calcular a soma dos dígitos de `n` (em base 10).
    ```c
    long soma_digitos(int n);
    ```
1. Dado um vetor `v` com `n` elementos, imprimir todas as `n!` permutações dos elementos de `v`.
    ```c
    long enum_permut(int n, int *v);
    ```
   Se você preferir, a função `enum_permut` não precisa ser a função recursiva, mas você pode fazer outra função que será a função recursiva propriamente dita, de maneira que `enum_permut` chame essa outra função (seja um *wrapper* para o uso dessa outra função).
1. Dado um vetor `v` com `n` elementos, possivelmente repetidos, imprimir todas as permutações distintas dos elementos de `v`.
    ```c
    long enum_permut(int n, int *v);
    ```
   Mesmo caso do exercício anterior.
1. (1.5) Suponha que `v` seja um vetor de inteiros. Sejam `p < q < r` índices válidos desse vetor. Considere o problema de trocar os elementos dos subvetores `v[p..(q - 1)]` e `v[q..(r - 1)]` de lugar, preservando a ordem em cada subvetor. Veja um exemplo do que isso significa na figura abaixo.

   ![Imgur](https://i.imgur.com/gF5jFlw.png)

   Descreva o código em C de um algoritmo que resolve o problema recursivamente usando espaço extra constante (que não dependa do tamanho do vetor de entrada). **Isto é, você não pode usar um vetor auxiliar!**
    ```c
    long troca_blocos(int p, int q, int r, int *v);
    ```