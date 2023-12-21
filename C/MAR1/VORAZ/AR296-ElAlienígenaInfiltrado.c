#include <stdio.h>
#include <stdlib.h>
#include <errno.h>


int errno;
int i;
// No compruebo errores de funciones por el compilador de acepta el reto

struct pair {
    int first, second;
};

// Enunciado: Nos dan 3 enteros "C", "F", enteros de un intervalo y "N" numero de tareas.
//  Tenemos que calcular el minimo numero de tareas para rellenar elintervalo [C,F), 
//  si no se puede imprimimos Imposible. 
// Para terminar el enunciado nos proporciona N lineas, cada una corresponde a la tarea
//  i-esima, con 2 enteros "c" y "f" cuando empieza y acaba cada una.


// Explicacion:
// Usamo un algoritmo voraz, para ello necesitamos que el algoritmo este ordenado
//  por orden creciente de comienzo de cada tarea. 
// Coste de preprocesado: O(nlogn) algoritmo de ordenacion, como puede ser QuickSort
// Para calcular el numero de tareas necesario miramos si la primera tarea empieza antes
//  que "C", si no empieza antes o al mismo tiempo, no se puede -> Imposible.
// 
// Procesamos todas las tareas que empiezan al mismo tiempo que "C" para guardar en "fin"
//  la tarea que termine mas tarde.
// Una vez procesado la parte inicial, recorremos la parte restante del vector de tareas 
//  y por cada iteracion buscamos la tarea que termine m�s tarde, de entre las no procesadas que
//  empiecen antes que "fin". El tiempo mas longevo se almacena en "fin" para seguir con el algoritmo.
// Complejidad Espacial: O(2n+6) = O(n). 
//  Por el vector de tareas, n tareas con 2 enteros, y las variables locales
// Complejidad Temporal: O(n) en el caso peor mira todas las tareas.
int voraz(int n, int C, int F, struct pair trabajos[]) {
    // Entero de retorno, si ret==-1 Imposible
    int ret = (trabajos[0].first > C ? -1 : 0); 
    int act = 0;                    // numero actual de tareas usadas
    int fin = trabajos[0].second;   // tiempo mas longevo abarcado actualmente
    int i = 1;                      // iteradores para recorrer el vector

    // vector<int> usados(n, 0); ver que tareas se usan para comprobar la optimalidad
    // int iUsado;
    
    // Procesa las tareas que empiezan antes que C
    while (i < n && !ret && trabajos[i].first <= C) {
        // Si la tarea i-esima termina mas tarde, se cambia en fin
        if (fin < trabajos[i].second) {
            fin = trabajos[i].second;
            //iUsado=i;
        }
        i++;
    }  
    // usados[iUsado] = 1; se marca la tarea usada
    
    // Se puede abarcar el intervalo con 1 tarea
    // ret == -1 porque puede haber una tarea que no empiece antes que "C" 
    //  pero si finalice despues de "F"
    if (fin >= F && ret != -1) ret = 1;
    act++; // suma la primera tarea usada
    int tmp;
    while (i < n && !ret) {
        // variable para almacenar el mas longevo de entre las posibles tareas
        tmp = fin;
        // Si la tarea i-esima empieza antes que "fin" procesa 
        if (trabajos[i].first <= fin) {
            // procesa mientras las tareas empiecen antes que fin
            do {
                // Si la tarea i-esima termina mas tarde, se cambia en fin
                if (tmp < trabajos[i].second) { 
                    tmp = trabajos[i].second;
                    //iUsado=i;
                    if (tmp >= F) ret = act + 1; // devuelve el numero de tareas usados
                }
                i++;
            } while (i < n && !ret && trabajos[i].first <= fin);
            fin = tmp;
            // usados[iUsado] = 1; se marca la tarea usada
        }
        else ret = -1; 
        act++;        
    }
    // Se procesan todos los datos y no se puede abarcar el intervalo
    if (ret == 0) ret = -1;
    return ret;
}


// Demostrar que la estrategia elegida es optima:
// Demostracion por reduccion de diferencias. Ambas ordenadas.
// X es el calculado con el algoritmo voraz.
// Y es el optimo.
// Miramos ambos vectores hasta que en una tarea no sean iguales. 
//  X[i]!=Y[i] en una se coge la tarea y otra no. La tarea j-esima usada en Y esta 
//  mas a la izquierda que en X. Movemos en Y a la posicion de X. 
// No dejamos sin cubrir ningun punto del intervalo ya que la voraz se encarga de que lo cumpla.
// Sigue siendo solucion y optima.
// Procedemos asi hasta que el vector Y sea igual al X. Por lo que si es optimo.

// Funcion comparacion para QuickSort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int resuelveCaso() {
    int C, F, N;
    scanf("%d %d %d", &C, &F, &N);
    //if (errno != 0) perror("scanf, C F N\n"); 
    if (!C && !F && !N) return 0; // centinela

    struct pair trabajos[N];
    for (i = 0; i < N; i++) {
        scanf("%d %d", &trabajos[i].first, &trabajos[i].second);   
        //if (errno != 0) perror("scanf, vector\n");      
    }
    qsort(trabajos, N, sizeof(struct pair), compare);

    // Si N == 0 no se puede completar el intervalo, 
    //  sabemos que C y F son distintos de 0 por la centinela
    int ret = (N > 0 ? voraz(N, C, F, trabajos) : -1);

    if (ret == -1) printf("Imposible\n");
    else printf("%d\n", ret);

    return 1;
}

/* Ejemplos de casos
1 10 4
2 8
0 5
7 11
5 10

0 3 2
0 1
2 3

0 10 3	
0 1
1 9
9 9

1 10 2
2 10
2 15

0 10 5
0 2
2 4
4 6
6 8
8 10
0 0 0

Salida:
2
Imposible
Imposible
Imposible
5
*/


int main() {
    while (resuelveCaso());

    return 0;
}