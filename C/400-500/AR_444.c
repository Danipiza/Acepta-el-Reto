#include <stdio.h>

int serpientes(int v[], int n, int k) {
    int maximo = 0;
    int a = 0, b = 1;
    int kAux = k;
    if (v[a] == 1) maximo = 1;

    if (n > 1) {
        while (b < n - 1) {
            if (v[a] == 0) {
                a++;
                if (a == b) {
                    kAux = k;
                    if (v[a] == 1) maximo = (maximo > 1) ? maximo : 1;
                    b++;
                }
            }
            else if (v[b] == 1) {
                maximo = (maximo > (b - a + 1)) ? maximo : (b - a + 1);
                b++;
                kAux = k;
            }
            else if (v[b] == 0 && kAux > 0) {
                b++;
                kAux--;
            }
            else {
                a++;
                maximo = (maximo > 1) ? maximo : 1;
                if (a == b) b++;
            }
            if (v[a] == 1 && v[b] == 1) maximo = (maximo > (b - a + 1)) ? maximo : (b - a + 1);
        }
        if (v[b] == 1) maximo = (maximo > 1) ? maximo : 1;
        if (v[a] == 1 && v[b] == 1) maximo = (maximo > (b - a + 1)) ? maximo : (b - a + 1);
    }

    return maximo;
}

int main() {
    int n, k, i;
    while (scanf("%d %d", &n, &k) == 2) {
        if (n == 0) break;

        int v[n];
        for (i = 0; i < n; i++) {
            scanf("%d", &v[i]);
        }

        int r = serpientes(v, n, k);
        printf("%d\n", r);
    }
    return 0;
}