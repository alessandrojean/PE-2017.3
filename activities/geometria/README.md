# Geometria
![aberta](https://img.shields.io/badge/aberta-01%2F11%2F2017%2009%3A00-green.svg) ![vencimento](https://img.shields.io/badge/vencimento-07%2F11%2F2017%2023%3A55-red.svg)

## Introdução

Nesta atividade você deverá partir da estrutura básica abaixo.

```c
struct s_ponto {
    double x;
    double y;
}
```

Para não ter que ficar escrevento `struct s_ponto` toda vez, vamos criar um apelido (usando `typedef`) que nos permite escrever esse tipo de dado apenas como `ponto` ou como `vetor`. Veja:

```c
typedef struct s_ponto ponto;
typedef struct s_ponto vetor;
```

Em seguida, você deverá criar as estruturas `s_segmento`, para representar um segmento de reta, e `s_triangulo`, para representar um triângulo no plano. Depois de criar essas estruturas, você pode acrescentar as linhas abaixo para simplificar o nome desses tipos:

```c
typedef struct s_segmento segmento;
typedef struct s_triangulo triangulo;
```

Use somente `ponto` dentro de `triangulo` (não use `segmento`).

## Exercício

Depois de definir essas estruturas, vocẽ deverá implementar as seguintes funções.

```c
// Calcula o produto interno <u,v>
double produto_interno(vetor p, vetor q);

// Calcula o vetor p - q
vetor subtrai(vetor p, vetor q);

/* Calcula o vetor resultante da rotação do vetor v
   de um ângulo de 90 graus (no sentido anti-horário). */
vetor roda90(vetor p);

// Calcula distância
double distancia(ponto p, ponto q);

/* Retorna 1 se o coseno do ângulo entre os vetores u e v é positivo
   retorna -1 se for negativo e 0 se for nulo. */
int sinal_do_coseno(vetor u, vetor v);

/* Retorna 1 se p, q e r estão em sentido horário e -1 se for
   anti-horário. Se os pontos forem colineares devolva 0. */
int sentido(ponto p, ponto q, ponto r);

// Retorna 1 se os segmentos se cruzam e 0 caso contrário.
int cruza(segmento s, segmento t);

/* Retorna 1 se o ponto p está no interior do triângulo t.
   Devolve 0 caso contrário. */
int dentro(ponto p, triangulo t);

// Opcional:

/* Devolve a cordenada do ponto em que s e t se intersecta
   caso eles se intersectam ou qualquer ponto caso eles não
   se intersectam. */
ponto cruzamento(segmanto s, segmento t);

// Calcula o ponto que é a projeção de p no segmento s.
ponto projeta(ponto p, segmento s);

/* Devolve 1 se os triângulos a e b se intersectam
   e devolve 0 caso contrário. */
int intersecta(triangulo a, triangulo b);
```

## Observações

As funções foram declaradas numa certa ordem e você deve respeitá-la! Isto é, não pode chamar uma função que foi declarada depois na definição de uma função declarada antes. (É claro que em C você pode fazer isso, mas para este exercício estou pedindo a você que não faça isso.)

A ordem foi pensada de modo que, na hora de implementar uma função é bem provável que você precise chamar alguma função que foi declarada antes dela (exceto pelas primeiras que são muito simples).

### Geometria analítica

Se você não se lembra de geometria analítica, aqui vão algumas dicas.

- As definições que você esqueceu você pode consultar no Google.
- O cosseno do ângulo `θ` entre dois vetores pode ser calculado através da lei dos cossenos
            
        c² = a² + b² - 2 * a * b * cos(θ)

  onde `c` é o comprimento do lado oposto ao ângulo `θ` no triângulo formado pelos dois vetores, e `a` e `b` são os comprimentos dos vetores. Mas primeiro expanda e depois simplifique a expressão que você encontrar para o cosseno, pois o que queremos saber do cosseno é só o sinal! A expressão final depois de simplificada fica *bem* simples!

- Nas funções `cruza` e `dentro`, você deve usar apenas algumas chamadas à função `sentido` e uns poucos operadores lógicos.
- Para a função `projeta`, lembre-se de que `u` projetado em `v` é um vetor múltiplo de `v`, digamos `αv`. Portanto, a dica é: você deve encontrar `α` que minimiza

        f(α) = ||u - αv||

  Outra dica é que, para minimizar a raiz quadrada de algo que é sempre não negativo, basta minimizar esse algo!