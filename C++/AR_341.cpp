#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;


struct Nodo {
    int id;
    int t;

    bool operator<(Nodo const& otro) const {
        return otro.t < t || (otro.t == t && otro.id < id);
    }
};

bool resuelveCaso() {
    int N, C;
    cin >> N >> C;
    if (!cin) return false;

    priority_queue<Nodo> QCajas;
    int t;
    for (int i = 0; i < N && i < C; i++) {
        cin >> t;
        QCajas.push({ i + 1,t });
    }

    if (N > C) cout << QCajas.size() + 1 << "\n";
    else {
        int j = QCajas.size();
        Nodo aux;
        while (j < C) {
            aux = QCajas.top(); QCajas.pop();
            cin >> t;
            QCajas.push({ aux.id,aux.t + t });
            j++;
        }
        cout << QCajas.top().id << "\n";
    }


    return true;
}

int main() {


    // Resolvemos
    while (resuelveCaso());


    return 0;
}