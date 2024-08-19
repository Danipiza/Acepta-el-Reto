#include <iostream>
#include <vector>       // libreria para almacenar los datos
// tambien se puede usar arrays de enteros = int[]


// Funciones para que el compilador tarde menos en ejecutarse
// no tenies que usarlo en clase
#pragma GCC optimize("O3,Ofast,unroll-loops")
static const int _ = []()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();
// ----------------------------------------------------------

using namespace std; // libreria standard
// para poder usar cin, cout, string, otras librerias...

void bar_javier(vector<double> v, 
                int& mejor_dia, int& peor_dia, string& domingo) {
    double suma_total;
    double maxima_caja, minima_caja;
    
    suma_total=v[0];
    maxima_caja=minima_caja=v[0];       

    double caja_diaria;
    for (int i=1;i<5;i++) {        
        caja_diaria=v[i];
        suma_total+=caja_diaria;
        if (maxima_caja<caja_diaria) {
            maxima_caja=caja_diaria;
            mejor_dia=i;
        }
        else if (minima_caja>caja_diaria) {
            minima_caja=caja_diaria;
            peor_dia=i;
        }
    }
    double caja_domingo=v[5];
    suma_total+=caja_domingo;
    if (maxima_caja<caja_domingo) {
        maxima_caja=caja_domingo;
        mejor_dia=5;
    }
    else if (minima_caja>caja_domingo) {
        minima_caja=caja_domingo;
        peor_dia=5;
    }
    domingo=(suma_total/6.0<caja_domingo ? "SI" : "NO");
}

bool resuelveCaso() {
    double caja_diaria;
    
    
    
    cin >> caja_diaria;
    if (caja_diaria ==-1) return false;
    
    vector<double> v;
    v.push_back(caja_diaria);
    for (int i=0;i<5;i++) {
        cin >> caja_diaria;
        v.push_back(caja_diaria);
    }
    
    int mejor_dia=0, peor_dia=0;
    string domingo = "";
    bar_javier(v,mejor_dia,peor_dia,domingo);
    
    vector<string> dias = { "MARTES","MIERCOLES","JUEVES","VIERNES","SABADO","DOMINGO" };
    cout << dias[mejor_dia] << " " << dias[peor_dia] << " " << domingo << "\n";

    /*
    suma_total=caja_diaria;
    maxima_caja=minima_caja=caja_diaria;
    mejor_dia=peor_dia=0;

    for (int i=1;i<5;i++) {
        cin >> caja_diaria;
        suma_total+=caja_diaria;
        if (maxima_caja<caja_diaria) {
            maxima_caja=caja_diaria;
            mejor_dia=i;
        }
        else if (minima_caja>caja_diaria) {
            minima_caja=caja_diaria;
            peor_dia=i;
        }
    }
    double caja_domingo;
    cin >> caja_domingo;
    suma_total+=caja_domingo;
    if (maxima_caja<caja_domingo) {
        maxima_caja=caja_domingo;
        mejor_dia=5;
    }
    else if (minima_caja>caja_domingo) {
        minima_caja=caja_domingo;
        peor_dia=5;
    }
    vector<string> dias = { "MARTES","MIERCOLES","JUEVES","VIERNES","SABADO","DOMINGO" };
    cout << dias[mejor_dia] << " " << dias[peor_dia] << " " << (suma_total/6.0<caja_domingo ? "SI\n" : "NO\n");
    */


    return true;
}


int main() {
    //ios_base::sync_with_stdio(false);

    while (resuelveCaso());

    return 0;
}