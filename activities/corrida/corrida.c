/*
  Alessandro Jean Gigi, 11070616
  Victor Parpinelli Ananias da Silva, 11072516
*/
#include <stdio.h>
#include <stdlib.h>

struct s_funcao {
    double a;
    double b;
};

typedef struct s_funcao funcao;

struct s_instrucao {
    int velocidade;
    double porcentagem;
    char variavel;
};

typedef struct s_instrucao instrucao;

typedef struct s_no * no;

struct s_no {
    instrucao inst;
    funcao tempo;
    funcao espaco;
    no prox;
    no ant;
};

// Soma de duas funções.
// f(x) + g(x)
funcao somar(funcao f, funcao g) {
    funcao ret = {f.a + g.a, f.b + g.b};
    return ret;
}

// Operação de produto por escalar.
// c * f(x)
funcao produto_por_escalar(double c, funcao f) {
    funcao ret = {f.a * c, f.b * c};
    return ret;
}

void imprimir_funcao(funcao f) {
    printf("%.2lfx + %.2lf\n", f.a, f.b);
}

// Cria um novo nó na lista.
no novo(int velocidade, double porcentagem, char variavel) {
  no x = (no) malloc(sizeof(struct s_no));

  if (x == NULL) {
    fprintf(stderr, "Memória insuficiente.\n");
    exit(1);
  }

  (x->inst).velocidade = velocidade;
  (x->inst).porcentagem = porcentagem;
  (x->inst).variavel = variavel;
  x->prox = NULL;
  x->ant = NULL;

  return x;
}

// Deleta um nó.
void deleta(no x) {
  free(x);
}

// Devolve o último nó de uma lista.
no final(no x) {
  if (x == NULL)
    return NULL;
  
  while (x->prox != NULL)
    x = x->prox;
  
  return x;
};

// Insere nó no final. 
// (Supõem que x e ini são ambos diferentes de NULL.)
// (Mas *ini pode ser NULL.)
void insere_final(no *ini, no x) {
  if (*ini == NULL) {
    *ini = x;
    return;
  }

  no y = final(*ini);
  y->prox = x;
  x->ant = y;
}

// Deleta todos os nós.
void limpar(no *inicio) {
  no x = *inicio;
  while (x != NULL) {
    *inicio = x->prox;
    deleta(x);
    x = *inicio;
  }

  *inicio = NULL;
}

void erro(char *msg) {
    fprintf(stderr, msg);
    exit(1);
}

void imprimir_instrucao(no x) {
    printf("%d %.2lf %c\n", (x->inst).velocidade, (x->inst).porcentagem, (x->inst).variavel);
}

void calcular_espaco_porcentagem(no x) {
    funcao f_tempo_mult = produto_por_escalar(- x->inst.velocidade * x->inst.porcentagem, x->ant->tempo);
    funcao f_tempo_atual = {x->inst.velocidade * x->inst.porcentagem, 0};

    x->espaco = somar(x->ant->espaco, f_tempo_atual);
    x->espaco = somar(x->espaco, f_tempo_mult);
}

void calcular_tempo_porcentagem(no x) {
    funcao f_espaco_mult = produto_por_escalar(- x->inst.porcentagem / x->inst.velocidade, x->ant->espaco);
    funcao f_espaco_atual = {0, (x->inst.porcentagem * 100.0) / x->inst.velocidade};

    x->tempo = somar(x->ant->tempo, f_espaco_atual);
    x->tempo = somar(x->tempo, f_espaco_mult);
}

funcao funcao_horaria(double velocidade, funcao atual, funcao anterior, funcao o_anterior) {
    funcao ret;
    funcao f_atual = produto_por_escalar(velocidade, atual);
    funcao f_ant = produto_por_escalar(- velocidade, anterior);

    ret = somar(o_anterior, f_atual);
    ret = somar(ret, f_ant);

    return ret;
}


double calcular(no inicio) {
    inicio->tempo.a = inicio->tempo.b = 0;
    inicio->espaco.a = inicio->espaco.b = 0;

    no x, ultimo;
    for (x = inicio->prox; x != NULL; ultimo = x, x = x->prox) {
        if (x->inst.variavel == 'T') {
            calcular_espaco_porcentagem(x);
            x->tempo = funcao_horaria(1.0 / x->inst.velocidade, x->espaco, x->ant->espaco, x->ant->tempo);
        }
        else {
            calcular_tempo_porcentagem(x);
            x->espaco = funcao_horaria(x->inst.velocidade, x->tempo, x->ant->tempo, x->ant->espaco);
        }

    }

    return (ultimo->inst.variavel == 'E')
            ? - ultimo->tempo.b / (ultimo->tempo.a - 1.0)
            : (100.0 - ultimo->espaco.b) / ultimo->espaco.a;
}

int main(int argc, char **argv) {
    int a, b, im;
    char c, v;

    no inicio = novo(0, 0, '\0');

    while (scanf("%c %d %d %c", &v, &a, &b, &c) != EOF) {
        if (v != 'C' && v != 'A') continue;

        // printf("%c %d %d %c\n", v, a, b, c);
        no e = novo((v == 'C') ? 10 : 5, (double) a / b, c);
        insere_final(&inicio, e);

         if (a == 1 && b == 1) {
            double t = calcular(inicio);
            printf("%.3lf\n", t);
            limpar(&(inicio->prox));
        } 
    }

    limpar(&inicio);

    return EXIT_SUCCESS;
}