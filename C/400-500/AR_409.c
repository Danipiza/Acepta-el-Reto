#include <stdio.h>
#include <stdlib.h>


int compare(const void* a, const void* b) {
    return (*(int*)a-*(int*)b);
}


int voraz(int num, const int* integrantes, int n) {
    int ret=0;
    int i=num-1;

    while (i<n) {
        if (integrantes[i]-integrantes[i-num+1]<=15) {
            ret++;
            i+=num-1;
        }
        i++;
    }

    return ret;
}

void resuelveCaso() {
    int i;
    int num, N;
    scanf("%d %d", &num, &N);

    int* integrantes=(int*)malloc(N*sizeof(int));
    for (i=0;i<N;i++) scanf("%d", &integrantes[i]);

    qsort(integrantes, N, sizeof(int), compare);

    printf("%d\n", voraz(num, integrantes, N));

    free(integrantes);
}

int main() {
    int i;
    int nCase;
    scanf("%d", &nCase);
    for (i=0;i<nCase;i++) resuelveCaso();

    return 0;
}
