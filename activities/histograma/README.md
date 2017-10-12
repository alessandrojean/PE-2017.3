# Histograma
![aberta](https://img.shields.io/badge/aberta-04%2F10%2F2017%2010%3A00-green.svg) ![vencimento](https://img.shields.io/badge/vencimento-16%2F10%2F2017%2023%3A55-red.svg)

Para este exercício, você deverá usar o arquivo temperatura.csv em anexo que contém um número (`float`) por linha. Esses números representam a temperatura média de cada dia, desde 01/01/1961 até 31/12/2016 registradas na estação meteorológica Mirante de Santana em São Paulo. 
O problema proposto nesta atividade consiste do seguinte. Você deve fazer um programa que lê cada um desses números e coloca-os em um vetor declarado assim:

```c
double t[20000];
```

Atenção, não são 20000 números, são menos! Portanto, ao mesmo tempo em que seu programa vai lendo os números, ele deve ir contando quantos são e colocar a quantidade numa variável `n`. Em seguida, seu programa deve calcular a média, o mínimo e o máximo de todos os números lidos. Digamos que seu programa colocou esses valores nas variáveis `med`, `min`, `max`, respectivamente. Depois de ter feito isso, seu programa deve calcular a média das temperaturas do vetor `t[]` que são estritamente maiores do que o valor em `med`. 

Por último, vem a parte principal deste exercício. Seu progrma deve fazer um histograma das temperaturas. O histograma deve ser feito da seguinte forma. Você deve tomar o intervalo [min, max) e dividí-lo em 20 partes iguais. Crie um vetor auxiliar com a declaração

```c
int aux[20];
```

Em seguida, você deve contar quantas temperaturas o vetor `t[]` possui que caem em cada um dos subintervalos e colocar essa contagem no vetor `aux[]`. Para conseguir isso, você deve usar um algoritmo parecido com o `CountingSort` que estudamos durante a aula. Seu programa deve, então, imprimir o vetor `aux`. A saída do seu programa, até o momento deve ser a seguinte:

    med = 19.737, min = 5.700, max = 29.160
    Média das temperaturas acima da média: 22.440
    aux[0] = 2
    aux[1] = 8
    aux[2] = 25
    aux[3] = 61
    aux[4] = 150
    aux[5] = 309
    aux[6] = 564
    aux[7] = 843
    aux[8] = 1348
    aux[9] = 1779
    aux[10] = 2127
    aux[11] = 2314
    aux[12] = 2443
    aux[13] = 2440
    aux[14] = 2178
    aux[15] = 1728
    aux[16] = 956
    aux[17] = 363
    aux[18] = 124
    aux[19] = 31

Emseguida, seu programa deve fazer um histograma com esses valores. Para cada faixa de temperatura `j`, seu programa deve colocar um número de * que corresponde a `aux[j] / 122`, ou seja, colocar um * para cada 122 temperaturas que caem dentro da faixa `j`. A saída do histograma deverá ser a seguinte:

    Temperaturas entre 05.700 e 06.873: *
    Temperaturas entre 06.873 e 08.046: *
    Temperaturas entre 08.046 e 09.219: *
    Temperaturas entre 09.219 e 10.392: *
    Temperaturas entre 10.392 e 11.565: **
    Temperaturas entre 11.565 e 12.738: ***
    Temperaturas entre 12.738 e 13.911: *****
    Temperaturas entre 13.911 e 15.084: *******
    Temperaturas entre 15.084 e 16.257: ************
    Temperaturas entre 16.257 e 17.430: ***************
    Temperaturas entre 17.430 e 18.603: ******************
    Temperaturas entre 18.603 e 19.776: *******************
    Temperaturas entre 19.776 e 20.949: *********************
    Temperaturas entre 20.949 e 22.122: ********************
    Temperaturas entre 22.122 e 23.295: ******************
    Temperaturas entre 23.295 e 24.468: ***************
    Temperaturas entre 24.468 e 25.641: ********
    Temperaturas entre 25.641 e 26.814: ***
    Temperaturas entre 26.814 e 27.987: **
    Temperaturas entre 27.987 e 29.160: *

Veja o esqueeto de programa em anexo e comece seu trabalho a partir dele.

Para quem achar que esse exercício não trouxe nenhum desafio, imprima o histograma na vertical:

    Histograma na vertical:
    
                *       
                **      
               ***      
              *****     
              *****     
              *****     
             *******    
             *******    
             *******    
            ********    
            ********    
            ********    
            ********    
            *********   
           **********   
           **********   
          ***********   
          ***********   
         *************  
        *************** 
    ********************