#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 8


// Enunciado: TODO

// Explicacion: TODO

// Complejidad:
// - Preprocesaod: O(nlogn) ordenar por un algoritmo de divide y venceras como
//  puede ser QuickSort
// - Temporal: O(n), recorre el vector de n elementos
// - Espacial: O(2n+4) = O(n) vector de n pares.
void voraz(int cambio, const int* dinero, int* vuelta, int n) {
    int i=0;

    while (i<n-1) {
        if (dinero[i]<=cambio) {
            vuelta[i]++;
            cambio-=dinero[i];
        }
        else i++;
    }   

    vuelta[i]=cambio;
}
// Demostracion por reduccion de diferencias. TODO

void resuelveCaso() {
    int i;

    int coste, pago;
    scanf("%d %d", &coste, &pago);
    int cambio=pago-coste;  
    if (cambio<0) {
        printf("DEBE %d\n", cambio * -1);
        return;
    }

    int dinero[]={200, 100, 50, 20, 10, 5, 2, 1};
    int vuelta[MAX_SIZE]={0};
    voraz(cambio, dinero, vuelta, MAX_SIZE);
    
    for (i=0;i<MAX_SIZE-1;i++) printf("%d ", vuelta[i]);

    printf("%d\n", vuelta[i]);
}
/*
TODO
Entrada:


Salida:

*/

int main() {
    int i;

    int nCase;
    scanf("%d", &nCase);
    for (i=0;i<nCase;i++) resuelveCaso();

    return 0;
}