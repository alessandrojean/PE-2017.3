# Triângulos ([1472](https://www.urionlinejudge.com.br/judge/pt/problems/view/1472))

São dados `N` pontos em uma circunferência. Você deve escrever um programa que determine quantos triângulos equiláteros distintos podem ser construídos usando esses pontos como vértices.

A figura abaixo ilustra um exemplo; (a) mostra um conjunto de pontos, determinados pelos comprimentos dos arcos de circunferência que têm pontos adjacentes como extremos, e (b) mostra os dois triângulos que podem ser construídos com esses pontos.

![figura](https://urionlinejudge.r.worldssl.net/gallery/images/problems/UOJ_1472.png)

##Entrada

A entrada contém vários casos de teste. A primeira linha de cada caso de teste contém um número inteiro `N` (`3 ≤ N ≤ 105`), o número de pontos dados. A segunda linha contém `N` inteiros `Xi` (`1 ≤ Xi ≤ 103`) para `1 ≤ i ≤ N`, representando os comprimentos dos arcos entre dois pontos consecutivos na circunferência: para `1 ≤ i ≤ (N − 1)`, `Xi` representa o comprimento do arco entre os pontos `i` e `i + 1`; `XN` representa o comprimento do arco entre os pontos `N` e 1. O final da entrada é determinado por `EOF` (fim de arquivo).

## Saída

Seu programa deve produzir uma única linha para cada caso de teste, contendo um único inteiro, o número de triângulos equiláteros distintos que podem ser construídos utilizando os pontos dados como vértices.
