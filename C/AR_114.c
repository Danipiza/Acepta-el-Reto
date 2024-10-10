#include <stdio.h>

// Solo pide el ultimo digito, al llegar a 5 el ultimo digito es 0. 0 * x = 0.
int factorial(int num) {
    if      (num<=1) return 1;
    else if (num==2) return 2;
    else if (num==3) return 6;
    else if (num==4) return 4;
    else             return 0;
}

void resuelveCaso() {
    int num;
    scanf("%d", &num);
    printf("%d\n", factorial(num));
}

int main() {
    int i;

    int n;
    scanf("%d", &n);
    for (i=0;i<n;i++) resuelveCaso();

    return 0;
}