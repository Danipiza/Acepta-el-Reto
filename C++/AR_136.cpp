#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int trolls(int fuerza, int n) {
    // CASO BASE
    if (fuerza * 2 >= n) return 0;

    // CASO RECURSIVO
    int auxI = n / 3;
    int auxD = n - auxI;
    

    if (auxD >= fuerza * 2) {
        if (auxI >= fuerza * 2) return trolls(fuerza, auxI) + trolls(fuerza, auxD) + 1;
        else return trolls(fuerza, auxD) + 1;
    }
    else return 1;
}

bool solve() {
    // read case
    int fuerza, n;
    cin >> fuerza >> n;
    if (fuerza == 0)
        return false;

    // compute solution
    int r = trolls(fuerza, n);

    // write solution
    cout << r << endl;

    return true;
}

int main() {
    while (solve());

    return 0;
}