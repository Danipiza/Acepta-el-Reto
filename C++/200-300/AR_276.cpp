#include <stdio.h>
#include <stdlib.h>
#include <errno.h>


int errno;
int i;
// No compruebo errores de funciones por el compilador de acepta el reto

struct pair {
    int first, second;
};

// Enunciado: Deborah quiere ver el mayor numero de peliculas 
//  en un cine, dado una planificacion. Para ello nos proporcionan
//  "N" el numero de peliculas que se proyectaran en el dia.
// Junto con "N" lineas, con la hora de inicio con formato XX:XX y la 
//  duracion de la pelicula. Teniendo en cuenta que al acabar la pelicula
//  Deborah tarda 10 minutos para comprar palomitas, cambiar de sala, ect
// Nos piden calcular el numero maximo de peliculas que puede ver en ese dia.

// Explicacion: Como nos piden calcular el numero maximo de peliculas
//  que puede ver en ese dia, implementamos un algoritmo voraz para calcular
//  la respuesta.
// Primero preprocesamos la salida, como tenemos el formato en horas y minutos lo
//  pasamos a minutos, multiplicando la hora de inicio por 60 y sumando los minutos 
//  de inicio. Luego lo ordenamos por orden ascendente.
// Una vez preprocesado recorremos el vector de peliculas y marcamos como vista la 
//  primera pelicula que pueda ver, con "fin" como la fecha de finalizacion de la misma.
// Seguimos procesando el vector, si puede ver la siguiente porque empieza antes
//  de fin + 10(mins por cambiar de sala) puede verla y lo a�ade. Si no puede verla
//  pero termina antes que la marcada anteriormente, cambiamos la pelicula por esta
//  para que tenga mas posibilidades de ver las posteriores. 

// Complejidad:
// - Preprocesaod: O(nlogn) ordenar por un algoritmo de divide y venceras como
//  puede ser QuickSort
// - Temporal: O(n), recorre el vector de n elementos
// - Espacial: O(2n+4) = O(n) vector de n pares.
int voraz(int n, struct pair pelis[]) {
    int ret = 1; // variable de retorno
    // variable con la finalizacion de la pelicula asignada anteriormente
    
    int fin = pelis[0].second; 
    int i = 1; // iteradores
    /*vector<int> ver(n, 0);
    ver[0] = 1;
    int idx = 0;*/
    while (i < n) { // O(n)
        // puede ver la pelicula siguiente
        //  porque empieza despues de que termine la que vio antes
        if (pelis[i].first >= fin + 10) { // O(1)
            fin = pelis[i].second;
            ret++; // incrementa las peliculas que puedever
            /*ver[1] = 1;
            idx = i;*/
        }
        // la pelicula termina antes que el "fin" actual
        //  lo cambia
        else if (pelis[i].second < fin) {
            fin = pelis[i].second;
            /*ver[idx] = 0;
            idx = i;*/
        }
        i++;
    }

    return ret;
}
// Demostracion por reduccion de diferencias
// X es el vector calculador por el algortimo voraz
// Y es el vector optimo
// Recorremos los vectores hasta encontrar una diferencia.
// Si X(i)!=Y(i), es porque una pelicula es elegida antes,
//  se actualiza el valor en Y por el de X. Por definicion 
//  del algoritmo voraz se cumple que como la parte procesada es igual
//  al del voraz, se pueda ver porque si no no estaria marcada.
// Al actualizar los valores se continua con el recorrido de los vectores
// Cuando llega al final son iguales, por lo que el algoritmo voraz
//  es optimo.
 

// Funcion comparacion para QuickSort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int resuelveCaso() {
    int N;
    scanf("%d", &N);
    // N==0, no hay mas planificaciones
    if (N == 0) return 0;
    
    // vector de parejas con el inicio y el final
    struct pair pelis[N]; 
    int ini, fin;
    int h, m; // variables locales, hora y minutos
    for (i = 0; i < N; i++) {
        scanf("%d:%d %d", &h, &m, &fin);        
        ini = h * 60 + m; // multiplica y añade los minutos
        fin += ini; // fin es la suma del inicio y la duracion        
        pelis[i].first = ini;
        pelis[i].second = fin;
    }
    // ordena el vector por orden ascendente de inicio 
    qsort(pelis,N,sizeof(struct pair), compare);

    printf("%d\n",voraz(N, pelis));

    return 1;
}
/*
N [0-1.000]
Ninguna pelicula termina despues de las 00:00 -> 24*60 = 1440

Entrada:
4
09:30 90
12:00 80
16:00 120
17:30 100

3
10:30 90
16:00 110
12:00 70

2
10:30 90
12:10 70

3
10:30 500
11:00 60
12:10 60

4
10:00 50
11:00 600
12:10 60
14:10 60

3
10:00 0
10:00 0
10:00 0

4
10:00 0
10:10 0
10:20 0
10:30 0

0

Salida:
3
2
2
2
3
1
4
*/

int main() {
    while (resuelveCaso());

    return 0;
}