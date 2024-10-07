#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1024

int M[MAX_N][MAX_N];


// El enunciado nos pide calcular si un cuadrado es diabolico, esoterico o normal.
// Para que un cuadrado sea diabolico, la suma de los números por columna, fila y 
//  diagonales principales sea la misma. A esta suma se le llama constante mágica (CM)
// 
// Para que un cuadrado sea esoterico, primero tiene que ser diabolico y luego ha de cumplir
//  las siguientes propiedades.
// 1. El cuadrado tiene que tener todos los elementos de 1 a n^2.
// 2. La suma de sus esquinas debe ser la constante mágica 2 (CM2) que cumple que: CM2=4*CM/n
// 3. La siguiente propiedad se divide en n=par o impar.
// 3a. n = Impar:
//      La suma de las cifras de las cuatro casillas de la mitad de los laterales suman CM2.
//      Si se multiplica el valor de la casilla central por 4, se obtiene CM2.
// 3b. n = Par:
//      La suma de las dos casillas centrales de cada uno de los cuatro laterales suman el doble de CM2.
//      La suma de las cuatro casillas centrales da como resultado CM2.




// Explicacion: Creamos dos funciones una para comprobar si es diabolico y otro para ver si es esoterico.
// 
// Diabolico: Hay que recorrer la matriz entera 2 veces y las diagonales, para comprobar que las sumas coinciden.
//  Para ello primero recorremos una fila y guardamos el valor, recorremos las demas filas y comprobamos si coinciden
//  Luego recorremos las columnas y posteriormente las diagonales.
// Si todas las sumas coinciden el cuadrado es diabolico, si en alguna no concidio, devuelve false y es un cuadrado normal.
//
// Esoterico: Si la funcion anterior devolvio true, entonces si puede ser esoterico, y entra a la funcion.
//  - La primera propiedad se puede comprobar con un set<int> o añadiendo en un vector todos los elementos de la matriz
//      para ordenarlo y comprobar linealmente si falta alguno, empezando por el primer elemento (v[0]=1) y terminando en 
//      en el ultimo (v[(n*n)-1]=n*n]). Estas soluciones tienen costes O(N^2NLogN) y (N^2 + NlogN) respectivamente, 
//      y se puede mejorar usando programacion dinamica. Se crea un vector de enteros con n*n+1 0s, se recorre la 
//      matriz entera comprobando si el elemento actual ya ha sido añadido previamente, si ya se añadio se acaba, pues no
//      cumple con la propiedad. Usando programacion dinamica se reduce la complejidad hasta O(n^2)
// 
//  - La segunda propiedad es mas facil, pues solo es una comprobacion de una suma.
// 
//  - La tercera propiedad hay que comprobar la paridad (n%2==0 ? par : impar) para luego comprobar las sumas a realizar.
//      Si es impar la suma de laterales solo se hace con la mitad, y el centro es una unica comprobacion en M[mitad][mitad].
//      Si es par hay que sumar las posiciones mitad y mitad-1 de los laterales, asi como en el centro del cuadrado.
//



// Complejidad: 
// - Espacial: O(1) solo se usan enteros.
// - Temporal: O(2(N^2) + 2N) = O(N^2) 
//    Se recorre 2 veces la matriz entera y 1 vez las diagonales principales

// Precondicion: Cuando se puede ejecutar la funcion
// Pre = { 2 <= n <= 1024 }
int es_diabolico(int n, int* CM) {
    int i, j;
    
    *CM=0;
    int sum=0;
    

    // --- Filas -----------------------------------------------------------    
    for (j=0;j<n;j++) *CM+=M[0][j];
    
    // ya no hace falta recorrer la primera fila
    for (i=1;i<n;i++) { // O(N^2)
        sum=0;
        for (j=0;j<n;j++) {
            sum+=M[i][j];
        }
        if (sum!=*CM) return 0;
    }
    
    // --- Columnas --------------------------------------------------------
    for (j=0;j<n;j++) { // O(N^2)
        sum=0;
        for (i=0;i<n;i++) {
            sum+=M[i][j];
        }
        if (sum!=*CM) return 0;
    }
    
    // --- Diagonales ------------------------------------------------------
    sum=0;
    for (i=0;i<n;i++) sum+=M[i][i]; // O(n)
    
    if (sum!=*CM) return 0;
    
    sum=0;
    for (i=0;i<n;i++) sum+=M[i][n-1-i]; // O(n)

    if (sum!=*CM) return 0;
    
    return 1;
}

