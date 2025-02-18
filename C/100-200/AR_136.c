#include <stdio.h>
#include <stdbool.h>

int trolls(int fuerza, int n) {
    // CASO BASE
    if (fuerza * 2 >= n) return 0;

    // CASO RECURSIVO
    int auxI = n / 3;
    int auxD = n - auxI;
    
    if (auxD >= fuerza * 2) {
        if (auxI >= fuerza * 2) return trolls(fuerza, auxI) + trolls(fuerza, auxD) + 1;
        else return trolls(fuerza, auxD) + 1;
    }
    else return 1;
}

bool solve() {
    int fuerza, n;
    if (scanf("%d %d", &fuerza, &n) != 2) return false;
    if (fuerza == 0)
        return false;

    
    int r = trolls(fuerza, n);

    
    printf("%d\n", r);

    return true;
}

int main() {
    while (solve());

    return 0;
}