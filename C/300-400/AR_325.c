#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PREFIX_LEN 100
#define MAX_RESULTS 10000

void cucurucho(
        char *prefix, 
        int C, int V, 
        // SOLUCION PARCIAL
        int kC, int kV, 
        // SOLUCION
        char **ret, int *retSize) {

    if (kC==C && kV==V) { // CASO BASE
        ret[*retSize]=strdup(prefix);
        (*retSize)++;

        return;
    }

    // CASO RECURSIVO
    char newPrefix[MAX_PREFIX_LEN];
    if (kC<C) {
        snprintf(newPrefix, sizeof(newPrefix), "%sC", prefix);
        cucurucho(newPrefix, C, V, kC+1, kV, ret, retSize);
    }
    if (kV<V) {
        snprintf(newPrefix, sizeof(newPrefix), "%sV", prefix);
        cucurucho(newPrefix, C, V, kC, kV+1, ret, retSize);
    }
}

void resuelveCaso() {
    int i;

    int C, V;
    scanf("%d %d", &C, &V);

    char *ret[MAX_RESULTS];
    int retSize=0;

    cucurucho("", C, V, 0, 0, ret, &retSize);

    for (i=0;i<retSize;i++) {
        printf("%s", ret[i]);
        free(ret[i]);
        if (i<retSize-1) printf(" ");
    }

    printf("\n");
}

int main() {
    int i;

    int n;
    scanf("%d", &n);
    for (i=0;i<n;i++) resuelveCaso();

    return 0;
}
