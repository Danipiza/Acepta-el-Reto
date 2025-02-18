#include <stdio.h>

int divisores_fact(int p, int n) {
    int ret=0;

    if ((p==1 || p<=n) && p>=0 && n>=0) ret=1;
    else ret=0;

    return ret;
}

int resuelveCaso() {
    long long int p, n;
    scanf("%lld %lld", &p, &n);

    if (p<=0 && n<=0) return 0;
    
    if (divisores_fact(p, n)) printf("YES\n");
    else printf("NO\n");

    return 1;
}

int main() {
    while (resuelveCaso());
    return 0;
}