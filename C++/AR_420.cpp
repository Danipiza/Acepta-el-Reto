#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>  

using namespace std;


int sumaClave(string& cadena, int clave) {
	int cont = 0;
	int suma = 0;
	int i = cadena.size() - 1;
	
	while (i >= 0) {
		suma += (int(cadena[i]) - 48);
		while (suma > clave) {
			suma -= (int(cadena[cadena.size() - 1]) - 48);
			cadena.pop_back();
		}
		if (suma == clave) cont++;
		i--;
	}
	
	return cont;
}

void solve() {
	int clave;
	string cadena;

	cin >> clave >> cadena;

	// compute solution
	int r = sumaClave(cadena, clave);

	// write solution
	cout << r << endl;
}

int main() {
	// uncomment to read from a file instead of standard input
	// ifstream ifs("sample.in");
	// cin.rdbuf(ifs.rdbuf());

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		solve();

	return 0;
}


/*#include <iostream>
#include <string>
#include <math.h>  
using namespace std;

int sumaClave(string& cadena, int clave) {
	int cont = 0;
	

	int a = 0, b = 1;
	int suma = cadena[a]-48 + cadena[b]-48;
	int aux = suma;
	if (suma == clave) {
		cont++;
		suma -= cadena[a] - 48;
		a++;
		b++;
	}
	if (cadena.size() == 1 && cadena[a] - 48 == clave) cont++;

	while (b < cadena.size()) {
		aux += cadena[b] - 48;
		/*if (cadena[a] - 48 == clave) {
			cont++;
			a++;
			b++;
		}
if (clave > aux) {
	suma += cadena[b] - 48;
	b++;
}
else if (clave < aux) {
	suma -= cadena[a] - 48;
	a++;
}
else {
	cont++;
	suma -= cadena[a] - 48;
	a++;
	b++;
	suma += cadena[b] - 48;
}
	}

	if (cadena[b - 1] - 48 == clave) cont++;

	/*for (int i = cadena.size() - 1; i >= 0; --i) {
		suma += (int(cadena[i]) - '0');
		while (suma > clave) {
			suma -= (int(cadena[cadena.size() - 1]) - '0');
			cadena.pop_back();
		}
		if (suma == clave) cont++;
	}
	return cont;
}

void solve() {
	int clave;
	string cadena;

	cin >> clave >> cadena;

	cout << sumaClave(cadena, clave) << '\n';
}

int main() {
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		solve();

	return 0;
}
*/