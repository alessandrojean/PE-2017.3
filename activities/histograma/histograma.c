#include <stdio.h>

#define N 20000

void bubble_sort(double t[], int n);
double media_acima_media(double media, double t[], int n);
void popular_aux(int aux[20], double t[], int n);
double histograma(int aux[20], double t[], int n);
void histograma_vertical(double max_aux, int aux[20]);

int main() {
  int n = 0;
  double t[N], med, min = 100, max = -100, soma = 0;;

  while(n < N && scanf("%lf", &t[n]) > 0) {
    if(t[n] > max)
        max = t[n];
    else if(t[n] < min)
        min = t[n];

    soma += t[n++];
  }
  
  med = soma / n;

  printf("med = %.3lf, min = %.3lf, max = %.3lf\n", med, min, max);

  bubble_sort(t, n);

  printf("Média das temperaturas acima da média: %.3lf\n", media_acima_media(med, t, n));

  int aux[20];
  
  popular_aux(aux, t, n);

  double max_aux = histograma(aux, t, n);

  histograma_vertical(max_aux, aux);

  /* escreva a maior parte de seu código aqui */
  
  return 0;
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

double media_acima_media(double med, double t[], int n){
    double soma = 0;
    int c = 0;
    for(int i = 0; i < n; i++){
        if(t[i] > med){
            soma += t[i];
            c++;
        }
    }

    return soma / c;
}

void popular_aux(int aux[20], double t[], int n){
    double passo = (t[n - 1] - t[0]) / 20, min = t[0];
    int j = 0;
    
    for(int i = 0; i < 20; i++){
        double max = min + passo * (i + 1);

        while(t[j] < max){
            aux[i]++;
            j++;
        }

        printf("aux[%d] = %d\n", i, aux[i]);
    }
}

double histograma(int aux[20], double t[], int n){
    double passo = (t[n - 1] - t[0]) / 20, min = t[0], max_aux = 0;

    for(int j = 0; j < 20; j++){
        double ast = aux[j] / 122.0;
        double max = min + passo;

        if(ast > max_aux)
            max_aux = ast;

        printf("Temperaturas entre %06.3lf e %06.3lf: ", min, max);
        while(ast-- > 0)
            printf("*");

        printf("\n");

        min = max;
    }

    return max_aux;
}

void histograma_vertical(double max_aux, int aux[20]){
    printf("Histograma na vertical:\n");
    for(double j = max_aux; j > 0; j--){
        for(int i = 0; i < 20; i++){
            printf(j <= (aux[i] + 121) / 122 ? "*" : " ");
        }
        printf("\n");
    }
}
