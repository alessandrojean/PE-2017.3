#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 20000

void bubble_sort(double t[], int n);
double media_acima_media(double media, double t[], int n);
int contar_bucket(double hist[20], double t[], int n);
void histograma(double hist[20], int max, double t[], int n);

int main(int argc, char** argv){
    double t[N], soma=0, media = 0, hist[20];
    int n = 0, c = 0;

    while(n < N && scanf("%lf", &t[n]) == 1)
        soma += t[n++];

    if(n == N)
        printf("Só li %d entradas.\n", n);

    bubble_sort(t, n);

    media = soma / n;
    printf("média = %.3lf, min = %.3lf, max = %.3lf\n", media, t[0], t[n - 1]);
    printf("média dos acima da média: %.3lf\n", media_acima_media(media, t, n));

    int max = contar_bucket(hist, t, n);
    histograma(hist, max, t, n);

    return (EXIT_SUCCESS);
}

void bubble_sort(double t[], int n){
    double aux = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (t[j] > t[j + 1]) {
                aux = t[j];
                t[j] = t[j + 1];
                t[j + 1] = aux;
            }
        }
    }
}

double media_acima_media(double media, double t[], int n){
    double soma = 0;
    int c = 0;
    for(int i = 0; i < n; i++){
        if(t[i] > media){
            soma += t[i];
            c++;
        }
    }

    return soma / c;
}

int contar_bucket(double hist[20], double t[], int n){
    double intervalo = t[n - 1] - t[0], passo = intervalo / 20, inf = t[0], sup = 0, max = 0;
    int j = 0;
    
    for(int i = 0; i < 20; i++){
        sup = inf + passo;

        hist[i] = 0;
        while(t[j++] < sup)
            hist[i]++;

        if (hist[i] > max)
            max = hist[i];
        
        inf = sup;
    }

    return max;
}

void histograma(double hist[20], int max, double t[], int n){
    double intervalo = t[n - 1] - t[0], passo = intervalo / 20, inf = t[0], sup = 0;
    for(int i = 0; i < 20; i++){
        sup = inf + passo;
        printf("%6.3lf <= t < %6.3lf: ", inf, sup);
        
        //Arredonda para cima
        //hist[i] = (hist[i] * 20.0 + max - 1) / max;
        hist[i] = hist[i] * 20.0 / max;
        while(hist[i]-- > 0)
            printf("*");

        printf("\n");

        inf = sup;
    }
}
