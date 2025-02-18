#include <iostream>

using namespace std;


bool toestoCampo(int x, int y) {	
	return x>=y;
}

bool resuelveCaso() {
	int x = 0, y = 0;
	cin >> x >> y;
	if (x == 0 && y == 0) return false;

	if (x>=y) cout << "CUERDO\n";
	else cout << "SENIL\n";
	
	return true;
}

int main() {
	while (resuelveCaso()) {}

	return 0;
}