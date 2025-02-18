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
int voraz(int peso, const vi& personas) {
    int ret = 0;
    int i = 0, n = personas.size()-1;
    while (i <= n) {
        if (personas[i] + personas[n] <= peso) { 
            i++; n--; 
        }
        else n--;
        ret++;
    }
    return ret;
}
// Demostracion por reduccion de diferencias




bool resuelveCaso() {
    int peso, N;
    cin >> peso >> N; 
    if (peso == 0 && N == 0) return false;

    vi personas;
    int a;
    for (int i = 0; i < N; i++) {
        cin >> a;
        personas.push_back(a);
    }
    // ordena el vector por orden ascendente de inicio 
    sort(personas.begin(), personas.end());

    cout << voraz(peso, personas) << "\n";

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