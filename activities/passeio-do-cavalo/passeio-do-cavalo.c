#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 8

int m_x[] = {2, 1, -1, -2, -2, -1, 1, 2, 2};
int m_y[] = {1, 2, 2, 1, -1, -2, -2, -1, 1};
char g_coordenadas[8] = "ABCDEFGH";

int verificar_validade(int x, int y, int tabuleiro[N][N]) {
    return x >= 0 && x < N && y >= 0 && y < N && tabuleiro[x][y] == 0;
}

void imprimir(int tabuleiro[N][N], char *passeio) {
    /*for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
            printf("%3d ", tabuleiro[i][j]);
        printf("\n");
    }
    //printf("\n");*/
    printf("%s\n", passeio);
}

void passeio_do_cavalo(int tabuleiro[N][N], char *passeio, int x, int y, int p, int c) {
    tabuleiro[x][y] = p;
    passeio[c] = g_coordenadas[y];
    passeio[c + 1] = (N - x) + '0';

    if (p >= N * N) {
        imprimir(tabuleiro, passeio);

        tabuleiro[x][y] = 0;
        passeio[c] = ' ';
        passeio[c + 1] = ' ';
        return;
    }

    for (int i = 0; i < 8; i++){
        int proximo_x = x + m_x[i];
        int proximo_y = y + m_y[i];

        //printf("%d %d\n", proximo_x, proximo_y);

        //printf("v_v: %d\n", verificar_validade(proximo_x, proximo_y));

        if (verificar_validade(proximo_x, proximo_y, tabuleiro)) {
            passeio_do_cavalo(tabuleiro, passeio, proximo_x, proximo_y, p + 1, c + 2);
        }
    }

    tabuleiro[x][y] = 0;
    passeio[c] = ' ';
    passeio[c + 1] = ' ';
}

int letra_para_numero(char letra) {
    for (int i = 0; i < N; i++) {
        if (g_coordenadas[i] == letra) return i;
    }

    return -1;
}

int main(int argc, char** argv) {
    
    int tabuleiro[N][N] = {0};
    char passeio[(N * N) * 2];

    int p = 1, c = 0;

    char inicio[3];
    printf("Use a notação usual de cordenadas do tabuleiro de xadrez.\n");
    printf("Entre com a coordenada de início: ");
    scanf("%s", inicio);

    int x = N - (inicio[1] - '0');
    int y = letra_para_numero(inicio[0]);

    //imprimir(tabuleiro);

    passeio_do_cavalo(tabuleiro, passeio, x, y, p, c);

    return EXIT_SUCCESS;
}