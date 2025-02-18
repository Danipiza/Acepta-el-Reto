#include <stdio.h>



int sumDigitos(int numero) {
    int ret;

    if (numero/10==0) {
        ret=numero%10;
        printf("%d", numero);
    }
    else {
        ret=sumDigitos(numero/10)+(numero%10);
        printf(" + %d", numero%10);
    }
    
    return ret;
}

int solve() {
    int n;
    if (scanf("%d", &n)!=1 || n<0) return 0;

    int suma=sumDigitos(n);
    printf(" = %d\n", suma);

    return 1;
}

int main() {
    while (solve());

    return 0;
}