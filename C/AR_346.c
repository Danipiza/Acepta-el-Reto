#include <stdio.h>
#include <stdlib.h>


int max(int a, int b) { return (a>b) ? a:b; }

// Pre: true
int dedos(const int* v, int size, int A) {
    int ret =0;
    int a      =0;
    int b      =1;
    int aux    =1;
   
    while (b<size) {
        if (v[b]<=v[a]+A-1) {
            aux++;
            b++;
        }
        else {
            a++;
            ret=max(ret, aux);
            aux--;
        }
    }

    ret=max(ret, aux);

    return ret;
}
// Pos: r = Sum k: 0 <= k < v.size(): v[k]

int solve() {
    int i;

    int N=0, A=0;
    scanf("%d %d", &N, &A);
    if (N==0 && A==0) return 0;

    int v[N];
    for (i=0;i<N;i++) scanf("%d", &v[i]);
    
    int r=dedos(v, N, A);

    printf("%d\n", r);

    return 1;
}

int main() {
    while (solve());

    return 0;
}