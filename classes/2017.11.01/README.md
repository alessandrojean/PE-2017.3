# Aula 06

## Alocando dinamicamente uma matriz

Na aula passada vimos que é bem tranquilo de chamar a função `malloc` para alocar um bloco de memória para armazenar um vetor, mas com a vantagem de podermos escolher o tamanho desse vetor em tempo de execução. Será que dá pra fazer a mesma coisa para matrizes bidimensionais? Sim, é possível, mas vamos ter que usar ponteiros para ponteiros.

Alocar memória para uma linha da matriz é fácil: basta chamar `malloc` e será retornado um ponteiro para a região de memória reservada pelo sistema. Então podemos alocar espaço de memória para cada linha (cada linha com o comprimento que quisermos) chamando `malloc`, e cada linha estará associada a um ponteiro. Como vamos guardar todos esses ponteiros? Afinal, existe um ponteiro para cada linha da matriz, não é? É fácil: podemos usar um vetor de ponteiros para armazená-los! Na hora de alocar espaço para esse vetor de ponteiros vamos chamar `malloc`, e essa chamada irá devolver um ponteiro: na verdade um ponteiro para ponteiro!

O exemplo abaixo ilustra melhor a situação:

```c
/* Número de linhas:  m.
   Número de colunas: n. */
int m, n, i;

/* Aloca espaço para o vetor de ponteiros. */
int **M = (int **) malloc(m * sizeof(int *));

/* Testa se o sistema conseguiu reservar a quantidade de memória desejada. */
if (M == NULL) {
  fprintf(stderr, "Quantidade de memória indisponível.\n");
  exit(1);
}

/* Aloca espaço para cada linha da matriz. */
for (i = 0; i < m; i++) {
  M[i] = malloc(n * sizeof(int));
  if (M[i] == NULL) {
    fprintf(stderr, "Quantidade de memória indisponível.\n");
    exit(1);
  }
}
```

`M` é um ponteiro para um ponteiro para int: num primeiro nível, ele aponta para um bloco de ponteiros, um para cada linha da matriz. Esse ponteiro do primeiro nível aponta para a primeira região de memória que foi alocada, e que possui `m` elementos, com cada elemento grande o suficiente para armazenar um ponteiro para int. Se obtivemos sucesso em alocar esse vetor `M`, então preenchemos cada ponteiro `M[i]` (são `m` no total) com um ponteiro devolvido por `malloc` que irá apontar para a posição de memória que guarda os `n` inteiros da `i`-ésima linha da matriz. Se a explicação não estiver fazendo muito sentido, uma figura poderá esclarecer (troque a palavra `array` da imagem por `M`):

<p align="center">
  <img src="https://www.eskimo.com/~scs/cclass/int/fig23.1.gif">
</p>

Uma vez feito isso, assim como no caso de vetores, podemos usar a sintaxe de matrizes para acessar os elementos da matriz que acabamos de alocar. Se escrevemos

```c
M[i][j]
```

estamos pedindo pelo `j`-ésimo inteiro no vetor apontado por `M[i]`. Por sua vez, `M[i]` é o `i`-ésimo elemento (ponteiro) no vetor apontado por `M`. Lembre-se que o compilador entende a linha de código acima como

```c
*(M[i] + j)
```

que, por sua vez, é o mesmo que

```c
*(*(M + i) + j)
```

Este é um resultado bem surpreendente: apesar da estrutura na memória ser completamente diferente de uma matriz alocada estaticamente por

```c
int M[m][n];
```

o modo de acesso, tanto para leitura quanto para escrita, é o mesmo: basta usar um par de colchetes com a linha e a coluna da matriz. 

Se um programa usa matrizes alocadas dinamicamente é possível escrever funções "heterogênias" que não precisam saber em tempo de compilação as dimensões da matriz passada como parâmetro. Em outras palavras, uma função consegue operar com matrizes de vários tamanhos e formas, como o cabeçalho no exemplo abaixo.

```c
void func(int **M, int m, int n) {
    /* código */
}
```

Essa função aceita um ponteiro para ponteiro pra int e supõe que se trata de uma matriz `m x n` alocada dinamicamente com o método que descrevemos acima. A função também aceita como parâmetro as dimensões da matriz, para saber quantas linhas e quantas colunas existem, para poder fazer iterações corretamente. Abaixo está uma função que preenche a matriz com zeros.

```c
void limpa(int **M, int m, int n) {
  int i, j;
  for(i = 0; i < m; i++) {
    for(j = 0; j < n; j++) {
      M[i][j] = 0;
    }
  }
}
```

Finalmente, quando chega a hora de liberar a memória alocada para a matriz alocada dinamicamente, precisamos lembrar de liberar a memória de cada região de memória que alocamos. (Só chamar `free(M)` não resolve o problema! Se fizéssemos isso, todos os ponteiros que apontavam para cada uma das linhas da matriz seriam perdidos e a memória não seria liberada, mas ficaria bloqueada até o término do programa. Isso seria um desperdício de memória.) O trecho de código que libera a memória de maneira correta fica assim:

```c
for (i = 0; i < m; i++) {
  free(M[i]);
}
free(M);
```

Texto traduzido e adaptado com certa liberdade de: https://www.eskimo.com/~scs/cclass/int/sx9b.html

[Vários modos de se alocar uma matriz dinamicamente em C](http://www.geeksforgeeks.org/dynamically-allocate-2d-array-c/)

Ler seções 6.1 até 6.4 do livro *The C Programming Language*.