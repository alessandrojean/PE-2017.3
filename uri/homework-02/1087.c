#include <stdio.h>

int abs(int a);

int main(){
    while(1)
    {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

        if (x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0)
            break;

        if (x1 == x2 && y1 == y2)
            printf("0\n");
        else if (abs(x1 - x2) == abs(y1 - y2) || ((x1 == x2) || (y1 == y2)))
            printf("1\n");
        else
            printf("2\n");
    }
    
    return 0;
}

int abs(int a){
    return a > 0 ? a : - a;
}