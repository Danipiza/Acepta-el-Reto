#include <stdio.h>
#include <stdlib.h>

int divisores_fact(int N, 
    int x1, int x2, 
    int y1, int y2) {
    if (x1==x2 && y1==y2) return 0;

    int ret=0;

    // No tienen la misma paridad, 
    //  el destino esta en una celda que nunca podra visitarse
    if ((x1+y1)%2!=(x2+y2)%2) ret=-1;
    else {
        // Si tienen la misma diferencia de distancias es por que esta
        //  en la misma diagonal, por lo que solo tiene que dar un paso.
        if (abs(x1-x2)==abs(y1-y2)) ret=1;
        else ret=2;
    }

    return ret;
}

int resuelveCaso() {
    int N, x1, x2, y1, y2;
    if (scanf("%d", &N)!=1 || N<=0) return 0;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    int salida=divisores_fact(N, x1, x2, y1, y2);

    if (salida==-1) printf("IMPOSIBLE\n");
    else printf("%d\n", salida);

    return 1;
}

int main() {
    while (resuelveCaso());
    return 0;
}