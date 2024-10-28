#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int first;
    int second;
} Pair;

int comparePairs(const void *a, const void *b) {
    Pair *pairA=(Pair *)a;
    Pair *pairB=(Pair *)b;

    return (pairA->first - pairB->first);
}

int voraz(Pair edificios[], int n) {
    int i;

    int ret=1;
    int fin=edificios[0].second;

    for (i=1;i<n;i++) {
        if (edificios[i].first<fin) {
            if (fin>edificios[i].second) fin=edificios[i].second;
        } 
        else {
            ret++;
            fin=edificios[i].second;
        }
    }

    return ret;
}

int resuelveCaso() {
    int i;

    int N;
    if (scanf("%d", &N)!=1 || N==0) return 0;

    Pair edificios[N];
    for (i=0;i<N;i++) {
        scanf("%d %d", &edificios[i].first, &edificios[i].second);
    }

    qsort(edificios, N, sizeof(Pair), comparePairs);

    printf("%d\n", voraz(edificios, N));
    return 1;
}

int main() {
    while (resuelveCaso());
    
    return 0;
}
