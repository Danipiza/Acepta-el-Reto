#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_N 25000

typedef struct {
    int valor;
    int cont;
    int primera_aparicion;
} Info_Num;

int compare(const void* a, const void* b) {
    Info_Num* na=(Info_Num*)a;
    Info_Num* nb=(Info_Num*)b;
    if (na->cont != nb->cont) return nb->cont-na->cont; 

    return na->primera_aparicion-nb->primera_aparicion; 
}

bool solve() {
    int i, j;

    int n;
    if (scanf("%d", &n)!=1 || n==0) return false;

    Info_Num numbers[MAX_N];
    int unique_cont = 0;

    for (i=0;i<n;i++) {
        int valor;
        scanf("%d", &valor);
  
        for (j=0;j<unique_cont;j++) {
            if (numbers[j].valor==valor) {
                numbers[j].cont++;
                break;
            }
        }

        // nuevo
        if (j==unique_cont) {
            numbers[unique_cont].valor =valor;
            numbers[unique_cont].cont  =1;
            numbers[unique_cont].primera_aparicion=i;
            unique_cont++;
        }
    }

    qsort(numbers, unique_cont, sizeof(Info_Num), compare);

    printf("%d\n", numbers[0].valor);

    return true;
}

int main() {
    while (solve());
    return 0;
}