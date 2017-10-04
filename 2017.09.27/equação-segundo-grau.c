#include <stdio.h>
#include <math.h>

int main(){
    //C-99: todas as variáveis são declaradas no início da função
    double a, b, c, delta, x1, x2;

    printf("Considere ax² + bx + c = 0.\n");
    printf("Digite os coeficientes a, b e c: \n");
    scanf("%lf %lf %lf", &a, &b, &c);

    if(a == 0){
        //Testa se a equação é de 1º grau
        if(b == 0){
            printf("Esta não é uma equação envolvendo x\n");
            return 0;
        }

        printf("A solução da equação é: x = %.3f\n", - c / b);

        return 0;
    }

    delta = b * b - 4 * a * c;

    if(delta > 0){
        x1 = (- b - sqrt(delta)) / (2 * a);
        x2 = (- b + sqrt(delta)) / (2 * a);

        printf("As raizes são: x1 = %.3f e x2 = %.3f\n", x1, x2);
        return 0;
    } else if(delta < 0){
        printf("A equação não tem raízes reais.\n");
        return 0;
    }

    //Uma raiz real dupla
    x1 = - b / (2 * a);

    printf("A raiz dupla é: x = %.3f\n", x1);

    return 0;
}