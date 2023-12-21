#include <stdio.h>
#include <stdlib.h>
#include <errno.h>


int errno;
// No compruebo errores de funciones por el compilador de acepta el reto

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
int puertaExtra(int n, int personas[]) {        
    int i = 1; // iterador
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
            if (tmp) puede = 0;
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
    scanf("%d", &N);
    int personas[N];
    int i = 0;
    for (; i < N; i++) {        
        scanf("%d", &personas[i]);
    }
    // devuelve el numero de personas que se mueven a la otra puerta
    int ret = puertaExtra(N, personas); 
    if (ret == -1) printf("NO\n");
    else printf("SI %d\n",(N - ret)); // N-ret para calcular cuantos se quedan
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


    int numCasos, i = 0;
    scanf("%d",&numCasos);
    for (; i < numCasos; i++) resuelveCaso();



    return 0;
}