#include <stdio.h>
#include <stdlib.h>


int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int voraz(int peso, const int *personas, int n) {
    int ret=0;
    int i=0, j=n-1;
    while (i<=j) {
        if (personas[i]+personas[j]<=peso) {
            i++;
            j--;
        } 
        else j--;

        ret++;
    }
    return ret;
}

int resuelveCaso() {
    int i;

    int peso, N;
    if (scanf("%d %d", &peso, &N)!=2) return 0;
    if (peso==0 && N==0) return 0;

    int *personas=(int *)malloc(N*sizeof(int));
    
    for (i=0;i<N;i++) scanf("%d", &personas[i]);
    
    qsort(personas, N, sizeof(int), compare);

    printf("%d\n", voraz(peso, personas, N));

    free(personas);
    return 1;
}

int main() {
    while (resuelveCaso());
    return 0;
}
