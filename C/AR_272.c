#include <stdio.h>

#define BASE_CONVERSION 6

void valorDivision(int numBaseDiez) {
    if (numBaseDiez/BASE_CONVERSION==0) 
        printf("%d", numBaseDiez);    
    else if (numBaseDiez/BASE_CONVERSION<=5) 
        printf("%d%d", numBaseDiez/BASE_CONVERSION, numBaseDiez%BASE_CONVERSION);    
    else {
        valorDivision(numBaseDiez/BASE_CONVERSION);
        printf("%d", numBaseDiez%BASE_CONVERSION);
    }
}

void solve() {
    int numBaseDiez;
    scanf("%d", &numBaseDiez);

    valorDivision(numBaseDiez);
    printf("\n");
}

int main() {
    int i;

	int numCasos;
    scanf("%d", &numCasos);
    for (i=0;i<numCasos;i++) solve();

    return 0;
}