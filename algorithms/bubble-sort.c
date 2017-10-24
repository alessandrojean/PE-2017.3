#include <stdio.h>
#include <stdlib.h>

void bubble_sort (int n, int *v);

int main (int argc, char **argv) {
    int v[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    int n = sizeof (v) / sizeof (v[0]);

    bubble_sort (n, v);

    for (int i = 0; i < n; i++) {
        printf ("%d ", v[i]);
    }

    return EXIT_SUCCESS;
}

void bubble_sort (int n, int *v) {
    int aux = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
	    if (v[j] > v[j + 1]) {
	        aux = v[j];
	        v[j] = v[j + 1];
	        v[j + 1] = aux;
	    }
	}
    }

}

