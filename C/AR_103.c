#include <stdio.h>
#include <stdlib.h>

#define MAX_DEGREE 20

double calcula_altura(double x, int* f, int n) {
    int i;

    double ret=0;
    double exponente=1;
	
  
    for (i=0;i<n;i++) {
        ret+=f[i]*exponente;
        exponente*=x;
    }

    return ret;
}


double calcula_area(int area, int* f, int n) {
    int i;

    double ret=0.0;
    double base, altura;
  	
  
    for (i=0;i<area;i++) {
        base   =1.0/(double)area;
        altura =calcula_altura(i*base, f, n);

        if (altura<0) continue;
        else if (altura>1) altura=1;

        ret+=base*altura;
    }

    return ret;
}

int resuelveCaso() {
    int grado;
    scanf("%d", &grado);
    if (grado==20) return 0;

    int f[MAX_DEGREE+1];
    int i;
  
  	for (i=0;i<=grado;i++) scanf("%d", &f[grado-i]);

    int n;
    scanf("%d", &n);
    double area_cain = calcula_area(n, f, grado+1);

    if (area_cain<0.4999) printf("ABEL\n");
    else if (area_cain>0.5001) printf("CAIN\n");
    else printf("JUSTO\n");

    return 1;
}

int main() {
    while (resuelveCaso());
    return 0;
}