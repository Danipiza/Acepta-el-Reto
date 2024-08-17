#include <iostream>
#include <vector>

using namespace std;

void prueba(vector<string> v) {
	

	if (v[0] + v[1][0] == v[1][1] + v[2]) {
		cout << "DIVERTIDOS\n";
		return;
	}
	if (v[0] + v[2][0] == v[2][1] + v[1]) {
		cout << "DIVERTIDOS\n";
		return;
	}
	if (v[1] + v[0][0] == v[0][1] + v[2]) {
		cout << "DIVERTIDOS\n";
		return;
	}
	if (v[1] + v[2][0] == v[2][1] + v[0]) {
		cout << "DIVERTIDOS\n";
		return;
	}
	if (v[2] + v[1][0] == v[1][1] + v[0]) {
		cout << "DIVERTIDOS\n";
		return;
	}
	if (v[2] + v[0][0] == v[0][1] + v[1]) {
		cout << "DIVERTIDOS\n";
		return;
	}
	

	cout << "INSULSOS\n";
}

int main() {
	int N;
	cin >> N;
	string a, b, c;
	vector<string> v(3);
	while (N--) {
		cin >> v[0] >> v[1] >> v[2];
		prueba(v);
		
	}

	return 0;
}