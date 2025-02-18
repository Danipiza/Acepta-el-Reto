#include <stdio.h>
#include <stdlib.h>

int voraz(int L, int* v, int n) {
    int ret=0;
    int i  =1;

    int act;
    while (i<n) {
        act=v[i-1];
        while (i<n && v[i]-act<=L) i++;
        ret++;

        i++;
    }

    if (i==n) ret++;

    return ret;
}

int resuelveCaso() {
    int i;

    int N, L;
    if (scanf("%d %d", &N, &L)!=2) return 0;
    
    int* v=(int*)malloc(N*sizeof(int));
    for (i=0;i<N;i++) scanf("%d", &v[i]);

    printf("%d\n", voraz(L, v, N));

    free(v);
    return 1;
}

int main() {
    while (resuelveCaso());

    return 0;
}