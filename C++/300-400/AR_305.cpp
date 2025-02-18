// Nombre del alumno Daniel Pizarro
// Usuario del Juez MAR159


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

using vi = vector<int>;

int voraz(vi& inv, vi& def) {
    int ret = 0;
    sort(inv.begin(), inv.end());
    sort(def.begin(), def.end());
    int i = 0, j = 0, n = inv.size();
    while (i<n) {
        if (inv[j] <= def[i]) {
            ret++;
            i++; j++;
        }
        else {
            i++;
        }
    }
    
    return ret;
}

bool resuelveCaso() {
    int N;
    cin >> N;
    if (!cin) return false;
    vi inv, def;
    int a;
    for (int i = 0; i < N; i++) {
        cin >> a;
        inv.push_back(a);
    }
    for (int i = 0; i < N; i++) {
        cin >> a;
        def.push_back(a);
    }

    cout << voraz(inv,def) << "\n";

    return true;

}

int main() {

    while (resuelveCaso());


    return 0;
}