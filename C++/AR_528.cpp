#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

// Pre: true
long long int multi(const vector<float>& v) {
    long long int ret = 0;
    
    float fAux;
    int iAux;
    int contCeros = 0, contUnos = 0, contDecimales = 0, contEnteros = 0;


    int i = 0;
    while (i < v.size()) {
        fAux = v[i];
        iAux = v[i];        
        if (v[i] == 0) {                // Ceros
            contCeros++;
        }
        else if (v[i] == 1) {           // Unos
            contUnos++;
        }
        else if (fAux - iAux != 0) {    // Decimales
            if (v[i] > 1) {
                contEnteros++;
            }
            else {
                contDecimales++;
            }            
        }
        else {                          // Enteros >= 2
            contEnteros++;
        }

        ++i;
    }

    int maximo = max(contCeros, contUnos);
    maximo = max(maximo, contDecimales);
    maximo = max(maximo, contEnteros);
    int j = 0;
    int aux = contCeros;
    // EJ: 0 0 0.2 0.34 0.5 1 1 2 5 8 9
    while (j < maximo) {
        if (contCeros > 0) { // Cuenta los ceros, 2 ceros, puede hacer pareja con todos los valores 
            ret += v.size() - contCeros;    // por lo que suma v.size - contCeros
            contCeros--;                    // 1ra iter -> 11 -2 2da iter -> 11 - 1 solo se cuenta (0, 0) una vez
        }        
        if (contUnos > 0) { // Suma todas las parejas con 1
            ret += v.size() - aux - contUnos; // Igual que con ceros
            contUnos--;
        }
        if (contDecimales > 0) { // Suma decimales
            ret += contDecimales - 1;
            
            contDecimales--;
        }
        if (contEnteros > 0) { // Suma enteros
            ret += contEnteros - 1;

            contEnteros--;
        }

        j++;
    }


    
    return ret;
}
// Pos: r = Sum k: 0 <= k < v.size(): v[k]

bool solve() {
    // read case
    int n;
    cin >> n;
    if (n == 0)
        return false;

    vector<float> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
        

    sort(v.begin(), v.end());

    // compute solution
    long long int r = multi(v);

    // write solution
    cout << r << "\n";

    return true;
}


int main() {
    // uncomment to read from a file instead of standard input
    // ifstream ifs("sample.in");
    // cin.rdbuf(ifs.rdbuf());

    while (solve());

    return 0;
}