#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;


using mapa = unordered_map<int, int>;
using vi = vector<int>;

// función que resuelve el problema
int bfs(int N, int K, mapa& serpientes, mapa& escaleras) {
    vi visited(N*N+1,0);
   
    queue<pair<int, int>> Q;
    Q.push({ 1,0 });
    visited[1] = true;
    int v, d, tmp=0;
    while (!Q.empty()) {
        v = Q.front().first; d = Q.front().second+1; Q.pop();
        
        for (int i = 1; i <= K; i++) {
            tmp = v + i;              
            if (escaleras.count(tmp) > 0) tmp = escaleras[tmp];
            else if (serpientes.count(tmp) > 0) tmp = serpientes[tmp];
            
            if (tmp == N*N) return d;
            if (!visited[tmp]) { visited[tmp] = true; Q.push({ tmp,d }); }
        }
    }

    return 0;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int N, K, S, E;
    cin >> N >> K >> S >> E;
    if (N == 0 && K == 0 && S == 0 && E == 0) return false;

    int i = 0;
    int a, b;
    mapa serpientes;
    for (; i < S; i++) {
        cin >> a >> b;
        serpientes[a] = b;
    }

    mapa escaleras;
    for (i = 0; i < E; i++) {
        cin >> a >> b;
        escaleras[a] = b;
    }
    cout << bfs(N, K, serpientes, escaleras) << "\n";

    // escribir sol


    return true;

}

int main() {

    while (resuelveCaso())
        ;


    return 0;
}