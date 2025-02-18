#include <stdio.h>
#include <stdlib.h>


// Enunciado: El enunciado nos pide calcular cuantos boletos pares se pueden
//  comprar de una serie de boletos. 
// Nos dan un entero "N", el numero de boletos, y en la siguiente linea 
//  aparecen los "N" numeros de cada boleto.
// Nos piden calcular el numero de boletos que pueden comprar, con la restriccion
//  del problema (cuantos pares hay).

// Explicacion: Es un problema iterativo puesto que hay que recorrer todos los 
//  boletos comprobando si cada uno cumple con la restriccion de ser par.
// Inserto los boletos en un vector de enteros para verlo mejor.
//  pero tambien se puede ir comprobando conforme se lee con cin >>
// Si el boleto i-esimo cumple con la restriccion se incrementa la variable 
//  de salida. Si no lo cumple no se hace nada.

// Complejidad: 
// - Espacial: O(n) hay n boletos que se almacenan en un vector de enteros.
// - Temporal: O(n) se recorre todo el vector.
int loteria(const int* boletos, int n) {
    int ret=0;
    int i=0;

    while (i<n) {
        if (boletos[i]%2==0) ret++;
        i++;
    }

    return ret;
}

void resuelveCaso() {
    int i;

    int N;
    scanf("%d", &N);
    int* boletos=(int*)malloc(N*sizeof(int));
    for (i=0;i<N;i++) scanf("%d", &boletos[i]);

    printf("%d\n", loteria(boletos, N));
    
    free(boletos);
}

int main() {
    int i;

    int numCasos;
    scanf("%d", &numCasos);
    for (i=0;i<numCasos;i++) resuelveCaso();

    return 0;
}