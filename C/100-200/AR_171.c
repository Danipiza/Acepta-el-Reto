#include <stdio.h>
#include <stdlib.h>


int numAbadias(int* v, int size) {
    int i;

    int ret=1, max=v[size-1];
    
    for (i=size-2;i>=0;i--) {
        if (v[i]>max) {
            ret++;
            max=v[i];
        }
    }

    return ret;
}

int resuelveCaso() {
    int i;

    int n;
    scanf("%d", &n);

    if (n==0) return 0;

    int* v=(int*)malloc(n*sizeof(int));
    for (i=0;i<n;i++) scanf("%d", &v[i]);

    printf("%d\n", numAbadias(v, n));

    free(v);
    return 1;
}

int main() {
    while (resuelveCaso());
    return 0;
}