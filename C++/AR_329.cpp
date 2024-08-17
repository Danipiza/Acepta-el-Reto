#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

using vii = vector<pair<int, int>>;

int voraz(vii& edificios){
    int ret = 1;
    int fin = edificios[0].second;
    for (int i = 1; i < edificios.size(); i++) {
        if (edificios[i].first < fin) {
            if (fin > edificios[i].second) fin = edificios[i].second;
        }
        else {
            ret++;
            fin = edificios[i].second;
        }
    }

    return ret;
}

bool resuelveCaso() {
    int N;
    cin >> N;
    if (N == 0) return false;
    
    vii edificios;
    int ini, fin;
    for (int i = 0; i < N; i++) {
        cin >> ini >> fin;
        edificios.push_back({ini,fin});
    }
    sort(edificios.begin(), edificios.end());
    
    cout << voraz(edificios) << "\n";


    return true;
}

int main() {


    while (resuelveCaso());



    return 0;
}