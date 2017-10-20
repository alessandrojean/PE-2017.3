#include <stdio.h>

int main(){
    int v[100], m = 0, p = 0, i;

    for(i = 0; i < 100; i++){
        scanf("%d", &v[i]);
        if(v[i] > m){
            m = v[i];
            p = i;
        }
    }

    printf("%d\n%d\n", m, p + 1);

    return 0;
}