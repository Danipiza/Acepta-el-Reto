#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Pre: true
int dedos(const vector<int>& v, int A) {
    int maximo = 0;
    int a = 0, b = 1;
    int aux = 1;
   
    while (b < v.size()) {
        if (v[b] <= v[a] + A - 1) {
            ++aux;
            ++b;
        }
        else {
            ++a;
            maximo = max(maximo, aux);
            --aux;
        }
    }
    maximo = max(maximo, aux);


    return maximo;
}
// Pos: r = Sum k: 0 <= k < v.size(): v[k]

bool solve() {
    // read case
    int N = 0, A = 0;
    cin >> N >> A;
    if (N == 0 && A == 0)
        return false;

    vector<int> v(N);
    for (int i = 0; i < N; ++i)
        cin >> v[i];

    // compute solution
    int r = dedos(v, A);

    // write solution
    cout << r << endl;

    return true;
}

int main() {

    while (solve());

    return 0;
}