#include <iostream>
#include <vector>

using namespace std;


int main() {
	int N;
	cin >> N;
	int num, pers;
	while (N--) {
		cin >> num >> pers;
		cout << (num / pers >= 12 ? "SI\n" : "NO\n");
	}

	return 0;
}