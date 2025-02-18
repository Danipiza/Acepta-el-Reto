#include <stdio.h>
#include <stdlib.h>

// Function to compare integers for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a-*(int*)b);
}

int voraz(int* inv, int* def, int n) {
    int i=0, j=0;

    int ret=0;
    
    
    qsort(inv, n, sizeof(int), compare);
    qsort(def, n, sizeof(int), compare);
    
    while (i<n) {

        if (inv[j]<=def[i]) {
            ret++;
            i++; j++;
        } 
        else i++;
    }
    
    return ret;
}

int resuelveCaso() {
    int i;

    int N;
    if (scanf("%d", &N)!=1) return 0;
    
    int* inv=malloc(N*sizeof(int));
    int* def=malloc(N*sizeof(int));
    
    for (i=0;i<N;i++) scanf("%d", &inv[i]);
    for (i=0;i<N;i++) scanf("%d", &def[i]);
    
    printf("%d\n", voraz(inv, def, N));
    
    free(inv);
    free(def);
    
    return 1;
}

int main() {
    while (resuelveCaso());
    
    return 0;
}