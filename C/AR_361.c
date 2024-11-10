#include <stdio.h>
#include <stdint.h>

void operaciones(
    // DESCRIPCCION
    const int *v, int num, 
    // SOL PARCIAL
	int numP,
	// MARCAJE
	int k,
	// SOLUCION
    int *fin) {    
    
    // CASO BASE
    if (k>=5) {
        if (numP==num) *fin=1;

        return;
    }


    // CASOS RECURSIVOS
    // SUMA
    if (!(*fin)) {
        operaciones(v, num, numP+v[k], k+1, fin);
    }
    // RESTA
    if (!(*fin)) {
        operaciones(v, num, numP-v[k], k+1, fin);
    }
    // MULTIPLICACION
    if (!(*fin)) {
        operaciones(v, num, numP*v[k], k+1, fin);
    }
    // DIVISION
    if (v[k]!=0 && *fin && numP%v[k]==0) {
        operaciones(v, num, numP/v[k], k+1, fin);
    }
}

int resuelveCaso() {
    int i;

    int n;
    if (scanf("%d", &n)!=1) return 0;

    int v[5];
    for (i=0;i<5;i++) scanf("%d", &v[i]);

    int fin=0;
    operaciones(v, n, v[0], 1, &fin);

    if (!fin) printf("NO\n");
    else printf("SI\n");

    return 1;
}

int main() {
    while (resuelveCaso());

    return 0;
}
