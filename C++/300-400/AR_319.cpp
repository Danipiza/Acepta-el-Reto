#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>
#include <vector>

using namespace std;

const int MOD = 10000;

// función que resuelve el problema
int bfs(int ini, int fin) {
    if (ini == fin)return 0;
    queue<pair<int, int>> Q;
    Q.push({ ini,0 });
    int v, d, tmp;
    vector<int> visited(MOD, 0);
    while (!Q.empty()) {
        v = Q.front().first; d = Q.front().second + 1; Q.pop();        
        // SUM
        tmp = (v + 1) % MOD;
        if (!visited[tmp]) {
            if (tmp == fin) return d;
            else { visited[tmp] = 1; Q.push({ tmp,d }); }
        }
        // MUL
        tmp = (v * 2) % MOD;
        if (!visited[tmp]) {
            if (tmp == fin) return d;
            else { visited[tmp] = 1; Q.push({ tmp,d }); }
        }
        // DIV
        tmp = (v / 3) % MOD;
        if (!visited[tmp]) {
            if (tmp == fin) return d;
            else { visited[tmp] = 1; Q.push({ tmp,d }); }
        }
    }

    return 0;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int ini, fin;
    cin >> ini >> fin;

    if (!std::cin) return false;

    cout << bfs(ini, fin) << "\n";

    // escribir sol


    return true;

}

int main() {

    while (resuelveCaso())
        ;


    return 0;
}