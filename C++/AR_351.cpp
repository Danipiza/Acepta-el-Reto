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
    int n, K;
    cin >> n;
    if (n == 0) return false;

    
    priority_queue<Nodo> Q;
    unordered_map<int, int> org;
    int id, t;
    for (int i = 0; i < n; i++) { 
        cin >> id >> t;
        org[id] = t;
        Q.push({ id, t }); 
    }

    cin >> K;
    

    int cont = 0;
    Nodo aux;
    while (cont < K) {
        aux = Q.top(); Q.pop();
        cout << aux.id << "\n";
        Q.push({ aux.id, aux.t + org[aux.id] });
        
        cont++;
    }
    cout << "----\n";

    return true;
}


int main() {


    // Resolvemos
    while (resuelveCaso());


    return 0;
}
(c) Acepta el reto, 2013 - 2024
