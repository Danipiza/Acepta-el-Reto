#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
using namespace std;

const int LADOS_CUADRADO = 4;

int fractales(int longitud, int numeroCuadrados){
	int sumaLongitud;
	
	if (longitud == 1) sumaLongitud = LADOS_CUADRADO * numeroCuadrados;
	else {
		sumaLongitud = fractales(longitud / 2, LADOS_CUADRADO * numeroCuadrados) + numeroCuadrados * LADOS_CUADRADO * longitud;
	}
	
	return sumaLongitud;
}


bool solve() {
	int longitud;
	cin >> longitud;
	if (!std::cin)
		return false;

	if (longitud == 0) cout << "0 \n";
	else {
		int sumaLongitud = fractales(longitud, 1);
		cout << sumaLongitud << '\n';
	}
	return true;

}

int main() {
	while (solve());

	return 0;
}