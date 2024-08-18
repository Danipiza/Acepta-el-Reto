#include <stdio.h>
#include <stdlib.h>
#include <errno.h>


int errno;
// No compruebo errores de funciones por el compilador de acepta el reto

// Enunciado: El enunciado nos pide calcular cuantos picos y valles hay en
//  unos datos de la AEMET. 
// Se considera pico (resp. valle) en una secuencia cuando la anterior y la 
//  siguiente en la secuencia son estrictamente menores (resp. mayores). 
// Nos dan un entero "N", el numero de datos, y en la siguiente linea 
//  aparecen los "N" puntos en la grafica.

// Explicacion: Es un problema iterativo puesto que hay que recorrer todos los 
//  datos comprobando es un pico o un valle.
// Inserto los datos en un vector de enteros para comprobarlos.
//  pero tambien se puede ir comprobando conforme se lee con cin >> con 3
//  variables locales.
// Si datos[i-1] y datos[i+1]   son menores que datos[i] es un pico
//                              son mayores que datos[i] es un valle.

// Complejidad: 
// - Espacial: O(n) hay n datos que se almacenan en un vector de enteros.
// - Temporal: O(n) se recorre todo el vector comprobando condiciones.

// Precondicion: Cuando se puede ejecutar la funcion
// Pre = { 0 <= boletos.size() <= 10.000 && v[i] >= -50 && v[i] <= 60 }
void picos_valles(int n, int datos[], 
    int *picos, int *valles) { // variables de entrada/salida
    int i = 1; // iteradores
    // Funcion cota: n-i (decrece hasta llegar a 0)
    // INV: 1 ≤ k < n-1 ∧ 
    //      picos = (# k : 1 ≤ k < i : datos[k-1] < datos[k] && datos[k] > datos[k+1]).
    //      valles = (# k : 1 ≤ k < i : datos[k-1] > datos[k] && datos[k] < datos[k+1]).
    // picos y valles contiene el numero de picos y valles que se han procesado 
    // hasta el momento. Se cumple antes durante y al final del bucle.
    while (i < n - 1) {
        if (datos[i - 1] < datos[i] && datos[i] > datos[i + 1]) *picos+=1;
        else if (datos[i - 1] > datos[i] && datos[i] < datos[i + 1]) *valles+=1;
        ++i;
    }    
}
// Postcondicion: Lo que devuelve el algoritmo
// picos =  (# k : 1 ≤ k < boletos.size() : datos[k-1] < datos[k] && datos[k] > datos[k+1]).
// valles = (# k : 1 ≤ k < boletos.size() : datos[k-1] > datos[k] && datos[k] < datos[k+1]).

void resuelveCaso() {
    int N;
    scanf("%d",&N);
    int datos[N];    
    int i = 0;
    for (; i < N; ++i) {
        scanf("%d",&datos[i]);
    }
    int picos = 0, valles = 0; // variables de entrada salida
    picos_valles(N, datos, &picos, &valles);
    printf("%d %d\n",picos,valles);
}
/*
N [0,10.000]
datos[i] [-50,60]
Entrada:
4

5
7 5 3 8 9

8
8 9 7 6 5 3 4 2

2
3 -5

8
4 -1 5 3 7 7 6 8

Salida:
0 1
2 1
0 0
1 3
*/

// lee por un fichero los datos de entrada
// en vez de escribirlos a mano por la terminal
int main() {
    int numCasos, i = 0;
    scanf("%d",&numCasos);
    for (; i < numCasos; i++) resuelveCaso();

    return 0;
}