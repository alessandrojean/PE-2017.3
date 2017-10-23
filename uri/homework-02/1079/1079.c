#include <stdio.h>

double media_ponderada(double v[]);

int main(){
    int n, j;
    scanf("%d", &n);

    for(j = 0; j < n; j++){
        double v[3];
        scanf("%lf %lf %lf", &v[0], &v[1], &v[2]);

        printf("%.1lf\n", media_ponderada(v));
    }

    return 0;
}

double media_ponderada(double v[]){
    return (v[0] * 2 + v[1] * 3 + v[2] * 5) / 10;
}