#include <stdio.h>
#include <math.h>

double distance(double x1, double y1, double x2, double y2);
double distance2(double c[4]);

double c[4];

int main(){
    printf("Digite coordenadas x1 y1 x2 y2:\n");
    scanf("%lf %lf %lf %lf", &c[0], &c[1], &c[2], &c[3]);

    printf("A distância entre os pontos é %.3f\n", distance2(c));

    return 0;
}

double distance(double x1, double y1, double x2, double y2){
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

double distance2(double c[4]){
    return sqrt(pow(c[2] - c[0], 2) + pow(c[3] - c[1], 2));
}