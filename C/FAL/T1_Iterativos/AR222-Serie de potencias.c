#include <stdio.h>
#include <stdlib.h>
#include <errno.h>


int errno;
// No compruebo errores de funciones por el compilador de acepta el reto

const int MOD = 1000007;

// Enunciado: El enunciado nos pide hacer un calculo x^0 + x^1 + x^2 + … + x^n
// Nos dan un entero "x" y "n". Hay que calcular el resultado de la serie.

// Explicacion: Es un problema iterativo puesto que hay que recorrer con un bucle 
//  para poder calcular el resultado de la serie.

// Complejidad: 
// - Espacial: O(n) hay n datos que se almacenan en un vector de enteros.
// - Temporal: O(n) se recorre todo el vector comprobando condiciones.

// Precondicion: Cuando se puede ejecutar la funcion
// Pre = { 0 <= n <= 1.000.000 && 1 <= x <= 100 }
int seriePotencia(int x, int n) {
    int ret = 1; // variable de retorno
    int i = 1; // iterador
    // variable auxiliar para la suma y poder usar MOD sin riesgo de 
    // sobrepasar el limite de int 2^31
    int aux = 1; 
    // Funcion cota: n-i (decrece hasta llegar a 0)
    // INV: 1 ≤ k < n+1 ∧ ret = (Sum : 1 ≤ k < i : x^k)   
    // ret contiene la suma actual que se ha procesado 
    // hasta el momento. Se cumple antes durante y al final del bucle.
    while (i < n + 1) {
        aux = (x * aux) % MOD;
        ret += aux;
        ret %= MOD;

        ++i;
    }

    return ret;
}
// Postcondicion: Lo que devuelve el algoritmo
// ret = (Sum : 1 ≤ k < n : x^k) 

int resuelveCaso() {
    int x, n;    
    if(scanf("%d %d",&x,&n)==-1) return 0;  

    printf("%d\n", seriePotencia(x, n));
    return 1;
}
/*
x [1,100]
n [0,1.000.000]

Entrada:
1 2

2 3

3 4

2 19

100 1000000

Salida:
3
15
121
48568
642708
*/

// lee por un fichero los datos de entrada
// en vez de escribirlos a mano por la terminal
int main() {
    while (resuelveCaso());  

    return 0;
}