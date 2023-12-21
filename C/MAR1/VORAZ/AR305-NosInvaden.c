#include <stdio.h>
#include <stdlib.h>
#include <errno.h>


int errno;
int i;
// No compruebo errores de funciones por el compilador de acepta el reto


// Enunciado: Estan invadiendo ciudades, y tenemos que
//  garantizar la victoria en el numero maximo de ciudades.
// Para garantizar la victoria se necesitan como minimo las mismas
//  unidades defensoras que invasoras.
// El enunciado nos da "N" el entero de ciudades invadidas.
// Y luego 2 lineas, la primera de estas es el numero de tropas por grupo
//  de defensores y la siguiente linea es la de los defensores.
 
// Explicacion: Para resolver el problema ordenamos por orden creciente
//  ambos vectores "inv" y "def" para con un algoritmo voraz calcular 
//  el numero maximo de ciudades que se puede garantizar la victoria.
// Una vez ordenado vamos seleccionando el primer grupo de defensores
//  que gana al grupo de invasores sin asignar.
// Tenemos 1 bucle que recorre los "N" grupos de defensores, si el actual 
//  grupo de defensores no gana al gurpo mas pequeño de invasores sin asignar
//  descartamos dicho grupo y pasamos al siguiente. Si el grupo garantiza
//  la victoria se le asigna y pasa al siguiente grupo en invasores y defensores.

// Complejidad:
// - Preprocesado: O(2(nlogn)) = O(nlogn) ya que se ordenan los 2 vectores de tamaño n
//  se puede implementar este coste con un algoritmo de ordenacion por divide y venceras 
//  como puede ser QuickSort
// - Temporal: O(n) en el caso peor recorre el vector defensor entero
// - Espacial: O(2n) = O(n), ya que tenemos 2 vectores de tamaño n
int voraz(int n, int inv[], int def[]) {
    int ret = 0; // variable de retorno
    int i = 0, j = 0; // iteradores del bucle
    //vi asignado(n, -1);
    while (i<n) { 
        // el defensor i-esimo puede con el invasor j-esimo
        // incrementa en 1 el valor de retorno y avanza en ambos vectores.
        if (inv[j] <= def[i]) {
            //asignado[i] = j;
            ret++;            
            i++; j++;
        }
        else i++;
    }
    
    return ret;
}
// Demostracion de optimalidad por reduccion de diferencias
// X es el vector calculado por el algoritmo voraz
// Y es el vector optimo
// Recorremos ambos vectores, hasta encontrar valores distintos (X[i]!=Y[i])
// X[i]==-1 && Y[i]!= -1 || X[i]!=-1 && Y[i]== -1, se le asigno a otro grupo 
//  defensa, por lo que intercambiamos los valores, es decir, Y[i]==-1 y Y[Y[i]]=X[i].
// Seguimos con el proceso hasta que sean iguales. Esto lo va a cumplir por como
//  esta construido el algoritmo voraz, siempre asigna la victoria al primero que pueda.
// Al terminar los vecoters son iguales por lo que el algoritmo voraz es optimo

// Funcion comparacion para QuickSort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int resuelveCaso() {
    int N;
    if(scanf("%d", &N)==-1) return 0;
    int inv[N];
    int def[N];
    // vector con "N" invasores
    for (i = 0; i < N; i++) { scanf("%d",&inv[i]); }
    // vector con "N" defensores
    for (i = 0; i < N; i++) { scanf("%d",&def[i]); }             
    
    // Preprocesado, ordenacion de los vectores
    qsort(inv,N,sizeof(int),compare);
    qsort(def,N,sizeof(int),compare);
    
    printf("%d\n", voraz(N,inv,def));

    return 1;
}

/*
N [1, 100.000]
L [1, 1.000]
numero de tropas en cada grupo = [1, 1.000.000] se puede hacer con int
Entrada:
4
40 20 80 30
25 50 35 40

4
40 50 60 70
99 25 30 50

2
11 11
10 10

2
10 10
10 10

2
10 10
11 11

3
1000000 1000000 1000000
1000000 1000000 1000000
3
1000000 1000000 1000000
999999 999999 999999

3
999999 999999 999999
1000000 1000000 1000000

Salida:
3
2
0
2
2
3
0
3
*/


int main() {
    while (resuelveCaso());

    return 0;
}
