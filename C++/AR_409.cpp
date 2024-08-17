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
int voraz(int num, const vi& integrantes) {
    int ret = 0;
    int i = num-1, n = integrantes.size();
    while (i < n) {
        if (integrantes[i] - integrantes[i - num + 1] <= 15) {
            ret++;
            i += num - 1;
        }
        i++;
    }
    return ret;
}
// Demostracion por reduccion de diferencias




void resuelveCaso() {
    int num, N;
    cin >> num >> N; 
    vi integrantes;
    int a;
    for (int i = 0; i < N; i++) {
        cin >> a;
        integrantes.push_back(a);
    }

    sort(integrantes.begin(), integrantes.end());

    cout << voraz(num, integrantes) << "\n";

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