// Complejidad: 
// - Espacial: O(N^2). Para almacenar en un vector 1..n^2 elementos.
// - Temporal: O(N^2). Recorre toda la matriz para comprobar la primera propiedad.
//              Si se usa un set<int> seria la misma complejidad espacia pero la
//              complejidad temporal aumentaria a O(2*N^2*LogN) al insertar y comprobar
//              si un valor esta en el set tiene coste NLogN.

// Precondicion: Cuando se puede ejecutar la funcion
// Pre = { 2 <= n <= 1024 }
int es_esoterico(int n, int CM) {
    int i, j;
    
    int CM2, pot, sum;
    
    // --- Propiedad 1 ------------------------------------------------------
    
    // 1 + 2 + ... + n = n*(n+1)/2
    // No se puede hacer. Si n = 4 y 1 + 1 + 4 + 4 = 10. 
    // Cumpliendo la suma pero no la propiedad

    // Programacion Dinamica para almacenar los numeros
    pot=n*n;
    int* dp=(int*)calloc(pot+1, sizeof(int));
    for (i=0;i<n;i++) {
        for (j=0;j<n;j++) {
            int valor=M[i][j];
            if (valor<=0 || valor>pot || dp[valor]) {
                free(dp);
                return 0;
            }
            dp[valor]=1;
        }
    }
    free(dp);
    
    // --- Propiedad 2 -----------------------------------------------------
    CM2=(4*CM)/n;
    
    // Suma de esquinas
    sum=M[0][0]+M[0][n-1]+M[n-1][0]+M[n-1][n-1];
    if (sum!=CM2) return 0;
    
    // --- Propiedad 3 -----------------------------------------------------
    int mitad=n/2;

    if (n%2==1) { // Si n es impar
        // Suma de laterales
        sum=M[0][mitad]+M[n-1][mitad]+M[mitad][0]+M[mitad][n-1];
        
        // Comprobacion de suma y el centro
        if (sum!=CM2 || M[mitad][mitad]*4!=CM2) return 0;
    } else { // Si n es par  
        
        // Suma de laterales
        sum=M[0][mitad-1]+M[0][mitad]+ 
            M[n-1][mitad-1]+M[n-1][mitad]+
            M[mitad-1][0]+M[mitad][0]+ 
            M[mitad-1][n-1]+M[mitad][n-1];
        
        // Comprobacion de suma
        if (sum != 2 * CM2) return 0;
        
        // Suma de las cuatro celdas del centro
        sum=M[mitad-1][mitad-1]+M[mitad-1][mitad]+
            M[mitad][mitad-1]+M[mitad][mitad];

        if (sum!=CM2) return 0;
    }
    
    return 1;
}

/*

3
4 9 2 3 5 7 8 1 6
2
1 2 3 4
4
16 3 2 13 5 10 11 8 9 6 7 12 4 15 14 1
3
28 21 26 23 25 27 24 29 22
3
2 8 1 6 3 5 7 4 9

7
22 47 16 41 10 35 4 5 23 48 17 42 11 29 30 6 24 49 18 36 12 13 31 7 25 43 19 37 38 14 32 1 26 44 20 21 39 8 33 2 27 45 46 15 40 9 34 3 28
8
1 63 62 4 5 59 58 8 56 10 11 53 52 14 15 49 48 18 19 45 44 22 23 41 25 39 38 28 29 35 34 32 33 31 30 36 37 27 26 40 24 42 43 21 20 46 47 17 16 50 51 13 12 54 55 9 57 7 6 60 61 3 2 64

0
*/

int resuelveCaso() {
    int i, j;

    int n;
    scanf("%d", &n);
    if (n==0) return 0;
    
  
    for (i=0;i<n;i++) {
        for (j=0;j<n;j++) {
            scanf("%d", &M[i][j]);
        }
    }
    
    int CM;
    if (es_diabolico(n, &CM)) {
        if (es_esoterico(n, CM)) printf("ESOTERICO\n");         
        else printf("DIABOLICO\n");        
    } else printf("NO\n");
    
    return 1;
}

int main() {
    while (resuelveCaso());
    
    return 0;
}