#include <stdio.h>
#include <math.h>

double distance(double x1, double y1, double x2, double y2);

int main(){
    double x1, y1, r1, x2, y2, r2;
    printf("Digite o x1, y1 e o raio do primeiro disco:\n");
    scanf("%lf %lf %lf", &x1, &y1, &r1);
    printf("Digite o x2, y2 e o raio do segundo disco:\n");
    scanf("%lf %lf %lf", &x2, &y2, &r2);

    printf(distance(x1, y1, x2, y2) > r1 + r2 ? "Os discos não se intersectam.\n" : "Os discos se intersectam.\n");

    return 0;
}

double distance(double x1, double y1, double x2, double y2){
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}