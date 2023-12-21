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

// Enunciado: El enunciado nos pide comprobar si Ramiro puede abrir la
//  segunda puerta para que los vecinos no se quejen de la espera.
// La puerta solo se puede abrir si las personas que van al lado impar
//  estan todas juntas al final de la fila.
// Nos dan un entero "N", el numero de personas, y en la siguiente linea 
//  aparecen los "N" numeros de cada persona, representando la butaca,
//  para saber que la persona i-esima va a la derecha (par) o izquierda (impar).
// Nos piden si puede abrir la puerta y cuantas personas se cambian de lado.
// Si puede abrir la puerta imprime "SI x" (numero de personas que no se mueven)
// Si no puede imprime "NO"

// Explicacion: Es un problema iterativo puesto que hay que recorrer todos las 
//  personas, comprobando su butaca para saber si es par o impar. 
// Inserto las personas en un vector de enteros para verlo mejor.
//  pero tambien se puede ir comprobando conforme se lee con cin >>
// Recorro el vector, cuando encuentro un impar incremento el numero de impares
//  y pongo a true (usando un entero) para marcar que ahora vienen los impares,
// Si aparece un impar se incrementa el numero de retorno, si aparece un par
//  no se puede abrir la puerta y termina el recorrido imprimiendo "NO".
// Si llega al final con la variable "puede" a true es porque cumple con la 
//  restriccion y se puede abrir la puerta.

// Complejidad: 
// - Espacial: O(n) hay n boletos que se almacenan en un vector de enteros.
// - Temporal: O(n) se recorre todo el vector.

// Precondicion: Cuando se puede ejecutar la funcion
// Pre = { 0 <= personas.size() <= 10.000 }
int puertaExtra(const vi& personas) {        
    int i = 1, n = personas.size(); // iteradores
    if (n == 0) return 0; // 0 personas
    int puede = 1; // variable que comprueba que si puede abrir la puerta
    // persona actual, comprueba si es par o impar y lo marca.
    int act = (personas[0] % 2 == 0); 
    // si la primera persona es impar quiere decir que solo pueden 
    // aparecer impares, y pone a 1 la variable de retorno.
    int ret = (personas[0] % 2 != 0); // variable de retorno
    int tmp; 
	
	// Funcion cota: n-i (decrece hasta llegar a 0)
	// INV: ?	
    while (i < n && puede) { // O(n)
        // par o impar de la persona i-esima
        tmp = (personas[i] % 2 == 0);
        // Solo han salido pares 
        if (act && !tmp) {
            if (!tmp) { // impar
                ret++; // incrementa el numero de impares
                // pone a false y apartir de ahora solo pueden salir impares
                act = 0;
            }
            // par no hace nada, pasa al siguiente
        }
        // ya ha salido el primer impar
        else if (!act) {
            // i-esimo par, termina la ejecucion, no cumple con
            //  la restriccion del problema
            if (tmp) puede = false;
            else ret++; // i-esimo impar, incrementa y continua
        }                 
        i++; // pasa al siguiente boleto
    }
    if (!puede) return -1;
    else return ret;
}
// Post ?

void resuelveCaso() {
    int N;
    cin >> N;
    vi personas;
    int a;
    for (int i = 0; i < N; i++) {
        cin >> a;
        // añade al final la persona con su butaca
        personas.push_back(a);
        // Se puede hacer asi, si se inicializa el tamaño del vector
        // vi personas(N);
        //cin >> personas[i];
    }
    // devuelve el numero de personas que se mueven a la otra puerta
    int ret = puertaExtra(personas); 
    if (ret == -1) cout << "NO\n";
    else cout << "SI " << N - ret << "\n"; // N-ret para calcular cuantos se quedan
}
/*
N [0,10.000]

Entrada:
8
10
2 4 6 8 10 1 3 5 7 9

5
6 2 3 0 1

5
1 3 5 7 9

10
1 3 5 7 10 1 3 5 7 9

5
2 4 6 8 10

0

1
1

1
2

Salida:
SI 5
NO
SI 0
NO
SI 5
SI 0
SI 0
SI 1

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