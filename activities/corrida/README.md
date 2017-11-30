# Corrida
![aberta](https://img.shields.io/badge/aberta-29%2F11%2F2017%2009%3A00-green.svg) ![vencimento](https://img.shields.io/badge/vencimento-12%2F12%2F2017%2023%3A55-red.svg)

Considere o seguinte problema. **[1]**

> Alice e Beto est�o apostando corrida. Ambos correm com a mesma velocidade, andam com a mesma velocidade e correm mais r�pido do que andam. A diferen�a est� na resist�ncia deles. Alice corre metade do tempo e anda a outra metade do tempo. Beto corre metade do espa�o e anda a outra metade do espa�o. Quem ganha a corrida?

Neste exerc�cio-programa, sua tarefa consiste em fazer um programa que resolve uma vers�o generalizada desse problema. O comportamento de cada competidor � descrito por uma sequ�ncia de instru��es. Cada instru��o diz se o competidor corre ou anda e por que fra��o do tempo ou do espa�o restante ele faz isso. Tomando como exemplo o problema original enunciado acima, a sequ�ncia de Alice teria duas instru�oes: `corre 50% tempo` e `anda 100% tempo`.

Quer dizer que, no inicio da corrida, Alice corre 50% do tempo que resta para completar a corrida e, feito isso, anda 100% do tempo que resta para completar a corrida a partir daquele ponto. S�o instru��es equivalentes: `corre 50% tempo` e `anda 100% espa�o`.

No exemplo, a sequ�ncia de instru��es correspondente ao Beto seria `corre 50% espa�o` e `anda 100% espa�o`.

Para representar as instru��es de uma forma que o computador consiga entender, vamos usar `C` para correr, `A` para andar, `T` para tempo e `E` para espa�o. Al�m disso, vamos substituir porcentagem por dois inteiros representando uma fra��o positiva menor que 1. Por exemplo, as instru��es da Alice ficariam assim.

    C 1 2 T A 1 1 T

Generalizar o problema significa que, agora, podemos ter muitos competidores (n�o s� Alice e Beto) e que cada competidor tem seu comportamento ditado por uma sequ�ncia de m�ltiplas instru��es. Por exemplo, poder�amos imaginar uma corrida com tr�s competidores que se comportam de acordo com as regras a seguir.

    C 1 6 T A 1 4 E C 1 6 E C 1 1 T
    C 1 4 T A 2 7 E C 1 1 T
    C 3 11 T C 2 7 E A 1 3 T C 1 1 E
    
S� para ter certeza de que voc� entendeu, se o comprimento do percurso fosse 100km, e os competidores corressem a 10km/h e andassem a 5km/h, o Corredor 1 demoraria 12h para complet�-lo: correria 20km em 2h (1/6 das 12h), depois andaria 20km (1/4 dos 80km restantes) em 4h, depois correria 10km (1/6 dos 60km restantrs) em 1h e, finalmente, correria 50km em 5h (1/1 das 5h restantes). O Corredor 2 empataria com o Corredor 1. Dada essa informa��o, tente deduzir sozinho quanto tempo e espa�o ele corre correspondente a cada uma das instru��es. Finalomente, deduza sozinho o tempo que o Corredor 3 demora para completar a corrida e decida se ele � o vencedor ou perdedor.

Vamos continuar supondo que todos correm com a mesma velocidade, andam com a mesma velocidade e correm mais r�pido do que andam. O problema � que, nessa vers�o mais geral, a rela��o entre a velocidade de corrida e de caminhada e o comprimento do percurso pode afetar o resultado de quem ser� o vencedor. Portanto, para que o problema de se determinar o vencedor esteja bem definido, vamos fixar em 10km/h a velocidade de corrida, em 5km/h a velocidade de caminhada e em 100km a dist�ncia a ser percorrida.

Este exerc�cio poder� ser feito em duplas, n�o triplas. O nome dos integrantes deve aparecer em um coment�rio, no in�cio do arquivo `.c` que ser� entregue no Tidia. Somente um dos integrantes deve submeter no Tidia.

## Dicas de implementa��o

Em uma das maneiras de se fazer este exerc�cio programa, voc� precisar� representar uma fun��o linear (i.e. uma fun��o da forma `f(x) = ax + b`, onde `a` e `b` s�o fra��es) como uma estrutura e dever� implementar opera��es bin�rias de soma e composi��o, uma opera��o de produto por escalar e deve ser capaz de inverter uma tal fun��o. A dica � que as instru��es devem ser consideradas na ordem inversa para que se possa descobrir o tempo e o espa�o percorridos.

**[1]** Adapta��o do problema 6 no livro *E a�, algum problema?* de Beth B�rgers e Elis Pacheco, Editora Moderna, S�o Paulo, 1997.