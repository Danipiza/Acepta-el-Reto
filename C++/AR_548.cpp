#include <iostream>
#include <vector>

using namespace std;

bool viajes(vector<int> v, int paradas, int med) {
	int sum = 0;
	bool ret = true;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] + sum <= med) sum += v[i];
		else {
			if (paradas > 0 && v[i] <= med) {
				sum = v[i];
				paradas--;
			}
			else ret = false;
		}
	}
	return ret;
}

int busquedaSolucion(const vector<int>& v, int paradas, int ini, int fin) {
    int ret;
    int med = (fin + ini) / 2;
    bool valida = viajes(v, paradas, med);

    if (ini == fin) ret = fin; // CASO BASE  
    else {
        if (valida) ret = busquedaSolucion(v, paradas, ini, med); // IZQ        
        else ret = busquedaSolucion(v, paradas, med + 1, fin); // DER
        
    }

    return ret;
}

bool resuelveCaso() {
	int n = 0, p = 0;
	cin >> n >> p;
	if (!cin) return false;

	int suma = 0;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		suma += v[i];
	}
		

	

	cout << busquedaSolucion(v, p, 0, suma) << "\n";

	return true;
}

int main() {
	while (resuelveCaso());

	return 0;
}