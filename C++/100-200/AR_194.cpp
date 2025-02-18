#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

using vii = vector<pair<int, int>>;

// Enunciado: 

// Explicacion: 

// Complejidad:
// - Preprocesaod: O(nlogn) ordenar por un algoritmo de divide y venceras como
//  puede ser QuickSort
// - Temporal: O(n), recorre el vector de n elementos
// - Espacial: O(2n+4) = O(n) vector de n pares.
int voraz(const string& carretera) {
    int ret = 0;
    int i = 0, n = carretera.size();
    //vector<int> tuneles(n, 0);
    while (i < n) {
        if (carretera[i] == '.') {
            ret++;
            //tuneles[i + 1] = 1;
            i += 2;
        }
        i++;
    }

    return ret;
}
// Demostracion por reduccion de diferencias




void resuelveCaso() {
    string carretera;
    cin >> carretera;    

    cout << voraz(carretera) << "\n";

}
/*

Entrada:


Salida:

*/

int main() {
    int nCase;
    cin >> nCase;
    for(int i=0;i<nCase;i++) resuelveCaso();

    return 0;
}