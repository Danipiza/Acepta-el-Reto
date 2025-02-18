#include <iostream>
#include <vector>
#include <string>

using namespace std;

using vs = vector<string>;

void obra_final(vs& v_obra, int filas, int columnas, char transformacion[]) {
    for (int i=0;i<filas;i++) {
        for (int j=0;j<columnas;j++) {
            v_obra[i][j]=transformacion[v_obra[i][j]-'A'];
        }
    }
}

bool resuelveCaso() {
    int filas, columnas;
    cin >> filas >> columnas;
    if (filas==0 && columnas==0) return false;

    vs v_obra(filas);
    for (int i = 0; i < filas; ++i) cin >> v_obra[i];

    int copistas;
    cin >> copistas;

    
    char transformacion[26];
    
    // rellenar cada pixel con su transformacion.
    // inicialmente A->A, B->B, ... Z->Z
    for (int i=0;i<26;i++) transformacion[i]='A'+i;

    char color1, color2;
    for (int i=0;i<copistas;i++) {
        cin >> color1 >> color2;        
        
        // recorrer la transformacion buscando, coincidencias
        for (int j=0;j<26;j++) {
            // si coincide se cambia al nuevo valor
            /* EJEMPLO
            A -> R
            color1 = 'R' color2 = 'Y'

            Al llegar a R se cambia por Y, y asi con todas las ocurrencias
            */
            if (transformacion[j]==color1) transformacion[j]=color2;
        }
    }

    
    obra_final(v_obra,filas,columnas,transformacion);
    
    for (int i=0;i<filas;i++) cout << v_obra[i] << "\n"; 

    return true;
}

int main() {
    while (resuelveCaso());
    return 0;
}
