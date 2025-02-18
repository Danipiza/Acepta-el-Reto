#include <iostream>
#include <algorithm>
using namespace std;

const int BASE_CONVERSION = 6;


void valorDivision(int numBaseDiez) {
	
	if (numBaseDiez / BASE_CONVERSION == 0) {
		cout << numBaseDiez;
	}
	else if (numBaseDiez / BASE_CONVERSION <= 5) {
		cout << numBaseDiez / BASE_CONVERSION << numBaseDiez % BASE_CONVERSION;
	}
	else {
		valorDivision(numBaseDiez / BASE_CONVERSION);
		cout << numBaseDiez % BASE_CONVERSION;
	}

}


void solve() {
	int numBaseDiez;
	cin >> numBaseDiez;

	valorDivision(numBaseDiez);
	cout << '\n';
}

int main() {
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		solve();


	return 0;
}