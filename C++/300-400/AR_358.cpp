#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <climits>
#include <memory>
#include <stdexcept>

using namespace std;

#define INF INT_MAX

template <typename Valor>
class Arista {
public:
    Arista() : pimpl(nullptr) {}
    Arista(int v, int w, Valor valor) : pimpl(std::make_shared<Arista_impl>(v, w, valor)) {}

    int uno() const { return pimpl->v; }
    int otro(int u) const { return (u == pimpl->v) ? pimpl->w : pimpl->v; }
    Valor valor() const { return pimpl->valor; }

    void print(std::ostream& o = std::cout) const {
        o << "(" << pimpl->v << ", " << pimpl->w << ", " << pimpl->valor << ")";
    }

    bool operator<(Arista<Valor> const& b) const {
        return valor() < b.valor();
    }
    bool operator>(Arista<Valor> const& b) const {
        return b.valor() < valor();
    }
private:
    struct Arista_impl {
        int v, w;
        Valor valor;
        Arista_impl(int v, int w, Valor valor) : v(v), w(w), valor(valor) {}
    };

    std::shared_ptr<Arista_impl> pimpl; // puntero a la arista "de verdad"
};

template <typename Valor>
inline std::ostream& operator<<(std::ostream& o, Arista<Valor> const& ar) {
    ar.print(o);
    return o;
}


template <typename Valor>
using AdysVal = std::vector<Arista<Valor>>;  // lista de adyacentes a un vértice

template <typename Valor>
class GrafoValorado {
public:

    /**
     * Crea un grafo valorado con V vértices, sin aristas.
     */
    GrafoValorado(int V) : _V(V), _A(0), _ady(_V) { }

    /**
     * Devuelve el número de vértices del grafo.
     */
    int V() const { return _V; }

    /**
     * Devuelve el número de aristas del grafo.
     */
    int A() const { return _A; }

    /**
     * Añade una arista al grafo.
     * @throws invalid_argument si algún vértice no existe
     */
    void ponArista(Arista<Valor> arista) {
        int v = arista.uno(), w = arista.otro(v);
        if (v < 0 || v >= _V || w < 0 || w >= _V)
            throw std::invalid_argument("Vertice inexistente");
        ++_A;
        _ady[v].push_back(arista);
        _ady[w].push_back(arista);
    }

    /**
     * Devuelve la lista de adyacentes de v.
     * @throws invalid_argument si v no existe
     */
    AdysVal<Valor> const& ady(int v) const {
        if (v < 0 || v >= _V) throw std::invalid_argument("Vertice inexistente");
        return _ady[v];
    }

    /**
     * Devuelve las aristas del grafo.
     */
    std::vector<Arista<Valor>> aristas() const {
        std::vector<Arista<Valor>> ars;
        for (int v = 0; v < V(); ++v)
            for (auto arista : ady(v))
                if (v < arista.otro(v))
                    ars.push_back(arista);
        return ars;
    }

    /**
     * Muestra el grafo en el stream de salida o
     */
    void print(std::ostream& o = std::cout) const {
        o << _V << " vértices, " << _A << " aristas\n";
        for (auto v = 0; v < _V; ++v) {
            o << v << ": ";
            for (auto const& w : _ady[v]) {
                o << w << " ";
            }
            o << "\n";
        }
    }

private:
    int _V;   // número de vértices
    int _A;   // número de aristas
    std::vector<AdysVal<Valor>> _ady;   // vector de listas de adyacentes
};


/**
 * Para mostrar grafos por la salida estándar.
 */

template <typename Valor>
inline std::ostream& operator<<(std::ostream& o, GrafoValorado<Valor> const& g) {
    g.print(o);
    return o;
}

using vi = vector<int>;
using vvi = vector<vi>;

struct Nodo {
    int d;
    int v;

    bool operator<(const Nodo& otro) const {
        return otro.d < d;
    }
};

// con colores
int dfs(int v, vvi& P, vi& camino) {
    if (camino[v] != -1)return camino[v];
    int tmp = 0;
    for (int u : P[v]) {
        tmp += dfs(u, P, camino);
    }
    camino[v] = tmp;
    return tmp;
}

void dijkstra(const GrafoValorado<int>& G, int s, int t, vvi& P) {
    vi visited(t + 1, 0);
    vi dist(t + 1, INF);
    
    dist[s] = 0;;
    P[s] = { -1 }; // raiz
    priority_queue<Nodo> Q;
    Q.push({ 0,s });
    int v, d, u, tmp;
    while (!Q.empty()) {
        v = Q.top().v; d = Q.top().d; Q.pop();
        if (d > dist[v]) continue;
        visited[v] = 1;
        for (Arista<int> a : G.ady(v)) {
            u = a.otro(v);
            if (visited[u]) continue;
            tmp = dist[v] + a.valor();
            if (dist[u] > tmp) {
                dist[u] = tmp;
                P[u] = { v };
                Q.push({ tmp, u });
            }
            else if (dist[u] == tmp) {
                P[u].push_back(v);
            }
        }
    }

}


bool resuelveCaso() {
    int V, A;
    cin >> V >> A;
    if (!cin) return false;
    GrafoValorado<int> G(V);
    int a, b, c;
    for (int i = 0; i < A; i++) {
        cin >> a >> b >> c;
        a--; b--;
        Arista<int> arist(a, b, c);
        G.ponArista(arist);
    }
    vvi P(V, vi());
    dijkstra(G, 0, G.V() - 1, P);
    vi camino(V, -1);
    camino[0] = 1;
    cout << dfs(V - 1, P, camino) << "\n";

    return true;
}

int main() {



    while (resuelveCaso());



    return 0;
}