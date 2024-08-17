#include <iostream>
#include <vector>
#include <map>

using namespace std;




// Pre: true
int moda(const map<int, int>& m) {
    int moda = 0;
    int valor = 0;
   



    return moda;
}
// Pos: r = Sum k: 0 <= k < v.size(): v[k]

bool solve() {
    // read case
    int n = 0;
    cin >> n;
    if (n == 0)
        return false;

    int moda = 0;
    int nombre = 0;

    map<int, int> m;
    int value;
    for (int i = 0; i < n; ++i) {
        cin >> value;
        int& p = m[value];
        p++;
        if (p > moda) {
            nombre = value;
            moda = p;
        }
    }

   // printf("%d\n", moda_name);
    
    

    // write solution
    cout << nombre << endl;

    return true;
}

int main() {

    while (solve());

    return 0;
}