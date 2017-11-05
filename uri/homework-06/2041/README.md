# Sequência de Gödelito ([2041](https://www.urionlinejudge.com.br/judge/pt/problems/view/2041))

Gödelito é fascinado por questões lógicas e matemáticas e passa muito tempo brincando em tentar descobrir a semântica por traz das sequencias matemáticas. O mais divertido para Gödelito não é tanto encontrar o próximo número da sequência, mas entender os axiomas que determinam o formato das sequencias.

Muitas sequencias são ditadas por regras matemáticas, por exemplo a sequência de Fibonacci cujo axioma é que cada número é a soma dos dois anteriores. Outras sequencias envolvem axiomas mais semânticos, por exemplo a sequência: 2, 10, 12, 16, 17, 18, 19, 200..., no qual axioma é: números cujo nome começa com a letra D.

Gödelito se deparou atualmente com uma sequência bem interessante. Depois de algum tempo ele descobriu que o axioma da sequência é semântico (ele tentou muitas contas matemáticas primeiro, o que só o deixou mais feliz quando descobriu o significado da sequência). A sequência é a mostrada abaixo:

```
3
13
1113
3113
132113
1113122113
311311222113
...
```

Gödelito ficou impressionado com o quanto essa sequência cresce rapidamente. E como não quer gastar as folhas do seu caderno para calcular todos os números que quer, pediu a sua ajuda para criar um algoritmo para encontrar os outros números da sequência. Mas ele te explicou o significado da sequência primeiro para facilitar a sua vida:

Cada número da sequência é gerado através da leitura do número anterior, por exemplo, o segundo número é 13 porque a linha de cima contém um (1) número três (3). O terceiro número é 1113, porque a linha de cima contém um (1) número um (1) e um (1) número três (3). O quarto número da sequência é 3113, pois a linha de cima contém três (3) números um (1) e um (1) número três (3). Acho que deu para entender a ideia, não é?

## Entrada

A entrada é composta de vários casos de teste. Cada caso de teste é composto de uma linha contendo um número inteiro `N`, que representa o enésimo número da sequência que deve ser calculado, com `0 < N <= 40`.

## Saída

A saída de cada caso de teste é apenas uma linha contendo o enésimo número da sequência.