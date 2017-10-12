# Enumeração
![aberta](https://img.shields.io/badge/aberta-11%2F10%2F2017%2008%3A00-green.svg) ![vencimento](https://img.shields.io/badge/vencimento-18%2F10%2F2017%2023%3A55-red.svg)

Neste exercício, você deverá fazer um programa que lê uma palavra da entrada padrão (no máximo 100 caracteres), e que implementa uma função recursiva para enumerar todas as subpalavras dessa palavra. 

Uma subpalavra de uma palavra x é uma subsequência contígua de carcateres em x. 
Faça a leitura usando o comando:

```c
scanf("%100s", v); 
```

onde `v` é uma variável global declarada como

```c
char v[101];
```

Por exemplo, se a palavra lida for `abacaxi`, a saida deve ser:

    abacaxi
    .bacaxi
    ..acaxi
    ...caxi
    ....axi
    .....xi
    ......i
    abacax.
    .bacax.
    ..acax.
    ...cax.
    ....ax.
    .....x.
    abaca..
    .baca..
    ..aca..
    ...ca..
    ....a..
    abac...
    .bac...
    ..ac...
    ...c...
    aba....
    .ba....
    ..a....
    ab.....
    .b.....
    a......
    .......

A ordem das palavras na saída não precisa ser a mesma do exemplo. Note que a palavra toda (`abacaxi`) e a palavra vazia (`.......`) também devem aparecer na saída. 
Para testar seu programa, use o script e os arquivos de correção automática anexado nesta atividade. Extraia o conteúdo do arquivo .zip em algum diretório e leia o README.