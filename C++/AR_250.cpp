#include<iostream>
#include<fstream>
#include <vector>
using namespace std;

const int N = 1000000;

int cambioCerradura(const vector<int>& v, int n, int t) {
    int k = 0;//empezamos a recorrer desde 0
    int i = v[0];// en izq cargamos el primer valor del vector
    int d = t - i;// en derecha cargamos el valor de la suma de todos los siguientes
    int dif = abs(d) - abs(i);
    int min = t;
    int pos = 0;


    while (k < (n - 1)) {
        d = t - i;
        dif = abs(d) - abs(i);
        if (abs(dif) < abs(min) && abs(dif) != abs(t)) {
            pos = k + 1;
            min = abs(dif);
        }

        ++k;
        i += v[k];
    }
    return pos;
}



bool solve() {
    int n;
    int t = 0;

    cin >> n;
    if (n == 0) return false;
    
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        t += v[i];
    }

    cout << cambioCerradura(v, n, t) << "\n";
    
    return true;
}

int main() {
    while (solve());

    return 0;
}