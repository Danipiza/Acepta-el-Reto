#include <iostream>
#include <string>
#include <list>
#include <string>

using namespace std;

void cucurucho(		// DESCRIPCION
	string prefix,
	int C, int V,
	// SOLUCION PARCIAL
	int kC, int kV,
	// SOLUCION
	list<string> &ret
) {
	if (kC == C && kV == V) { // CASO BASE
		ret.push_back(prefix);
		return;
	}

	// CASO RECURSIVO
	if (kC < C) {
		cucurucho(prefix + "C", C, V,
			kC + 1, kV, ret);
	}
	if (kV < V) {
		cucurucho(prefix + "V", C, V,
			kC, kV + 1, ret);
	}


}

void resuelveCaso() {
	int C, V;
	cin >> C >> V;
	list<string> ret;
	cucurucho("", C, V, 0, 0,ret);
	int tam = ret.size();
	for (int i = 0; i < tam; i++) {
		cout << ret.front();
		ret.pop_front();
		if (!ret.empty()) cout << " ";
	}
	cout << "\n";
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		resuelveCaso();
	}
}