#include <stdio.h>
#include <string.h>

// Enunciado: 

// Explicacion: 

// Complejidad:
// - Preprocesaod: O(nlogn) ordenar por un algoritmo de divide y venceras como
//  puede ser QuickSort
// - Temporal: O(n), recorre el vector de n elementos
// - Espacial: O(2n+4) = O(n) vector de n pares.
int voraz(const char* carretera) {
    int ret=0;
    int i=0, n=strlen(carretera);

    while (i<n) {
        if (carretera[i]=='.') {
            ret++;
            i += 2;
        }

        i++;
    }

    return ret;
}
// Demostracion por reduccion de diferencias
// TODO


void resuelveCaso() {
    char carretera[10001];  
    scanf("%s", carretera);
    printf("%d\n", voraz(carretera));
}

int main() {
    int i;

    int nCase;
    scanf("%d", &nCase);
    for (i=0;i<nCase;i++) resuelveCaso();

    return 0;
}