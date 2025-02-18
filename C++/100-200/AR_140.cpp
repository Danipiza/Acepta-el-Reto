#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
using namespace std;


int sumDigitos(int numero) {
	int ret;

	if (numero / 10 == 0) {
		ret = numero % 10;
		cout << numero;
	}
	else {
		ret = sumDigitos(numero / 10) + (numero % 10);
		cout << " + ";
		cout << (numero % 10);
	}
	return ret;
}


bool solve() {
	int n;
	cin >> n;
	if (n < 0)
		return false;

	int suma = sumDigitos(n);
	cout << " = " << suma << '\n';

	return true;

}

int main() {
	while (solve());

	return 0;
}