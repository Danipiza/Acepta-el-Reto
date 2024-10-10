#include <stdio.h>
#include <string.h>


void resuelveCaso() {
    printf("Hola mundo.\n");
}

int main() {
    int i;

    int n;
    scanf("%d", &n);
    for(i=0;i<n;i++) resuelveCaso();

    return 0;
}
