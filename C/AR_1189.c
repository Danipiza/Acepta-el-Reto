#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int embarque(int* v, int* size, int N) {
    int i=0, j=0;

    for (i=0;i<*size;i++) {
        if (v[i]!=N) {
            v[j++]=v[i];
        }
    }

    *size=j;
    return *size;
}

int solve() {
    int i;

    int n;
    scanf("%d", &n);
    if (n==0) return 0;

    int* v=(int*)malloc(n*sizeof(int));
    for (i=0;i<n;i++) scanf("%d", &v[i]);
        
    int nAcciones;
    scanf("%d", &nAcciones);
    char accion[10];
    int numAccion;
    for (i=0;i<nAcciones;i++) {
        scanf("%s %d", accion, &numAccion);
        if (strcmp(accion, "EMBARQUE")==0) {            
            printf("%d\n", embarque(v, &n, numAccion));
        }
        else if (strcmp(accion, "CONSULTA")==0 && n>0) {
            printf("%d\n", v[numAccion-1]);
        }
    }
    
    printf("*\n");

    free(v);
    return 1;
}

int main() {
    while (solve());
    return 0;
}