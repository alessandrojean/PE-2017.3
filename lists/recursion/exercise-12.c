#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void imprimir_vetor(int p, int q, int r, int n, int *v) {
    printf("[ ");
    
    for(int i = 0; i < n; i++){
        if (i == p || i == q || i == r) printf("| ");
        printf("%d ", v[i]);
    }
    printf("]\n");
}

void trocar(int a, int b, int n, int *v) {
    //printf("trocar(%d, %d, %d, v)\n", a, b, n);

    int t;
    for (int i = 0; i < n; i++){
        //printf("trocando %d por %d\n", *(v + a + i), *(v + b + i));
        t = v[a + i];
        v[a + i] = v[b + i];
        v[b + i] = t;
    }
}

long troca_blocos(int p, int q, int r, int *v) {
    //printf("troca_blocos(%d, %d, %d, v)\n", p, q, r);

    if (p == q || p > r || q > r || r - q == 0 || q - p == 0) return 0;

    int tam_pq = q - p, tam_qr = r - q;
    //printf("tam_pq=%d, tam_qr=%d\n", tam_pq, tam_qr);

    if (r - q == q - p){
        //printf("blocos iguais\n");
        trocar(p, q, tam_qr, v);
        return 0;
    }

    if (q - p < r - q){
        //printf("a menor\n");
        trocar(p, q, r - q, v);
        //imprimir_vetor(22, v);
        //printf("troca_blocos(%d, %d, %d, v)\n", r - (q - p), r - 1, r);
        troca_blocos(r - tam_pq, r + (tam_pq - tam_qr), r, v);
    }
    else{
        //printf("b menor\n");
        trocar(p, q, r - q, v);
        //imprimir_vetor(22, v);
        //printf("troca_blocos(%d, %d, %d, v)\n", q - 1, q, r);
        troca_blocos(p + tam_qr, q, r, v);
    }
}




int main(int argc, char** argv) {
    int n = 0;
    
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    int vet[n];
    printf("Digite os elementos do vetor:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &vet[i]);
    }

    int p = 0, q = 0, r = 0;
    printf("Digite p, q e r: ");
    scanf("%d %d %d", &p, &q, &r);

    printf("Vetor original:\n");
    imprimir_vetor(p, q, r, n, vet);

    troca_blocos(p, q, r, vet);

    printf("Vetor com subvetores trocados:\n");
    imprimir_vetor(p, r - (q - p), r, n, vet);

    return EXIT_SUCCESS;
}