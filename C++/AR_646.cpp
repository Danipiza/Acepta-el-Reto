#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <map>
#include <string>
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



using namespace std;

// Ejercicio que pregunta: Dado un mapa de una ciudad, con
//	los caminos entre intersecciones, y su anchura.
// Determinar si un camion con una anchura determinada
//	puede ir desde un origen "s" a un destino "t".

// Algoritmo de Busqueda en Anchura
// Complejidad Espacial: O(A+V) en este caso cada arista tiene 
//	clase con 3 enteros
// Complejidad Temporal: O(A+V) ya que recorre todas las aristas
//	y vertices del mapa (si puede por la restriccion de anchura)

// Para resolver este problema implemento busqueda en anchura, para
//	recorrer el mapa de intersecciones y expandir las intersecciones
//	que esten en la cola. Se pueden añadir a la cola si la anchura de 
//	la arista es mayor o igual que el tamaño del camion. Por lo que 
//	si un camion tiene una anchura superior al del camino no se añade.
// Y si no puede llegar al vertice destino es porque no hay un camino 
//	por el que quepa el camion, e imprime "NO", si si hay camino
//	imprime "SI".
bool bfs(const GrafoValorado<int>& G, int s, int t, int C) {
	// vector de visitados para marcar nodos ya visitados
	//	 y reducir el tiempo de ejecucion
	vector<int> visited(G.V(),0); 
	bool fin = false; // booleano para terminar si llega al destino
	queue<int> Q; // cola del algoritmo bfs
	Q.push(s); // añade el nodo origen
	visited[s] = 1;
	int v,u;
	while (!Q.empty() && !fin) {
		v = Q.front(); Q.pop(); // saca de la cola el primer valor
		for (Arista<int> a : G.ady(v)) { // expande dicho nodo
			u = a.otro(v);
			// si el nodo adyacente ya fue visitado pasa al siguiente nodo adyacente
			if (visited[u]) continue; 		
			if (a.valor() >= C) { // si la anchura es menor se añade a la cola
				if (u == t) fin = true; // si es el destino acaba el algoritmo
				visited[u] = 1; // marca el nodo como visitado
				Q.push(u);
			}
		}
	}
	return fin;
}

bool resuelveCaso() {
	int V, A;
	cin >> V >> A;
	if (!cin) return false;

	// GrafoValorado ya que es un mapa con direciones 
	//	y anchura como valor
    GrafoValorado<int> G(V);
	int a, b, c;
    for (int i = 0; i < A; i++) {
		cin >> a >> b >> c;
		a--; b--; // para reducir el tamaño del vector del grafo en 1
		//G.ponArista({ a, b, c });
		Arista<int> arista(a, b, c);
		G.ponArista(arista);		
    }

	int K;
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> a >> b >> c;
		a--; b--;
		if (bfs(G, a, b, c)) cout << "SI\n";
		else cout << "NO\n";
	}



	return true;
}

int main() {

	while (resuelveCaso());

	return 0;
}