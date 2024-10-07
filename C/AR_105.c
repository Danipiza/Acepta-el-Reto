#include <stdio.h>
#include <string.h>

#define DAYS 6


void bar_javier(double v[], int* mejor_dia, int* peor_dia, char* domingo) {
    int i;
    
    double suma_total  =v[0];
    double maxima_caja =v[0], minima_caja=v[0];
    
    *mejor_dia =0;
    *peor_dia  =0;

    double caja_diaria;
  	
    for (i=1;i<5;i++) {
        caja_diaria =v[i];
        suma_total +=caja_diaria;

        if (maxima_caja<caja_diaria) {
            maxima_caja =caja_diaria;
            *mejor_dia  =i;
        }
        else if (minima_caja>caja_diaria) {
            minima_caja =caja_diaria;
            *peor_dia   =i;
        }
    }

    double caja_domingo=v[5];
    suma_total+=caja_domingo;
    if (maxima_caja<caja_domingo) {
        maxima_caja =caja_domingo;
        *mejor_dia  =5;
    }
    else if (minima_caja>caja_domingo) {
        minima_caja =caja_domingo;
        *peor_dia   =5;
    }

    strcpy(domingo, ((suma_total/6.0)<caja_domingo ? "SI":"NO"));
}

int resuelveCaso() {
    int i;

    double caja_diaria;
    
    scanf("%lf", &caja_diaria);
    if (caja_diaria==-1) return 0;
    
    double v[DAYS];
    v[0]=caja_diaria;
    
  
  	for (i=1;i<DAYS;i++) {
        scanf("%lf", &v[i]);
    }
    
    int mejor_dia=0, peor_dia=0;
    char domingo[3];
    bar_javier(v, &mejor_dia, &peor_dia, domingo);
    
    const char* dias[]={"MARTES", "MIERCOLES", "JUEVES", "VIERNES", "SABADO", "DOMINGO"};
    printf("%s %s %s\n", dias[mejor_dia], dias[peor_dia], domingo);

    return 1;
}

int main() {
    while (resuelveCaso());
    return 0;
}