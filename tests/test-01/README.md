# Prova 01
*Prova do Prof. Daniel M. Martin, CMCC/UFABC.*

1. **(2.0)** Escreva um programa completo em C que lê um inteiro positivo `n`, depois lê `n` inteiros positivos, depois calcula e imprime o máximo, o mínimo e a média dos últimos `n` valores lidos e, finalmente, imprime a média daqueles valores que forem menores que a média. Não precisa usar `malloc` para esta questão.

1. **(0.5)** Supondo que o arquivo contendo seu programa se chama `stats.c`, como você faria para compilar o seu programa usando o compilador `gcc` no terminal?

1. **(0.5)** Supondo, agora, que o arquivo executável do seu programa se chama `stats`, e supondo que existe um arquivo chamado `temps.txt`, como você faria para executar seu programa, no terminal, passando como entrada os dados dentro de `temps.txt`?

1. **(2.5)** Considere o programa abaixo. Supondo que variáveis locais sejam alocadas em posições consecutivas de memória, como ficaria a saída do programa a seguir? Suponha que o endereço da variável `a` seja 0. Embora a saída do programa seja em base hexadecimal, você pode (e deve) usar base 10 para responder a este exercício.

   ```c
   #include <stdio.h>

   int main() {
       int a;
       char c;
       int *p = &a;
       char v[4];
       int **q = &p;

       printf("&a = %p\n", &a);
       printf("&c = %p\n", &c);
       printf("&p = %p\n", &p);
       printf("&v = %p\n", &v);
       printf("&q = %p\n", &q);

       return 0;
   }
   ```

   Para fazer este exercício você deve saber a quantidade de memória ocupada por cada tipo de dado: `char` = 1 byte, `int` = 4 bytes, qualquer ponteiro = 8 bytes.

1. **(2.0)** Suponha que um vetor `v` de inteiros com `N` elementos e suponha que os inteiros armazenados nesse vetor variam de `A` até `B`, para algum par de inteiros `A < B`. Descreva como seria a execução do algoritmo Counting Sort sobre esse vetor. Quanta memória adicional seria necessária? Justifique sua resposta. Seja preciso, mas não precisa dar o pseudo-código.

1. **(2.5)** Faça um algoritmo recursivo que recebe um ponteiro para o primeiro elemento de um vetor de inteiros com `n` elementos e que decide se o vetor está ordenado (de forma não-decrescente). Ou seja, você deve implementar recursivamente a função

   ```c
   int ordenado(int n, int *v);
   ```

   que devolve 1 se `v[0] <= v[1] <= ... <= v[n - 1]` e devolve 0 caso contrário.