#include <stdio.h>
#include <string.h>


int conversion(char nivel) {
    int ret=2; // s

    if      (nivel=='d') ret=6;
    else if (nivel=='p') ret=10;
    else if (nivel=='f') ret=14;

    return ret;
}


void configuracion_electronica(int electrones, char *ret) {
    const char *niveles[]={ "1s", "2s", "2p", "3s", "3p",
                            "4s", "3d", "4p", "5s", "4d",
                            "5p", "6s", "4f", "5d", "6p",
                            "7s", "5f", "6d", "7p" };

    int mapa[128];
    mapa['s']=2;  mapa['p']=6;
    mapa['d']=10; mapa['f']=14;

    char buffer[100]="";    
    int i=0, tmp;
    tmp=mapa[niveles[i][1]];

    while (electrones>tmp) {                        
        electrones-=tmp;

        sprintf(buffer + strlen(buffer), "%s%d ", niveles[i], tmp);

        i++;
        tmp=mapa[niveles[i][1]];
    }

    sprintf(buffer+strlen(buffer), "%s%d", niveles[i], electrones);
    strcpy(ret, buffer);
}

int resuelveCaso() {
    char elemento[100];
    scanf("%s", elemento);
    if (strcmp(elemento, "Exit")==0) return 0;

    int electrones;
    scanf("%d", &electrones);

    char salida[200];
    configuracion_electronica(electrones, salida);
    printf("%s\n", salida);
    
    return 1;
}

int main() {
    while (resuelveCaso());

    return 0;
}
