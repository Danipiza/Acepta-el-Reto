#include <stdio.h>


#define LADOS_CUADRADO 4

int fractales(int longitud, int numeroCuadrados) {
    int ret;
    
    if (longitud==1) ret=LADOS_CUADRADO*numeroCuadrados; 
    else {
        ret=fractales(longitud/2, LADOS_CUADRADO*numeroCuadrados) + 
                    numeroCuadrados*LADOS_CUADRADO*longitud;
    }
    
    return ret;
}

int solve() {
    int longitud;
    if (scanf("%d", &longitud)!=1) return 0;

    if (longitud==0) printf("0\n"); 
    else {
        int sumaLongitud=fractales(longitud, 1);
        printf("%d\n", sumaLongitud);
    }

    return 1;
}

int main() {
    while (solve());
    
    return 0;
}