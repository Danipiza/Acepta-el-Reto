#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int calendarios(const vector<int>& v) {
	int maximo = 1930, minimo = 1990;
	for (int i = 0; i < v.size(); ++i) {
		maximo = max(maximo, v[i]);
		minimo = min(minimo, v[i]);
	}

	return maximo - minimo - v.size() + 1;
}

void resuelveCaso() {
	int n = 0;
	cin >> n;
	vector<int> v(n);

	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	cout << calendarios(v) << "\n";

}

int main() {
	int numCasos = 0;
	cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) {
		resuelveCaso();
	}


	return 0;
}