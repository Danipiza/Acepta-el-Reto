#include <iostream>

using namespace std;


int main() {
	int N;
	cin >> N;
	while (N!=0) {
		int ret = 0,a;
		for (int i = 0; i < N; i++) {
			cin >> a;
			ret += a;
		}
		cout << ret - N + 1 << "\n";
		cin >> N;
	}

	return 0;
}