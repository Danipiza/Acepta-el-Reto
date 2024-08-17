#include <iostream>


using namespace std;

bool movil(int& sumNodos, bool& fin) {
	
	
	int pi = 0, di = 0, pd = 0, dd = 0;
	cin >> pi >> di >> pd >> dd;
	if (pi == 0 && di == 0 && pd == 0 && dd == 0) {
		fin = true;
		return false;
	}
	// CASO BASE
	if (pi != 0 && pd != 0) { // MOVIL SIN SUBMOVILES
		sumNodos += pi + pd;
		if (pi * di == pd * dd) return true;
		else {			
			return false;
		}
	}

	// CASO RECURSIVO	
	// IZQ
	bool izq = true;
	int izqNodos = pi;
	if (pi == 0) {
		izq = movil(izqNodos, fin);
	}

	// DERECHA
	bool der = true;
	int derNodos = pd;
	if (pd == 0) {
		der = movil(derNodos, fin);
	}
	sumNodos = izqNodos + derNodos;

	
	return izqNodos * di == derNodos * dd && izq && der;
	
	
}

bool solve() {
	int sumNodos = 0;
	bool fin = false;

	if (movil(sumNodos, fin)) cout << "SI\n";
	else if (fin) return false;
	else cout << "NO\n";
	
	return true;
}


/*
bool movil(int pi, int di, int pd, int dd, int& sumNodos) {
	// CASO BASE
	if (pi != 0 && pd != 0) { // MOVIL SIN SUBMOVILES
		sumNodos += pi + pd;
		if (pi * di == pd * dd) return true;
		else return false;
	}

	// CASO RECURSIVO	

	// IZQ
	bool izq;
	int izqNodos = 0;
	if (pi == 0) {
		int piAux = 0, diAux = 0, pdAux = 0, ddAux = 0;
		cin >> piAux >> diAux >> pdAux >> ddAux;
		izq = movil(piAux, diAux, pdAux, ddAux, izqNodos);
	}

	// DERECHA
	bool der;
	int derNodos = 0;
	if (pd == 0) {
		int piAux = 0, diAux = 0, pdAux = 0, ddAux = 0;
		cin >> piAux >> diAux >> pdAux >> ddAux;
		der = movil(piAux, diAux, pdAux, ddAux, derNodos);
	}
	sumNodos = izqNodos + derNodos;

	if (pi == 0 && pd == 0) return izqNodos * di == derNodos * dd && izq && der;
	else if (pi == 0) return izqNodos * di == pd * dd && izq;
	else if (pd == 0) return pi * di == derNodos * dd && der;
}


bool solve() {
	int pi, di, pd, dd;
	cin >> pi >> di >> pd >> dd;

	if (pi == 0 && di == 0 && pd == 0 && dd == 0) return false;

	int sumNodos = 0;
	if (movil(pi, di, pd, dd, sumNodos)) cout << "SI\n";
	else cout << "NO\n";

	return true;
}*/

int main() {
	ios_base::sync_with_stdio(false);
	while (solve()) {}

	return 0;
}