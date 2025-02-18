#include <stdio.h>
#include <string.h>
#include <float.h>

#define MAX_STRING 20

const char categorias[] = {'D', 'A', 'M', 'I', 'C'};


const char* conversion(char categoria) {
    if      (categoria=='D') return "DESAYUNOS";
	else if (categoria=='A') return "COMIDAS";
	else if (categoria=='M') return "MERIENDAS";
	else if (categoria=='I') return "CENAS";
	else if (categoria=='C') return "COPAS";
}

const char* categoria_maximo(double ventas[]) {
    int i;
    static char ret[MAX_STRING];
    strcpy(ret, "EMPATE");

    double maximo_valor=-DBL_MAX;
    int count          =0;

    for (i=0;i<5;i++) {
        if (maximo_valor<ventas[i]) {
            maximo_valor=ventas[i];
            strcpy(ret, conversion(categorias[i]));
            count=1;
        } 
        else if (ventas[i]==maximo_valor) count++;
    }
    
    if (count>1) strcpy(ret, "EMPATE");

    return ret;
}

const char* categoria_minimo(double ventas[]) {
    int i;

    static char ret[MAX_STRING];
    strcpy(ret, "EMPATE");

    double minimo_valor=DBL_MAX;
    int count          =0;

    for (i=0;i<5;i++) {
        if (minimo_valor>ventas[i]) {
            minimo_valor=ventas[i];
            strcpy(ret, conversion(categorias[i]));
            count=1;
        } 
        else if (ventas[i]==minimo_valor) count++;
    }

    if (count>1) strcpy(ret, "EMPATE");

    return ret;
}

int main() {
    int i;
    
    double ventas[5]={0};
    double total=0;
    int num_ventas_comidas=0, num_ventas_total=0;
    
    char categoria;
    double valor;
    while (scanf(" %c %lf", &categoria, &valor)== 2) {
        if (categoria=='N' && valor==0) {
            const char* aux = "NO";
            if (ventas[1]/num_ventas_comidas>(total/num_ventas_total)) aux="SI";

            printf("%s#%s#%s\n", 
                categoria_maximo(ventas), categoria_minimo(ventas), aux);
            
            for (i=0;i<5;i++) ventas[i]=0;
            total              =0;
            num_ventas_total   =0;
            num_ventas_comidas =0;
        } 
        else {
            int index=strchr(categorias, categoria)-categorias;
            ventas[index]+=valor;
            if (categoria=='A') num_ventas_comidas++;
            
            total+=valor;
            num_ventas_total++;
        }
    }

    return 0;
}