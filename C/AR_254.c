#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void* a, const void* b) {
    return (*(int*)a-*(int*)b);
}

// Enunciado: 

// Explicacion: 

// Complejidad:
// - Preprocesaod: O(nlogn) ordenar por un algoritmo de divide y venceras como
//  puede ser QuickSort
// - Temporal: O(n), recorre el vector de n elementos
// - Espacial: O(2n+4) = O(n) vector de n pares.
int voraz(const int* esquiadores, const int* esquis, int n) {
    int i;
    int ret=0;

    for(i=0;i<n;i++) {
        ret+=abs(esquiadores[i]-esquis[i]);
    }

    return ret;
}
// Demostracion por reduccion de diferencias. TODO

int resuelveCaso() {
    int i;
    
    int N;
    scanf("%d", &N);
    if (N==0) return 0;

    int* esquiadores =(int*)malloc(N*sizeof(int));
    int* esquis      =(int*)malloc(N*sizeof(int));

    for(i=0;i<N;i++) scanf("%d", &esquiadores[i]);
    for(i=0;i<N;i++) scanf("%d", &esquis[i]);

    qsort(esquiadores, N, sizeof(int), compare);
    qsort(esquis, N, sizeof(int), compare);

    printf("%d\n", voraz(esquiadores, esquis, N));

    free(esquiadores);
    free(esquis);

    return 1;
}
/*
TODO
Entrada:


Salida:

*/

int main() {
    while (resuelveCaso());
    
    return 0;
}