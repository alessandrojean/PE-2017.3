# Reconstrução
![aberta](https://img.shields.io/badge/aberta-11%2F10%2F2017%2012%3A00-green.svg) ![vencimento](https://img.shields.io/badge/vencimento-20%2F10%2F2017%2023%3A55-red.svg)

Neste exercício, você deverá fazer um programa que recebe, na entrada padrão, os seguintes dados. Primeiramente um inteiro positivo `n` menor que 200 e, em seguida, dois inteiros `a` e `b` entre 0 e (n-1). Finalmente, seu programa deve ler `n²` inteiros que correspondem às entradas de uma matriz quadrada `M` com dimensões `n x n`.

A interpretação desses números é a seguinte. Imagine que um mapa (grafo) possui `n` locais (vértices) de interesse. A matriz `M` codifica rotas ótimas nesse mapa entre cada par de locais de interesse. Por exemplo, `M[i][j]` contém infomação sobre a melhor rota do local `i` até o local `j`. Mas que tipo de informação é essa? 

Se `M[i][j] = -1`, isso significa que as localidades `i` e `j` estão ligadas por uma estrada, e que o caminho ótimo de `i` até `j` é tomar essa estrada, não passando por nenhum outro vértice intermediário.

Se `M[i][j] = n`, isso significa que não existe caminho nenhum nesse mapa ligando a localidade `i` à localidade `j`. Portanto é impossível de ir de `i` até `j`.

Se `0 <= M[i][j] < n`, então `M[i][j]` é o índice de algum nó `k` que pertence a um caminho ótimo de `i` até `j`. Portanto, para se ir de `i` até `j` de maneira ótima, basta ir de `i` até `k` de maneira ótima e, em seguida, ir de `k` até `j` de maneira ótima. 

Você deverá fazer uma função recursiva cuja declaração é:

```c
void imprime_caminho(int i, int j);
```

Sua função deve consultar a matriz `M`, que deve ser global, para determinar um caminho ótimo entre os valores `a` e `b` que foram lidos na entrada. A variável `n` também deve ser global. Se não existir caminho de `a` até `b`, então seu programa deve imprimir a palavra "impossível" (sem acento e sem áspas) na saída padrão. 

Se `a = b`, então seu programa deve imprimir o caminho trivial que consiste apenas do número `a`.

Finalmente, se `-1 <= M[a][b] < n`, então quer dizer que existe caminho de `a` até `b`, e seu programa deve imprimir o caminho ótimo de `a` até `b` que pode ser reconstruído da matriz `M`.

Use o script de correção automatizada que foi anexado nesta atividade.