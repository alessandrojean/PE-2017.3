#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    if(n>=5){
        long int i;
        for(i = 2; i <= n; i++){
            if (i % 2 == 0){
                printf("%ld^2 = %ld\n", i, i * i);
            }
        }
    }  

    return 0;
}