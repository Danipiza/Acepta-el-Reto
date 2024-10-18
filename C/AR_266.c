#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void obra_final(char** v_obra, int filas, int columnas, char transformacion[]) {
    int i, j;

    for(i=0;i<filas;i++) {
        for(j=0;j<columnas;j++) {
            v_obra[i][j]=transformacion[v_obra[i][j]-'A'];
        }
    }
    
}

int resuelveCaso() {
    int i, j;
    int filas, columnas;
    scanf("%d %d", &filas, &columnas);
    if (filas==0 && columnas==0) return 0;

    char** v_obra=(char**)malloc(filas*sizeof(char*));
    for(i=0;i<filas;i++) {
        v_obra[i]=(char*)malloc((columnas+1)*sizeof(char));
        scanf("%s", v_obra[i]);
    }

    int copistas;
    scanf("%d", &copistas);

    char transformacion[26];
    // rellenar cada pixel con su transformacion.
    // inicialmente A->A, B->B, ... Z->Z
    for(i=0;i<26;i++) transformacion[i]='A'+i;

    char color1, color2;
    for(i=0;i<copistas;i++) {
        scanf(" %c %c", &color1, &color2);
        
        // recorrer la transformacion buscando, coincidencias
        for(j=0;j<26;j++) {
            // si coincide se cambia al nuevo valor
            /* EJEMPLO
            A -> R
            color1 = 'R' color2 = 'Y'

            Al llegar a R se cambia por Y, y asi con todas las ocurrencias
            */
            if (transformacion[j]==color1) transformacion[j]=color2;
        }
    }

    obra_final(v_obra, filas, columnas, transformacion);
    
    for(i=0;i<filas;i++) {
        printf("%s\n", v_obra[i]);
        free(v_obra[i]);
    }
    
    free(v_obra);

    return 1;
}

int main() {
    while (resuelveCaso());

    return 0;
}