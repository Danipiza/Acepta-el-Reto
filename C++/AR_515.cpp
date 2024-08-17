#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int copas(int n, bool miTurno) {
    // CASO BASE
    if (n <= 0) return 0;

    // CASO RECURSIVO
    if (!miTurno) return copas(n - 1, true) + 1;
    else if (n % 2 == 0) { // PAR Y MI TURNO
        return copas(n - 2, false) + 1;
    }
    else { // IMPAR Y MI TURNO
        return copas(n - 1, false) + 1;
    }
}

int copasLineal(int n) {
    // CASO BASE
    if (n == 1) return 1;
    else if (n % 2 == 0) {
        return n;
    }
    else {
        return n - 1;
    }
    
}

bool solve() {
    // read case
    int n;
    cin >> n;
    if (n == 0)
        return false;

    // compute solution
    int r = copasLineal(n);

    // write solution
    cout << r << endl;

    return true;
}

int main() {
    while (solve());

    return 0;
}