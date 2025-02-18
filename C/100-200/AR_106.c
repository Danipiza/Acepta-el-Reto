#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_LENGTH 14  


void comprueba_pais(const char* num, 
                    char* pais) {
    int i, j;

    struct MapEntry {
        const char* key;
        const char* value;
    };

    struct MapEntry mapa[]={
        {"0", "EEUU"}, {"380", "Bulgaria"}, {"50", "Inglaterra"},
        {"539", "Irlanda"}, {"560", "Portugal"}, {"70", "Noruega"},
        {"759", "Venezuela"}, {"850", "Cuba"}, {"890", "India"}
    };
    
    int mapa_size=sizeof(mapa)/sizeof(mapa[0]);

    strcpy(pais, "Desconocido");
    char id[4]="";

    for (i=0;i<3;i++) {
        strncat(id, &num[i], 1);
        for (j=0;j<mapa_size;j++) {
            if (strcmp(id, mapa[j].key)==0) {
                strcpy(pais, mapa[j].value);
                return;
            }
        }
    }

}


int EAN(int digitos, const char* num, 
        char* salida) {
    int i;

    int codigo_error=num[digitos-1]-'0';
    int suma        =0;

    int tmp=0, aux=(digitos==8) ? 1:0;
    for (i=digitos-2;i>=0;i--) {
        tmp=1;

        if ((i+aux)%2==1) tmp=3;
        
        suma+=(num[i]-'0')*tmp;
    }

    int sum_multiplo=suma%10;
    if (sum_multiplo!=0) sum_multiplo=10-sum_multiplo;        
    int ret=(sum_multiplo==codigo_error);

    if (ret && digitos==13) comprueba_pais(num, salida);

    return ret;
}

int resuelveCaso() {    
    char num[MAX_LENGTH];

    scanf("%s", num);
    if (strcmp(num, "0")==0) return 0;

    int digitos=strlen(num);    
    if (digitos<8) { // si es inferior a 8 hay que añadir 0s
        char temp[MAX_LENGTH]="00000000";
        strcpy(temp+(8-digitos), num);
        strcpy(num, temp);
        digitos=8;
    }
    else if (digitos>8 && digitos < 13) { // si distinto de 8 e inferior a 13 hay que añadir 0s
        char temp[MAX_LENGTH]="0000000000000";
        strcpy(temp+(13-digitos), num);
        strcpy(num, temp);
        digitos=13;
    }

    char pais[20]="";
    int salida=EAN(digitos, num, pais);

    if (salida) {
        printf("SI");
        if (digitos==13) printf(" %s", pais);
    }
    else printf("NO");
    printf("\n");
    
    return 1;    
}

int main() {
    while (resuelveCaso());
    return 0;
}