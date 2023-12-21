#include <stdio.h>
#include <stdlib.h>
#include <errno.h>


int errno;
// No compruebo errores de funciones por el compilador de acepta el reto

// Enunciado: Tenemos una manguera con "N" agujeros, para
//  taparlos tenemos muchos parches de una longitud "L". 
// Los agujeros vienen dados en la segunda linea de cada caso
//  "N" enteros seguidos de espacios en blanco. Y ya vienen
//  ordenados en la entrada.
// El problema nos pide calcular el numero minimo de parches
//  necesarios para tapar todos los agujeros de la manguera.

// Explicacion: Para resolver el problemas vamos a implementar
//  un algortimo voraz, para calcular el numero minimo de parches necesarios.
// Como tenemos "N" agujeros empezamos por el primero sumando "L" (la longitud
//  del parche) a su posicion y comprobamos cuantos agujeros podemos tapar con
//  el parche actual, cuando no se puedan tapar mas pasamos al siguiente y repetimos
//  el proceso, asií hasta tapar los "N" agujeros.
// Implemento con 2 bucles, el principal termina cuando ya ha visitado los "N" agujeros
//  y el bucle interno es el que comprueba cuantos agujeros se pueden tapar con el 
//  parche actual.
// Complejidad: 
// - Temporal: O(n) ya que recorremos los "N" agujeros
// - Espacial: O(n+5) = O(n), 5 son las variables locales.
int voraz(int n, int L, int v[]) {
    int ret = 0; // variable de retorno
    int i = 1; // iteradores del vector
    int act; // posicion actual del agujero
	//vi parches(n,0);
    while (i<n) {
        act = v[i - 1];
        // mientras que la posicion del actual sea menor o igual
        //  a la suma de la longitud del parche se avanza en el
        //  vector, ya que se puede tapar
        while (i < n && v[i] - act <= L) { i++; /*parches[i]=ret+1;*/} 
        ret++;
        i++;
    }
    // no ha comprobado el ultimo por lo que se suma otro parche
    if (i == n) { /*parches[i-1]=ret+1;*/ ret++; }
    return ret;
}
// Demostracion de optimalidad: por reduccion de diferencias
// X es el vector de parche usado para la posicion i-esima
//  calculado con el algoritmo voraz
// Y es el vector optimo
// Recorremos los vectores y cuando los valores no coincidan (X[i]!=Y[i])
//  movemos el valor Y a la izquierda, por el que esta en X. 
// El parche usado cubre otras posiciones por lo que cambia tambien los 
//  valores en Y. Continua como antes.
// El resultado es igual por lo que el algoritmo es optimo.

int resuelveCaso() {
    int N, L; // numero de agujeros y longitud del parche
    // no hay mas datos por leer, se acaba
    if(scanf("%d %d",&N,&L)==-1) return 0;
    
    int i = 0;
    int v[N];
    for (; i < N; i++) { scanf("%d", &v[i]); }

    printf("%d\n",voraz(N, L, v));

    return 1;
}
/*
N [1, 100.000]
L [1, 1.000]
posiciones de los agujeros = [0, 1.000.000.000] se puede hacer con int

Entrada:
3 2
1 6 10

3 1000
1 6 10

3 1000
1 1001 2001

3 1000
1 1002 2003

3 5
1 7 10

8 10
3 8 8 9 20 45 55 90

5 1
1 3 4 5 5

5 1
1 3 5 7 7

5 1
1 3 5 7 9

Salida:
3
1
2
3
2
4
3
4
5
*/


int main() {
    while(resuelveCaso());

    return 0;
}
