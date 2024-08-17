#include <iostream>
#include <vector>

using namespace std;

void operaciones(	// DESCRIPCCION
	const vector<int>& v, int num,
	// SOL PARCIAL
	int numP,
	// MARCAJE
	int k,
	// SOLUCION
	bool& fin
) {

	// CASO BASE
	if (k >= 5) {
		if (numP == num) {
			fin = true;
		}

		return;
	}



	// CASO RECURSIVO

	// SUMA	
	if (!fin) {
		operaciones(v, num,
			numP + v[k],
			k + 1,
			fin);
	}

	// RESTA
	if (!fin) {
		operaciones(v, num,
			numP - v[k],
			k + 1,
			fin);
	}


	// MULTIPLICACION
	if (!fin) {
		operaciones(v, num,
			numP * v[k],
			k + 1,
			fin);
	}


	// DIVIVISON
	if (v[k] != 0 && !fin && numP % v[k] == 0) {
		operaciones(v, num,
			numP / v[k],
			k + 1,
			fin);
	}

	

}


bool resuelveCaso() {
	int n;
	cin >> n;

	if (!cin) return false;

	vector<int> v(5);
	for (int i = 0; i < 5; i++) cin >> v[i];

	bool fin = false;
	operaciones(v, n, v[0], 1, fin);

	if (!fin) cout << "NO\n";
	else cout << "SI\n";

	return true;
}

int main() {	
	while (resuelveCaso());

	return 0;
}