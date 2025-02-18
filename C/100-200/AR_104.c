#include <stdio.h>

int movil(int* sumNodos, int* fin) {
    int pi=0, di=0, pd=0, dd=0;

    scanf("%d %d %d %d", &pi, &di, &pd, &dd);
    if (pi==0 && di==0 && pd==0 && dd==0) {
        *fin=1;
        return 0;
    }

    // CASO BASE
    if (pi!=0 && pd!=0) { // MOVIL SIN SUBMOVILES
        *sumNodos+=pi+pd;
        if (pi*di==pd*dd) return 1;
        else return 0;
    }

    // CASO RECURSIVO    
    // IZQ
    int izq=1;
    int izqNodos=pi;
    if (pi==0) {
        izq=movil(&izqNodos, fin);
    }

    // DERECHA
    int der=1;
    int derNodos=pd;
    if (pd==0) der=movil(&derNodos, fin);
    *sumNodos=izqNodos+derNodos;

    return izqNodos*di==derNodos*dd && izq && der;
}

int solve() {
    int sumNodos=0;
    int fin=0;

    if (movil(&sumNodos, &fin)) printf("SI\n");
    else if (fin) return 0;
    else printf("NO\n");
    
    return 1;
}

int main() {
    while (solve()) {}
    return 0;
}