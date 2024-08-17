#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

using vi = vector<int>;

// Enunciado: 

// Explicacion: 

// Complejidad:
// - Preprocesaod: O(nlogn) ordenar por un algoritmo de divide y venceras como
//  puede ser QuickSort
// - Temporal: O(n), recorre el vector de n elementos
// - Espacial: O(2n+4) = O(n) vector de n pares.
void voraz(int cambio, const vi& dinero,
          vi& vuelta) {
    int i = 0, n = dinero.size();
    while (i < n-1) {
        if (dinero[i] <= cambio) {
            vuelta[i]++;
            cambio -= dinero[i];
        }
        else {
            i++;
        }
        
    }   
    vuelta[i] = cambio;
}
// Demostracion por reduccion de diferencias




void resuelveCaso() {
    int coste, pago;
    cin >> coste >> pago;
    int cambio = pago - coste;  
    if (cambio < 0) {
        cout << "DEBE " << cambio * -1 << "\n";
        return;
    }
    vi dinero = { 200,100,50,20,10,5,2,1 };
    vi vuelta(8, 0);
    voraz(cambio, dinero, vuelta);
    int i = 0;
    for (; i < dinero.size() - 1; i++) {
        cout << vuelta[i] << " ";
    }
    cout << vuelta[i] << "\n";
}
/*

Entrada:


Salida:

*/

int main() {
      
    int nCase;
    cin >> nCase;
    for (int i = 0; i < nCase; i++) resuelveCaso();


    return 0;
}