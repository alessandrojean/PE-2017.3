#include <stdio.h>

int main(){
    int v[3] = {0, 0, 0}, n;

    while(1){
        scanf("%d", &n);

        if(n > 0 && n < 5){
            if(n == 4) break;

            v[n - 1]++;
        }
    }

    printf("MUITO OBRIGADO\nAlcool: %d\nGasolina: %d\nDiesel: %d\n", v[0], v[1], v[2]);

    return 0;
}