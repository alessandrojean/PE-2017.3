# Aula 05
*Retirado dos slides do Prof. Daniel M. Martin, CMCC/UFABC.*

## Ponteiros

Uma variável que armazena referência a outra variável.

### Derreferenciação

Derreferenciação de um ponteiro `y` significa "olhar"/consultar o valor da variável apontada por `y`.

### Ponteiro `NULL`

Ponteiro `NULL` significa um ponteiro que não faz referência a nenhuma variável.

### Atribuição de ponteiros

    y, z ponteiros
    z = y (atribuir valor de y a z)
    
### Ponteiros ruins

Ponteiros ruins apontam para coisa nenhuma ou para algo indesejado.

### Sintaxe de ponteiros em C

```c
int x = 10;
int *y = &x;
float *z;
printf("%p\n", y);
```

### Operador de derreferenciação em C

Se `y` é um ponteiro para uma variável inteira `x`, então `*y` é o item de memória apontado por `y` (`x`).

### Aritmética com ponteiros em C

`y` é um ponteiro, `y + 1` é a posição de memória do "objeto" seguinte àquele apontado por `y`. Depende do tipo de `y`.

```c
char *y;
y + 1;
```

Se `y` contém o endereço de memória `e` e o tipo de `*y` ocupa `b` bytes de memória, então `y + 1` é o endereço de memória `e + b`.

Quando temos um vetor `v[]`, em C, `v` contém o endereço do primeiro byte ocupado pelo vetor, e o tipo de `*v` é o tipo de dado de cada elemento do vetor.

Em C, `v[i]` é equivalente a `*(v + i)`.

### Exemplo de passagem de ponteiros como parâmetro

```c
void inline troca(int *p, int *q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}

int main() {
    int x = 7, y = 5;
    troca(&x, &y);
    
    return 0;
}
```

## Alocação dinâmica de memória

```c
#include <stdlib.h>
#define N 20000000

void erro() {
    printf("msg\n");
    exit(1);
}

int main() {
    int *v = (int *) malloc(N * sizeof(int));
    if (v == NULL) erro();
    
    for (int i = 0; i < N; i++)
        scanf("%d", v + i);
        
    return 0;
}
```
