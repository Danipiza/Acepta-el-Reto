#include <stdio.h>
#include <string.h>

int poliDivisible(long long int num, int tamano) {
    int ret;
    
    if 		(tamano == 1) 		ret=1;
    else if (num % tamano == 0) ret=poliDivisible(num/10, tamano-1);
    else 						ret=0;
    
    return ret;
}

int solve() {
    long long int num;
    if (scanf("%lld", &num)!=1) return 0;
    
    char numero[20];
    sprintf(numero, "%lld", num);
    int size=strlen(numero);

    int poli=poliDivisible(num, size);    
    if (poli) printf("POLIDIVISIBLE\n");
    else 	  printf("NO POLIDIVISIBLE\n");
    
    return 1;
}

int main() {
    while (solve());
	
    return 0;
}