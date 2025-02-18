#include <stdio.h>


#define K 31543

long long int eleva(long long int x, int n) {
    
    if (n==0) return 1;
    else {
        long long int var=eleva(x, n/2);

        if (n%2==0) return (var*var)%K;
        else 		return ((x%K)*var*var)%K;
    }
}

int resuelveCaso() {
    long long int x;
    int n;
    
	if (scanf("%lld %d", &x, &n)!=2) return 0;
    if (x==0 && n==0) return 0;
    
	printf("%lld\n", eleva(x, n));
    
	return 1;
}

int main() {
    while (resuelveCaso());

    return 0;
}