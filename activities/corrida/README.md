# Corrida
![aberta](https://img.shields.io/badge/aberta-29%2F11%2F2017%2009%3A00-green.svg) ![vencimento](https://img.shields.io/badge/vencimento-15%2F12%2F2017%2023%3A55-red.svg)

Considere o seguinte problema. **[1]**

> Alice e Beto estão apostando corrida. Ambos correm com a mesma velocidade, andam com a mesma velocidade e correm mais rápido do que andam. A diferença está na resistência deles. Alice corre metade do tempo e anda a outra metade do tempo. Beto corre metade do espaço e anda a outra metade do espaço. Quem ganha a corrida?

Neste exercício-programa, sua tarefa consiste em fazer um programa que resolve uma versão generalizada desse problema. O comportamento de cada competidor é descrito por uma sequência de instruções. Cada instrução diz se o competidor corre ou anda e por que fração do tempo ou do espaço restante ele faz isso. Tomando como exemplo o problema original enunciado acima, a sequência de Alice teria duas instruçoes: `corre 50% tempo` e `anda 100% tempo`.

Quer dizer que, no inicio da corrida, Alice corre 50% do tempo que resta para completar a corrida e, feito isso, anda 100% do tempo que resta para completar a corrida a partir daquele ponto. São instruções equivalentes: `corre 50% tempo` e `anda 100% espaço`.

No exemplo, a sequência de instruções correspondente ao Beto seria `corre 50% espaço` e `anda 100% espaço`.

Para representar as instruções de uma forma que o computador consiga entender, vamos usar `C` para correr, `A` para andar, `T` para tempo e `E` para espaço. Além disso, vamos substituir porcentagem por dois inteiros representando uma fração positiva menor que 1. Por exemplo, as instruções da Alice ficariam assim.

    C 1 2 T A 1 1 T

Generalizar o problema significa que, agora, podemos ter muitos competidores (não só Alice e Beto) e que cada competidor tem seu comportamento ditado por uma sequência de múltiplas instruções. Por exemplo, poderíamos imaginar uma corrida com três competidores que se comportam de acordo com as regras a seguir.

    Competidor 1: C 1 6 T A 1 4 E C 1 6 E C 1 1 T
    Competidor 2: C 1 4 T A 2 7 E C 1 1 T
    Competidor 3: C 3 11 T C 2 7 E A 1 3 T C 1 1 E
    
Só para ter certeza de que você entendeu, se o comprimento do percurso fosse 100km, e os competidores corressem a 10km/h e andassem a 5km/h, o Corredor 1 demoraria 12h para completá-lo: correria 20km em 2h (1/6 das 12h), depois andaria 20km (1/4 dos 80km restantes) em 4h, depois correria 10km (1/6 dos 60km restantrs) em 1h e, finalmente, correria 50km em 5h (1/1 das 5h restantes). O Corredor 2 empataria com o Corredor 1. Dada essa informação, tente deduzir sozinho quanto tempo e espaço ele corre correspondente a cada uma das instruções. Finalomente, deduza sozinho o tempo que o Corredor 3 demora para completar a corrida e decida se ele é o vencedor ou perdedor.

Vamos continuar supondo que todos correm com a mesma velocidade, andam com a mesma velocidade e correm mais rápido do que andam. O problema é que, nessa versão mais geral, a relação entre a velocidade de corrida e de caminhada e o comprimento do percurso pode afetar o resultado de quem será o vencedor. Portanto, para que o problema de se determinar o vencedor esteja bem definido, vamos fixar em 10km/h a velocidade de corrida, em 5km/h a velocidade de caminhada e em 100km a distância a ser percorrida.

Este exercício poderá ser feito em duplas, não triplas. O nome dos integrantes deve aparecer em um comentário, no início do arquivo `.c` que será entregue no Tidia. Somente um dos integrantes deve submeter no Tidia.

## Entrada e Saída

A entrada do seu programa será composta por diversas linhas, cada uma contendo uma sequência de, no máximo, 1000 instruções relativas ao comportamento de um corredor. Cada instrução engloba quatro elementos: um caractere (`C` ou `A`), seguido de dois números inteiros positivos (o segundo maior ou igual que o primeiro), seguidos de um caractere (`T` ou `E`). Os elementos de uma instrução vêm separados uns dos outros por pelo menos um espaço em branco. As instruções também são separadas umas das outras do mesmo modo. Os dois números da última instrução de um corredor serão sempre iguais a 1, denotando que aquele corredor termina o percurso correndo ou andando 100% do percurso restante (tempo ou espaço).

A saída do seu programa será o tempo que cada competidor demora para completar o percurso, impresso com três casas decimais, um número por linha. A `i`-ésima linha na saída será o tempo correspondente ao competidor na `i`-ésima linha da entrada.

## Exemplo

*Entrada:*

    C 1 2 T A 1 1 T
    C 1 2 E A 1 1 E
    A 1 3 T C 2 3 E A 1 1 T
    A 8 15 T A 1 6 E C 1 1 E

*Saída correspondente:*

    13.333
    15.000
    15.000
    15.000

## Leitura

Você já sabe muito bem que, em linguagem C, que as linhas

```c
int n;
scanf("%d", &n);
```

ignoram uma quantidade arbitrária de espaços em branco até o primeiro caractere que não seja espaço em branco e, em seguida, tenta ler um número inteiro (`int`).

O problema é que, na hora de ler caracteres (`char`), se fizermos

```c
char x;
scanf("%c", &x);
```

o caractere armazenado em `x` será o primeiro que aparecer no *buffer* de leitura, podendo ser um espaço em branco. Para encontrar o primeiro `char` que seja diferente de espaço em branco, podemos fazer manualmente:

```c
int r;
char x;
do {
    r = scanf("%c", &x);
} while (r == 1 &&
    (x == ' ' || x == '\t' || x == '\n' || x == '\r'));
if (r == 1) {
    // x foi lido com sucesso e x não é espaço em branco
} else {
    // Erro de leitura ou fim da entrada foi atingido.
}
```

Ou podemos trocar **todo** o laço do `do-while` por

```c
scanf(" %c", &x);
```

Note o espaço antes de `%c`! Mas agora fique atento pois, desse modo, o `scanf` não distingue quando uma linha acaba e começa outra (porque ele engole o `'\n'`). Para este exercício-programa isso não será um problema, pois a última instrução de cada linha sempre tem o numerador e o denominador da fração iguais a 1. De qualquer modo, nunca se esqueça de olhar o valor retornado pela função `scanf` para ver se a leitura foi feita com sucesso.

Para quem quiser ler cada linha da entrada e colocar numa *string* (i.e., num vetor de `char`), e depois processar essa *string*, uma possibilidade seria ler cada linha usando `getline()` e depois processar a linha usando `sscanf()`. Pesquise como usar essas funções.

## Dicas de implementação

Em uma das maneiras de se fazer este exercício programa, você precisará representar uma função linear (i.e. uma função da forma `f(x) = ax + b`, onde `a` e `b` são frações) como uma estrutura e deverá implementar operações binárias de soma e composição, uma operação de produto por escalar e deve ser capaz de inverter uma tal função. A dica é que as instruções devem ser consideradas na ordem inversa para que se possa descobrir o tempo e o espaço percorridos.

Vamos dar um exemplo considerando a entrada:

    C 2 7 E A 1 3 T C 1 1 E

Digamos que antes de executar a última instrução (`C 1 1 E`), ainda resta percorrer `S0` kilometros em `t0` horas. Como este último trecho do percurso será de corrida, então a relação de `S0` e `t0` é

    S0 = 10 * t0

Agora vejamos como seria a situação antes da instrução (`A 1 3 T`). Digamos que, nesse ponto do percurso, ainda resta percorrer `S1` kilometros e `t1` horas **até o final**. Assim, as relações entre `t1` e `t0`, e entre `S1` e `S0` são as seguintes:

    t1 - t0 = (1/3) * t1
    S1 - S0 = 5 * (t1 - t0)

Simplificando, temos

    t1 = (3/2) * t0
    S1 = 5 * (1/3) * t1 + S0

Já temos `t1` em função de `t0`. Se quisermos `S1` em função de `t0`, teremos:

    S1 = (5 * (1/2) + 10) * t0

Mais um passo. Agora estamos antes da instrução `C 2 7 E` e nos resta percorrer `S2` kilometros e resta `t2` horas. As relações entre `t2` e `t1`, e entre `S2` e `S1` são as seguintes:

    S2 - S1 = (2/7) * S2
    S2 - S1 = 10 * (t2 - t1)

Simplificando, temos

    S2 = (7/5) * S1
    t2 = (1/10) * (2/5) * S1 + t1

Como `S1` e `t1` são funções de `t0`, temos

    S2 = (7/5) * (5 * (1/2) + 10) * t0
    t2 = (1/10) * (2/5) * (5 * (1/2) + 10) * t0 + (3/2) * t0

Após simplificar, temos

    S2 = 17.5 * t0
    t2 = 2 * t0

Como combinamos que o percurso todo terá 100km, `S2 = 100`. Agora podemos deduzir o valor de `t0` e usá-lo para calcular `t2` que é o que o exercício pede.

    t2 = 2 * (100 / 17.5) = 11.42857142857142...

Portanto, a saída correspondente à entrada examinada seria:

    11.429

**[1]** Adaptação do problema 6 no livro *E aí, algum problema?* de Beth Bürgers e Elis Pacheco, Editora Moderna, São Paulo, 1997.