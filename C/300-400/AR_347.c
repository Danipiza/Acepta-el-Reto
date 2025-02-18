#include <stdio.h>

int pajaritas(int x, int y) {   
    // CASO BASE
    if (x<10 || y<10) return 0;
    
    // CASO RECURSIVO
    int minimo=0;
    int divAux=0;
    if (x>y) {
        minimo=y;
        divAux=x/y;

        return pajaritas(x-minimo*divAux, y)+divAux;
    }
    else if (x<y) {
        minimo=x;
        divAux=y/x;

        return pajaritas(x, y-minimo*divAux) +divAux;
    }
    else { // x == y SE HACE EL PAJARITO GRANDE
        return 1;
    }
}

int pajaritasLineal(int x, int y) {
    int ret=0;
    
    int divAux;
    while (x>=10 && y>=10) {        
        divAux=0;

        if (x>y) {            
            divAux=x/y;

            ret+=divAux;
            x  -=y*divAux;            
        }
        else if (x<y) {            
            divAux=y/x;

            ret +=divAux;
            y   -=x*divAux;
        }
        else { // x == y SE HACE EL PAJARITO GRANDE
            ret+=1;
            
            x=0;
        }
    }    
    
    return ret;
}

int solve() {
    
    int x, y;
    if (scanf("%d %d", &x, &y)!=2) return 0;
    if (x==0 && y==0) return 0;       

    int r= ajaritasLineal(x, y);

    printf("%d\n", r);

    return 1;
}

int main() {
    while (solve());

    return 0;
}
