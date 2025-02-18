#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Pre: true
int serpientes(const vector<int>& v, int k) {
    int maximo = 0;
    int a = 0, b = 1;
    int kAux = k;
    int bAux = 1;
    if (v[a] == 1) maximo = 1;

    if (v.size() > 1) {               

        while (b < v.size() - 1) {
            if (v[a] == 0) {
                a++;
               
                if (a == b) {
                    kAux = k;
                    if (v[a] == 1) maximo = max(maximo, 1);
                    b++;
                }
            }
            else if (v[b] == 1) {
                maximo = max(maximo, (b - a + 1));
                b++;
                kAux = k;
            }
            else if (v[b] == 0 && kAux > 0) {
                //maximo = max(maximo, (b - a + 1));
                b++;
                kAux--;
            }
            else {
                a++;
                //kAux = k;
                maximo = max(maximo, 1);
                if (a == b) b++;
            }
            if (v[a] == 1 && v[b] == 1) maximo = max(maximo, (b - a + 1));
        }
        if (v[b] == 1) maximo = max(maximo, 1);
        if (v[a] == 1 && v[b] == 1) maximo = max(maximo, (b - a + 1));
    }


    return maximo;
}
// Pos: r = Sum k: 0 <= k < v.size(): v[k]


bool solve() {
    // read case
    int n, k;
    cin >> n >> k;
    if (n == 0)
        return false;

    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    // compute solution
    int r = serpientes(v, k);

    // write solution
    cout << r << endl; 

    return true;
}

int main() {
    while (solve());

    return 0;
}