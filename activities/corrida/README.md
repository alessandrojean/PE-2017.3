# Corrida
![aberta](https://img.shields.io/badge/aberta-29%2F11%2F2017%2009%3A00-green.svg) ![vencimento](https://img.shields.io/badge/vencimento-12%2F12%2F2017%2023%3A55-red.svg)

Considere o seguinte problema. **[1]**

> Alice e Beto estão apostando corrida. Ambos correm com a mesma velocidade, andam com a mesma velocidade e correm mais rápido do que andam. A diferença está na resistência deles. Alice corre metade do tempo e anda a outra metade do tempo. Beto corre metade do espaço e anda a outra metade do espaço. Quem ganha a corrida?

Neste exercício-programa, sua tarefa consiste em fazer um programa que resolve uma versão generalizada desse problema. O comportamento de cada competidor é descrito por uma sequência de instruções. Cada instrução diz se o competidor corre ou anda e por que fração do tempo ou do espaço restante ele faz isso. Tomando como exemplo o problema original enunciado acima, a sequência de Alice teria duas instruçoes: `corre 50% tempo` e `anda 100% tempo`.

Quer dizer que, no inicio da corrida, Alice corre 50% do tempo que resta para completar a corrida e, feito isso, anda 100% do tempo que resta para completar a corrida a partir daquele ponto. São instruções equivalentes: `corre 50% tempo` e `anda 100% espaço`.

No exemplo, a sequência de instruções correspondente ao Beto seria `corre 50% espaço` e `anda 100% espaço`.

Para representar as instruções de uma forma que o computador consiga entender, vamos usar `C` para correr, `A` para andar, `T` para tempo e `E` para espaço. Além disso, vamos substituir porcentagem por dois inteiros representando uma fração positiva menor que 1. Por exemplo, as instruções da Alice ficariam assim.

    C 1 2 T A 1 1 T

Generalizar o problema significa que, agora, podemos ter muitos competidores (não só Alice e Beto) e que cada competidor tem seu comportamento ditado por uma sequência de múltiplas instruções. Por exemplo, poderíamos imaginar uma corrida com três competidores que se comportam de acordo com as regras a seguir.

    C 1 6 T A 1 4 E C 1 6 E C 1 1 T
    C 1 4 T A 2 7 E C 1 1 T
    C 3 11 T C 2 7 E A 1 3 T C 1 1 E
    
Só para ter certeza de que você entendeu, se o comprimento do percurso fosse 100km, e os competidores corressem a 10km/h e andassem a 5km/h, o Corredor 1 demoraria 12h para completá-lo: correria 20km em 2h (1/6 das 12h), depois andaria 20km (1/4 dos 80km restantes) em 4h, depois correria 10km (1/6 dos 60km restantrs) em 1h e, finalmente, correria 50km em 5h (1/1 das 5h restantes). O Corredor 2 empataria com o Corredor 1. Dada essa informação, tente deduzir sozinho quanto tempo e espaço ele corre correspondente a cada uma das instruções. Finalomente, deduza sozinho o tempo que o Corredor 3 demora para completar a corrida e decida se ele é o vencedor ou perdedor.

Vamos continuar supondo que todos correm com a mesma velocidade, andam com a mesma velocidade e correm mais rápido do que andam. O problema é que, nessa versão mais geral, a relação entre a velocidade de corrida e de caminhada e o comprimento do percurso pode afetar o resultado de quem será o vencedor. Portanto, para que o problema de se determinar o vencedor esteja bem definido, vamos fixar em 10km/h a velocidade de corrida, em 5km/h a velocidade de caminhada e em 100km a distância a ser percorrida.

Este exercício poderá ser feito em duplas, não triplas. O nome dos integrantes deve aparecer em um comentário, no início do arquivo `.c` que será entregue no Tidia. Somente um dos integrantes deve submeter no Tidia.

## Dicas de implementação

Em uma das maneiras de se fazer este exercício programa, você precisará representar uma função linear (i.e. uma função da forma `f(x) = ax + b`, onde `a` e `b` são frações) como uma estrutura e deverá implementar operações binárias de soma e composição, uma operação de produto por escalar e deve ser capaz de inverter uma tal função. A dica é que as instruções devem ser consideradas na ordem inversa para que se possa descobrir o tempo e o espaço percorridos.

**[1]** Adaptação do problema 6 no livro *E aí, algum problema?* de Beth Bürgers e Elis Pacheco, Editora Moderna, São Paulo, 1997.