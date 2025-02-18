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
int voraz(const vi& esquiadores, const vi& esquis) {
    int ret = 0;
    int i = 0, n = esquis.size();
    while (i < n) {
        ret += abs(esquiadores[i] - esquis[i]);
        i++;
    }

    return ret;
}
// Demostracion por reduccion de diferencias




bool resuelveCaso() {
    int N;
    cin >> N; // N peliculas
    // N==0, no hay mas esquiadores
    if (N == 0) return false;
    vi esquiadores, esquis;
    int a;
    for (int i = 0; i < N; i++) {
        cin >> a;
        esquiadores.push_back(a);
    }

    for (int i = 0; i < N; i++) {
        cin >> a;
        esquis.push_back(a);
    }      
    sort(esquiadores.begin(), esquiadores.end());
    sort(esquis.begin(), esquis.end());

    cout << voraz(esquiadores, esquis) << "\n";

    return true;
}
/*

Entrada:


Salida:

*/

int main() {


    while (resuelveCaso());

    return 0;
}