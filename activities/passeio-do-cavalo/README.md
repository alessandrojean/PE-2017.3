# Passeio do cavalo
![aberta](https://img.shields.io/badge/aberta-17%2F10%2F2017%2012%3A00-green.svg) ![vencimento](https://img.shields.io/badge/vencimento-27%2F10%2F2017%2023%3A55-red.svg)

**ESTE EXERCÍCIO É OPCIONAL** (valendo 0.35 ponto a mais na média se gerar pelo menos 1 caminhos por segundo em um Intel Core i5 @ 3.2GHz)

## Xadrez

No jogo de xadrez, cada tipo de peça tem um jeito diferente de se movimentar. Talvez a peça mais curiosa seja o cavalo, que se move em forma de L. O movimento do cavalo consiste em andar 2 casas em uma direção (Leste, Oeste, Norte ou Sul) e depois 1 casa em uma direção ortogonal. Veja a figura.

![chess-movies](http://www.expert-chess-strategies.com/images/knight-moves.gif)

## Passeio do cavalo

O problema do cavalo, ou passeio do cavalo, é um problema matemático envolvendo o movimento da peça do cavalo no tabuleiro de xadrez. O cavalo é colocado no tabuleiro vazio e, seguindo as regras do jogo, precisa passar por todas as casas do tabuleiro exatamente uma vez em movimentos consecutivos. A referência mais antiga ao problema do Passeio do Cavalo aparece num manuscrito de Rudrata que data do século 9.

## Heurística

Se você quiser achar um passeio do cavalo manualmente em seu tabuleiro de xadrez, existe uma heurística que pode ajudá-lo a fazer isso relativamente rápido. Essa heurística consiste em começar no canto do tabuleiro e sempre andar para uma posição não preenchida que fique o mais perto possível das bordas do tabuleiro.

## Programa

Neste exercício você deverá fazer um programa para enumerar passeios do cavalo. Seu programa deve usar uma função recursiva que implementa a técnica de backtracking para a busca de soluções. Duarante as chamadas recursivas, você deve usar uma matriz global 8x8 para se lembrar de quais casas já foram visitadas. Você também deve usar um vetor global para armazenar a ordem em que o passeio visita as casas do tabuleiro, a fim de poder imprimir o passeio quando encontrar um.

## Imprimindo um passeio

Na hora de imprimir um passeio que seu programa encontrou, use a notação usual de cordenadas do tabuleiro xadrez. Veja a figura abaixo:

![coordenadas](https://i.stack.imgur.com/YxP53.gif) 

As linhas são numeradas de 1 até 8 e as colunas de A até H. Por exemplo, se seu cavalo começou no canto inferior esquerdo e andou (em L) duas casas para a direita e uma para cima, e depois andou (em L) duas casas para cima e uma para a esquerda, então o começo do seu passeio (impresso) será

    A1C2B4...

São 128 caracteres para descrever 1 passeio. Seu programa deve imprimir 1 passeio por linha.