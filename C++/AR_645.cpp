#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <memory>
#include <stdexcept>


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

class ConjuntosDisjuntos {
public:

    // crea una estructura de partición con los elementos 0..N-1, cada uno en un conjunto
    ConjuntosDisjuntos(int N) : nelems(N), ncjtos(nelems), id(nelems, -1) {}

    // devuelve el número de conjuntos disjuntos
    int num_cjtos() const { return ncjtos; }

    //  devuelve el identificador del conjunto que contiene a p
    int buscar(int p) const {
        if (id.at(p) < 0) // es una raíz
            return p;
        else
            return id[p] = buscar(id[p]);
    }

    // unir los conjuntos que contengan a p y q
    void unir(int p, int q) {
        auto i = buscar(p);
        auto j = buscar(q);
        if (i == j) return;
        if (id[i] < id[j]) { // i es la raíz del mayor árbol
            id[i] += id[j]; id[j] = int(i);
        }
        else {
            id[j] += id[i]; id[i] = int(j);
        }
        --ncjtos;
    }

    int tam(int p) const {
        return -id[buscar(p)];
    }

    bool unidos(int p, int q) const {
        return buscar(p) == buscar(q);
    }

protected:
    int nelems;           // los elementos son 0 .. nelems-1
    int ncjtos;           // número de conjuntos disjuntos
    mutable std::vector<int> id;  // si id[i]>=0 es el padre de i, si no es el tamaño del conjunto de i

};



using namespace std;

using vi = vector<int>;

int kruskal(GrafoValorado<int>& G) {
    vector<Arista<int>> _ARM;
    int coste = 0;
    priority_queue<Arista<int>, vector<Arista<int>>, greater<Arista<int>>> pq;
    //PriorityQueue<Arista<Valor>> pq(g.aristas());    
    for (Arista<int> a : G.aristas()) {
        pq.push(a);
    }

    ConjuntosDisjuntos cjtos(G.V());
    while (!pq.empty()) {
        auto a = pq.top(); pq.pop();
        int v = a.uno(), w = a.otro(v);
        if (!cjtos.unidos(v, w)) {
            cjtos.unir(v, w);
            _ARM.push_back(a); coste += a.valor();
            if (_ARM.size() == G.V() - 1) break;
        }
    }
    return (_ARM.size() == G.V() - 1 ? coste : -1);
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
    int ret = kruskal(G);
    if (ret == -1)cout << "No hay puentes suficientes\n";
    else cout << ret << "\n";



    return true;
}

int main() {


    while (resuelveCaso());



    return 0;
}