#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <map>
#include <string>

using namespace std;

// Modificaciones de la clase:
// unir() se añade una condicion que compara el tamaño del conjunto actual con el maximo, 
//	si es mayor el actual se actualiza el valor del conjunto maximo
// se añade la variable conjuntoMax, tamaño del conjunto mas grande del grafo
class ConjuntosDisjuntos {
public:

	// crea una estructura de partición con los elementos 0..N-1, cada uno en un conjunto
	ConjuntosDisjuntos(int N) : nelems(N), ncjtos(nelems), conjuntoMax(1), id(nelems, -1) {}

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
			if (tam(p) > conjuntoMax) conjuntoMax = tam(p);
		}
		else {
			id[j] += id[i]; id[i] = int(j);
			if (tam(q) > conjuntoMax) conjuntoMax = tam(q);
		}
		--ncjtos;
	}

	int tam(int p) const {
		return -id[buscar(p)];
	}

	bool unidos(int p, int q) const {
		return buscar(p) == buscar(q);
	}

	int componenteMasGrande() const {
		return conjuntoMax;
	}

protected:
	int nelems;           // los elementos son 0 .. nelems-1
	int ncjtos;           // número de conjuntos disjuntos
	int conjuntoMax;	  // Conjunto maximo del grafo
	mutable std::vector<int> id;  // si id[i]>=0 es el padre de i, si no es el tamaño del conjunto de i

};

// Funcion que calcula si la celda esta dentro de la matriz
bool dentro(int F, int C, int x, int y) {
	return x >= 0 && x < F && y >= 0 && y < C;
}

// Codigo mas limpio
using vc = vector<char>;
using vvc = vector<vc>;

// Array con las direcciones adayacentes de una celda
int mX[8] = { -1,-1,-1,0,0,1,1,1 };
int mY[8] = { -1,0,1,-1,1,-1,0,1 };

// Une manchas, recorre las direcciones adayacentes de la celda dada (i,j)
//	y junta si tiene algun conjunto adayacente
void unirManchas(int F, int C, int i, int j, ConjuntosDisjuntos& disj, vvc& mat, int cont) {
	int x, y;
	for (int k = 0; k < 8-cont; k++) {
		x = i + mX[k]; y = j + mY[k];
		if (dentro(F, C, x, y) && mat[x][y] == '#') disj.unir(i * C + j, x * C + y);
	}	
}


bool resuelveCaso() {
	int F, C;
	cin >> F >>C;
	if (!std::cin) return false;
	
	getchar(); // Quitar el salto de linea, en visual no hace falta, juez?
	int hayPetroleo = 0;
	// Matriz con los chars, # es petroleo
	vvc M(F, vector<char>(C));
	// Grafo de componentes Disjuntas
	ConjuntosDisjuntos GDisj(F * C);
	char elem;
	for (int i = 0; i < F; ++i) {
		for (int j = 0; j < C; ++j) {
			elem = getchar();
			M[i][j] = elem;
			if (elem == '#') {
				hayPetroleo++;
				unirManchas(F, C, i, j, GDisj, M, 3); // Las 3 casillas de abajo no se procesan todavia				
			}
		}
		getchar(); // Quitar el salto de linea, en visual no hace falta, juez?
	}
	if (hayPetroleo > 0) cout << GDisj.componenteMasGrande();
	else cout << "0";

	int N, x, y;
	cin >> N;
	if (N > 0) cout << " ";
	for (int i = 0; i < N; ++i) {
		cin >> x >> y;
		x--;
		y--;
		M[x][y] = '#';		
		unirManchas(F, C, x, y, GDisj, M, 0);
		cout << GDisj.componenteMasGrande();
		if (i < N - 1) cout << " ";
	}
	cout << '\n';
	return true;
}

int main() {
	/*#ifndef DOMJUDGE
	std::ifstream in("sample.in");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif*/

	while (resuelveCaso());

	/*#ifndef DOMJUDGE
		std::cin.rdbuf(cinbuf);
	#endif*/
	return 0;
}