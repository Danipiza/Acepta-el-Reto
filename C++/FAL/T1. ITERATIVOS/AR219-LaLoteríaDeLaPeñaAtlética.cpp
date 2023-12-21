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

// Precondicion: Cuando se puede ejecutar la funcion
// Pre = { 0 <= boletos.size() <= 10.000 }
int loteria(const vi& boletos) {
    int ret = 0; // variable de retorno
    int i = 0, n = boletos.size(); // iteradores
	// Funcion cota: n-i (decrece hasta llegar a 0)
	// INV: 0 ≤ k ≤ n ∧ ret = (Sum k : 0 ≤ k < i : V [k]).
	// ret contiene el numero de boletos pares que se han procesado 
	// hasta el momento. Se cumple antes durante y al final del bucle.
    while (i < n) { // O(n)
        // si el numero del boleto i-esimo modulo 2 es 0, el numero es par.
        // O(1)
        if (boletos[i] % 2 == 0) ret++;
        i++; // pasa al siguiente boleto
    }
    return ret;
}
// Postcondicion: Lo que devuelve el algoritmo
// ret = # k: 0 <= k < boletos.size(): v[k]%2 == 0 }
//	cuenta k: 		entre 			 : condiciones

void resuelveCaso() {
    int N;
    cin >> N;
    vi boletos;
    int a;
    for (int i = 0; i < N; i++) {
        cin >> a;
        // añade al final los elementos de la entrada
        boletos.push_back(a); 
        // Se puede hacer asi, si se inicializa el tamaño del vector
        // vi boletos(N);
        //cin >> boletos[i];
    }

    cout << loteria(boletos) << "\n";    
}
/*
N [0,10.000]
boletos [0,99.999]
Entrada:
3

10
1 2 3 4 5 6 7 8 9 10

5
1 1 1 1 1

5
2 2 2 2 2

Salida:
5
0 
5
*/

// lee por un fichero los datos de entrada
// en vez de escribirlos a mano por la terminal
int main() {  
    // PARA ACEPTA EL RETO HAY QUE QUITARLO
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif



    int numCasos;
    cin >> numCasos;
    for (int i = 0; i < numCasos; i++) resuelveCaso();



    // PARA ACEPTA EL RETO HAY QUE QUITARLO
#ifndef DOMJUDGE 
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}