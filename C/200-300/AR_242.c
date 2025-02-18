#include <stdio.h>
#include <stdlib.h>


// Pre: 1
long long int erasmus(const int* v, int size) {
    int i;

    long long int ret=0;
    
    if (size!=1) {
        long long int sum=v[size-1];
        for (i=size-2;i>=0;i--) {
            ret=ret+v[i]*sum;
            sum=sum+v[i];
        }
    }

    return ret;
}
// Pos: r = Sum k: 0 <= k < v.size(): v[k]

int resuelveCaso() {
    int i;

    int n;
    scanf("%d", &n);
    if (n==0) return 0;

    int* v=(int*)malloc(n*sizeof(int));
    for (i=0;i<n;i++) scanf("%d", &v[i]);

    
    printf("%lld\n", erasmus(v, n));

    free(v);
    return 1;
}

int main() {
    while (resuelveCaso());

    return 0;
}