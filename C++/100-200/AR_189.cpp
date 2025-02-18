#include <iostream>
#include <vector>
#include <algorithm>



using namespace std;

// Pre: true
/*int embarque(vector<int>& v, int N) {
    int i = 0, j = 0;
    bool fin = false;

    sort(v.begin(), v.end());


    while (!fin) {
        if (v[i] == N) {
            j = i;
            while (v[i] == N && i != v.size() - 1) {
                ++i;
            }
            fin = true;
            if (i == v.size() - 1) {
                v.erase(v.begin() + j, v.end());
            }
            else {
                v.erase(v.begin() + j, v.begin() + i);
            }
            
        }

        
        ++i;
        if (i == v.size() - 1) fin = true;
    } 

    return v.size();
}*/



int embarque(vector<int>& v, int N) {       
    int i = 0;

   /* while (i < v.size()) {
        if (v[i] == N) {
            v.erase(v.begin() + i, v.begin() + i + 1);
        }
        ++i;
    }*/
    v.erase(remove(v.begin(), v.end(), N), v.end());
    

    return v.size();
}
// Pos: r = Sum k: 0 <= k < v.size(): v[k]

/*long long int consulta(const vector<long long int>& v, int N) {
    return v[N-1];
}*/

bool solve() {
    // read case
    int n;
    cin >> n;
    if (n == 0)
        return false;

    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
        
    int nAcciones;
    cin >> nAcciones;
    string accion;
    int numAccion;
    for (int i = 0; i < nAcciones; ++i) {
        cin >> accion;
        cin >> numAccion;
        if (accion == "EMBARQUE") {            
            cout << embarque(v, numAccion) << "\n";
        }
        else if (accion == "CONSULTA" && v.size() > 0) {
            cout << v[numAccion - 1] << "\n";
        }
    }
    cout << "*\n";
    

    return true;
}

int main() {
    while (solve());
    return 0;
}