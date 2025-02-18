#include <iostream>
#include <fstream> // libreria para leer desde un fichero
#include <vector> // libreria para almacenar los datos
// tambien se puede usar arrays de enteros = int[]

// Funciones para que el compilador tarde menos en ejecutarse
// no tenies que usarlo en clase
#pragma GCC optimize("O3,Ofast,unroll-loops")
static const int _ = []()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();
// ----------------------------------------------------------

using namespace std; // libreria standard
// para poder usar cin, cout, string, otras librerias...

// para que el codigo quede mas limpio
// acorta el uso de vector de enteros
using vi = vector<int>;

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

bool resuelveCaso() {
    int x, n;
    cin >> x >> n;
    if (!cin) return false;

    cout << seriePotencia(x, n) << "\n";
    return true;
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



    while (resuelveCaso());  


    return 0;
}