#include <stdio.h>
#include <stdlib.h>
#include <math.h>



int cambioCerradura(const int* v, int n, int t) {
    int k=0;    //empezamos a recorrer desde 0
    int i=v[0]; // en izq cargamos el primer valor del vector
    int d=t-i;  // en derecha cargamos el valor de la suma de todos los siguientes
    
    int dif=abs(d)-abs(i);
    int min=t;
    int pos=0;

    while (k<(n-1)) {
        d  =t-i;
        dif=abs(d)-abs(i);

        if (abs(dif)<abs(min) && abs(dif)!=abs(t)) {
            pos=k+1;
            min=abs(dif);
        }

        k++;
        i+=v[k];
    }
    return pos;
}

int solve() {
    int i;

    int n;
    int t=0;

    scanf("%d", &n);
    if (n==0) return 0;
    
    int* v=(int*)malloc(n*sizeof(int));
    for (i=0;i<n;i++) {
        scanf("%d", &v[i]);
        t+=v[i];
    }

    printf("%d\n", cambioCerradura(v, n, t));
    
    free(v);
    return 1;
}

int main() {
    while (solve());

    return 0;
}