// Nombre del alumno Daniel Pizarro
// Usuario del Juez MAR159


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

using vi = vector<int>;

int voraz(int L, vi& v) {
    int ret = 0;
    int i = 1, n = v.size();
    int act;
    while (i<n) {
        act = v[i - 1];
        while (i < n && v[i] - act <= L) { i++; }
        ret++;
        i++;
    }
    if (i == n)ret++;
    return ret;
}

bool resuelveCaso() {
    int N, L;
    cin >> N >> L;
    if (!cin) return false;
    vi v;
    int a;
    for (int i = 0; i < N; i++) {
        cin >> a;
        v.push_back(a);
    }

    cout << voraz(L, v) << "\n";

    return true;

}

int main() {

    
    while(resuelveCaso());



    return 0;
}