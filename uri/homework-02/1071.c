#include <stdio.h>

int main(){
    int x, y, s = 0;
    scanf("%d %d", &x, &y);


    if(x > y){
        int i = y % 2 != 0 ? y + 2 : y + 1;
        for(; i < x; i += 2)
            s += i;
        printf("%d\n", s);
    } else if(x < y){
        int i = x % 2 != 0 ? x + 2 : x + 1;
        for(; i < y; i += 2)
            s += i;
        printf("%d\n", s);
    } else
        printf("0\n");

    return 0;
}