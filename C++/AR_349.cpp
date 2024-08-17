#include <iostream>

using namespace std;

int operar () {
	char valor;
	cin >> valor;
	if (isalnum(valor)) return valor - '0';
	else {
		int sum1 = operar();
		int sum2 = operar();
		if (valor == '+') return sum1 + sum2;
		else if (valor =='-') return sum1 - sum2;
		else if (valor == '*') return sum1 * sum2;
		else return sum1 / sum2;
	}
}

void solve() {
	cout << operar() << '\n';
}

int main() {	
	int numCasos;
	cin >> numCasos;
	
	for (int i = 0; i < numCasos; ++i)
		solve();
	return 0;
}