#include <stdio.h>
#include <stdlib.h>

int sum(const int *v, int size) {
    int i;

    int ret=0;
    for (i=0;i<size;i++){
        ret+=v[i];
    }

    return ret;
}

int solve() {
    int i;

    int n;
    if (scanf("%d", &n)!=1 || n==0) return 0;

    int x, maxGlobal, maxNinos, ninos=1;
    scanf("%d", &x);
    maxGlobal=maxNinos=x;

    for (i=1;i<n;i++) {
        scanf("%d", &x);

        if (x>maxGlobal) maxGlobal=x;
        if (x<=maxNinos) {
            ninos=i+1;
            maxNinos=maxGlobal;
        }
    }

    printf("%d\n", ninos);
    return 1;
}

int main() {
    while (solve());
    
    return 0;
}
