#include <iostream>

using namespace std;

unsigned long long int longitud(int n) {
	unsigned long long int ret;
	
	// CASO BASE
	if (n == 1) return 3;
	
	// CASO RECURSIVO
	ret = n + 2 + 2 * longitud(n - 1);

	return ret;
}

char busqueda(int n, unsigned long long k) {
	char ret;

	// CASO BASE 
	if (n == 1) {
		if (k == 1) return 'B';
		else if (k == 3) return 'H';
		else return 'U';
	}

	// CASO RECURSIVO
	unsigned long long int l = longitud(n-1);
	if (k < l + 1) return busqueda(n - 1, k); // PARTE IZQUIERDA
	else if (k > l + 2 + n) return busqueda(n - 1, k - (l + 2 + n)); // PARDE DERECHA
	else {
		k -= l;
		if(k == 1) return 'B';
		else if(k == n + 2) return 'H';
		else return 'U';
	}
}

bool resuelveCaso() {
	int n;
	unsigned long long int k;

	cin >> n >> k;
	if (!cin) return false;
	cout << busqueda(n, k) << "\n";

	return true;
}

int main() {
	while (resuelveCaso());

	return 0;
}
(c) Acepta el reto, 2013 - 2024
