#include <stdio.h>

int main(){
    int n1, n2, f;
    scanf("%d %d", &n1, &n2);

    if(n1>n2){
        f = n1 % n2 == 0;
    }else{
        f = n2 % n1 == 0;
    }

    printf(f ? "Sao Multiplos\n" : "Nao sao Multiplos\n");

    return 0;
}