#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <queue>
#include <climits>
#include <memory>
#include <stdexcept>


using namespace std;

const int INF = INT_MAX;

struct Node {
    int d;
    int v;

    bool operator<(const Node& otro) const {
        return otro.d < d;
    }
};

using vi = vector<int>;


template <typename Valor>
class AristaDirigida {
public:
    AristaDirigida() : pimpl(nullptr) {}
    AristaDirigida(int v, int w, Valor valor) : pimpl(std::make_shared<AristaDirigida_impl>(v, w, valor)) {}
    int desde() const { return pimpl->v; }
    int hasta() const { return pimpl->w; }
    Valor valor() const { return pimpl->valor; }

    void print(std::ostream& o = std::cout) const {
        o << "(" << pimpl->v << ", " << pimpl->w << ", " << pimpl->valor << ")";
    }

    bool operator<(AristaDirigida<Valor> const& b) const {
        return valor() < b.valor();
    }
    bool operator>(AristaDirigida<Valor> const& b) const {
        return b.valor() < valor();
    }
private:
    struct AristaDirigida_impl {
        int v, w;
        Valor valor;
        AristaDirigida_impl(int v, int w, Valor valor) : v(v), w(w), valor(valor) {}
    };
    std::shared_ptr<AristaDirigida_impl> pimpl;
};

template <typename Valor>
inline std::ostream& operator<<(std::ostream& o, AristaDirigida<Valor> const& ar) {
    ar.print(o);
    return o;
}



template <typename Valor>
using AdysDirVal = std::vector<AristaDirigida<Valor>>;  // lista de adyacentes a un vértice

template <typename Valor>
class DigrafoValorado {
public:

    /**
     * Crea un grafo con V vértices.
     */
    DigrafoValorado(int v) : _V(v), _A(0), _ady(_V) {}

    /**
     * Crea un grafo dirigido y valorado a partir de los datos en el flujo de entrada.
     */
    DigrafoValorado(std::istream& flujo) : _A(0) {
        flujo >> _V;
        _ady.resize(_V);
        int E, v, w;
        Valor c;
        flujo >> E;
        while (E--) {
            flujo >> v >> w >> c;
            ponArista({ v, w, c });
        }
    }

    /**
     * Devuelve el número de vértices del grafo.
     */
    int V() const { return _V; }

    /**
     * Devuelve el número de aristas del grafo.
     */
    int A() const { return _A; }

    /**
     * Añade la arista dirigida v-w al grafo.
     * @throws invalid_argument si algún vértice no existe
     */
    void ponArista(AristaDirigida<Valor> arista) {
        int v = arista.desde(), w = arista.hasta();
        if (v < 0 || v >= _V || w < 0 || w >= _V)
            throw std::invalid_argument("Vertice inexistente");
        ++_A;
        _ady[v].push_back(arista);
    }

    /**
     * Comprueba si hay arista de v a w.
     */
    bool hayArista(int v, int w) const {
        for (auto a : _ady[v])
            if (a.a() == w) return true;
        return false;
    }

    /**
     * Devuelve la lista de adyacencia de v.
     * @throws invalid_argument si v no existe
     */
    AdysDirVal<Valor> const& ady(int v) const {
        if (v < 0 || v >= _V)
            throw std::invalid_argument("Vertice inexistente");
        return _ady[v];
    }

    /**
     * Devuelve el grafo dirigido inverso.
     */
    DigrafoValorado<Valor> inverso() const {
        DigrafoValorado inv(_V);
        for (auto v = 0; v < _V; ++v) {
            for (auto a : _ady[v]) {
                inv.ponArista({ a.hasta(), a.desde(), a.valor() });
            }
        }
        return inv;
    }

    /**
     * Muestra el grafo en el stream de salida o
     */
    void print(std::ostream& o = std::cout) const {
        o << _V << " vértices, " << _A << " aristas\n";
        for (auto v = 0; v < _V; ++v) {
            o << v << ": ";
            for (auto a : _ady[v]) {
                o << a << " ";
            }
            o << "\n";
        }
    }

private:
    int _V;   // número de vértices
    int _A;   // número de aristas
    std::vector<AdysDirVal<Valor>> _ady;   // vector de listas de adyacentes

};	

void dijkstra(int s, const DigrafoValorado<int>& G, vi& D) {
    D[s] = 0;
    priority_queue<Node> Q;
    Q.push({ 0,s });
    int v, d, u, tmp;
    while (!Q.empty()) {
        v = Q.top().v; d = Q.top().d; Q.pop();
        if (d > D[v])continue;
        for (auto arista : G.ady(v)) {
            u = arista.hasta();
            tmp = D[v] + arista.valor();
            if (tmp < D[u]) {
                D[u] = tmp;
                Q.push({ tmp,u });
            }
        }
    }
}

bool resuelveCaso() {
    // leer los datos de la entrada
    int V, A;
    cin >> V >> A;
    if (!cin) return false;
    DigrafoValorado<int> G1(V), G2(V);
    int a, b, c;
    for (int i = 0; i < A; i++) {
        cin >> a >> b >> c;
        a--; b--;
        AristaDirigida<int> arist(a, b, c);
        G1.ponArista(arist);
        AristaDirigida<int> aristInv(b, a, c);
        G2.ponArista(aristInv);
    }

    int O, P;
    vi v;
    cin >> O >> P;
    O--;
    vi D(V, INF);
    vi DInv(V, INF);
    D[O] = 0;  DInv[O] = 0;
    // A todas las casas a repartir    
    dijkstra(O, G1, D);
    dijkstra(O, G2, DInv);
    int caminos = 0, tmp;    
    for (int i = 0; i < P; i++) {
        cin >> a;
        if (caminos == -1) continue;
        a--;
        if (D[a] == INF || DInv[a] == INF) {
            caminos = -1;
        }
        else caminos += D[a] + DInv[a];
    }        

    if (caminos == -1) cout << "Imposible\n";
    else cout << caminos << "\n";


    return true;
}

int main() {


    while (resuelveCaso());



    return 0;
}