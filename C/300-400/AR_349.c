#include <stdio.h>
#include <ctype.h>

int operar() {
    char valor;
    scanf(" %c", &valor); 
    
    if (isalnum(valor)) return valor-'0';
    else {
        int sum1=operar();
        int sum2=operar();

        if      (valor=='+') return sum1+sum2;
        else if (valor=='-') return sum1-sum2;
        else if (valor=='*') return sum1*sum2;
        else                 return sum1/sum2;
    }
}

void solve() {

    printf("%d\n", operar());
}

int main() {
    int i;

    int numCasos;
    scanf("%d", &numCasos);

    for (i=0;i<numCasos;i++) solve();
    return 0;
}
