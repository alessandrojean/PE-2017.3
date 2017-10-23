#include <stdio.h>

int main(){
    int s = 2002, e;

    while(1){
        scanf("%d", &e);
        if(e == s){
            printf("Acesso Permitido\n");
            break;
        } else
            printf("Senha Invalida\n");
    }

    return 0;
}